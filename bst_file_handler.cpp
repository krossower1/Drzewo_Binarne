#include "bst_file_handler.h"
#include <fstream>
#include <iostream>
#include <sstream>

// Konstruktor
BSTFileHandler::BSTFileHandler(BST& tree) : treeRef(tree) {}

// Rekursywny zapis w kolejności preorder
void BSTFileHandler::saveNode(std::ofstream& out, BST::Node* node) const {
    if (!node) return;
    out.write(reinterpret_cast<const char*>(&node->key), sizeof(node->key));
    saveNode(out, node->left);
    saveNode(out, node->right);
}

// Zapis do pliku binarnego
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

// Odczyt z pliku binarnego i wstawienie do drzewa
void BSTFileHandler::loadNode(std::ifstream& in) {
    int key;
    while (in.read(reinterpret_cast<char*>(&key), sizeof(key))) {
        treeRef.insertKey(key);  // dodaje elementy do istniejącego drzewa
    }
}

// Wczytanie drzewa z pliku binarnego
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

// Wczytanie drzewa z pliku tekstowego
void BSTFileHandler::loadFromText(const std::string& filename, bool append) {
    if (!append) treeRef.clearTree();  // czyścimy drzewo jeśli nie appendujemy

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

// Zapis drzewa do pliku tekstowego w wybranej kolejności
void BSTFileHandler::saveToText(const std::string& filename, int method) const {
    std::ofstream out(filename);
    if (!out) {
        std::cerr << "Nie mozna otworzyc pliku tekstowego do zapisu: " << filename << "\n";
        return;
    }

    std::vector<int> elements;

    // ----------
    // Wybór metody zapisu
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
