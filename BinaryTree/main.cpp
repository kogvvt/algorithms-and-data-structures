#include <iostream>
#include <utility>
using namespace std;

class BinaryTree{
public:
    struct Node{
        string nodeData;
        int nodeCount;
        Node *leftNode;
        Node *rightNode;
    };
    Node *rootNode;
    static Node *newNode(string nodeValue){
        Node *node = new Node;
        node->nodeData = std::move(nodeValue);
        node->rightNode = nullptr;
        node->leftNode = nullptr;
        node->nodeCount = 1;
        return node;
    }
    Node *insertIntoNode(Node *node, const string& value){
        if(node== nullptr){
            return newNode(value);
        }
        int result = node->nodeData.compare(value);
        if(result > 0){
            node->leftNode = insertIntoNode(node->leftNode, value);
        }else if(result < 0) {
            node->rightNode = insertIntoNode(node->rightNode, value);
        }else{
            node->nodeCount++;
        }
        return node;
    }
    BinaryTree() : rootNode(nullptr){};
    ~BinaryTree(){
        deleteTree(rootNode);
    }
    void deleteTree(Node *node){
        if(node!= nullptr){
            deleteTree(node->leftNode);
            deleteTree(node->rightNode);
            delete node;
        }
    }
    void binaryInOrderTraversal() {
        binaryInOrderTraversal(rootNode);
    }
    void binaryInOrderTraversal(Node *node){
        if(node == nullptr) {
            return;
        }
        binaryInOrderTraversal(node->leftNode);
        for(int i=0; i<node->nodeCount;++i){
            cout << node->nodeData <<"\n";
        }
        binaryInOrderTraversal(node->rightNode);
    }
    void insertIntoNode(string value){
        rootNode = insertIntoNode(rootNode, value);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    unsigned int n;
    std::string data;
    BinaryTree binaryTree = BinaryTree();
    std::cin >> n;
    for(int i=0; i<n; ++i){
        std::cin >> data;
        binaryTree.insertIntoNode(data);
    }
    binaryTree.binaryInOrderTraversal();
    return 0;
}
