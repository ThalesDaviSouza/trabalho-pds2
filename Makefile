BUILD_DIR = ./build
CPPFLAGS = -I include

all: compilerProject 

compilerProject: $(BUILD_DIR)/main.o $(BUILD_DIR)/jogador.o $(BUILD_DIR)/jogadorInGame.o $(BUILD_DIR)/gerenciadorDeJogadores.o $(BUILD_DIR)/menu.o $(BUILD_DIR)/menuItem.o $(BUILD_DIR)/menuGerenciarJogadores.o
	g++ -o output $(BUILD_DIR)/main.o $(BUILD_DIR)/jogador.o $(BUILD_DIR)/jogadorInGame.o $(BUILD_DIR)/gerenciadorDeJogadores.o $(BUILD_DIR)/menu.o $(BUILD_DIR)/menuItem.o $(BUILD_DIR)/menuGerenciarJogadores.o

$(BUILD_DIR)/main.o: ./src/main.cpp ./include/jogador.hpp | build
	g++ $(CPPFLAGS) -c ./src/main.cpp -o $(BUILD_DIR)/main.o

$(BUILD_DIR)/jogador.o: ./src/jogador.cpp ./include/jogador.hpp | build
	g++ $(CPPFLAGS) -c ./src/jogador.cpp -o $(BUILD_DIR)/jogador.o 

$(BUILD_DIR)/jogadorInGame.o: ./src/jogadorInGame.cpp ./include/jogadorInGame.hpp | build
	g++ $(CPPFLAGS) -c ./src/jogadorInGame.cpp -o $(BUILD_DIR)/jogadorInGame.o 

$(BUILD_DIR)/gerenciadorDeJogadores.o: ./src/gerenciadorDeJogadores.cpp ./include/gerenciadorDeJogadores.hpp | build
	g++ $(CPPFLAGS) -c ./src/gerenciadorDeJogadores.cpp -o $(BUILD_DIR)/gerenciadorDeJogadores.o 

$(BUILD_DIR)/menu.o: ./src/menus/menu.cpp ./include/menus/menu.hpp | build
	g++ $(CPPFLAGS) -c ./src/menus/menu.cpp -o $(BUILD_DIR)/menu.o 

$(BUILD_DIR)/menuItem.o: ./src/menus/menuItem.cpp ./include/menus/menuItem.hpp | build
	g++ $(CPPFLAGS) -c ./src/menus/menuItem.cpp -o $(BUILD_DIR)/menuItem.o 

$(BUILD_DIR)/menuGerenciarJogadores.o: ./src/menus/menuGerenciarJogadores.cpp ./include/menus/menuGerenciarJogadores.hpp | build
	g++ $(CPPFLAGS) -c ./src/menus/menuGerenciarJogadores.cpp -o $(BUILD_DIR)/menuGerenciarJogadores.o 

build:
	mkdir build