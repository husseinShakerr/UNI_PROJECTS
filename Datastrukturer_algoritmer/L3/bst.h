//
// Created by zhass on 5/19/2025.
//

#ifndef BST_H
#define BST_H
#include <vector>





class bst {
    struct node {
        int key;

        node *left_child = nullptr;
        node *right_child = nullptr;

        explicit node(int k) : key(k), left_child(nullptr), right_child(nullptr) {
        }
    };
    node *root = nullptr;
    const std::vector<int>& primesList;
public:
    explicit bst(std::vector<int> &list);
    /*
    ~bst() {
        deleteBst(root);
    }*/
    node *assignBst(int start, int end);

    bool search(const node* curr, int key_value) const;


    //void deleteBst(node* curr);

    bool searchKey(int key_value) const;

};


#endif
