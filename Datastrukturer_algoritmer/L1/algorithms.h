//
// Created by zhass on 3/27/2025.
//

#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include "reader.h"
#include <limits>
#include <algorithm>

using matrix_t = std::vector<std::vector<weight_t>>;
using paths = std::vector<std::pair<node_id_t, weight_t>>;

bool dfs(const matrix_t &matrix);
void dfs_recursive(size_t node, const matrix_t &matrix, std::vector<bool> &visited);
bool bfs(const matrix_t &matrix);
paths dijkstra(const matrix_t &matrix, node_id_t start);
matrix_t convert_to_matrix(const adjacency_list_t &adj_list);
void print_all_paths(const paths &path, node_id_t start);


#endif //ALGORITHMS_H
