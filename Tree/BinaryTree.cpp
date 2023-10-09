#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree() {
    int data;
    cin >> data;
    if (data == -1) {
        return NULL;
    }
    node* root = new node(data);

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree();

    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree();

    return root;
}

void printLevelOrderTraversal(node* root) {
    if (root == NULL) {
        return;
    }

    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; i++) {
            node* temp = q.front();
            q.pop();
            cout << temp->data << " ";
            if (temp->left != NULL) {
                q.push(temp->left);
            }
            if (temp->right != NULL) {
                q.push(temp->right);
            }
        }
        cout << endl;
    }
}

void printInorderTraversal(node* root) {
    if (root == NULL) {
        return;
    }
    printInorderTraversal(root->left);
    cout << root->data << " ";
    printInorderTraversal(root->right);
}

void printPostorderTraversal(node* root) {
    if (root == NULL) {
        return;
    }
    printPostorderTraversal(root->left);
    printPostorderTraversal(root->right);
    cout << root->data << " ";
}

void printPreorderTraversal(node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    printPreorderTraversal(root->left);
    printPreorderTraversal(root->right);
}

int main() {
    node* root = NULL;

    cout << "Enter the value of root node: ";
    root = buildTree();

    cout << "Level Traversal" << endl;
    printLevelOrderTraversal(root);

    cout << "Inorder Traversal" << endl;
    printInorderTraversal(root);
    cout << endl;

    cout << "Preorder Traversal" << endl;
    printPreorderTraversal(root);
    cout << endl;

    cout << "Postorder Traversal" << endl;
    printPostorderTraversal(root);
    cout << endl;

    return 0;
}
