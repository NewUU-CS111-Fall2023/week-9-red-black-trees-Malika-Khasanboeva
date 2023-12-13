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
    void leftRotate(Node *&);
    void rightRotate(Node *&);
;

void RedBlackTree::leftRotate(Node *&ptr) {
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


void RedBlackTree::rightRotate(Node *&ptr) {
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
