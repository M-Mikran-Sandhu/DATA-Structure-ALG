#include <iostream>
using namespace std;

class Node {
public:
    int key, height;
    Node* left;
    Node* right;

    Node(int val) {
        key = val;
        height = 1;
        left = right = NULL;
    }
};

int height(Node* n) {
    return n ? n->height : 0;
}

int getBalance(Node* n) {
    return n ? height(n->left) - height(n->right) : 0;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Node* insert(Node* node, int key) {
    if (!node) return new Node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void preorder(Node* root) {
    if (root) {
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {
    Node* root = NULL;
    int n, val;

    cout << "Enter number of nodes to insert: ";
    cin >> n;

    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        root = insert(root, val);
    }

    cout << "Preorder traversal of AVL tree:\n";
    preorder(root);
    cout << endl;

    return 0;
}
