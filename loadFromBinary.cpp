#include "bst_file_handler.h"
#include <fstream>
#include <iostream>
#include <sstream>

void BSTFileHandler::loadFromBinary(const std::string& filename) {
    std::ifstream in(filename, std::ios::binary);
    if (!in) {
        std::cerr << "Nie mozna otworzyc pliku do odczytu: " << filename << "\n";
        return;
    }
    loadNode(in);
    in.close();
    std::cout << "Wczytano drzewo z pliku binarnego: " << filename << "\n";
}