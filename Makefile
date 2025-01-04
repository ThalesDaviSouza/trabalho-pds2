BUILD_DIR = ./build
CPPFLAGS = -std=c++17 -I include

all: compilerProject 

compilerProject: $(BUILD_DIR)/main.o $(BUILD_DIR)/jogador.o $(BUILD_DIR)/jogadorInGame.o $(BUILD_DIR)/gerenciadorDeJogadores.o
	g++ -o output $(BUILD_DIR)/main.o $(BUILD_DIR)/jogador.o $(BUILD_DIR)/jogadorInGame.o $(BUILD_DIR)/gerenciadorDeJogadores.o

$(BUILD_DIR)/main.o: ./src/main.cpp ./include/jogador.hpp | build
	g++ $(CPPFLAGS) -c ./src/main.cpp -o $(BUILD_DIR)/main.o

$(BUILD_DIR)/jogador.o: ./src/jogador.cpp ./include/jogador.hpp | build
	g++ $(CPPFLAGS) -c ./src/jogador.cpp -o $(BUILD_DIR)/jogador.o 

$(BUILD_DIR)/jogadorInGame.o: ./src/jogadorInGame.cpp ./include/jogadorInGame.hpp | build
	g++ $(CPPFLAGS) -c ./src/jogadorInGame.cpp -o $(BUILD_DIR)/jogadorInGame.o 

$(BUILD_DIR)/gerenciadorDeJogadores.o: ./src/gerenciadorDeJogadores.cpp ./include/gerenciadorDeJogadores.hpp | build
	g++ $(CPPFLAGS) -c ./src/gerenciadorDeJogadores.cpp -o $(BUILD_DIR)/gerenciadorDeJogadores.o 

build:
	mkdir build