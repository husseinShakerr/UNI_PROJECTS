#ifndef GENERATOR_H
#define GENERATOR_H
#include <vector>


class generator {
public:
    static std::vector<int> randomNumbers(size_t);
    static std::vector<int> ascending(size_t);
    static std::vector<int> descending(size_t);
    static std::vector<int> constants(size_t);
};



#endif //GENERATOR_H
