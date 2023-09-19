#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int size;
    int front;
    int rear;

public:
    Queue(int size) {
        this->size = size;
        this->front = -1;
        this->rear = -1;
        arr = new int[size];
    }

    void insert(int element) {
        if (rear == size - 1) {
            cout << "Queue Overflow" << endl;
        } else {
            if (front == -1) {
                front = 0;
            }
            rear++;
            arr[rear] = element;
        }
    }

    void pop() {
        if (front == -1) {
            cout << "Queue Underflow" << endl;
        } else {
            front++;
            if (front > rear) {
                front = -1;
                rear = -1;
            }
        }
    }

    int getFront() {
        if (front == -1) {
            cout << "Queue is Empty" << endl;
            return -1;
        } else {
            return arr[front];
        }
    }

    bool isEmpty() {
        return front == -1;
    }

    ~Queue() {
        delete[] arr;
    }
};

int main() {
    Queue q(5);

    if(q.isEmpty()){
        cout << "Queue is empty" << endl;
    }
    else{
        cout << "Queue is not Empty" << endl;
    }
    q.insert(5);
    q.insert(10);
    q.insert(15);

    cout << q.getFront() << endl;

    q.pop();
    cout << q.getFront() << endl;

    q.pop();
    cout << q.getFront() << endl;

    q.pop();

    return 0;
}
