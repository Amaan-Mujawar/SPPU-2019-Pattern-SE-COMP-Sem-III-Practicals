/*
A double-ended queue (deque) is a linear list in which additions and deletions may be
made at either end. Obtain a data representation mapping a deque into a one
dimensional array. Write C++ program to simulate deque with functions to add and
delete elements from either end of the deque.
*/


#include <iostream>
#define MAX 10
using namespace std;

struct que {
    int arr[MAX];
    int front, rear;
};

void init(struct que* q) {
    q->front = -1;
    q->rear = -1;
}

void print(struct que q) {
    if (q.front == -1) {
        cout << "Queue is empty!" << endl;
        return;
    }
    int i = q.front;
    cout << "Queue elements: ";
    while (i != q.rear) {
        cout << q.arr[i] << " ";
        i = (i + 1) % MAX;
    }
    cout << q.arr[q.rear] << endl;
}

int isempty(struct que q) {
    return q.front == -1;
}

int isfull(struct que q) {
    return (q.rear + 1) % MAX == q.front;
}

void addf(struct que* q, int data) {
    if (isfull(*q)) {
        cout << "Queue Overflow! Cannot add element at the front.\n";
        return;
    }
    if (isempty(*q)) {
        q->front = q->rear = 0;
    } else {
        q->front = (q->front - 1 + MAX) % MAX;
    }
    q->arr[q->front] = data;
    cout << data << " added at the front.\n";
}

void addr(struct que* q, int data) {
    if (isfull(*q)) {
        cout << "Queue Overflow! Cannot add element at the rear.\n";
        return;
    }
    if (isempty(*q)) {
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX;
    }
    q->arr[q->rear] = data;
    cout << data << " added at the rear.\n";
}

int delf(struct que* q) {
    if (isempty(*q)) {
        cout << "Queue Underflow! No elements to delete from the front.\n";
        return -1;
    }
    int data = q->arr[q->front];
    if (q->front == q->rear) {
        init(q);
    } else {
        q->front = (q->front + 1) % MAX;
    }
    return data;
}

int delr(struct que* q) {
    if (isempty(*q)) {
        cout << "Queue Underflow! No elements to delete from the rear.\n";
        return -1;
    }
    int data = q->arr[q->rear];
    if (q->front == q->rear) {
        init(q);
    } else {
        q->rear = (q->rear - 1 + MAX) % MAX;
    }
    return data;
}

int main() {
    struct que q;
    int data, ch;

    init(&q);

    do {
        cout << "\n======== MENU ========\n";
        cout << "1. Insert at Front\n";
        cout << "2. Insert at Rear\n";
        cout << "3. Delete from Front\n";
        cout << "4. Delete from Rear\n";
        cout << "5. Print Queue\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter data to insert at the front: ";
                cin >> data;
                addf(&q, data);
                break;

            case 2:
                cout << "Enter data to insert at the rear: ";
                cin >> data;
                addr(&q, data);
                break;

            case 3:
                data = delf(&q);
                if (data != -1)
                    cout << "Deleted from front: " << data << endl;
                break;

            case 4:
                data = delr(&q);
                if (data != -1)
                    cout << "Deleted from rear: " << data << endl;
                break;

            case 5:
                print(q);
                break;

            case 6:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (ch != 6);

    return 0;
}