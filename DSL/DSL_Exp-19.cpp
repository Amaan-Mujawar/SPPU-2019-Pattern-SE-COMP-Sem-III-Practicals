/*
Department of Computer Engineering has student's club named 'Pinnacle Club'. Students
of second, third and final year of department can be granted membership on request.
Similarly one may cancel the membership of club. First node is reserved for president of
club and last node is reserved for secretary of club. Write C++ program to maintain club
member‘s information using singly linked list. Store student PRN and Name. Write
functions to:
a) Add and delete the members as well as president or even secretary.
b) Compute total number of members of club
c) Display members
d) Two linked lists exists for two divisions. Concatenate two lists.
*/


#include <iostream>
using namespace std;

class node {
private:
    char name[10];
    long prn;
    node* next;

public:
    node() {
        prn = 0;
        next = NULL;
    }
    friend class list;
};

class list {
private:
    node* president;
    node* secretary;
    node* current;

    int count;

public:
    list() {
        president = NULL;
        secretary = NULL;
        current = NULL;
        count = 0;
    }

    void gethead();
    void gettail();
    void addmember();
    void displaylist();
    void remove();
    void display_count();
    void display_reverse(node* head);

    node* getPresident() {
        return president;
    }
};

void list::gethead() {
    count++;
    president = new node;
    cout << "Enter Name of President:" << endl;
    cin >> president->name;
    cout << "Enter PRN of President:" << endl;
    cin >> president->prn;
    president->next = NULL;
    secretary = president;
}

void list::gettail() {
    if (president == NULL) {
        cout << "Please enter President first." << endl;
        return;
    }
    count++;
    secretary = new node;
    cout << "Enter the name of the Secretary:" << endl;
    cin >> secretary->name;
    cout << "Enter PRN of Secretary:" << endl;
    cin >> secretary->prn;
    secretary->next = NULL;
    president->next = secretary;
}

void list::addmember() {
    if (president == NULL || secretary == NULL) {
        cout << "Please initialize President and Secretary first." << endl;
        return;
    }

    count++;
    node* tmp = new node;
    cout << "Enter Member name:\n";
    cin >> tmp->name;
    cout << "Enter PRN of Member:\n";
    cin >> tmp->prn;

    if (tmp->prn < president->prn) {
        tmp->next = president;
        president = tmp;
    } else if (tmp->prn > secretary->prn) {
        secretary->next = tmp;
        tmp->next = NULL;
        secretary = tmp;
    } else {
        current = president;
        while (current->next != NULL && current->next->prn < tmp->prn) {
            current = current->next;
        }
        tmp->next = current->next;
        current->next = tmp;
    }
}

void list::display_count() {
    cout << "Member count: " << count << endl;
}

void list::displaylist() {
    current = president;
    if (current == NULL) {
        cout << "List is empty!" << endl;
        return;
    }
    cout << "Members of the List:\n";
    while (current != NULL) {
        cout << "Name: " << current->name << ", PRN: " << current->prn << endl;
        current = current->next;
    }
}

void list::remove() {
    if (count == 0 || president == NULL) {
        cout << "Error, Underflow!" << endl;
        return;
    }
    long pno;
    cout << "Enter the PRN of the member to be removed:" << endl;
    cin >> pno;

    if (pno == president->prn) {
        node* tmp = president;
        president = president->next;
        delete tmp;
        count--;
        if (president == NULL) secretary = NULL;
        return;
    }

    current = president;
    while (current->next != NULL && current->next->prn != pno) {
        current = current->next;
    }

    if (current->next == NULL) {
        cout << "Member Not Found!" << endl;
        return;
    }

    node* tmp = current->next;
    current->next = current->next->next;

    if (tmp == secretary) secretary = current;
    delete tmp;
    count--;
}

void list::display_reverse(node* head) {
    if (head == NULL) {
        return;
    }
    display_reverse(head->next);
    cout << "Name: " << head->name << ", PRN: " << head->prn << endl;
}

int main() {
    list a;
    a.gethead();
    a.gettail();

    int c = 0, bl = 1;

    while (bl) {
        cout << "\nEnter Choice:\n";
        cout << "1. Add Member\n2. Delete Member\n3. Display No of Members\n";
        cout << "4. Display Members\n5. Display in Reverse\n6. Exit\n";
        cin >> c;

        switch (c) {
        case 1:
            a.addmember();
            break;
        case 2:
            a.remove();
            break;
        case 3:
            a.display_count();
            break;
        case 4:
            a.displaylist();
            break;
        case 5:
            cout << "Members in Reverse Order:\n";
            a.display_reverse(a.getPresident());
            break;
        case 6:
            bl = 0;
            break;
        default:
            cout << "Wrong choice!" << endl;
            break;
        }
    }

    cout << "Thanks for using the program!\n";
    return 0;
}
