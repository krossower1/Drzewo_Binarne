#ifndef BST_H
#define BST_H

#include <iostream>
#include <memory>
#include <stack>
#include <iterator>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cstring>
#include <sstream>
#include <algorithm>

using namespace std;

/**
 * @brief Klasa reprezentująca drzewo BST (Binary Search Tree).
 */
class BST {
    friend class BSTFileHandler; ///< Klasa przyjaciół umożliwiająca dostęp do prywatnych elementów drzewa

private:
    /**
     * @brief Struktura węzła drzewa.
     */
    struct Node {
        int key;       ///< Klucz węzła
        Node* left;    ///< Wskaźnik na lewego potomka
        Node* right;   ///< Wskaźnik na prawego potomka
        /**
         * @brief Konstruktor węzła.
         * @param k Klucz węzła
         */
        Node(int k) : key(k), left(nullptr), right(nullptr) {}
    };

    Node* root; ///< Wskaźnik na korzeń drzewa

    /**
     * @brief Rekursywne wstawianie klucza do drzewa.
     * @param node Wskaźnik na bieżący węzeł
     * @param key Klucz do wstawienia
     * @return Wskaźnik na węzeł po wstawieniu
     */
    Node* insert(Node* node, int key) {
        if (!node) return new Node(key);
        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        return node;
    }

    /**
     * @brief Rekursywne usuwanie węzła z drzewa.
     * @param node Wskaźnik na bieżący węzeł
     * @param key Klucz do usunięcia
     * @return Wskaźnik na węzeł po usunięciu
     */
    Node* remove(Node* node, int key) {
        if (!node) return nullptr;
        if (key < node->key) node->left = remove(node->left, key);
        else if (key > node->key) node->right = remove(node->right, key);
        else {
            if (!node->left) {
                Node* r = node->right;
                delete node;
                return r;
            } else if (!node->right) {
                Node* l = node->left;
                delete node;
                return l;
            } else {
                Node* succParent = node;
                Node* succ = node->right;
                while (succ->left) {
                    succParent = succ;
                    succ = succ->left;
                }
                node->key = succ->key;
                node->right = remove(node->right, succ->key);
            }
        }
        return node;
    }

    /**
     * @brief Rekursywne czyszczenie drzewa.
     * @param node Wskaźnik na węzeł
     */
    void clear(Node* node) {
        if (!node) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

    /**
     * @brief Rekursywne przejście preorder.
     * @param node Wskaźnik na węzeł
     * @param out Wektor do którego zapisywane są klucze
     */
    void preorder(Node* node, vector<int>& out) const {
        if (!node) return;
        out.push_back(node->key);
        preorder(node->left, out);
        preorder(node->right, out);
    }

    /**
     * @brief Rekursywne przejście inorder.
     * @param node Wskaźnik na węzeł
     * @param out Wektor do którego zapisywane są klucze
     */
    void inorder(Node* node, vector<int>& out) const {
        if (!node) return;
        inorder(node->left, out);
        out.push_back(node->key);
        inorder(node->right, out);
    }

    /**
     * @brief Rekursywne przejście postorder.
     * @param node Wskaźnik na węzeł
     * @param out Wektor do którego zapisywane są klucze
     */
    void postorder(Node* node, vector<int>& out) const {
        if (!node) return;
        postorder(node->left, out);
        postorder(node->right, out);
        out.push_back(node->key);
    }

    /**
     * @brief Rekursywne szukanie ścieżki do klucza.
     * @param node Wskaźnik na węzeł
     * @param key Klucz do wyszukania
     * @param path Wektor przechowujący ścieżkę
     * @return true jeśli znaleziono klucz, false w przeciwnym wypadku
     */
    bool findPath(Node* node, int key, vector<int>& path) const {
        if (!node) return false;
        path.push_back(node->key);
        if (node->key == key) return true;
        if (key < node->key) {
            if (findPath(node->left, key, path)) return true;
        } else {
            if (findPath(node->right, key, path)) return true;
        }
        path.pop_back();
        return false;
    }

    /**
     * @brief Rekursywne zapisanie drzewa w preorder do strumienia (np. plik binarny)
     * @param node Wskaźnik na węzeł
     * @param fout Strumień wyjściowy
     */
    void serializePreorder(Node* node, ostream& fout) const {
        if (!node) {
            char marker = 0;
            fout.write(&marker, sizeof(marker));
            return;
        }
        char marker = 1;
        fout.write(&marker, sizeof(marker));
        fout.write(reinterpret_cast<const char*>(&(node->key)), sizeof(node->key));
        serializePreorder(node->left, fout);
        serializePreorder(node->right, fout);
    }

public:
    BST() : root(nullptr) {}
    ~BST() { clearTree(); }

    /// Wstawia nowy klucz do drzewa
    void insertKey(int key);

    /// Usuwa klucz z drzewa
    void removeKey(int key);

    /// Czyści całe drzewo
    void clearTree();

    /// Zwraca ścieżkę od korzenia do danego klucza
    vector<int> getPathTo(int key) const;

    /// Zwraca elementy w kolejności preorder
    vector<int> getPreorder() const;

    /// Zwraca elementy w kolejności inorder
    vector<int> getInorder() const;

    /// Zwraca elementy w kolejności postorder
    vector<int> getPostorder() const;

    /// Wypisuje wektor kluczy na ekran
    static void printVectorTraversal(const vector<int>& v);

    /// Rekursywne wyświetlenie drzewa w konsoli
    void printTreeGraphic2(Node* node, int indent = 0, int indentStep = 4) const;

    /// Wyświetlenie drzewa w konsoli
    void printTreeGraphic(int indentStep = 4) const;

    /// Zwraca wskaźnik do korzenia
    BST::Node* getRoot() const { return root; }
};

#endif // BST_H