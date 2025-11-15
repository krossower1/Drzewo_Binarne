#include <iostream>
#include <memory>
#include <stack>
#include <iterator>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cstring>
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

    void serializePreorder(Node* node, ostream& fout) const {
        if (!node) {
            char marker = 0;
            fout.write(&marker, sizeof(marker));
            return;
        }
        char marker = 1;
        fout.write(&marker, sizeof(marker));
        fout.write(reinterpret_cast<const char*>(&(node->key)), sizeof(node->key));
        serializePreorder(node->left, fout);
        serializePreorder(node->right, fout);
    }

public:
    BST() : root(nullptr) {}
    ~BST() { clearTree(); }
    void insertKey(int key);
    void removeKey(int key);
    void clearTree();
    vector<int> getPathTo(int key) const;
    vector<int> getPreorder() const;
    vector<int> getInorder() const;
    vector<int> getPostorder() const;
    static void printVectorTraversal(const vector<int>& v);
    void printTreeGraphic2(Node* node, int indent = 0, int indentStep = 4) const;
    void printTreeGraphic(int indentStep = 4) const;
    bool saveTreeAsText(const string& filename) const {
        ofstream fout(filename, ios::out | ios::binary | ios::app);
        if (!fout) return false;
        saveAsTextInorder(root, fout);
        fout << "\n";
        fout.close();
        return true;
    }
    void saveAsTextInorder(Node* node, ostream& out) const {
        if (!node) return;
        saveAsTextInorder(node->left, out);
        out << node->key << " ";
        saveAsTextInorder(node->right, out);
    }
    bool serializeToBinary(const string& filename) const {
        ofstream out(filename, ios::binary);
        if (!out) return false;
        serializePreorder(root, out);
        out.close();
        return true;
    }
};