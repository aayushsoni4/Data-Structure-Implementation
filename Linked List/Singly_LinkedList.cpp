#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void InsertAtHead(Node* &head, int key){

    Node* temp = new Node(key);
    temp->next = head;
    head = temp;

}

void InsertAtTail(Node* &head, int key){

    Node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = new Node(key);
}

void InsertAtPosition(Node* &head, int key, int pos){

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

void print(Node* head){
    while(head!=NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}



int main (){
    Node* node = new Node(1);

    InsertAtHead(node,2);
    InsertAtHead(node,3);

    print(node);

    InsertAtTail(node,4);
    InsertAtTail(node,5);

    print(node);

    InsertAtPosition(node,6,10);

    print(node);
}