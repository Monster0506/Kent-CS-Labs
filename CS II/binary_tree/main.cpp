#include <iostream>

#include "btree.hpp"

int main() {
  btree<int> tree;

  int elements[] = {8, 4, 55, 1, 7, 16, 87, 2, 9, 64, 99};
  for (int val : elements) {
    tree.insert(val);
  }

  std::cout << "Inorder Traversal: ";
  tree.inorder(std::cout);
  std::cout << std::endl;

  std::cout << "Preorder Traversal: ";
  tree.preorder(std::cout);
  std::cout << std::endl;

  std::cout << "Postorder Traversal: ";
  tree.postorder(std::cout);
  std::cout << std::endl;

  int find_elements[] = {16, 5, 99};
  for (int val : find_elements) {
    std::cout << "Find " << val << ": "
              << (tree.find(val) ? "Found" : "Not Found") << std::endl;
  }
  std::cout << "Depth of node 8: " << tree.findDepth(8) << std::endl;
  std::cout << "Depth of node 99: " << tree.findDepth(99) << std::endl;
  std::cout << "Depth of node 5: " << tree.findDepth(5) << std::endl;

  return 0;
}
