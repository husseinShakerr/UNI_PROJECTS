#include "algorithms.h"
#include "reader.h"
#include <iostream>

int main() {
    auto adj_list = parse_file("graph.txt");
    auto matrix = convert_to_matrix(adj_list);
    std::cout<<"----- DFS -----\n";
    if (dfs(matrix)) {
        std::cout<<"Connected!"<<std::endl;
    }else
        std::cout<<"Not connected"<<std::endl;

    std::cout<<"----- BFS -----\n";
    if (bfs(matrix)) {
        std::cout<<"Connected!"<<std::endl;
    }
    else {
        std::cout<<"Not connected"<<std::endl;
    }


    node_id_t start, end;
    std::cout<<"Choose starting point: "<<std::endl;
    std::cin>>start;
    auto p = dijkstra(matrix, start);
    print_all_paths(p, start);


    return 0;
}
