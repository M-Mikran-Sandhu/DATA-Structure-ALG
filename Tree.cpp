#include<iostream>
using namespace std;

class node {
public:
    int d;
    node *left, *right;
    node(int d) {
        this->d = d;
        left = right = NULL;
    }
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

    void pre_o(node* r) {
        if (r == NULL) return;
        cout << r->d << " ";
        pre_o(r->left);
        pre_o(r->right);
    }
};

int main() {
    node *r = NULL;
    B c;
    int n, val;

    cout << "How many values do you want to insert? ";
    cin >> n;

    cout << "Enter " << n << " integer values:\n";
    for (int i = 0; i < n; ++i) {
        cin >> val;
        r = c.insert(r, val);
    }

    cout << "Preorder traversal of the tree: ";
    c.pre_o(r);
    cout << endl;

    return 0;
}
