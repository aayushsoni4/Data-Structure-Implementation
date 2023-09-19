#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    ~Node() {
        int value = this->data;
        if (this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        if (this->prev != NULL) {
            delete prev;
            this->prev = NULL;
        }
        cout << "Memory is freed for node with data " << value << endl;
    }
};

void InsertAtHead(Node* &head, int key) {
    Node* temp = new Node(key);
    temp->next = head;
    if (head != NULL) {
        head->prev = temp;
    }
    head = temp;
}

void InsertAtTail(Node* &head, int key) {
    Node* temp = head;
    Node* newNode = new Node(key);
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
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
    if (temp->next != NULL) {
        temp->next->prev = nodeToInsert;
    }
    nodeToInsert->prev = temp;
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
            if (head != NULL) {
                head->prev = NULL;
            }
            temp->next = NULL;
            delete temp;
        } 
        else {
            cout << "List is empty. Node not deleted." << endl;
        }
    } 
    else {
        Node* curr = head;
        int cnt = 1;

        while (cnt < pos && curr != NULL) {
            curr = curr->next;
            cnt++;
        }

        if (curr == NULL) {
            cout << "Position is out of range. Node not deleted." << endl;
        } 
        else {
            if (curr->prev != NULL) {
                curr->prev->next = curr->next;
            }
            if (curr->next != NULL) {
                curr->next->prev = curr->prev;
            }
            curr->next = NULL;
            curr->prev = NULL;
            delete curr;
        }
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

    print(node);

    deleteNode(2, node);
    print(node);

    return 0;
}
