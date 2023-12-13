#include <iostream>
using namespace std;

enum Color RED, BLACK;

class Node {
public:
    int data;
    Color color;
    Node *left, *right, *parent;
    Node(int data) {
        this->data = data;
        color = RED;
        left = right = parent = NULL;
    }
;

class RedBlackTree {
private:
    Node *root;
    void rotateLeft(Node *&);
    void rotateRight(Node *&);
    void fixViolation(Node *&);
    void inorderHelper(Node *);
public:
    RedBlackTree()  root = NULL; 
    void insert(const int &);
    void printTree()  inorderHelper(root); 
;

void RedBlackTree::rotateLeft(Node *&ptr) {
    Node *rightChild = ptr->right;
    ptr->right = rightChild->left;
    if (ptr->right != NULL)
        ptr->right->parent = ptr;
    rightChild->parent = ptr->parent;
    if (ptr->parent == NULL)
        root = rightChild;
    else if (ptr == ptr->parent->left)
        ptr->parent->left = rightChild;
    else
        ptr->parent->right = rightChild;
    rightChild->left = ptr;
    ptr->parent = rightChild;


void RedBlackTree::rotateRight(Node *&ptr) {
    Node *leftChild = ptr->left;
    ptr->left = leftChild->right;
    if (ptr->left != NULL)
        ptr->left->parent = ptr;
    leftChild->parent = ptr->parent;
    if (ptr->parent == NULL)
        root = leftChild;
    else if (ptr == ptr->parent->left)
        ptr->parent->left = leftChild;
    else
        ptr->parent->right = leftChild;
    leftChild->right = ptr;
    ptr->parent = leftChild;


void RedBlackTree::fixViolation(Node *&ptr) {
    Node *parentPtr = NULL;
    Node *grandParentPtr = NULL;
    while ((ptr != root) && (ptr->color != BLACK) && (ptr->parent->color == RED)) {
        parentPtr = ptr->parent;
        grandParentPtr = ptr->parent->parent;
        if (parentPtr == grandParentPtr->left) {
            Node *unclePtr = grandParentPtr->right;
            if (unclePtr != NULL && unclePtr->color == RED) {
                grandParentPtr->color = RED;
                parentPtr->color = BLACK;
                unclePtr->color = BLACK;
                ptr = grandParentPtr;
             else {
                if (ptr == parentPtr->right) {
                    rotateLeft(parentPtr);
                    ptr = parentPtr;
                    parentPtr = ptr->parent;
                }
                rotateRight(grandParentPtr);
                swap(parentPtr->color, grandParentPtr->color);
                ptr = parentPtr;
            }
         else {
            Node *unclePtr = grandParentPtr->left;
            if ((unclePtr != NULL) && (unclePtr->color == RED)) {
                grandParentPtr->color = RED;
                parentPtr->color = BLACK;
                unclePtr->color = BLACK;
                ptr = grandParentPtr;
             else {
                if (ptr == parentPtr->left) {
                    rotateRight(parentPtr);
                    ptr = parentPtr;
                    parentPtr = ptr->parent;
                }
                rotateLeft(grandParentPtr);
                swap(parentPtr->color, grandParentPtr->color);
                ptr = parentPtr;
            }
        }
    }
    root->color = BLACK;


void RedBlackTree::insert(const int &data) {
    Node *newNode = new Node(data);
    if (root == NULL) {
        newNode->color = BLACK;
        root = newNode;
     else {
        Node *temp = root;
        Node *parent = NULL;
        while (temp != NULL) {
            parent = temp;
            if (newNode->data < temp->data)
                temp = temp->left;
            else
                temp = temp->right;
        }
        newNode->parent = parent;
        if (newNode->data < parent->data)
            parent->left = newNode;
        else
            parent->right = newNode;
        fixViolation(newNode);
    }


void RedBlackTree::inorderHelper(Node *ptr) {
    if (ptr == NULL)
        return;
    cout << "(" << ptr->data << "(";
    if (ptr->color == RED)
        cout << "RED)";
    else
        cout << "BLACK)";
    inorderHelper(ptr->left);
    inorderHelper(ptr->right);
    cout << ")";


int main() {
    RedBlackTree tree;
    int n, val;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> val;
        tree.insert(val);
    }
    tree.printTree();
    return 0;
