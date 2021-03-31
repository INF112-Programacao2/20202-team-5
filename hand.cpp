#include "hand.h"

Hand::Hand(int inittialNumberOfCards,Deck &deck){
   for(int i=0;i<inittialNumberOfCards;i++){
       draw(1,deck);
   }
}

void Hand::draw(int ammount,Deck &deck){
    for (int i=0;i<ammount;i++){
        _cards.push_back(deck.drawCards());
    }
}

void Hand::play(Card* card,Stack &stack){
    int j = 0;
    for(int i=0;j==0;i++){
        if(_cards[i]==card){
            stack.set_topCard(card);
            _cards.erase(_cards.begin()+i);
        }
    }
}

bool Hand::hasPlay(Card* stackTopCard){
    for(int i=0;i<=_cards.size();i++){
        if((_cards[i]->get_color() == stackTopCard->get_color())||(_cards[i]->get_number() == stackTopCard->get_number())){
            return true;
        }
    }
    return false;
}

//void Hand::noPlay(){}
