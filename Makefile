CXX = g++
CXXFLAGS = -std=c++17 -Wall -I include

SRC = src/main.cpp src/Produto.cpp src/Inventario.cpp src/Menu.cpp
OBJ = $(SRC:.cpp=.o)

EXEC = inventario

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(EXEC)

clean:
	rm -f $(OBJ) $(EXEC)
