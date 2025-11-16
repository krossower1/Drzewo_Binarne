#include "bst_file_handler.h"
#include <fstream>
#include <iostream>
#include <sstream>

void BSTFileHandler::loadNode(std::ifstream& in) {
    int key;
    while (in.read(reinterpret_cast<char*>(&key), sizeof(key))) {
        treeRef.insertKey(key);
    }
}