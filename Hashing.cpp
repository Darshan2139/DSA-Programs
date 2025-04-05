#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;
bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int nextPrime(int size) {
    while (!isPrime(size)) {
        ++size;
    }
    return size;
}

struct Node {
    int studentID;
    int score;
    Node(int id, int s) : studentID(id), score(s) {}
};


class HashTable {
private:
    vector<list<Node>> chainTable;
    vector<pair<int, int>> probeTable;
    int tableSize;

    int hashFunction(int key) {
        return key % tableSize;
    }

public:
    HashTable(int initialSize) {
        tableSize = nextPrime(initialSize);
        chainTable.resize(tableSize);
        probeTable.resize(tableSize, {-1, -1});  // Initialize with -1 for empty slots
    }


    void insertItemChaining(int studentID, int score) {
        int index = hashFunction(studentID);
        chainTable[index].emplace_back(studentID, score);
    }

    void insertItemProbing(int studentID, int score) {
        int index = hashFunction(studentID);
        while (probeTable[index].first != -1) {
            index = (index + 1) % tableSize; // Linear probing
        }
        probeTable[index] = {studentID, score};
    }

    void deleteItemChaining(int studentID) {
        int index = hashFunction(studentID);
        auto& chain = chainTable[index];
        chain.remove_if([studentID](const Node& node) { return node.studentID == studentID; });
    }

    void deleteItemProbing(int studentID) {
        int index = hashFunction(studentID);
        while (probeTable[index].first != -1) {
            if (probeTable[index].first == studentID) {
                probeTable[index] = {-1, -1}; // Mark as deleted
                return;
            }
            index = (index + 1) % tableSize;
        }
    }

    void displayChaining() {
        cout << "Hash Table (Separate Chaining):" << endl;
        for (int i = 0; i < tableSize; ++i) {
            cout << i << ": ";
            for (const auto& node : chainTable[i]) {
                cout << "{" << node.studentID << ", " << node.score << "} -> ";
            }
            cout << "null" << endl;
        }
    }

    void displayProbing() {
        cout << "Hash Table (Linear Probing):" << endl;
        for (int i = 0; i < tableSize; ++i) {
            if (probeTable[i].first != -1) {
                cout << i << ": {" << probeTable[i].first << ", " << probeTable[i].second << "}" << endl;
            } else {
                cout << i << ": null" << endl;
            }
        }
    }
};

int main() {
    HashTable hashTable(6);
    hashTable.insertItemChaining(231, 123);
    hashTable.insertItemChaining(326, 432);
    hashTable.insertItemChaining(212, 523);
    hashTable.insertItemChaining(321, 43);
    hashTable.insertItemChaining(433, 423);
    hashTable.insertItemChaining(262, 111);

    hashTable.displayChaining();
    hashTable.deleteItemChaining(212);
    hashTable.displayChaining();
    hashTable.insertItemProbing(231, 123);
    hashTable.insertItemProbing(326, 432);
    hashTable.insertItemProbing(212, 523);
    hashTable.insertItemProbing(321, 43);
    hashTable.insertItemProbing(433, 423);
    hashTable.insertItemProbing(262, 111);
    hashTable.displayProbing();
    hashTable.deleteItemProbing(212);
    hashTable.displayProbing();
    cout<<"prepared by 23CE051 Darshan";
    return 0;
}
