#ifndef CS2_TREE_LAB_BTREE_HPP
#define CS2_TREE_LAB_BTREE_HPP

#include <iostream>

template <typename T>
class btree {
 public:
  btree() : left(0), right(0), empty(true) {}
  btree(const T& val) : left(0), right(0), empty(false), data(val) {}
  btree(const btree<T>&);
  ~btree();

  void swap(btree<T>&);
  btree<T>& operator=(btree<T> rhs) {
    swap(rhs);
    return *this;
  }

  bool isEmpty() const { return empty; }
  void insert(const T&);

  bool find(const T&) const;
  void inorder(std::ostream&) const;
  void preorder(std::ostream&) const;
  void postorder(std::ostream&) const;
  int findDepth(const T&) const;

 private:
  btree<T>* left;
  btree<T>* right;
  bool empty;
  T data;

  int findDepthHelper(const T&, int) const;
};

template <typename T>
btree<T>::btree(const btree<T>& actual) : btree<T>() {
  data = actual.data;
  empty = actual.empty;
  if (actual.left) {
    left = new btree<T>(*(actual.left));
  }
  if (actual.right) {
    right = new btree<T>(*(actual.right));
  }
}

template <typename T>
btree<T>::~btree() {
  if (left) delete left;
  if (right) delete right;
}

template <typename T>
void btree<T>::swap(btree<T>& rhs) {
  std::swap(data, rhs.data);
  std::swap(empty, rhs.empty);
  std::swap(left, rhs.left);
  std::swap(right, rhs.right);
}

template <typename T>
void btree<T>::insert(const T& item) {
  if (empty) {
    data = item;
    empty = false;
  } else if (item < data) {
    if (!left) {
      left = new btree<T>(item);
    } else {
      left->insert(item);
    }
  } else if (item > data) {
    if (!right) {
      right = new btree<T>(item);
    } else {
      right->insert(item);
    }
  } else {
    return;  // No duplicates
  }
}

template <typename T>
bool btree<T>::find(const T& key) const {
  if (empty) return false;
  if (key == data) return true;
  if (key < data) return left ? left->find(key) : false;
  return right ? right->find(key) : false;
}

template <typename T>
void btree<T>::inorder(std::ostream& out) const {
  if (empty) return;
  if (left) left->inorder(out);
  out << data << " ";
  if (right) right->inorder(out);
}

template <typename T>
void btree<T>::preorder(std::ostream& out) const {
  if (empty) return;
  out << data << " ";
  if (left) left->preorder(out);
  if (right) right->preorder(out);
}

template <typename T>
void btree<T>::postorder(std::ostream& out) const {
  if (empty) return;
  if (left) left->postorder(out);
  if (right) right->postorder(out);
  out << data << " ";
}

template <typename T>
int btree<T>::findDepth(const T& key) const {
  if (empty) return -1;
  return findDepthHelper(key, 0);
}

template <typename T>
int btree<T>::findDepthHelper(const T& key, int depth) const {
  if (key == data) return depth;
  if (key < data) {
    return left ? left->findDepthHelper(key, depth + 1) : -1;
  } else {
    return right ? right->findDepthHelper(key, depth + 1) : -1;
  }
}

#endif
