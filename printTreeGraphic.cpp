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
* @brief Call to print a graphic depiction of the tree, display error message
*
**/

void BST::printTreeGraphic(int indentStep) const {
    if (!root) { cout << "(drzewo puste)\n"; return; }
    printTreeGraphic2(root, 0, indentStep);
}