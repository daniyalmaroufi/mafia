CPP_EXEC=g++
CPP_STD=-std=c++11
CPP_FLAGS=-g
MAFIA_DIR=Mafia/
PLAYER_DIR=Player/


CPP=$(CPP_EXEC) $(CPP_STD) $(CPP_FLAGS)

all: mafia.out

mafia.out: obj/main.o obj/mafia.o obj/player.o
	$(CPP) obj/main.o obj/mafia.o  obj/player.o -o mafia.out

obj/main.o: main/main.cpp
	$(CPP) -c main/main.cpp -o obj/main.o

obj/mafia.o: $(MAFIA_DIR)Mafia.cpp $(MAFIA_DIR)Mafia.hpp
	$(CPP) -c $(MAFIA_DIR)Mafia.cpp -o obj/mafia.o

obj/player.o: $(PLAYER_DIR)Player.cpp $(PLAYER_DIR)Player.hpp
	$(CPP) -c $(PLAYER_DIR)Player.cpp -o obj/player.o

clean:
	rm -r *.out
	rm -r obj/*.o
