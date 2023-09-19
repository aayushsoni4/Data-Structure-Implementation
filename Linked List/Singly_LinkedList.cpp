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

int main (){
    Node* node = new Node(1);
    Node* temp = node;

    temp->next = new Node(2);
    temp = temp->next;

    temp->next = new Node(3);
    temp = temp->next;

    temp->next = new Node(4);
    temp = temp->next;

    temp = node;

    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    
}