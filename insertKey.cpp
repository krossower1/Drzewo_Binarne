#include <iostream>
#include <memory>
#include <stack>
#include <iterator>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include "bst.h"

/**
* @brief Inserts a key into a new node
*
**/


void BST::insertKey(int key) {
    root = insert(root, key);
}