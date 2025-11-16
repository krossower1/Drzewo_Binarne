#include "bst_file_handler.h"
#include <fstream>
#include <iostream>
#include <sstream>

void BSTFileHandler::saveToBinary(const std::string& filename, int mode) const {
    std::ofstream out(filename, std::ios::binary);
    if (!out) {
        std::cerr << "Nie mozna otworzyc pliku do zapisu: " << filename << "\n";
        return;
    }

    std::vector<int> data;

    if (mode == 1)
        data = treeRef.getPreorder();
    else if (mode == 2)
        data = treeRef.getInorder();
    else if (mode == 3)
        data = treeRef.getPostorder();

    for (int v : data)
        out.write(reinterpret_cast<const char*>(&v), sizeof(v));

    out.close();
    std::cout << "Zapisano w trybie: "
        << (mode == 1 ? "preorder" :
            mode == 2 ? "inorder" : "postorder")
        << "\n";
}