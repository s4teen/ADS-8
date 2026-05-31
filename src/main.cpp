// Copyright 2021 NNTU-CS
#include <string>

#include "bst.h"

void makeTree(BST<std::string>& tree, const char* fileName);
void printFreq(BST<std::string>& tree);

int main() {
    BST<std::string> tree;

    makeTree(tree, "war_peace.txt");
    printFreq(tree);

    return 0;
}
