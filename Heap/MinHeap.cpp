#include <bits/stdc++.h>
using namespace std;

class MinHeap {
public:
    int size;
    int *arr;

    MinHeap() {
        size = 0;
        arr = new int[200000];
    }

    void insert(int val) {
        size++;
        arr[size] = val;
        int k = size;
        while (k > 1) {
            int parent = k / 2;
            if (arr[parent] > arr[k]) {
                swap(arr[parent], arr[k]);
                k = parent;
            } else {
                break;
            }
        }
    }

    bool isEmpty() {
        return size == 0;
    }

    int top() {
        if (isEmpty()) {
            return INT_MAX;
        }
        return arr[1];
    }

    void pop() {
        if (isEmpty()) {
            return;
        }
        swap(arr[1], arr[size]);
        size--;
        heapify(1);
    }

    void heapify(int i) {
        int largest = i;
        int leftChild = 2 * i;
        int rightChild = 2 * i + 1;

        if (leftChild <= size && arr[leftChild] < arr[largest]) {
            largest = leftChild;
        }

        if (rightChild <= size && arr[rightChild] < arr[largest]) {
            largest = rightChild;
        }

        if (i != largest) {
            swap(arr[i], arr[largest]);
            heapify(largest);
        }
    }

    ~MinHeap() {
        delete[] arr;
    }
};

int main() {
    MinHeap h;
    h.insert(10);
    h.insert(1);
    h.insert(11);
    h.insert(6);
    h.insert(60);
    h.insert(20);

    cout << "Min Heap elements: ";
    while (!h.isEmpty()) {
        cout << h.top() << " ";
        h.pop();
    }

    cout << endl;

    return 0;
}
