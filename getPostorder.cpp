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
 * @brief Zwraca elementy drzewa w kolejności postorder (Left -> Right -> Root).
 *
 * Funkcja wykorzystuje prywatną funkcję postorder(), która rekurencyjnie
 * przeszukuje drzewo i wypełnia wektor elementami w kolejności postorder.
 *
 * @return vector<int> Wektor elementów drzewa w kolejności postorder.
 */
vector<int> BST::getPostorder() const {
    vector<int> out;
    postorder(root, out);
    return out;
}