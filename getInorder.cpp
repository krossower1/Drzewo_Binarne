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

vector<int> BST::getInorder() const {
    vector<int> out;
    inorder(root, out);
    return out;
}