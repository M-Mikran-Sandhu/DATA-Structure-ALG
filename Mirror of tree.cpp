//Mirror of tree 
#include<iostream>
using namespace std;

class node {
public:
    node* right;
    int data;
    node* left;

    node(int num) {
        data = num;
        right = left = NULL;
    }
};

class tree {
    node* root;
public:
    tree() {
        root = NULL;
    }

    void enternode(int num) {
        root = insert(root, num);
    }

    node* insert(node* temp, int num) {
        if (temp == NULL)
            return new node(num);
        if (num < temp->data)
            temp->left = insert(temp->left, num);
        else
            temp->right = insert(temp->right, num);
        return temp;
    }

    void mirrorTree() {
        mirror(root);
    }

    void mirror(node* temp) {
        if (temp == NULL)
            return;
        node* swap = temp->left;
        temp->left = temp->right;
        temp->right = swap;

        mirror(temp->left);
        mirror(temp->right);
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

    cout << "How many nodes do you want to enter? ";
    cin >> n;

    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; ++i) {
        cin >> val;
        t.enternode(val);
    }

    cout << "\nOriginal Tree: ";
    t.display();

    t.mirrorTree();

    cout << "Mirrored Tree: ";
    t.display();

    return 0;
}
