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

void BST::printTreeGraphic(int indentStep) const {
    if (!root) { cout << "(drzewo puste)\n"; return; }
    printTreeGraphic2(root, 0, indentStep);
}