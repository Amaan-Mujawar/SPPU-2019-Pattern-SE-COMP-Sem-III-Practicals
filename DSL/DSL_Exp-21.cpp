/*
Write C++ program for storing appointment schedule for day. Appointments are booked
randomly using linked list. Set start and end time and min and max duration for visit 
slot. Write functions for-
A) Display free slots 
B) Book appointment 
C) Sort list based on time
D) Cancel appointment(check validity, time bounds, availability)
E) Sort list based on time using pointer manipulation
*/


#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Node {
    int start_time;
    int end_time;
    Node* next;

    Node(int start, int end) {
        start_time = start;
        end_time = end;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    void displayFreeSlots(int day_start, int day_end) {
        if (!head) {
            cout << "All slots are free from " << day_start << " to " << day_end << endl;
            return;
        }

        Node* temp = head;
        int prev_end = day_start;

        do {
            if (prev_end < temp->start_time) {
                cout << "Free slot: " << prev_end << " to " << temp->start_time << endl;
            }
            prev_end = temp->end_time;
            temp = temp->next;
        } while (temp != head);

        if (prev_end < day_end) {
            cout << "Free slot: " << prev_end << " to " << day_end << endl;
        }
    }

    void bookAppointment(int start, int duration, int day_start, int day_end) {
        int end = start + duration;
        if (start < day_start || end > day_end || duration <= 0) {
            cout << "Invalid appointment time." << endl;
            return;
        }

        Node* new_node = new Node(start, end);

        if (!head) {
            head = new_node;
            head->next = head;
            cout << "Appointment booked successfully from " << start << " to " << end << endl;
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;
        do {
            if ((start >= temp->end_time && (!temp->next || end <= temp->next->start_time)) ||
                (temp == head && (start < head->start_time))) {
                break;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);

        if ((prev && start < prev->end_time) || (temp && end > temp->start_time)) {
            cout << "Cannot book appointment. Slot overlaps with an existing appointment." << endl;
            delete new_node;
            return;
        }

        if (prev) {
            new_node->next = prev->next;
            prev->next = new_node;
        } else {
            new_node->next = head;
            head = new_node;
        }

        cout << "Appointment booked successfully from " << start << " to " << end << endl;
    }

    void sortAppointments() {
        if (!head || head->next == head) {
            return;
        }

        Node* sorted = nullptr;
        Node* current = head;
        Node* next_node;

        do {
            next_node = current->next;
            if (!sorted || current->start_time < sorted->start_time) {
                current->next = sorted;
                sorted = current;
            } else {
                Node* temp = sorted;
                while (temp->next && temp->next->start_time < current->start_time) {
                    temp = temp->next;
                }
                current->next = temp->next;
                temp->next = current;
            }
            current = next_node;
        } while (current != head);

        head = sorted;
    }

    void cancelAppointment(int start, int end) {
        if (!head) {
            cout << "No appointments to cancel." << endl;
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;

        do {
            if (temp->start_time == start && temp->end_time == end) {
                if (temp == head) {
                    if (head->next == head) {
                        delete head;
                        head = nullptr;
                    } else {
                        Node* last = head;
                        while (last->next != head) {
                            last = last->next;
                        }
                        head = head->next;
                        last->next = head;
                        delete temp;
                    }
                } else {
                    prev->next = temp->next;
                    delete temp;
                }
                cout << "Appointment from " << start << " to " << end << " cancelled successfully." << endl;
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);

        cout << "No matching appointment found to cancel." << endl;
    }

    ~CircularLinkedList() {
        if (!head) return;

        Node* temp = head;
        do {
            Node* next_node = temp->next;
            delete temp;
            temp = next_node;
        } while (temp != head);

        head = nullptr;
    }
};

int main() {
    CircularLinkedList schedule;
    int day_start = 9;
    int day_end = 17;
    int choice;

    do {
        cout << "\n--- Appointment Scheduler ---\n";
        cout << "1. Display free slots\n";
        cout << "2. Book appointment\n";
        cout << "3. Sort appointments\n";
        cout << "4. Cancel appointment\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                schedule.displayFreeSlots(day_start, day_end);
                break;
            case 2: {
                int start, duration;
                cout << "Enter start time and duration: ";
                cin >> start >> duration;
                schedule.bookAppointment(start, duration, day_start, day_end);
                break;
            }
            case 3:
                schedule.sortAppointments();
                cout << "Appointments sorted successfully." << endl;
                break;
            case 4: {
                int start, end;
                cout << "Enter start time and end time of the appointment to cancel: ";
                cin >> start >> end;
                schedule.cancelAppointment(start, end);
                break;
            }
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);

    return 0;
}