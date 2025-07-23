#include <iostream>
using namespace std;

const int SIZE = 10;

class HashTable {
private:
    int table[SIZE];

public:
    HashTable() {
        for (int i = 0; i < SIZE; i++)
            table[i] = -1; // -1 indicates empty slot
    }

    // Hash function
    int hashFunction(int key) {
        return key % SIZE;
    }

    // Insert using linear probing
    void insert(int key) {
        int index = hashFunction(key);

        // Linear probing
        int startIndex = index;
        while (table[index] != -1) {
            index = (index + 1) % SIZE;
            if (index == startIndex) {
                cout << "Hash table is full!\n";
                return;
            }
        }

        table[index] = key;
    }

    // Search for a key
    bool search(int key) {
        int index = hashFunction(key);
        int startIndex = index;

        while (table[index] != -1) {
            if (table[index] == key)
                return true;
            index = (index + 1) % SIZE;
            if (index == startIndex)
                break;
        }

        return false;
    }

    // Display the table
    void display() {
        cout << "Hash Table:\n";
        for (int i = 0; i < SIZE; i++) {
            cout << i << " --> ";
            if (table[i] != -1)
                cout << table[i];
            else
                cout << "EMPTY";
            cout << endl;
        }
    }
};

int main() {
    HashTable ht;
    int n, value;

    cout << "Enter number of elements to insert: ";
    cin >> n;

    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        ht.insert(value);
    }

    ht.display();

    cout << "\nEnter value to search: ";
    cin >> value;
    if (ht.search(value))
        cout << value << " found in hash table.\n";
    else
        cout << value << " not found in hash table.\n";

    return 0;
}
