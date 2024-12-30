/*
Develop a program in C++ to create a database of student’s information system containing the 
following information: Name, Roll number, Class, Division, Date of Birth, Blood group, contact 
address, Telephone number, Driving license no. and other. Construct the database with 
suitable member functions. Make use of constructor, default constructor, copy constructor, 
destructor, static member functions, friend class, this pointer, inline code and dynamic 
memory allocation operators-new and delete as well as exception handling.
*/


#include <iostream>
#include <cstring>
using namespace std;

class Person {
    char name[50], dob[10], bg[5];
    int h, w;

public:
    static int count;
    friend class Personal;

    Person() {
        strcpy(name, "");
        strcpy(dob, "");
        strcpy(bg, "");
        h = w = 0;
    }

    static void recordcount() {
        cout << "\n\nTotal Number of Records: " << count << endl;
    }
};

class Personal {
    char add[70], num[15], policy_num[15], driv_licno[15];

public:
    Personal() {
        strcpy(add, "");
        strcpy(num, "");
        strcpy(policy_num, "");
        strcpy(driv_licno, "");
    }

    void getdata(Person *P1);
    void display(const Person *P1) const;
    friend class Person;
};

int Person::count = 0;

void Personal::getdata(Person *P1) {
    cout << "\nEnter Name: ";
    cin.ignore();
    cin.getline(P1->name, 50);
    cout << "\nEnter DOB in DD/MM/YYYY format: ";
    cin >> P1->dob;
    cout << "\nEnter Blood Group: ";
    cin >> P1->bg;
    cout << "\nEnter Height (in cm): ";
    cin >> P1->h;
    cout << "\nEnter Weight (in kg): ";
    cin >> P1->w;
    cout << "\nEnter Address: ";
    cin.ignore();
    cin.getline(this->add, 70);
    cout << "\nEnter Phone Number: ";
    cin >> this->num;
    cout << "\nEnter Policy Number: ";
    cin >> this->policy_num;
    cout << "\nEnter Driving License Number: ";
    cin >> this->driv_licno;
    Person::count++;
}

void Personal::display(const Person *P1) const {
    cout << "\n" << P1->name << "\t" << P1->dob << "\t" << P1->bg << "\t" << P1->h << "\t" << P1->w << "\t" << this->num << "\t" << this->policy_num << "\t" << this->driv_licno << "\t" << this->add;
}

int main() {
    int n = 0, ch, i;
    Personal *p1[30];
    Person *p2[30];

    while (true) {
        cout << "\n\n---MENU---\n";
        cout << "1. Enter Data\n";
        cout << "2. Display Data\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            cout << "\nPlease Enter The Following Information: ";
            p1[n] = new Personal;
            p2[n] = new Person;
            p1[n]->getdata(p2[n]);
            n++;
            Person::recordcount();
            break;

        case 2:
            cout << "\nNAME\tDOB\tBLOOD GROUP\tHEIGHT\tWEIGHT\tPHONE NUMBER\tPOLICY NO.\tDRIVING LICENSE NO.\tADDRESS\n";
            for (i = 0; i < n; i++) {
                p1[i]->display(p2[i]);
            }
            Person::recordcount();
            break;

        case 3:
            cout << "Exiting the program. Goodbye!\n";
            for (i = 0; i < n; i++) {
                delete p1[i];
                delete p2[i];
            }
            return 0;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
