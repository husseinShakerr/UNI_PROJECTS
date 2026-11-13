// Created by zhass on 2024-10-14.


#ifndef PQ_H
#define PQ_H
#include <functional>
#include <iostream>
#include <algorithm>
#include <vector>


template<typename T, typename COMP = std::less<>>
class pq {
    std::vector<T> data;
    COMP comparator;
public:
    pq() = default;
    explicit pq(COMP comp) : comparator(comp) {}
    template<typename IT>
    pq(IT firts, IT last, COMP comp = COMP()) : comparator(comp) {
        data.insert(data.end(), firts, last);
        std::make_heap(data.begin(), data.end(), comp);
    }
    void push(T element) {
        data.push_back(element);
        std::push_heap(data.begin(), data.end(), comparator);
    }
    const T& top() const {
        return data.front();
    }
    T pop() {
        std::pop_heap(data.begin(), data.end(), comparator);
        T result = data.back();
        data.pop_back();
        return result;
    }
    bool empty() const {
        return data.empty();
    }
    size_t size() const {
        return data.size();
    }
    auto begin() const {
        return data.begin();
    }
    auto end() const {
        return data.end();
    }
    void print () const {
        for(const auto& element : data) {
            std::cout << element<<"\n";
        }

    }
};



#endif //PQ_H
