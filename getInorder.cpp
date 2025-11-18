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
 * @brief Zwraca wektor kluczy w porządku inorder (L–K–P).
 *
 * Metoda wywołuje prywatną funkcję rekurencyjną inorder(),
 * która wypełnia przekazany wektor wartościami odczytanymi
 * w kolejności inorder.
 *
 * @return vector<int> Wektor zawierający klucze drzewa w porządku inorder.
 */
vector<int> BST::getInorder() const {
    vector<int> out;
    inorder(root, out);
    return out;
}
