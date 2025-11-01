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

using namespace std;

class BST {
private:
    struct Node {
        int key;
        Node* left;
        Node* right;
        Node(int k) : key(k), left(nullptr), right(nullptr) {}
    };
    Node* root;

    Node* insert(Node* node, int key) {
        if (!node) return new Node(key);
        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        return node;
    }

    Node* remove(Node* node, int key) {
        if (!node) return nullptr;
        if (key < node->key) node->left = remove(node->left, key);
        else if (key > node->key) node->right = remove(node->right, key);
        else {
            if (!node->left) {
                Node* r = node->right;
                delete node;
                return r;
            }
            else if (!node->right) {
                Node* l = node->left;
                delete node;
                return l;
            }
            else {
                Node* succParent = node;
                Node* succ = node->right;
                while (succ->left) {
                    succParent = succ;
                    succ = succ->left;
                }
                node->key = succ->key;
                node->right = remove(node->right, succ->key);
            }
        }
        return node;
    }

    void clear(Node* node) {
        if (!node) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

    void preorder(Node* node, vector<int>& out) const {
        if (!node) return;
        out.push_back(node->key);
        preorder(node->left, out);
        preorder(node->right, out);
    }
    void inorder(Node* node, vector<int>& out) const {
        if (!node) return;
        inorder(node->left, out);
        out.push_back(node->key);
        inorder(node->right, out);
    }
    void postorder(Node* node, vector<int>& out) const {
        if (!node) return;
        postorder(node->left, out);
        postorder(node->right, out);
        out.push_back(node->key);
    }

    bool findPath(Node* node, int key, vector<int>& path) const {
        if (!node) return false;
        path.push_back(node->key);
        if (node->key == key) return true;
        if (key < node->key) {
            if (findPath(node->left, key, path)) return true;
        }
        else {
            if (findPath(node->right, key, path)) return true;
        }
        path.pop_back();
        return false;
    }

public:
    BST() : root(nullptr) {}
    ~BST() { clearTree(); }

    void insert(int key) {
        root = insert(root, key);
    }

    void removeKey(int key) {
        root = remove(root, key);
    }
    
    void clearTree() {
        clear(root);
        root = nullptr;
    }

    vector<int> getPathTo(int key) const {
        vector<int> path;
        if (findPath(root, key, path)) return path;
        return {};
    }

    bool isEmpty() const { return root == nullptr; }

    vector<int> getPreorder() const {
        vector<int> out; preorder(root, out); return out;
    }
    vector<int> getInorder() const {
        vector<int> out; inorder(root, out); return out;
    }
    vector<int> getPostorder() const {
        vector<int> out; postorder(root, out); return out;
    }

    static void printVectorTraversal(const vector<int>& v) {
        if (v.empty()) { cout << "(brak)\n"; return; }
        for (size_t i = 0; i < v.size(); ++i) {
            if (i) cout << " ";
            cout << v[i];
        }
        cout << "\n";
    }

};

static void showMenu() {
    cout << "====== Program: drzewo BST ======\n";
    cout << "1. Dodaj element\n";
    cout << "2. Usun element\n";
    cout << "3. Usun cale drzewo\n";
    cout << "4. Szukaj drogi do elementu\n";
    cout << "5. Wyswietl drzewo (wybierz metode: preorder/inorder/postorder)\n";
    cout << "0. Wyjscie\n";
    cout << "Wybierz opcje: ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    BST tree;
    bool running = true;
    while (running) {
        showMenu();
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
            tree.insert(v);
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
            cout << "Podaj klucz do wyszukania (sciezka): ";
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