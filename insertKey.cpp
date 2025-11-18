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
 * @brief Wstawia nowy klucz do drzewa BST.
 *
 * Funkcja wywołuje prywatną funkcję insert(), która rekurencyjnie
 * znajduje odpowiednie miejsce w drzewie i wstawia nowy węzeł.
 *
 * @param key Klucz do wstawienia.
 */
void BST::insertKey(int key) {
    root = insert(root, key);
}