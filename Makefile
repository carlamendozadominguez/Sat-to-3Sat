SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g -I$(INC) -c
HDRS = $(INC)/SAT.h $(INC)/SAT3.h $(INC)/SAT2SAT3.h

all: $(BIN)/convertir

$(BIN)/convertir: $(OBJ)/convertir.o $(OBJ)/SAT.o $(OBJ)/SAT3.o $(OBJ)/SAT2SAT3.o 
	$(CXX) $^ -o $@

$(OBJ)/convertir.o: $(SRC)/convertir.cpp $(HDRS)
	$(CXX) $(CPPFLAGS) $< -o $@

$(OBJ)/SAT2SAT3.o: $(SRC)/SAT2SAT3.cpp $(HDRS)
	$(CXX) $(CPPFLAGS) $< -o $@

$(OBJ)/SAT3.o: $(SRC)/SAT3.cpp $(HDRS)
	$(CXX) $(CPPFLAGS) $< -o $@

$(OBJ)/SAT.o: $(SRC)/SAT.cpp $(HDRS)
	$(CXX) $(CPPFLAGS) $< -o $@

clean:
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~ $(BIN)/*