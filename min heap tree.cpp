#include <iostream>
using namespace std;

#define MAX 100

class MinHeap {
    int arr[MAX];
    int size;

public:
    MinHeap() {
        size = 0;
    }

    // Insert an element
    void insert(int val) {
        if (size >= MAX) {
            cout << "Heap is full!\n";
            return;
        }

        // Add to the end
        arr[size] = val;
        int i = size;
        size++;

        // Fix the min-heap property by moving up
        while (i != 0 && arr[(i - 1) / 2] > arr[i]) {
            swap(arr[i], arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    // Display the heap as array
    void display() {
        cout << "Heap array:\n";
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    // Remove and return minimum (root)
    int removeMin() {
        if (size <= 0)
            return -1;

        if (size == 1) {
            size--;
            return arr[0];
        }

        int root = arr[0];
        arr[0] = arr[size - 1];
        size--;

        heapify(0);
        return root;
    }

private:
    // Heapify (min-heap) from given index
    void heapify(int i) {
        int smallest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if (left < size && arr[left] < arr[smallest])
            smallest = left;

        if (right < size && arr[right] < arr[smallest])
            smallest = right;

        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            heapify(smallest);
        }
    }
};

int main() {
    MinHeap heap;
    int n, val;

    cout << "Enter number of elements to insert: ";
    cin >> n;

    cout << "Enter values:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        heap.insert(val);
    }

    heap.display();

    cout << "\nMinimum value removed: " << heap.removeMin() << endl;

    cout << "\nHeap after removal:\n";
    heap.display();

    return 0;
}
