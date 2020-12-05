CPP_EXEC=g++
CPP_STD=-std=c++11
CPP_FLAGS=-g
GAME_MANAGER_DIR=GameManager/
MAFIA_DIR=Mafia/
PLAYER_DIR=Player/
JOKER_DIR=Joker/
VILLAGER_DIR=Villager/


CPP=$(CPP_EXEC) $(CPP_STD) $(CPP_FLAGS)

all: mafia.out

mafia.out: obj/main.o obj/game_manager.o obj/mafia.o obj/player.o obj/joker.o obj/godfather.o obj/silencer.o obj/villager.o obj/detective.o obj/doctor.o obj/bulletproof.o
	$(CPP) obj/main.o obj/game_manager.o obj/mafia.o  obj/player.o obj/joker.o obj/godfather.o obj/silencer.o obj/villager.o obj/detective.o obj/doctor.o obj/bulletproof.o -o mafia.out

obj/main.o: main/main.cpp
	$(CPP) -c main/main.cpp -o obj/main.o

obj/game_manager.o: $(GAME_MANAGER_DIR)GameManager.cpp $(GAME_MANAGER_DIR)GameManager.hpp
	$(CPP) -c $(GAME_MANAGER_DIR)GameManager.cpp -o obj/game_manager.o

obj/mafia.o: $(MAFIA_DIR)Mafia.cpp $(MAFIA_DIR)Mafia.hpp
	$(CPP) -c $(MAFIA_DIR)Mafia.cpp -o obj/mafia.o

obj/silencer.o: $(MAFIA_DIR)Silencer.cpp $(MAFIA_DIR)Silencer.hpp
	$(CPP) -c $(MAFIA_DIR)Silencer.cpp -o obj/silencer.o

obj/godfather.o: $(MAFIA_DIR)GodFather.cpp $(MAFIA_DIR)GodFather.hpp
	$(CPP) -c $(MAFIA_DIR)GodFather.cpp -o obj/godfather.o

obj/player.o: $(PLAYER_DIR)Player.cpp $(PLAYER_DIR)Player.hpp
	$(CPP) -c $(PLAYER_DIR)Player.cpp -o obj/player.o

obj/joker.o: $(JOKER_DIR)Joker.cpp $(JOKER_DIR)Joker.hpp
	$(CPP) -c $(JOKER_DIR)Joker.cpp -o obj/joker.o

obj/villager.o: $(VILLAGER_DIR)Villager.cpp $(VILLAGER_DIR)Villager.hpp
	$(CPP) -c $(VILLAGER_DIR)Villager.cpp -o obj/villager.o

obj/detective.o: $(VILLAGER_DIR)Detective.cpp $(VILLAGER_DIR)Detective.hpp
	$(CPP) -c $(VILLAGER_DIR)Detective.cpp -o obj/detective.o

obj/doctor.o: $(VILLAGER_DIR)Doctor.cpp $(VILLAGER_DIR)Doctor.hpp
	$(CPP) -c $(VILLAGER_DIR)Doctor.cpp -o obj/doctor.o

obj/bulletproof.o: $(VILLAGER_DIR)BulletProof.cpp $(VILLAGER_DIR)BulletProof.hpp
	$(CPP) -c $(VILLAGER_DIR)BulletProof.cpp -o obj/bulletproof.o

clean:
	rm -r *.out
	rm -r obj/*.o
