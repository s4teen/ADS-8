// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#include <utility>
#include <vector>

template <typename T>
class BST {
 private:
  struct Node {
    T key;
    int count;
    Node* left;
    Node* right;

    explicit Node(const T& value)
        : key(value), count(1), left(nullptr), right(nullptr) {}
  };

  Node* root;

  void clear(Node* node) {
    if (node == nullptr) {
      return;
    }

    clear(node->left);
    clear(node->right);
    delete node;
  }

  void insert(Node*& node, const T& value) {
    if (node == nullptr) {
      node = new Node(value);
      return;
    }

    if (value < node->key) {
      insert(node->left, value);
    } else if (value > node->key) {
      insert(node->right, value);
    } else {
      node->count++;
    }
  }

  bool search(Node* node, const T& value) const {
    if (node == nullptr) {
      return false;
    }

    if (value < node->key) {
      return search(node->left, value);
    } else if (value > node->key) {
      return search(node->right, value);
    } else {
      return true;
    }
  }

  int depth(Node* node) const {
    if (node == nullptr) {
      return 0;
    }

    int leftDepth = depth(node->left);
    int rightDepth = depth(node->right);

    if (leftDepth > rightDepth) {
      return leftDepth + 1;
    } else {
      return rightDepth + 1;
    }
  }

  void toVector(Node* node, std::vector<std::pair<T, int> >* result) const {
    if (node == nullptr) {
      return;
    }

    toVector(node->left, result);
    result->push_back(std::make_pair(node->key, node->count));
    toVector(node->right, result);
  }

 public:
  BST() : root(nullptr) {}

  ~BST() {
    clear(root);
  }

  BST(const BST&) = delete;
  BST& operator=(const BST&) = delete;

  void insert(const T& value) {
    insert(root, value);
  }

  bool search(const T& value) const {
    return search(root, value);
  }

  int depth() const {
    return depth(root);
  }

  std::vector<std::pair<T, int> > toVector() const {
    std::vector<std::pair<T, int> > result;
    toVector(root, &result);
    return result;
  }
};


#endif  // INCLUDE_BST_H_
