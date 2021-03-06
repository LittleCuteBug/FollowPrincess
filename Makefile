#OBJS specifies which files to compile as part of the project
OBJS = src/main.cpp src/CPlayer.cpp src/CMap.cpp src/SDLFunc.cpp src/CGame.cpp src/SDLCGame.cpp src/GameStatus.cpp src/GameState.cpp

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = game

#This is the target that compiles our executable
all : $(OBJS)
	gcc $(OBJS) -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lstdc++ -o $(OBJ_NAME)