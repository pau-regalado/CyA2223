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
EXECUTABLE  := dfa_simulator
PARAMSDFA 			:= dataFile/modificacion.fa dataFile/modificacion.txt
PARAMSNFA 			:= dataFile/nfamodificacion.fa dataFile/modificacion.txt
PARAMSMOD 			:= dataFile/nfamodificacion.fa dataFile/modificacion.fa dataFile/modificacion.txt
PARAMS6   			:= dataFile/dfa6.fa
SOURCES := $(wildcard $(SRC)/*.cc)
OBJS	:= $(patsubst $(SRC)/%.cc,$(BUILD)/%.o,$(SOURCES))

.PHONY: all project dfa nfa run clean

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

dfa:
	clear
	@echo "๐ Executing..."
	./$(BIN)/$(EXECUTABLE) $(PARAMSDFA)

nfa:
	clear
	@echo "๐ Executing..."
	./$(BIN)/$(EXECUTABLE) $(PARAMSNFA)

mod:
	clear
	@echo "๐ Executing..."
	./$(BIN)/$(EXECUTABLE) $(PARAMSMOD)  

p:
	clear
	@echo "๐ Executing..."
	./$(BIN)/$(EXECUTABLE) $(PARAMS6)  

clean:
	@echo "๐งน Clearing..."
	rm -f $(BIN)/* $(BUILD)/*