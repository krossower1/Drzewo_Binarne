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
 * @brief Usuwa węzeł o podanym kluczu z drzewa BST.
 *
 * Funkcja wywołuje prywatną funkcję remove() rozpoczynając od korzenia drzewa.
 *
 * @param key Klucz węzła, który ma zostać usunięty.
 */
void BST::removeKey(int key) {
    root = remove(root, key);
}