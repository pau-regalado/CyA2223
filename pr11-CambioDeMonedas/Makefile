#################################################
# MAKEFILE
#################################################

CXX		 := g++
CXXFLAGS := -std=c++11

BIN     := bin
SRC     := src
BUILD	:= build
INCLUDE := include
LIB     := lib
LIBRARIES   := 
EXECUTABLE  := monedas
PARAMS    			:= 10
PARAMS8   			:= dataFile/input.gra outputFiles/test1.gra
SOURCES := $(wildcard $(SRC)/*.cc)
OBJS	:= $(patsubst $(SRC)/%.cc,$(BUILD)/%.o,$(SOURCES))

.PHONY: all project run clean

all: $(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(OBJS)
	@echo "๐ง Building..."
	$(CXX) -o $@ $(CXXFLAGS) -L$(LIB) $(OBJS)

$(BUILD)/%.o: $(SRC)/%.cc
	@echo "๐ง Building..."
	$(CXX) -c -o $@ $(CXXFLAGS) $<

project:
	clear
	@echo "๐ Creating Project Structure..."
	mkdir -p bin build include src

run:
	clear
	@echo "๐ Executing..."
	./$(BIN)/$(EXECUTABLE) $(PARAMS)

clean:
	@echo "๐งน Clearing..."
	rm -f $(BIN)/* $(BUILD)/*