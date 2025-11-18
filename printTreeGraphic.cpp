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
 * @brief Wyświetla drzewo BST w formie graficznej w konsoli.
 *
 * Funkcja wywołuje rekurencyjną metodę printTreeGraphic2 dla korzenia drzewa.
 * Jeśli drzewo jest puste, wyświetla odpowiedni komunikat.
 *
 * @param indentStep Ilość spacji używana do wcięć dla kolejnych poziomów drzewa.
 */

void BST::printTreeGraphic(int indentStep) const {
    if (!root) { cout << "(drzewo puste)\n"; return; }
    printTreeGraphic2(root, 0, indentStep);
}