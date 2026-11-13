CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -pedantic -std=c++17 -g


SRC = main.cpp functions.cpp linked_list.cpp
OBJ = $(SRC:.cc=.o)
EXEC = linked_list

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $(OBJ) $(LBLIBS)

clean:
	rm -rf $(OBJ) $(EXEC)