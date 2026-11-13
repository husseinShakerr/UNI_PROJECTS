//
// Created by zhass on 5/19/2025.
//

#include "bst.h"

bst::bst(std::vector<int>& list) : primesList(list), root(nullptr) {
    root = assignBst(0, list.size()-1);
}

bst::node* bst::assignBst(int start, int end) {
    if (start > end) {
        return nullptr;
    }

    int mid = start + (end - start) / 2;

    node* newNode = new node(primesList[mid]);
    newNode->left_child = assignBst(start, mid - 1);
    newNode->right_child = assignBst(mid + 1, end);
    return newNode;
}
bool bst::search(const node* curr, int key_value) const {
    while (curr != nullptr) {
        if (curr->key == key_value)
            return true;
        if (curr->key > key_value)
            curr = curr->left_child;
        else
            curr = curr->right_child;
    }
    return false;
}/*
void bst::deleteBst(node* curr) {
    if (curr == nullptr) {
        return;
    }
    deleteBst(curr->left_child);
    deleteBst(curr->right_child);
    delete curr;
}*/
bool bst::searchKey(int key) const {
    return search(root, key);
}
