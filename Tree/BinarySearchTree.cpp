#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

node* insertIntoBST(node* root, int val) {
    if (root == NULL) {
        return new node(val);
    }

    if (val < root->data) {
        root->left = insertIntoBST(root->left, val);
    } else if (val > root->data) {
        root->right = insertIntoBST(root->right, val);
    }

    return root;
}

bool search(node* root, int val) {
    if (root == NULL) {
        return false;
    }

    if (val == root->data) {
        return true;
    } else if (val < root->data) {
        return search(root->left, val);
    } else {
        return search(root->right, val);
    }
}

void inorderTraversal(node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

node* inorderSuccsessor(node* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

void levelOrderTraversal(node* root){
    if(root==NULL) {
        return;
    }

    queue<node*>q;
    q.push(root);
    while(!q.empty()) {
        int n = q.size();
        for(int i=0;i<n;i++){
            node* temp = q.front();
            q.pop();
            cout << temp->data << " ";
            if(temp->left!=NULL) {
                q.push(temp->left);
            }
            if(temp->right!=NULL) {
                q.push(temp->right);
            }
        }
        cout << endl;
    }
}

node* deleteNode(node* root, int val) {
    if(root==NULL) {
        return root;
    }

    if(val<root->data) {
        root->left = deleteNode(root->left, val);
    }
    else if(val>root->data) {
        root->right = deleteNode(root->right, val);
    }
    else {
        if(root->left == NULL) {
            node* temp = root->right;
            delete root;
            return temp;
        } 
        else if (root->right == NULL) {
            node* temp = root->left;
            delete root;
            return temp;
        }

        node* temp = inorderSuccsessor(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    node* root = NULL;
    root = insertIntoBST(root, 50);
    insertIntoBST(root, 30);
    insertIntoBST(root, 70);
    insertIntoBST(root, 20);
    insertIntoBST(root, 40);
    insertIntoBST(root, 35);
    insertIntoBST(root, 45);
    insertIntoBST(root, 60);
    insertIntoBST(root, 80);

    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    int searchValue = 40;
    if (search(root, searchValue)) {
        cout << searchValue << " is found in the BST." << endl;
    }
    else {
        cout << searchValue << " is not found in the BST." << endl;
    }
    
    cout << "Level Order Traversal before deletion: " << endl;
    levelOrderTraversal(root);
    cout << endl;

    deleteNode(root,30);

    cout << "Level Order Traversal after deletion: " << endl;
    levelOrderTraversal(root);
    cout << endl;

    return 0;
}
