#include <iostream>
#include <functional>
#include "node.h"
#include <vector>

using namespace std;



int cnt; // for solving problem..
template <typename T>
class BinarySearchTree {

 private:
  Node<T>* root;
  
 public:
  BinarySearchTree<T>();
  ~BinarySearchTree<T>();

  bool search(T value, function<int(T&, T&)>& comp);
  bool remove(T value, function<int(T&, T&)>& comp);
  bool internal_remove(Node<T>*& current, T value, function<int(T&, T&)>& comp);
  bool insert(T value, function<int(T&, T&)>& f);
  bool internal_insert(Node<T>*& current, T value, function<int(T&, T&)>& f);
  Node<T>*& find_left_most_child(Node<T>*& current);
  void replace_node(Node<T>*& replaced, Node<T>*& newone);
  void traverse_pre_order(function<void(T&)>& f);
  void internal_traverse_pre_order(Node<T>* current, function<void(T&)>& f);
  void traverse_in_order(function<void(T&)>& f);
  void internal_traverse_in_order(Node<T>* current, function<void(T&)>& f);
  void traverse_post_order(function<void(T&)>& f);
  void internal_traverse_post_order(Node<T>* current, function<void(T&)>& f);
  bool is_empty(void);
};

template <typename T>
BinarySearchTree<T>::BinarySearchTree() {
  root = nullptr;
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {
  delete root;
}

template <typename T>
bool BinarySearchTree<T>::search(T value, function<int(T&, T&)>& comp)
{
  Node<T>* current = root;

  while (current) {
    if (comp(current->data, value) == 0) {
      return true;
    } else if (comp(value, current->data) == 1) {
      current = current->right;
    } else {
      current = current->left;
    }
  }

  return false;
}

template <typename T>
Node<T>*& BinarySearchTree<T>::find_left_most_child(Node<T>*& current) {

  while(current->left) {
    current = current->left;
  }
  
  return current;
}

template <typename T>
void BinarySearchTree<T>::replace_node(Node<T>*& replaced, Node<T>*& newone) {

  if (replaced == nullptr || newone == nullptr) {
    return;
  }

  if (replaced->left != nullptr && replaced->right != nullptr) {
      newone->left = replaced->left;
    if(replaced->right != newone)
      newone->right = replaced->right;
  }
  
  Node<T>* temp = replaced;
  replaced = newone;
  delete temp;
  
  return;
}

template <typename T>
bool BinarySearchTree<T>::remove(T value, function<int(T&, T&)>& comp)
{
  return internal_remove(root, value, comp);
}

template <typename T>
bool BinarySearchTree<T>::internal_remove(Node<T>*& current, T value,
                                          function<int(T&, T&)>& comp) {

  if (comp(current->data, value) == 0) {
    if (current->left == nullptr && current->right == nullptr) {
      // if leaf node,
      delete current;
      current = nullptr;
    } else if (current->left != nullptr && current->right != nullptr) {
      // if has two children
      replace_node(current, find_left_most_child(current->right));
    } else if (current->left != nullptr && current->right == nullptr) {
      // only has a left child;
      replace_node(current, current->left);
    } else if (current->left == nullptr && current->right != nullptr) {
      // only has a right child
      replace_node(current, current->right);
    }

    return true;
    
  } else if (comp(value, current->data) == 1) {
    // if the variable value is greater than current node's data
    return internal_remove(current->right, value, comp);
  } else {
    // if the variable value is less than current node's data
    return internal_remove(current->left, value, comp);
  }

  return false;
}

template <typename T>
bool BinarySearchTree<T>::insert(T value, function<int(T&, T&)>& comp) {
	
  return internal_insert(root, value, comp);
}

template <typename T>
bool BinarySearchTree<T>::internal_insert(Node<T>*& current, T value,
                                          function<int(T&, T&)>& comp) 
{
	
  // recursive
  if (current == nullptr) {
    current = new Node<T>(value);
    cout << cnt << endl;
    return true;
  } else if (comp(current->data, value) == 1) {
    // if the variable current is greater than value,
    cnt++; 
    return internal_insert(current->left, value, comp);
  } else if (comp(current->data, value) == -1) {
  	cnt++; 
    // if the variable current is less than value,
    return internal_insert(current->right, value, comp);
  } 

  // duplicated
  return false;
}

template <typename T>
void BinarySearchTree<T>::traverse_pre_order(function<void(T&)>& printer)
{
  // depth-first traversal
  internal_traverse_pre_order(root, printer);
}

template <typename T>
void BinarySearchTree<T>::internal_traverse_pre_order(Node<T>* current,
                                                      function<void(T&)>& f) {
  if (current == nullptr) {
    return;
  }

  f(current->data);
  internal_traverse_pre_order(current->left, f);
  internal_traverse_pre_order(current->right, f);
}

template <typename T>
void BinarySearchTree<T>::traverse_in_order(function<void(T&)>& printer)
{
  // depth-first traversal
  internal_traverse_in_order(root, printer);
}

template <typename T>
void BinarySearchTree<T>::internal_traverse_in_order(Node<T>* current,
                                                      function<void(T&)>& f) {
  if (current == nullptr) {
    return;
  }

  internal_traverse_in_order(current->left, f);
  f(current->data);
  internal_traverse_in_order(current->right, f);
}
template <typename T>
void BinarySearchTree<T>::traverse_post_order(function<void(T&)>& printer)
{
  // depth-first traversal
  internal_traverse_post_order(root, printer);
}

template <typename T>
void BinarySearchTree<T>::internal_traverse_post_order(Node<T>* current,
                                                      function<void(T&)>& f) {
  if (current == nullptr) {
    return;
  }

  internal_traverse_post_order(current->left, f);
  internal_traverse_post_order(current->right, f);
  f(current->data);

}


template <typename T>
bool BinarySearchTree<T>::is_empty(void)
{
  if (root == nullptr)
    return false;
  
  return true;
}

std::vector<int> v;
int num_nodes;
void input() {
	int temp;
	cin >> num_nodes;
	for(int i=0; i<num_nodes; i++) {
		cin >> temp;
		v.push_back(temp);
	}
}

int main(int argc, char *argv[])
{

  BinarySearchTree<int> bst;
  input();
  function<int(int&, int&)> comparator = [](int& lhs, int& rhs)->int{
    if(lhs > rhs) {
      return 1;
    } else if (lhs < rhs) {
      return -1;
    } else {
      return 0;
    }
  };

  function<void(int& value)> printer = [](int& value)->void{
    std::cout << value << std::endl;
  };

  for(auto iter : v) {
  	bst.insert(iter, comparator);
  }
  // bst.insert(3, comparator);
  // bst.insert(2, comparator);
  // bst.insert(5, comparator);
  // bst.insert(4, comparator);
  // bst.insert(6, comparator);

  // cout << "traversing" << endl;
  // bst.traverse_in_order(printer);
  // cout << "SDsd" << endl;
  // bst.traverse_post_order(printer);
  // cout << "SDsd" << endl;
  // bst.traverse_in_order(printer);  
  // auto x = []() {cout << "print"<<endl;};
  // x();
  // int b = 3;
  // auto n = [&, b] (int c) {return (double)b+(double)c + 0.5;};
  // cout << n(3) << endl;

  // for_each(v.begin(), v.end(), [](int& iter) {cout << iter << endl;});

  return 0;
}
