#include<iostream>
#include<queue>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
    node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class tree {
    int a[100]; // increased array size for more flexibility
    int i = 0, c = 0;

public:
    node* insert(node* root, int val) {
        if (root == NULL) {
            return new node(val);
        }
        if (val < root->data) {
            root->left = insert(root->left, val);
        } else {
            root->right = insert(root->right, val);
        }
        return root;
    }

    void display_level(node* root) {
        queue<node*> q;
        int l = 0;
        if (root == NULL) return;

        q.push(root);
        q.push(NULL);

        while (!q.empty()) {
            node* curr = q.front();
            q.pop();
            if (curr == NULL) {
                if (!q.empty()) {
                    cout << endl;
                    q.push(NULL);
                    l++;
                    continue;
                } else {
                    l++;
                    break;
                }
            }
            cout << curr->data << " ";
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        cout << "\n\nHeight of tree is: " << l << endl;
    }

    void cout_leafs(node* root) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL) {
            a[i++] = root->data;
            c++;
        }
        cout_leafs(root->left);
        cout_leafs(root->right);
    }

    void display_leafs() {
        cout << "\nTotal leaf nodes: " << c << endl;
        cout << "Leaf nodes: ";
        for (int j = 0; j < i; j++) {
            cout << a[j] << " ";
        }
        cout << endl;
        i = c = 0;
    }

    void count_parents(node* root) {
        if (root == NULL) return;
        if (root->left != NULL || root->right != NULL) {
            a[i++] = root->data;
            c++;
        }
        count_parents(root->left);
        count_parents(root->right);
    }

    void display_parents() {
        cout << "\nTotal parent nodes: " << c << endl;
        cout << "Parent nodes: ";
        for (int j = 0; j < i; j++) {
            cout << a[j] << " ";
        }
        cout << endl;
        i = c = 0;
    }

    void siblings(node* root) {
        if (root == NULL) return;
        if (root->left != NULL || root->right != NULL) {
            cout << "\nParent: " << root->data << " => Children: ";
            if (root->left) cout << root->left->data << " ";
            if (root->right) cout << root->right->data << " ";
        }
        siblings(root->left);
        siblings(root->right);
    }

    void count_sub_trees(node* root) {
        static int s = -1;
        if (root == NULL) return;
        if (s != -1) {
            a[i++] = root->data;
            c++;
        }
        s++;
        count_sub_trees(root->left);
        count_sub_trees(root->right);
    }

    void display_sub_trees() {
        cout << "\nTotal subtrees (excluding root): " << c << endl;
        cout << "Subtree roots: ";
        for (int j = 0; j < i; j++) {
            cout << a[j] << " ";
        }
        cout << endl;
        i = c = 0;
    }
};

int main() {
    tree t;
    node* root = NULL;
    int n, val;

    cout << "Enter number of nodes to insert in BST: ";
    cin >> n;

    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        root = t.insert(root, val);
    }

    cout << "\nLevel Order Traversal:\n";
    t.display_level(root);

    t.cout_leafs(root);
    t.display_leafs();

    t.count_parents(root);
    t.display_parents();

    t.siblings(root);

    t.count_sub_trees(root);
    t.display_sub_trees();

    return 0;
}
