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
* @brief Print a vector of the path to an element
*
**/

void BST::printVectorTraversal(const vector<int>& v) {
    if (v.empty()) { cout << "(brak)\n"; return; }
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) cout << " ";
        cout << v[i];
    }
    cout << "\n";
}