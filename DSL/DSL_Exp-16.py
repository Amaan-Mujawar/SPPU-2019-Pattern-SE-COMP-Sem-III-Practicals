/*
Write a Python program to store first year percentage of students in array. Write
function for sorting array of floating point numbers in ascending order using quick 
sort and display top five scores.
*/


def input_percent():
    perc = []
    students = int(input("Enter number of students: "))
    for i in range(students):
        perc.append(float(input(f"Enter the percentage of student {i+1}: ")))
    return perc


def print_percent(perc):
    for percentage in perc:
        print(percentage)


def percent_part(perc, start, end):
    pivot = perc[start]
    low_bound = start + 1
    up_bound = end
    while True:
        while low_bound <= up_bound and perc[low_bound] <= pivot:
            low_bound += 1
        while low_bound <= up_bound and perc[up_bound] >= pivot:
            up_bound -= 1
        if low_bound <= up_bound:
            perc[low_bound], perc[up_bound] = perc[up_bound], perc[low_bound]
        else:
            break
    perc[start], perc[up_bound] = perc[up_bound], perc[start]
    return up_bound


def QuickSort(perc, start, end):
    if start < end:
        part = percent_part(perc, start, end)
        QuickSort(perc, start, part - 1)
        QuickSort(perc, part + 1, end)


def disp_top_five(perc):
    print("Top 5 percentages are:")
    top_five = sorted(perc, reverse=True)[:5]
    for percentage in top_five:
        print(percentage)

unsorted = []
flag = 1
while flag == 1:
    print("\n-------------------MENU-------------------")
    print("1. Accept the percentage of students.")
    print("2. Display the percentage of students.")
    print("3. Perform Quick sort on the data.")
    print("4. Exit")
    ch = int(input("\nEnter your choice (from 1 to 4): "))
    
    if ch == 1:
        unsorted = input_percent()
    elif ch == 2:
        print("Student Percentages:")
        print_percent(unsorted)
    elif ch == 3:
        if unsorted:
            print("Percentage of students after performing Quick Sort:")
            QuickSort(unsorted, 0, len(unsorted) - 1)
            print_percent(unsorted)
            a = input("Do you want top 5 percentages (yes/no): ").strip().lower()
            if a == 'yes':
                disp_top_five(unsorted)
        else:
            print("No data to sort. Please input percentages first.")
    elif ch == 4:
        print("Thanks for using this program!")
        flag = 0
    else:
        print("Enter a valid choice!")