/*
Write a Python program to store marks scored in subject “Fundamental of Data Structure” 
by N students in the class. Write functions to compute following:
a) Theaverage score of class
b) Highest score and lowest score of class
c) Count of students who were absent for the test
d) Display mark with highest frequency
*/


def average(listofmarks):
    total = 0
    count = 0
    for i in range(len(listofmarks)):
        if listofmarks[i] != -1:
            total += listofmarks[i]
            count += 1
    avg = total / count
    print("Total marks: ", total)
    print("Average marks: {:.2f}".format(avg))

def maximum(listofmarks):
    for i in range(len(listofmarks)):
        if listofmarks[i] != -1:
            max_marks = listofmarks[0]
            break
    for i in range(1, len(listofmarks)):
        if listofmarks[i] > max_marks and listofmarks[i] != -1:
            max_marks = listofmarks[i]
    return max_marks

def minimum(listofmarks):
    for i in range(len(listofmarks)):
        if listofmarks[i] != -1:
            min_marks = listofmarks[0]
            break
    for i in range(1, len(listofmarks)):
        if listofmarks[i] < min_marks and listofmarks[i] != -1:
            min_marks = listofmarks[i]
    return min_marks

def absentcount(listofmarks):
    count = 0
    for i in range(len(listofmarks)):
        if listofmarks[i] == -1:
            count += 1
    return count

def maxfrequency(listofmarks):
    frequency = {}
    for mark in listofmarks:
        if mark != -1:
            if mark in frequency:
                frequency[mark] += 1
            else:
                frequency[mark] = 1

    print("\nMarks | Frequency")
    for key, value in frequency.items():
        print(f"  {key}   |    {value}")

    max_freq = max(frequency.values())
    for mark, freq in frequency.items():
        if freq == max_freq:
            return mark, freq

marksinFDS = []
numberofstudents = int(input("Enter total number of students: "))
for i in range(numberofstudents):
    marks = int(input("Enter marks of student " + str(i + 1) + " (use -1 for absent students): "))
    marksinFDS.append(marks)

flag = 1
while flag == 1:
    print("\n----------MENU-----------\n")
    print("1. Total and average marks of class")
    print("2. Highest and lowest marks in class")
    print("3. Number of students absent for class")
    print("4. Marks with highest frequency")
    print("5. Exit\n")

    ch = int(input("Enter your choice (from 1 to 5): "))

    if ch == 1:
        average(marksinFDS)
    elif ch == 2:
        print("Highest score in class: ", maximum(marksinFDS))
        print("Lowest score in class: ", minimum(marksinFDS))
    elif ch == 3:
        print("Number of students absent in class: ", absentcount(marksinFDS))
    elif ch == 4:
        mark, freq = maxfrequency(marksinFDS)
        print(f"Highest frequency is of marks {mark}, which occurred {freq} times.")
    elif ch == 5:
        print("Thanks for using this program!")
        flag = 0
        break
    else:
        print("!!Wrong choice!!")

    a = input("\nDo you want to continue (yes/no): ").lower()
    if a != "yes":
        flag = 0
        print("Thanks for using this program!")