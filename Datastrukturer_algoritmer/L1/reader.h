#ifndef READER_H
#define READER_H
#include <istream>
#include <vector>
#include <map>


using node_id_t = int;
using weight_t = double;
using meta_t = std::map<node_id_t, std::string>;

struct edge{
    node_id_t n1;
    node_id_t n2;
    weight_t w;
    std::string desc;
};

using edge_list_t = std::vector<edge>;

using adjacency_list_t = std::pair<meta_t, edge_list_t>;

adjacency_list_t parse_file(std::string filename);

#endif //READER_H
