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

    void post_o(node* r) {
        if (r == NULL) return;
        post_o(r->left);
        post_o(r->right);
        cout << r->d << " ";
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

    cout << "Postorder traversal: ";
    c.post_o(r);
    cout << endl;

    return 0;
}

