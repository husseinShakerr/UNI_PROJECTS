/**
 * @author: Hussein Alshaikhshaker
 * Creating date: 2024-05-08
 * Last day edited: 2024-05-31
 * Course: DT019G/DT026G
 * File: Functions, constructors, destructor, maze generator, maze solver(hann inte skriva klart).
 * Grade: E
 */
#include "labyrinth.h"

//constructor
labyrinth::labyrinth() : width(5), height(5), start(nullptr){
    //Sätter in noder in matrisen.
    for(int y = 0 ; y < height ; y++){
        std::vector<node*> vec;
        for(int x = 0 ; x < width ; x++) {
            node* newNode = new node();
            vec.push_back(newNode);
        }
        maze.push_back(vec);
    }
    //Dirigera pekare.
    for (int y  = 0 ; y < height ; y++) {
        for(int x = 0 ; x < width ; x++){
            if(y-1 >= 0){
                maze[y][x]->n_up = maze[y-1][x];
            }
            if(x-1 >= 0){
                maze[y][x]->n_left = maze[y][x-1];
            }
            if(y+1 < height){
                maze[y][x]->n_down = maze[y+1][x];
            }
            if(x+1 < width){
                maze[y][x]->n_right = maze[y][x+1];
            }
        }
    }
    setStartNode();
}

//destructor
labyrinth::~labyrinth(){
    for(size_t y = 0 ; y < height ; y++){
        for(size_t x = 0 ; x < width ; x++){
            delete maze[y][x];
        }
    }
}
//generator
void labyrinth::genLabyrinth() {
    std::stack<node*> backTrack;
    start->visited = true;
    backTrack.push(start);
    std::vector<node*> possibleNeighbours;
    while(!backTrack.empty()){
        node* current = backTrack.top();
        current->visited = true;
        backTrack.pop();
        checkNeighbours(current, possibleNeighbours);
        if(!possibleNeighbours.empty()){
            backTrack.push(current);
            int RandNeighbour = rand() % (int)possibleNeighbours.size();
            node* nextNode = possibleNeighbours[RandNeighbour];
            //Om vägen gick nedåt.
            if(nextNode == current->n_down){
                //current->downWalw1l = false;
                current->n_down->upWall = false;
            }
            //Om vägen gick uppåt
            if(nextNode == current->n_up){
                current->upWall = false;
                //current->n_up->downWall = false;
            }
            //Om vägen gick vänster
            else if(nextNode == current->n_left){
                current->leftWall = false;
                //current->n_left->rightWall = false;
            }
            //Om vägen gick höger
            else if(nextNode == current->n_right){
                //current->rightWall = false;
                current->n_right->leftWall = false;
            }
            backTrack.push(nextNode);
        }
        possibleNeighbours.clear();
    }
}


void labyrinth::print() const {
    for(int y = 0 ; y < height ; y++){
        for (int i = 0; i < 2 ; ++i) {
            for(int x = 0 ; x < width ; x++){
                if(i == 0){
                    if(maze[y][x]) {
                        if(y == 0 && x == 0)
                            std::cout<< WALL <<"S";
                        else if (maze[y][x]->upWall)
                                std::cout<<WALL<<WALL;
                        else
                            std::cout<< WALL <<" ";
                    }
                }
                else {
                    if(maze[y][x]) {
                        if (maze[y][x]->leftWall)
                            std::cout<< WALL <<" ";
                        else
                            std::cout << "  ";
                    }
                }
            }
            std::cout << WALL;
            std::cout<<std::endl;
        }
    }
    for(int i = 0 ; i < 9 ; i++){
        std::cout<<WALL;
    }
    std::cout<<"E"<<WALL<<std::endl;
}
void labyrinth::setStartNode(){
    //Fasta startpunkt.
    start = maze[0][0];
}

void labyrinth::checkNeighbours(node* current, std::vector<node*> &possibleNeighbours){
    //Om vänster granne är obesökt.
    if(current->n_left != nullptr && !current->n_left->visited){
        possibleNeighbours.push_back(current->n_left);
    }
    //Om höger granne är obesökt
    if(current->n_right != nullptr && !current->n_right->visited){
        possibleNeighbours.push_back(current->n_right);
    }
    //Om övre granne är obesökt
    if(current->n_up != nullptr &&  !current->n_up->visited){
        possibleNeighbours.push_back(current->n_up);
    }
    //Om grannen nedanför är obesökt
    if(current->n_down != nullptr && !current->n_down->visited){
        possibleNeighbours.push_back(current->n_down);
    }
}
void clearConsole(){
    std::cout<< "\033[2J\033[H";
}