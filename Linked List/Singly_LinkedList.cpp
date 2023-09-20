#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node() {
        int value = this->data;
        if (this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is freed for node with data " << value << endl;
    }
};

void InsertAtHead(Node* &head, int key) {
    Node* temp = new Node(key);
    temp->next = head;
    head = temp;
}

void InsertAtTail(Node* &head, int key) {
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new Node(key);
}

void InsertAtPosition(Node* &head, int key, int pos) {
    if (pos < 1) {
        cout << "Invalid position. Node not inserted." << endl;
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while (cnt < pos - 1 && temp != NULL) {
        temp = temp->next;
        cnt += 1;
    }

    if (temp == NULL) {
        InsertAtTail(head, key);
        return;
    }

    Node* nodeToInsert = new Node(key);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteNode(int pos, Node*& head) {
    if (pos < 1) {
        cout << "Invalid position. Node not deleted." << endl;
        return;
    }

    if (pos == 1) {
        Node* temp = head;
        if (head != NULL) {
            head = head->next;
            temp->next = NULL;
            delete temp;
        } 
        else {
            cout << "List is empty. Node not deleted." << endl;
        }
    } 
    else {
        Node* prev = NULL;
        Node* curr = head;
        int cnt = 1;

        while (cnt < pos && curr != NULL) {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        if (curr == NULL) {
            cout << "Position is out of range. Node not deleted." << endl;
        } 
        else {
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
        }
    }
}

void deleteNodeWithValue(int value, Node*& head) {
    Node* prev = NULL;
    Node* curr = head;

    while (curr != NULL && curr->data != value) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        cout << "Node with value " << value << " not found." << endl;
    } 
    else {
        if (prev == NULL) {
            head = curr->next;
        } 
        else {
            prev->next = curr->next;
        }
        curr->next = NULL;
        delete curr;
    }
}

void print(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* node = new Node(1);

    InsertAtHead(node, 2);
    InsertAtHead(node, 3);

    print(node);

    InsertAtTail(node, 4);
    InsertAtTail(node, 5);

    print(node);

    InsertAtPosition(node, 6, 10);
    InsertAtPosition(node, 20, 100);

    print(node);

    deleteNode(2, node);
    print(node);

    return 0;
}
