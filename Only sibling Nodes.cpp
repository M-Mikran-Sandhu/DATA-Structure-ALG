#include<iostream>
using namespace std;

class node {
public:
    int d;
    node *left, *right;
    node(int val) : d(val), left(NULL), right(NULL) {}
};

class B {
public:
    node* insert(node* r, int v) {
        if (r == NULL){
            return new node(v);
        }
        if (v < r->d){
            r->left = insert(r->left, v);
        }
        else if (v > r->d){
            r->right = insert(r->right, v);
        }
        return r;
    }

    void in_o(node* r) {
        if (r == NULL) return;
        in_o(r->left);
        cout << r->d << " ";
        in_o(r->right);
    }

    void printSiblings(node* r) {
        if (r == NULL) return;

        // If both left and right child exist, they are siblings
        if (r->left != NULL && r->right != NULL) {
            cout << "Siblings: " << r->left->d << " and " << r->right->d << endl;
        }

        // Recurse on left and right subtree
        printSiblings(r->left);
        printSiblings(r->right);
    }
};

int main() {
    node *r = NULL;
    B c;
    int n, val;

    cout << "How many values? ";
    cin >> n;

    cout << "Enter values:\n";
    for (int i = 0; i < n; ++i) {
        cin >> val;
        r = c.insert(r, val);
    }

    cout << "Inorder traversal: ";
    c.in_o(r);
    cout << endl;

    cout << "\nSibling nodes in the tree:\n";
    c.printSiblings(r);

    return 0;
}
