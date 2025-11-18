#ifndef BST_FILE_HANDLER_H
#define BST_FILE_HANDLER_H

#include <string>
#include <vector>
#include "bst.h"

/**
 * @brief Klasa obsługująca zapis i odczyt drzewa BST do/z plików.
 */
class BSTFileHandler {
public:
    /**
     * @brief Konstruktor przyjmujący referencję do drzewa BST.
     * @param tree Referencja do obiektu BST
     */
    BSTFileHandler(BST& tree);

    /**
     * @brief Zapis drzewa do pliku binarnego w kolejności preorder.
     * @param filename Nazwa pliku
     */
    void saveToBinary(const std::string& filename) const;

    /**
     * @brief Zapis drzewa do pliku binarnego w wybranej kolejności.
     * @param filename Nazwa pliku
     * @param mode 1=preorder, 2=inorder, 3=postorder
     */
    void saveToBinary(const std::string& filename, int mode) const;

    /**
     * @brief Wczytanie drzewa z pliku binarnego (czyści drzewo przed wczytaniem).
     * @param filename Nazwa pliku
     */
    void loadFromBinary(const std::string& filename);

    /**
     * @brief Wczytanie drzewa z pliku tekstowego.
     * @param filename Nazwa pliku
     * @param append Jeśli true, dodaje do istniejącego drzewa; jeśli false, czyści drzewo
     */
    void loadFromText(const std::string& filename, bool append = true);

    /**
     * @brief Zapis drzewa do pliku tekstowego w wybranej kolejności.
     * @param filename Nazwa pliku
     * @param method 1=preorder, 2=inorder, 3=postorder
     */
    void saveToText(const std::string& filename, int method) const;

private:
    BST& treeRef; ///< Referencja do drzewa, którym zarządza klasa

    /**
     * @brief Rekursywny zapis węzła do strumienia binarnego (preorder).
     * @param out Strumień wyjściowy
     * @param node Wskaźnik na węzeł
     */
    void saveNode(std::ofstream& out, BST::Node* node) const;

    /**
     * @brief Rekursywny odczyt węzła z pliku binarnego i wstawienie do drzewa.
     * @param in Strumień wejściowy
     */
    void loadNode(std::ifstream& in);
};

#endif
