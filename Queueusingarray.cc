#include <iostream>
using namespace std;

class Queue {
private:
    int front, rear, size;
    int* queue;
public:
    Queue(int s) {
        front = rear = -1;
        size = s;
        queue = new int[s];
    }

    ~Queue() {
        delete[] queue;
    }

    void enqueue(int value) {
        if (rear == size - 1) {
            cout << "Queue is full\n";
            return;
        }
        if (front == -1) front = 0;
        queue[++rear] = value;
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Removed " << queue[front++] << "\n";
        if (front > rear) front = rear = -1;
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty\n";
            return;
        }
        for (int i = front; i <= rear; i++)
            cout << queue[i] << " ";
        cout << "\n";
    }
};

int main() {
    int size, choice, value;
    cout << "Enter the size of the queue: ";
    cin >> size;

    Queue q(size);

    while (true) {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid choice\n";
        }
    }

    return 0;
}
