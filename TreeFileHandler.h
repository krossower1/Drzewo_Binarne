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

class TreeFileHandler {
public:
    static bool saveBinary(const BST& tree, const string& filename) {
        return tree.serializeToBinary(filename);
    }

    static bool saveTextTree(const BST& tree, const string& filename) {
        return tree.saveTreeAsText(filename);
    }
};