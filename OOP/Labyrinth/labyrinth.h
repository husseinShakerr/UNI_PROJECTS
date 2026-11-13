/**
 * @author: Hussein Alshaikhshaker
 * Creating date: 2024-05-08
 * Last day edited: 2024-05-31
 * Course: DT019G/DT026G
 * File: Headerfil, innehåller labyrint klass och node struct.
 * Grade: E
 */

#ifndef LABYRINTH_H
#define LABYRINTH_H
#include <iostream>
#include <vector>
#include <stack>
//#define WALL "\u2588"
#define WALL "#"
void clearConsole();

class labyrinth {
    struct node{
        node* n_right {nullptr};
        node* n_left {nullptr};
        node* n_up {nullptr};
        node* n_down {nullptr};

        bool leftWall{true}, upWall{true};
        bool visited = false;
    };
    node* start;
    std::vector<std::vector<node*>> maze;
    int width, height;
    void checkNeighbours(node*, std::vector<node*>&);

public:
    labyrinth();
    ~labyrinth();
    void genLabyrinth();
    void print() const;
    void setStartNode();
};

#endif
