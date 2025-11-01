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

vector<int> BST::getPreorder() const {
    vector<int> out;
    preorder(root, out);
    return out;
}