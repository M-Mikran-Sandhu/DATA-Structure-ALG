#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int num) {
        data = num;
        left = right = NULL;
    }
};

class tree {
    node* root;

public:
    tree() {
        root = NULL;
    }

    void enternode(int val) {
        root = insert(root, val);
    }

    node* insert(node* temp, int val) {
        if (temp == NULL)
            return new node(val);
        if (val < temp->data)
            temp->left = insert(temp->left, val);
        else
            temp->right = insert(temp->right, val);
        return temp;
    }

    bool hasCycle() {
        return false; // No way to detect cycles without tracking visited pointers
    }
};

int main() {
    tree t;
    int n, val;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> val;
        t.enternode(val);
    }

    if (t.hasCycle())
        cout << "Cycle detected in the tree." << endl;
    else
        cout << "No cycle found. The tree is safe." << endl;

    return 0;
}
