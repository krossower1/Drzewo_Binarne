#ifndef BST_FILE_HANDLER_H
#define BST_FILE_HANDLER_H

#include <string>
#include <vector>
#include "bst.h"

class BSTFileHandler {
public:
    BSTFileHandler(BST& tree); // Konstruktor przyjmujący referencję do drzewa

    // Zapis drzewa do pliku binarnego
    void saveToBinary(const std::string& filename) const;

    // Odczyt drzewa z pliku binarnego (czyści drzewo przed wczytaniem)
    void loadFromBinary(const std::string& filename);

    // Wczytanie drzewa z pliku tekstowego (opcjonalnie do istniejącego drzewa)
    void loadFromText(const std::string& filename, bool append = true);

    // zapis do pliku tekstowego
    void saveToText(const std::string& filename, int method) const;

    //zapis do pliku binarnego
    void saveToBinary(const std::string& filename, int mode) const;
private:
    BST& treeRef;



    // Pomocnicze funkcje do rekursywnego zapisu/odczytu
    void saveNode(std::ofstream& out, BST::Node* node) const;
    void loadNode(std::ifstream& in);
};

#endif
