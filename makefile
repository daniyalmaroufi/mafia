CPP_EXEC=g++
CPP_STD=-std=c++11
CPP_FLAGS=-g
BALL_DIR=Ball/


CPP=$(CPP_EXEC) $(CPP_STD) $(CPP_FLAGS)

all: mafia.out

mafia.out: obj/main.o
	$(CPP) obj/main.o -o mafia.out

obj/main.o: main/main.cpp
	$(CPP) -c main/main.cpp -o obj/main.o

clean:
	rm -r *.out
	rm -r obj/*.o