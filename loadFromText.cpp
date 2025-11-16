#include "bst_file_handler.h"
#include <fstream>
#include <iostream>
#include <sstream>

void BSTFileHandler::loadFromText(const std::string& filename, bool append) {
    if (!append) treeRef.clearTree();

    std::ifstream in(filename);
    if (!in) {
        std::cerr << "Nie mozna otworzyc pliku tekstowego: " << filename << "\n";
        return;
    }

    std::string line;
    while (std::getline(in, line)) {
        std::stringstream ss(line);
        int num;
        while (ss >> num) {
            treeRef.insertKey(num);
        }
    }

    in.close();
    std::cout << "Wczytano drzewo z pliku tekstowego: " << filename << "\n";
}