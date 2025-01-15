BUILD_DIR = ./build
BUILD_DIR_TESTS = ./build/tests

BUILD = build
BUILD_MENU = build/menus
BUILD_TESTS = build\tests
BUILD_TESTS_MENUS = build\tests\menus

SRC_DIR = ./src
TESTS_DIR = ./tests
INCLUDE_DIR = ./include

CXX = g++ -std=gnu++11
CPPFLAGS = -I$(INCLUDE_DIR)
CXXFLAGS = -c

SOURCES = $(wildcard $(SRC_DIR)/**/*.cpp $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))

SOURCES_NO_MAIN = $(filter-out $(SRC_DIR)/main.cpp, $(wildcard $(SRC_DIR)/**/*.cpp $(SRC_DIR)/*.cpp))
OBJECTS_NO_MAIN = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SOURCES_NO_MAIN))
SOURCES_TESTS = $(wildcard $(TESTS_DIR)/**/*.cpp $(TESTS_DIR)/*.cpp)
OBJECTS_TESTS = $(patsubst $(TESTS_DIR)/%.cpp, $(BUILD_DIR_TESTS)/%.o, $(SOURCES_TESTS))

TARGET = output
TARGET_TEST = output_test

# Compila o programa normal
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | preparar_build
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $< -o $@

preparar_build: $(BUILD) $(BUILD_MENU)

$(BUILD): 
	mkdir $(BUILD)

$(BUILD_MENU):
	mkdir $(BUILD_MENU)


# Compila os testes
tests: $(TARGET_TEST)
	$(TARGET_TEST)

$(TARGET_TEST): $(OBJECTS_TESTS) $(OBJECTS_NO_MAIN) | clean
	$(CXX) -o $@ $^

$(BUILD_DIR_TESTS)/%.o: $(TESTS_DIR)/%.cpp | preparar_build_tests
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $< -o $@

preparar_build_tests: $(BUILD_TESTS) $(BUILD_TESTS_MENUS)

$(BUILD_TESTS):
	mkdir $(BUILD_TESTS)

$(BUILD_TESTS_MENUS):
	mkdir $(BUILD_TESTS_MENUS)


clean:
	del *.o *.exe