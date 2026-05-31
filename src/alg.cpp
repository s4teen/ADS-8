// Copyright 2021 NNTU-CS
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "bst.h"

void makeTree(BST<std::string>& tree, const char* fileName) {
  std::ifstream file(fileName);

  if (!file.is_open()) {
    std::cout << "File error!" << std::endl;
    return;
  }

  std::string word;
  char ch;

  while (file.get(ch)) {
    if (ch >= 'A' && ch <= 'Z') {
      word += static_cast<char>(ch - 'A' + 'a');
    } else if (ch >= 'a' && ch <= 'z') {
      word += ch;
    } else {
      if (!word.empty()) {
        tree.insert(word);
        word.clear();
      }
    }
  }

  if (!word.empty()) {
    tree.insert(word);
  }
}

void printFreq(BST<std::string>& tree) {
  std::vector<std::pair<std::string, int>> words = tree.toVector();

  std::sort(words.begin(), words.end(),
            [](const std::pair<std::string, int>& a,
               const std::pair<std::string, int>& b) {
              if (a.second != b.second) {
                return a.second > b.second;
              }
              return a.first < b.first;
            });

  int mkdirResult = std::system("mkdir -p result");

  if (mkdirResult != 0) {
    std::cout << "Directory error!" << std::endl;
    return;
  }

  std::ofstream out("result/freq.txt");

  if (!out.is_open()) {
    std::cout << "File error!" << std::endl;
    return;
  }

  for (const auto& item : words) {
    std::cout << item.first << " " << item.second << std::endl;
    out << item.first << " " << item.second << std::endl;
  }
}
