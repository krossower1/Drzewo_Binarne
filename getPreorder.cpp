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
 * @brief Zwraca elementy drzewa w kolejności preorder (Root -> Left -> Right).
 *
 * Funkcja wykorzystuje prywatną funkcję preorder(), która rekurencyjnie
 * przeszukuje drzewo i wypełnia wektor elementami w kolejności preorder.
 *
 * @return vector<int> Wektor elementów drzewa w kolejności preorder.
 */
vector<int> BST::getPreorder() const {
    vector<int> out;
    preorder(root, out);
    return out;
}