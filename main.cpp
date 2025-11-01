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

int main() {
    BST tree;
    bool running = true;
    while (running) {
        cout << "====== Program: drzewo BST ======\n";
        cout << "1. Dodaj element\n";
        cout << "2. Usun element\n";
        cout << "3. Usun cale drzewo\n";
        cout << "4. Szukaj drogi do elementu\n";
        cout << "5. Wyswietl drzewo (wybierz metode: preorder/inorder/postorder)\n";
        cout << "0. Wyjscie\n";
        cout << "Wybierz opcje: ";
        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            string dump;
            getline(cin, dump);
            cout << "Niepoprawne dane. Sprobuj ponownie.\n";
            continue;
        }
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
        case 0: {
            cout << "Koniec. Zamykam program.\n";
            running = false;
            break;
        }
        default:
            cout << "Nieznana opcja. Sprobuj ponownie.\n";
        }
        cout << "\n";
    }

    return 0;
}