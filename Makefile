ifeq ($(OS),Windows_NT)
    SLASH = \\
		RM = del
else
    SLASH = /
		RM = rm -f
endif

BUILD_DIR = ./build
BUILD_DIR_TESTS = ./build/tests

BUILD = build
BUILD_MENU = build$(SLASH)menus
BUILD_TABULEIRO = build$(SLASH)tabuleiros

BUILD_TESTS = build$(SLASH)tests
BUILD_TESTS_MENUS = build$(SLASH)tests$(SLASH)menus
BUILD_TESTS_TABULEIROS = build$(SLASH)tests$(SLASH)tabuleiros

SRC_DIR = ./src
TESTS_DIR = ./tests
INCLUDE_DIR = ./include

CXX = g++ -std=gnu++11
CXX_COVERAGE = g++ -std=gnu++11 -fprofile-arcs -ftest-coverage -g
CPPFLAGS = -I$(INCLUDE_DIR)
CXXFLAGS = -c

SOURCES = $(wildcard $(SRC_DIR)/**/*.cpp $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))

SOURCES_NO_MAIN = $(filter-out $(SRC_DIR)/main.cpp, $(wildcard $(SRC_DIR)/**/*.cpp $(SRC_DIR)/*.cpp))
OBJECTS_NO_MAIN = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SOURCES_NO_MAIN))
SOURCES_TESTS = $(wildcard $(TESTS_DIR)/**/*.cpp $(TESTS_DIR)/*.cpp)
OBJECTS_TESTS = $(patsubst $(TESTS_DIR)/%.cpp, $(BUILD_DIR_TESTS)/%.o, $(SOURCES_TESTS))

TARGET = output
TARGET_COVERAGE = output_coverage
TARGET_TEST = output_test

# Compila o programa normal
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | preparar_build
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $< -o $@

preparar_build: $(BUILD) $(BUILD_MENU) $(BUILD_TABULEIRO)

$(BUILD): 
	mkdir $@

$(BUILD_MENU):
	mkdir $@

$(BUILD_TABULEIRO):
	mkdir $@


# Compila os testes
tests: $(TARGET_TEST)
	./$(TARGET_TEST)

$(TARGET_TEST): $(OBJECTS_TESTS) $(OBJECTS_NO_MAIN) | clean
	$(CXX) -o $@ $^

$(BUILD_DIR_TESTS)/%.o: $(TESTS_DIR)/%.cpp | preparar_build_tests
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $< -o $@

preparar_build_tests: $(BUILD_TESTS) $(BUILD_TESTS_MENUS) $(BUILD_TESTS_TABULEIROS)

$(BUILD_TESTS):
	mkdir $@

$(BUILD_TESTS_MENUS):
	mkdir $@

$(BUILD_TESTS_TABULEIROS):
	mkdir $@

# Gera o relatório
report: aviso_report $(TARGET_COVERAGE) | clean 
	$(TARGET_COVERAGE)
	gcovr -r . --html --html-details -o report.html --exclude 'tests/.*'
	@echo Report gerado com sucesso!
	@echo Para conferir ele, abra o arquivo report.html

aviso_report:
	@echo Preparando para gerar o report...
	@echo Caso nao possua o gcovr tente o comando no README

$(TARGET_COVERAGE): $(SOURCES_TESTS) $(SOURCES_NO_MAIN) | clean
	$(CXX_COVERAGE) $(CPPFLAGS) -o $@ $^

# Gera o relatório
report: aviso_report $(TARGET_COVERAGE) | clean 
	$(TARGET_COVERAGE)
	gcovr -r . --html --html-details -o report.html --exclude 'tests/.*'
	@echo Report gerado com sucesso!
	@echo Para conferir ele, abra o arquivo report.html

aviso_report:
	@echo Preparando para gerar o report...
	@echo Caso nao possua o gcovr tente o comando no README

$(TARGET_COVERAGE): $(SOURCES_TESTS) $(SOURCES_NO_MAIN) | clean
	$(CXX_COVERAGE) $(CPPFLAGS) -o $@ $^


clean:
	$(RM) *.o *.exe *.gcno *.gcda *.css *.html
	
	