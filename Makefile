BUILD_DIR = ./build
CPPFLAGS = -I include

all: compilerProject 

compilerProject: $(BUILD_DIR)/main.o $(BUILD_DIR)/jogador.o $(BUILD_DIR)/jogadorInGame.o
    g++ -o output $(BUILD_DIR)/main.o $(BUILD_DIR)/jogador.o $(BUILD_DIR)/jogadorInGame.o

$(BUILD_DIR)/main.o: ./src/main.cpp ./include/jogador.hpp | build
    g++ $(CPPFLAGS) -c ./src/main.cpp -o $(BUILD_DIR)/main.o

$(BUILD_DIR)/jogador.o: ./src/jogador.cpp ./include/jogador.hpp | build
    g++ $(CPPFLAGS) -c ./src/jogador.cpp -o $(BUILD_DIR)/jogador.o 

$(BUILD_DIR)/jogadorInGame.o: ./src/jogadorInGame.cpp ./include/jogadorInGame.hpp | build
    g++ $(CPPFLAGS) -c ./src/jogadorInGame.cpp -o $(BUILD_DIR)/jogadorInGame.o 

build:
    mkdir build