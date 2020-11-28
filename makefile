CPP_EXEC=g++
CPP_STD=-std=c++11
CPP_FLAGS=-g
MAFIA_DIR=Mafia/


CPP=$(CPP_EXEC) $(CPP_STD) $(CPP_FLAGS)

all: mafia.out

mafia.out: obj/main.o obj/mafia.o
	$(CPP) obj/main.o obj/mafia.o -o mafia.out

obj/main.o: main/main.cpp
	$(CPP) -c main/main.cpp -o obj/main.o

obj/mafia.o: $(MAFIA_DIR)Mafia.cpp $(MAFIA_DIR)Mafia.hpp
	$(CPP) -c $(MAFIA_DIR)Mafia.cpp -o obj/mafia.o

clean:
	rm -r *.out
	rm -r obj/*.o