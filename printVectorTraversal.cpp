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
 * @brief Wyświetla zawartość wektora reprezentującego przegląd drzewa (preorder, inorder, postorder).
 *
 * Funkcja służy do wygodnego drukowania kolejności węzłów drzewa w konsoli.
 *
 * @param v Wektor kluczy drzewa do wyświetlenia.
 */
void BST::printVectorTraversal(const vector<int>& v) {
    if (v.empty()) { cout << "(brak)\n"; return; }
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) cout << " ";
        cout << v[i];
    }
    cout << "\n";
}