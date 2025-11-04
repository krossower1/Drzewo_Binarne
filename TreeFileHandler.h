using namespace std;

class TreeFileHandler {
public:
    static bool saveBinary(const BST& tree, const string& filename) {
        return tree.serializeToBinary(filename);
    }

    static bool saveTextTree(const BST& tree, const string& filename) {
        return tree.saveTreeAsText(filename);
    }
};