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
 * @brief Usuwa całe drzewo BST.
 *
 * Funkcja wywołuje prywatną metodę `clear(node*)`, która
 * rekurencyjnie usuwa wszystkie węzły drzewa.
 */
void BST::clearTree() {
    clear(root);
    root = nullptr;
}
