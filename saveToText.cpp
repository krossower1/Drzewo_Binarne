#include "bst_file_handler.h"
#include <fstream>
#include <iostream>
#include <sstream>

void BSTFileHandler::saveToText(const std::string& filename, int method) const {
    std::ofstream out(filename);
    if (!out) {
        std::cerr << "Nie mozna otworzyc pliku tekstowego do zapisu: " << filename << "\n";
        return;
    }

    std::vector<int> elements;

    if (method == 1) elements = treeRef.getPreorder();
    else if (method == 2) elements = treeRef.getInorder();
    else if (method == 3) elements = treeRef.getPostorder();
    else {
        std::cerr << "Niepoprawna metoda, zapisano inorder.\n";
        elements = treeRef.getInorder();
    }

    for (size_t i = 0; i < elements.size(); ++i) {
        if (i) out << " ";
        out << elements[i];
    }
    out << "\n";
    out.close();
}
