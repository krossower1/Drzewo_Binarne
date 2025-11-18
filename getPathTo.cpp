#include <iostream>
#include <memory>
#include <stack>
#include <iterator>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include "bst.h"

using namespace std;

/**
 * @brief Zwraca ścieżkę od korzenia do podanego klucza w drzewie.
 *
 * Funkcja wykorzystuje prywatną funkcję findPath(), która rekurencyjnie
 * przeszukuje drzewo w poszukiwaniu klucza i wypełnia wektor ścieżki.
 *
 * @param key Klucz, do którego chcemy znaleźć ścieżkę.
 * @return vector<int> Wektor zawierający kolejność kluczy od korzenia
 * do poszukiwanego klucza. Zwraca pusty wektor, jeśli klucz nie istnieje w drzewie.
 */
vector<int> BST::getPathTo(int key) const {
    vector<int> path;
    if (findPath(root, key, path)) return path;
    return {};
}