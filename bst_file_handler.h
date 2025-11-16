#ifndef BST_FILE_HANDLER_H
#define BST_FILE_HANDLER_H

#include <string>
#include <vector>
#include "bst.h"

class BSTFileHandler {
public:
    BSTFileHandler(BST& tree) : treeRef(tree) {};
    void loadFromBinary(const std::string& filename);
    void loadFromText(const std::string& filename, bool append = true);
    void saveToText(const std::string& filename, int method) const;
    void saveToBinary(const std::string& filename, int mode) const;
private:
    BST& treeRef;
    void saveNode(std::ofstream& out, BST::Node* node) const;
    void loadNode(std::ifstream& in);
};

#endif
