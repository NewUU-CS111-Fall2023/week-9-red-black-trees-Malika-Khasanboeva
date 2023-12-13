#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int v) {
        val = v;
        left = NULL;
        right = NULL;
    }
;

class binarySearchTree {
private:
    Node* root;
public:
    binarySearchTree() {
        root = NULL;
    }
    void add(int val) {
        Node* newNode = new Node(val);
        if (root == NULL) {
            root = newNode;
            return;
        }
        Node* cur = root;
        while (true) {
            if (val < cur->val) {
                if (cur->left == NULL) {
                    cur->left = newNode;
                    return;
                }
                else {
                    cur = cur->left;
                }
            }
            else if (val > cur->val) {
                if (cur->right == NULL) {
                    cur->right = newNode;
                    return;
                }
                else {
                    cur = cur->right;
                }
            }
            else {
                return; // value already exists in tree
            }
        }
    }
    void printInOrder(Node* node) {
        if (node == NULL) {
            return;
        }
        printInOrder(node->left);
        cout << node->val << " ";
        printInOrder(node->right);
    }
    int height(Node* node) {
        if (node == NULL) {
            return -1;
        }
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return max(leftHeight, rightHeight) + 1;
    }
    int depth(int val) {
        Node* cur = root;
        int depth = 0;
        while (cur != NULL) {
            if (val < cur->val) {
                cur = cur->left;
                depth++;
            }
            else if (val > cur->val) {
                cur = cur->right;
                depth++;
            }
            else {
                return depth;
            }
        }
        return -1; // value not found in tree
    }
    Node* deleteNode(Node* node, int val) {
        if (node == NULL) {
            return NULL;
        }
        if (val < node->val) {
            node->left = deleteNode(node->left, val);
        }
        else if (val > node->val) {
            node->right = deleteNode(node->right, val);
        }
        else {
            if (node->left == NULL && node->right == NULL) {
                delete node;
                return NULL;
            }
            else if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            else {
                Node* minRight = node->right;
                while (minRight->left != NULL) {
                    minRight = minRight->left;
                }
                node->val = minRight->val;
                node->right = deleteNode(node->right, minRight->val);
            }
        }
        return node;
    }
    void AVLify(Node* node, vector<int>& vals) {
        if (node == NULL) {
            return;
        }
        AVLify(node->left, vals);
        vals.push_back(node->val);
        AVLify(node->right, vals);
    }
    Node* buildAVL(int start, int end, vector<int>& vals) {
        if (start > end) {
            return NULL;
        }
        int mid = (start + end) / 2;
        Node* newNode = new Node(vals[mid]);
        newNode->left = buildAVL(start, mid - 1, vals);
        newNode->right = buildAVL(mid + 1, end, vals);
        return newNode;
    }
    void AVL() {
        vector<int> vals;
        AVLify(root, vals);
        root = buildAVL(0, vals.size() - 1, vals);
    }
;

int main() {
    binarySearchTree tree;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int val;
        char comma;
        cin >> val >> comma;
        tree.add(val);
    }
    tree.printInOrder(tree.getRoot());
    cout << endl;
    tree.AVL();
    cout << tree.printInOrder(tree.getRoot()) << endl;
    return 0;
