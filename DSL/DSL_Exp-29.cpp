/*
Queues are frequently used in computer programming, and a typical example is the creation 
of a job queue by an operating system. If the operating system does not use priorities, 
then the jobs are processed in the order they enter the system. Write C++ program for 
simulating job queue. Write functions to add job and delete job from queue.
*/


#include <iostream>
#define MAX 10
using namespace std;

struct queue {
    int data[MAX];
    int front, rear;
};

class Queue {
    struct queue q;

public:
    Queue() {
        q.front = q.rear = -1;
    }

    bool isempty() {
        return (q.front == q.rear);
    }

    bool isfull() {
        return (q.rear == MAX - 1);
    }

    void enqueue(int x) {
        if (isfull()) {
            cout << "\nQueue Overflow! Cannot add more elements.\n";
        } else {
            q.data[++q.rear] = x;
            cout << x << " added to the queue.\n";
        }
    }

    int delqueue() {
        if (isempty()) {
            cout << "\nQueue Underflow! No elements to remove.\n";
            return -1;
        } else {
            int removed = q.data[++q.front];
            cout << removed << " removed from the queue.\n";

            if (q.front == q.rear) {
                q.front = q.rear = -1;
            }
            return removed;
        }
    }

    void display() {
        if (isempty()) {
            cout << "\nQueue is empty.\n";
        } else {
            cout << "\nQueue contains: ";
            for (int i = q.front + 1; i <= q.rear; i++) {
                cout << q.data[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Queue obj;
    int choice, x;

    do {
        cout << "\n================= MENU =================";
        cout << "\n 1. Insert Job";
        cout << "\n 2. Delete Job";
        cout << "\n 3. Display Jobs";
        cout << "\n 4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert: ";
                cin >> x;
                obj.enqueue(x);
                break;

            case 2:
                obj.delqueue();
                break;

            case 3:
                obj.display();
                break;

            case 4:
                cout << "\nExiting program. Goodbye!\n";
                break;

            default:
                cout << "\nInvalid choice! Please enter a number between 1 and 4.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}