// Wheather a tree is balanced
#include<iostream>
#include<cmath>
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

    int checkHeight(node* temp, bool& isBalanced) {
        if (temp == NULL)
            return 0;

        int leftHeight = checkHeight(temp->left, isBalanced);
        int rightHeight = checkHeight(temp->right, isBalanced);

        if (abs(leftHeight - rightHeight) > 1)
            isBalanced = false;

        return max(leftHeight, rightHeight) + 1;
    }

    bool isTreeBalanced() {
        bool isBalanced = true;
        checkHeight(root, isBalanced);
        return isBalanced;
    }

    void inorder(node* temp) {
        if (temp == NULL)
            return;
        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }

    void display() {
        cout << "Inorder Traversal: ";
        inorder(root);
        cout << endl;
    }
};

int main() {
    tree t;
    int n, val;
    cout<<"Enter Number of Node you wnat to enter:";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> val;
        t.enternode(val);
    }

    t.display();

    if (t.isTreeBalanced())
        cout << "The tree is balanced." << endl;
    else
        cout << "The tree is NOT balanced." << endl;

    return 0;
}
