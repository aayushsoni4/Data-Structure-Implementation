#include <iostream>
using namespace std;

class Deque {
private:
    int* arr;
    int front;
    int rear;
    int size;

public:
    Deque(int size) {
        this->size = size;
        front = rear = -1;
        arr = new int[size];
    }

    void pushFront(int element) {
        if ((front == 0 && rear == size - 1) || (front == rear + 1)) {
            cout << "Queue Overflow" << endl;
        } 
        else if (front == -1) {
            front = rear = 0;
        } 
        else if (front == 0) {
            front = size - 1;
        } 
        else {
            front--;
        }
        arr[front] = element;
    }

    void pushRear(int element) {
        if ((front == 0 && rear == size - 1) || (front == rear + 1)) {
            cout << "Queue Overflow" << endl;
        } 
        else if (front == -1) {
            front = rear = 0;
        } 
        else if (rear == size - 1) {
            rear = 0;
        } 
        else {
            rear++;
        }
        arr[rear] = element;
    }

    void popFront() {
        if (front == -1) {
            cout << "Queue Underflow" << endl;
        }
        else if (front == rear) {
            front = rear = -1;
        } 
        else if (front == size - 1) {
            front = 0;
        } 
        else {
            front++;
        }
    }

    void popRear() {
        if (front == -1) {
            cout << "Queue Underflow" << endl;
        } 
        else if (front == rear) {
            front = rear = -1;
        } 
        else if (rear == 0) {
            rear = size - 1;
        } 
        else {
            rear--;
        }
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return arr[rear];
    }

    bool isEmpty() {
        return front == -1;
    }

    ~Deque() {
        delete[] arr;
    }
};

int main() {
    Deque deque(5);

    deque.pushFront(1);
    deque.pushRear(2);
    deque.pushFront(3);

    cout << "Front element: " << deque.getFront() << endl;
    cout << "Rear element: " << deque.getRear() << endl;

    deque.popFront();
    deque.popRear();

    cout << "Front element after pop: " << deque.getFront() << endl;
    cout << "Rear element after pop: " << deque.getRear() << endl;

    return 0;
}
