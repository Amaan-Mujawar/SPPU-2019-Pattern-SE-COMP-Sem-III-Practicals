/*
Write a Python program to maintain club members, sort on roll numbers in ascending order. 
Write function “Ternary_Search” to search whether particular student is member of club or 
not. Ternary search is modified binary search that divides array into 3 halves instead 
of two.
*/


def accept_roll():
    roll_no = []
    no_of_students = int(input("Enter the number of students: "))
    for i in range(no_of_students):
        roll_no.append(int(input("Enter roll number of student {0}: ".format(i + 1))))
    return roll_no

def print_roll(roll_no):
    print("Roll Numbers:")
    for i in range(len(roll_no)):
        print(roll_no[i])

def insertion_sort(roll_no):
    for i in range(1, len(roll_no)):
        key = roll_no[i]
        j = i - 1
        while j >= 0 and key < roll_no[j]:
            roll_no[j + 1] = roll_no[j]
            j -= 1
        roll_no[j + 1] = key
    return roll_no

def NR_Ternary_search(roll, roll_find):
    left = 0
    right = len(roll) - 1

    while left <= right:
        mid1 = left + (right - left) // 3
        mid2 = left + 2 * (right - left) // 3

        if roll_find == roll[mid1]:
            return mid1
        elif roll_find == roll[mid2]:
            return mid2

        if roll_find < roll[mid1]:
            right = mid1 - 1
        elif roll_find > roll[mid1] and roll_find < roll[mid2]:
            left = mid1 + 1
            right = mid2 - 1
        else:
            left = mid2 + 1

    return -1

unsort_roll = []
sort_roll = []
flag = 1

while flag == 1:
    print("\n-------MENU---------")
    print("1. Accept student roll numbers")
    print("2. Display the roll numbers of students")
    print("3. Sort roll numbers using insertion sort")
    print("4. Perform non-recursive ternary search")
    print("5. Exit\n")

    ch = int(input("Enter your choice (1 to 5): "))

    if ch == 1:
        unsort_roll = accept_roll()
    elif ch == 2:
        if unsort_roll:
            print_roll(unsort_roll)
        else:
            print("No roll numbers to display. Please enter data first.")
    elif ch == 3:
        if unsort_roll:
            print("Elements after performing insertion sort:")
            sort_roll = insertion_sort(unsort_roll.copy())
            print_roll(sort_roll)
        else:
            print("No roll numbers to sort. Please enter data first.")
    elif ch == 4:
        if sort_roll:
            find_roll = int(input("Enter the roll number to be searched: "))
            index = NR_Ternary_search(sort_roll, find_roll)
            if index != -1:
                print(f"The roll number {find_roll} is found at position {index + 1}.")
            else:
                print(f"The roll number {find_roll} is not found!!")
        else:
            print("Please sort the roll numbers first (Option 3).")
    elif ch == 5:
        print("Thanks for using this program!!")
        flag = 0
    else:
        print("Wrong choice! Please try again.")