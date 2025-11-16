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
* @brief Clear the tree
*
**/

void BST::clearTree() {
    clear(root);
    root = nullptr;
}