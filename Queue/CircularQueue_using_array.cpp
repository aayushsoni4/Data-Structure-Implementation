#include <iostream>
using namespace std;

class CircularQueue {
private:
    int *arr;
    int front;
    int rear;
    int size;

public:
    CircularQueue(int size) {
        this->size = size;
        arr = new int[size];
        front = rear = -1;
    }

    void push(int element) {
        if ((front == 0 && rear == size - 1) || ((rear + 1) % size == front)) {
            cout << "Queue Overflow" << endl;
        } else if (front == -1) {
            front = rear = 0;
            arr[rear] = element;
        } else if (rear == size - 1 && front != 0) {
            rear = 0;
            arr[rear] = element;
        } else {
            rear = (rear + 1) % size;
            arr[rear] = element;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
        } else if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }

    bool isEmpty() {
        return front == -1;
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return -1;
        } else {
            return arr[front];
        }
    }

    ~CircularQueue() {
        delete[] arr;
    }
};

int main() {
    CircularQueue queue(5);
    
    queue.push(1);
    queue.push(2);
    queue.push(3);

    cout << "Front element: " << queue.getFront() << endl;

    queue.pop();
    cout << "Front element after pop: " << queue.getFront() << endl;

    return 0;
}
