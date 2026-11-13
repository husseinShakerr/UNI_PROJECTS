//
// Created by zhass on 3/27/2025.
//

#include "algorithms.h"
#include <iostream>
#include <queue>


matrix_t convert_to_matrix(const adjacency_list_t &adj_list) {
    const auto& meta = adj_list.first;
    const auto& edges = adj_list.second;
    size_t nodes = meta.size();
    //std::cout<< adj_list.first.size() << std::endl;
    //std::cout<< adj_list.second.size() << std::endl;

    matrix_t matrix(nodes, std::vector<weight_t>(nodes, std::numeric_limits<weight_t>::infinity()));

    //Tilldela 0 för de avstånd som går till sig själv.
    for (size_t i = 0 ; i < nodes; i++) {
        matrix[i][i] = 0;
    }
    //Tilldela avstånd för alla vägar.
    for (const auto& edge : edges) {
        matrix[edge.n1][edge.n2] = edge.w;
        //Dubbelriktar vägarna. Denna rad löste så att man kan ta sig från och till alla noder i grafen.
        matrix[edge.n2][edge.n1] = edge.w;
    }
    return matrix;
}

bool dfs(const matrix_t &matrix) {
    if (matrix.empty())
        return false;
    std::vector<bool> visited(matrix.size(), false);
    dfs_recursive(0, matrix, visited);
    //std::cout<<visited.size()<<std::endl;
    return std::all_of(visited.begin(), visited.end(), [](bool v) { return v; });
}
void dfs_recursive(size_t node, const matrix_t &matrix, std::vector<bool> &visited_list) {
    visited_list[node] = true;

    for (size_t neighbor = 0; neighbor < matrix.size(); neighbor++) {
        if (matrix[node][neighbor] != std::numeric_limits<weight_t>::infinity() && !visited_list[neighbor]) {
            dfs_recursive(neighbor, matrix, visited_list);
        }
    }
}

bool bfs(const matrix_t &matrix) {
    if (matrix.empty()){std::cout<<"Matrix is empty"; return false;}
    std::vector<bool> visited(matrix.size(), false);
    std::queue<size_t> q;
    size_t start_node = 0, node = 0;
    visited[start_node] = true;
    q.push(start_node);
    while (!q.empty()) {
        node = q.front();
        q.pop();
        for (size_t neighbor = 0; neighbor < matrix.size(); neighbor++) {
            if (matrix[node][neighbor] != 0 && matrix[node][neighbor] != std::numeric_limits<weight_t>::infinity() && !visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return std::all_of(visited.begin(), visited.end(), [](bool v) { return v; });
}

paths dijkstra(const matrix_t &matrix, node_id_t start) {
    paths path(matrix.size());
    std::vector<weight_t> distance(matrix.size(), std::numeric_limits<weight_t>::infinity());
    std::priority_queue<std::pair<weight_t, node_id_t>, std::vector<std::pair<weight_t, node_id_t>>, std::greater<>> q;

    path[start] = {start, 0};
    distance[start] = 0;
    std::pair<weight_t, node_id_t> current_node = {0, start};
    q.push(current_node);

    while (!q.empty()) {
        current_node = q.top();
        q.pop();
       for (node_id_t next_node = 0; next_node < matrix.size(); next_node++) {
            if (matrix[current_node.second][next_node] != std::numeric_limits<weight_t>::infinity()) {
                if (matrix[current_node.second][next_node] + distance[current_node.second] < distance[next_node] ) {
                    distance[next_node] = distance[current_node.second] + matrix[current_node.second][next_node];
                    path[next_node].first = current_node.second;
                    path[next_node].second = distance[next_node];
                    q.push({matrix[current_node.second][next_node], next_node});
                }
            }
        }
    }
    return path;
}


void print_all_paths(const paths &path, node_id_t start) {
    std::cout << "Shortest paths from start " << start << ":\n";

    for (node_id_t destination = 0; destination < path.size(); ++destination) {
        if (destination == start) continue;

        std::vector<node_id_t> full_path;
        node_id_t pre_node = destination;

        while (pre_node != start) {
            full_path.push_back(pre_node);
            pre_node = path[pre_node].first;
        }

        if (pre_node == start) {
            full_path.push_back(start);
            std::reverse(full_path.begin(), full_path.end());
            std::cout << "To " << destination << " (Distance: " << path[destination].second << "): ";
            for (size_t i = 0; i < full_path.size(); ++i) {
                std::cout << full_path[i];
                if (i < full_path.size() - 1) std::cout << " -> ";
            }
            std::cout << "\n";
        }
    }
}
