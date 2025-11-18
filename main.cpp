#include <iostream>
#include <cmath>
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
#include "bst_file_handler.h" 

using namespace std;

/**
* @brief The main body and interface
*
**/

int main() {
    BST tree;
    BSTFileHandler fileHandler(tree);
    int choice;
    bool running = true;
    int i = 1;
    while (running) {
        i += 1;
        cout << "\n====== Program: drzewo BST ======\n";
        cout << "1. Dodaj element\n";
        cout << "2. Usun element\n";
        cout << "3. Usun cale drzewo\n";
        cout << "4. Szukaj drogi do elementu\n";
        cout << "5. Wyswietl drzewo (preorder, inorder, postorder)\n";
        cout << "6. Wyswietl drzewo graficznie\n";
        cout << "7. Zapisz drzewo do pliku tekstowego\n";
        cout << "8. Zapisz drzewo do pliku binarnego\n";
        cout << "9. Wczytanie drzewa z pliku tekstowego\n";
        cout << "10. Wczytanie drzewa z pliku binarnego\n";
        cout << "0. Wyjscie\n";
        cout << "Wybierz opcje: ";
        cin >> choice;
        cout << "\n";
        switch (choice) {
        case 1: {
            cout << "Podaj liczbe do dodania: ";
            int v;
            cin >> v;
            tree.insertKey(v);
            cout << "Dodano " << v << ".\n";
            break;
        }
        case 2: {
            cout << "Podaj liczbe do usuniecia: ";
            int v;
            cin >> v;
            tree.removeKey(v);
            cout << "Usunieto (jesli istniala) " << v << ".\n";
            break;
        }
        case 3: {
            cout << "Usunac cale drzewo? (t/n): ";
            char c;
            cin >> c;
            if (c == 't' || c == 'T' || c == 'y' || c == 'Y') {
                tree.clearTree();
                cout << "Drzewo usuniete.\n";
            }
            else cout << "Anulowano.\n";
            break;
        }
        case 4: {
            cout << "Podaj klucz do wyszukania sciezki: ";
            int v;
            cin >> v;
            vector<int> path = tree.getPathTo(v);
            if (path.empty()) cout << "Element nie znaleziony w drzewie.\n";
            else {
                cout << "sciezka od korzenia do " << v << ": ";
                for (size_t i = 0; i < path.size(); ++i) {
                    if (i) cout << " -> ";
                    cout << path[i];
                }
                cout << "\n";
            }
            break;
        }
        case 5: {
            cout << "Wybierz metode (1=preorder,2=inorder,3=postorder): ";
            int m;
            cin >> m;
            if (m == 1) {
                auto v = tree.getPreorder();
                cout << "Preorder: "; BST::printVectorTraversal(v);
            }
            else if (m == 2) {
                auto v = tree.getInorder();
                cout << "Inorder: "; BST::printVectorTraversal(v);
            }
            else if (m == 3) {
                auto v = tree.getPostorder();
                cout << "Postorder: "; BST::printVectorTraversal(v);
            }
            else cout << "Niepoprawna metoda.\n";
            break;
        }
        case 6: {
            cout << "Grafika drzewa od lewej strony.\n";
            tree.printTreeGraphic();
            break;
        }
        case 7: {
            cout << "Podaj nazwe pliku tekstowego do zapisu: ";
            std::string fname;
            cin >> fname;

            /*
            cout << "Wybierz metode zapisu drzewa:\n";
            cout << "1. Preorder\n";
            cout << "2. Inorder\n";
            cout << "3. Postorder\n";
            cout << "Twoj wybor: ";
            cin >> method;
            */
            int method = 1;

            fileHandler.saveToText(fname, method);
            cout << "Zapisano drzewo do pliku tekstowego: " << fname << "\n";
            break;
        }
        case 8: {
            cout << "Podaj nazwe pliku binarnego do zapisu: ";
            string fname;
            cin >> fname;

            /*
            cout << "Wybierz metode zapisu:\n";
            cout << "1. Preorder\n";
            cout << "2. Inorder\n";
            cout << "3. Postorder\n";
            cin >> mode;
            */
            int mode = 1;

            if (mode < 1 || mode > 3) {
                cout << "Niepoprawna metoda zapisu.\n";
                break;
            }

            fileHandler.saveToBinary(fname, mode);
            cout << "Zapisano drzewo do pliku: " << fname << "\n";
            break;
        }
        case 9: {
            cout << "Podaj nazwe pliku tekstowego do wczytania: ";
            string fname;
            cin >> fname;
            cout << "Czy wczytac do pustego drzewa? (t/n): ";
            char c;
            cin >> c;
            bool append = !(c == 't' || c == 'T' || c == 'y' || c == 'Y');
            fileHandler.loadFromText(fname, append);
            break;
        }
        case 10: {
            cout << "Podaj nazwe pliku binarnego do wczytania: ";
            string fname;
            cin >> fname;
            cout << "Czy wczytac do pustego drzewa? (t/n): ";
            char c;
            cin >> c;
            if (c == 't' || c == 'T' || c == 'y' || c == 'Y') tree.clearTree();
            fileHandler.loadFromBinary(fname);
            break;
        }
        case 0: {
            cout << "Koniec. \n";
            running = false;
            break;
        }
        default: {
            cin.clear();
            cout << "Nieznana opcja. Sprobuj ponownie.\n";
        }
        cout << "\n";
        }
    }
    return i;

}