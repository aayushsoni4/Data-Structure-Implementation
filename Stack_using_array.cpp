#include <bits/stdc++.h>
using namespace std;

class Stack{

private:
    int *arr;
    int top;
    int size;

public:
    Stack(int size){
        this->size = size;
        this->arr = new int[size];
        this->top=-1;
    }

    void push(int element){
        if(this->top==this->size-1){
            cout << "Stack Overflow" << endl;
        }
        else{
            this->top++;
            arr[top]=element;
        }
    }

    void pop(){
        if(this->top!=-1){
            this->top--;
        }
        else{
            cout << "Stack Underflow" << endl;
        }
    }

    int peek(){
        if(this->top!=-1){
            return arr[this->top];
        }
        else{
            cout << "Stack is Empty" << endl;
            return -1;
        }
    }

    bool isEmpty(){
        if(this->top!=-1){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){
    Stack st(5);
    
    st.push(10);
    st.push(100);
    st.push(1000);

    cout << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;
    
    if(st.isEmpty()){
        cout << "Stack is Empty" << endl;
    }    
    else{
        cout << "Stack is not Empty" << endl;
    }

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
}