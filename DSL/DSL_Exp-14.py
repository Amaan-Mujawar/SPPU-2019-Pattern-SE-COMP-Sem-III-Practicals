/*
Write a Python program to store first year percentage of students in array. Write 
function for sorting array of floating point numbers in ascending order using
a) Selection Sort.
b) Bubble sort and display top five scores.
*/


def selection_sort(marks):
    for i in range(len(marks)):
        min_idx = i
        for j in range(i + 1, len(marks)):
            if marks[min_idx] > marks[j]:
                min_idx = j
        marks[i], marks[min_idx] = marks[min_idx], marks[i]

    print("\nMarks of students after performing Selection Sort:")
    for mark in marks:
        print(mark)

def bubble_sort(marks):
    n = len(marks)
    for i in range(n - 1):
        for j in range(0, n - i - 1):
            if marks[j] > marks[j + 1]:
                marks[j], marks[j + 1] = marks[j + 1], marks[j]

    print("\nMarks of students after performing Bubble Sort:")
    for mark in marks:
        print(mark)

def top_five_marks(marks):
    print("\nTop 5 Marks are:")
    sorted_marks = sorted(marks, reverse=True)
    for i in range(min(5, len(sorted_marks))):
        print(sorted_marks[i])

marks = []

n = int(input("Enter number of students whose marks are to be displayed: "))
print(f"Enter marks for {n} students (Press ENTER after each student's marks): ")
for i in range(n):
    ele = int(input(f"Enter marks for student {i + 1}: "))
    marks.append(ele)

print("\nThe marks of", n, "students are:")
print(marks)

flag = True
while flag:
    print("\n---------MENU---------")
    print("1. Selection Sort of marks")
    print("2. Bubble Sort of marks")
    print("3. Exit")

    ch = int(input("\nEnter your choice (from 1 to 3): "))

    if ch == 1:
        selection_sort(marks.copy())
        a = input("\nDo you want to display the top marks from the list (yes/no): ").lower()
        if a == 'yes':
            top_five_marks(marks)
        else:
            print("\nThanks for using this program!")
            flag = False

    elif ch == 2:
        bubble_sort(marks.copy())
        a = input("\nDo you want to display the top marks from the list (yes/no): ").lower()
        if a == 'yes':
            top_five_marks(marks)
        else:
            print("\nThanks for using this program!")
            flag = False

    elif ch == 3:
        print("\nThanks for using this program!")
        flag = False

    else:
        print("\nEnter a valid choice!")
        print("\nThanks for using this program!")
        flag = False