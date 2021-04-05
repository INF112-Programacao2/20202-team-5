
output: main.o board.o card.o coloredCard.o deck.o game.o numberedCard.o player.o stack.o blackCard.o coloredDrawCard.o skipCard.o wildCard.o
	g++ main.o board.o card.o coloredCard.o deck.o game.o numberedCard.o player.o stack.o blackCard.o coloredDrawCard.o skipCard.o wildCard.o -o output

main.o: main.cpp
	g++ -c main.cpp

board.o: board.cpp board.h
	g++ -c board.cpp

card.o: card.cpp card.h
	g++ -c card.cpp

coloredCard.o: coloredCard.cpp coloredCard.h
	g++ -c coloredCard.cpp

deck.o: deck.cpp deck.h
	g++ -c deck.cpp

game.o: game.cpp game.h
	g++ -c game.cpp

numberedCard.o: numberedCard.cpp numberedCard.h
	g++ -c numberedCard.cpp

player.o: player.cpp player.h
	g++ -c player.cpp

stack.o: stack.cpp stack.h
	g++ -c stack.cpp

blackCard.o: blackCard.cpp blackCard.h
	g++ -c blackCard.cpp

coloredDrawCard.o: coloredDrawCard.cpp coloredDrawCard.h
	g++ -c coloredDrawCard.cpp

skipCard.o: skipCard.cpp skipCard.h
	g++ -c skipCard.cpp

wildCard.o: wildCard.cpp wildCard.h
	g++ -c wildCard.cpp

clean:
	rm *.o output
