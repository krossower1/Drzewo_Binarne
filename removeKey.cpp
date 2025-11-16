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

using namespace std;

/**
* @brief Remove a node having a chosen key
*
**/

void BST::removeKey(int key) {
    root = remove(root, key);
}