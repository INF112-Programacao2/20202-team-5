
output: main.o card.o board.o coloredCard.o deck.o game.o numberedCard.o player.o stack.o blackCard.o coloredDrawCard.o skipCard.o wildCard.o hand.o plus4.o reverseCard.o
	g++ main.o card.o board.o coloredCard.o deck.o game.o numberedCard.o player.o stack.o blackCard.o coloredDrawCard.o skipCard.o wildCard.o hand.o plus4.o reverseCard.o -o output -I/usr/include/allegro5 -L/usr/lib -lallegro -lallegro_main -lallegro_font -lallegro_image

main.o: main.cpp
	g++ -c main.cpp

card.o: card.cpp card.h
	g++ -c card.cpp

board.o: board.cpp board.h
	g++ -c board.cpp

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

hand.o: hand.cpp hand.h
	g++ -c hand.cpp

plus4.o: plus4.cpp plus4.h
	g++ -c plus4.cpp

reverseCard.o: reverseCard.cpp reverseCard.h
	g++ -c reverseCard.cpp

clean:
	rm *.exe.stackdump *.h.gch *.ghc *.o output
