#include "bst_file_handler.h"
#include <fstream>
#include <iostream>
#include <sstream>

void BSTFileHandler::saveNode(std::ofstream& out, BST::Node* node) const {
    if (!node) return;
    out.write(reinterpret_cast<const char*>(&node->key), sizeof(node->key));
    saveNode(out, node->left);
    saveNode(out, node->right);
}