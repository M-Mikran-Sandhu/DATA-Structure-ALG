//write a cpp program that prints only the leaf nodes in a tree
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
        if (r == NULL) {
            return new node(v);
        }
        if (v < r->d) {
            r->left = insert(r->left, v);
        } else if (v > r->d) {
            r->right = insert(r->right, v);
        }
        return r;
    }

    void printLeafNodes(node* r) {
        if (r == NULL) return;

        if (r->left == NULL && r->right == NULL) {
            cout << r->d << " ";
            return;
        }

        printLeafNodes(r->left);
        printLeafNodes(r->right);
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

    cout << "Leaf nodes: ";
    c.printLeafNodes(r);
    cout << endl;

    return 0;
}
