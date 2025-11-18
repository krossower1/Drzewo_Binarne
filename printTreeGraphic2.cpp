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
 * @brief Rekurencyjnie wyświetla drzewo BST w formie graficznej w konsoli.
 *
 * Funkcja wywołuje się rekurencyjnie dla prawego i lewego dziecka węzła,
 * stosując wcięcia w zależności od poziomu drzewa.
 *
 * @param node Wskaźnik na aktualny węzeł drzewa.
 * @param indent Aktualny poziom wcięcia dla tego węzła.
 * @param indentStep Ilość spacji dodawanych przy przechodzeniu na niższy poziom drzewa.
 */

void BST::printTreeGraphic2(Node* node, int indent, int indentStep) const {
    if (!node) return;
    if (node->right) printTreeGraphic2(node->right, indent + indentStep, indentStep);
    if (indent) cout << setw(indent) << ' ';
    cout << node->key << "\n";
    if (node->left) printTreeGraphic2(node->left, indent + indentStep, indentStep);
}