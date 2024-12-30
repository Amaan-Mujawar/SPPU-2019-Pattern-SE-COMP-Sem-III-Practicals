/*
In second year computer engineering class, group A student’s play cricket, group B 
students play badminton and group C students play football.
Write a Python program using functions to compute following:
a) List of students who play both cricket and badminton
b) List of students who play either cricket or badminton but not both
c) Number of students who play neither cricket nor badminton
d) Number of students who play cricket and football but not badminton.
(Note- While realizing the group, duplicate entries should be avoided, Do not use SET
 built-in functions)
*/


def removeDuplicate(d):
    lst = []
    for i in d:
        if i not in lst:
            lst.append(i)
    return lst

def intersection(lst1, lst2):
    lst3 = []
    for val in lst1:
        if val in lst2:
            lst3.append(val)
    return lst3

def union(lst1, lst2):
    lst3 = lst1.copy()
    for val in lst2:
        if val not in lst3:
            lst3.append(val)
    return lst3

def diff(lst1, lst2):
    lst3 = []
    for val in lst1:
        if val not in lst2:
            lst3.append(val)
    return lst3

def sym_diff(lst1, lst2):
    D1 = diff(lst1, lst2)
    print("Difference between Cricket and Badminton (C-B) is:", D1)
    D2 = diff(lst2, lst1)
    print("Difference between Badminton and Cricket (B-C) is:", D2)
    lst3 = union(D1, D2)
    return lst3

def CB(lst1, lst2):
    lst3 = intersection(lst1, lst2)
    print("\nList of students who play both Cricket and Badminton is:", lst3)
    return len(lst3)

def eCeB(lst1, lst2):
    lst3 = sym_diff(lst1, lst2)
    print("\nList of students who play either Cricket or Badminton but not both is:", lst3)
    return len(lst3)

def nCnB(lst1, lst2, lst3):
    lst4 = diff(lst1, union(lst2, lst3))
    print("\nList of students who play neither Cricket nor Badminton is:", lst4)
    return len(lst4)

def CBnF(lst1, lst2, lst3):
    lst4 = diff(intersection(lst1, lst2), lst3)
    print("\nList of students who play Cricket and Football but not Badminton is:", lst4)
    return len(lst4)

SEComp = []
n = int(input("\nEnter the number of students in SE COMP: "))
print("Enter the names of", n, "students:")
for i in range(n):
    SEComp.append(input())

print("Original list of students in SEComp:", SEComp)

Cricket = []
n = int(input("\nEnter the number of students who play Cricket: "))
print("Enter the names of students who play Cricket:")
for i in range(n):
    Cricket.append(input())
Cricket = removeDuplicate(Cricket)
print("List of students playing Cricket after removing duplicates:", Cricket)

Football = []
n = int(input("\nEnter the number of students who play Football: "))
print("Enter the names of students who play Football:")
for i in range(n):
    Football.append(input())
Football = removeDuplicate(Football)
print("List of students playing Football after removing duplicates:", Football)

Badminton = []
n = int(input("\nEnter the number of students who play Badminton: "))
print("Enter the names of students who play Badminton:")
for i in range(n):
    Badminton.append(input())
Badminton = removeDuplicate(Badminton)
print("List of students playing Badminton after removing duplicates:", Badminton)

flag = 1
while flag:
    print("\n--------------------MENU--------------------")
    print("1. List of students who play both Cricket and Badminton")
    print("2. List of students who play either Cricket or Badminton but not both")
    print("3. List of students who play neither Cricket nor Badminton")
    print("4. Number of students who play Cricket and Football but not Badminton")
    print("5. Exit\n")
    ch = int(input("Enter your choice (1-5): "))

    if ch == 1:
        print("Number of students who play both Cricket and Badminton:", CB(Cricket, Badminton))
    elif ch == 2:
        print("Number of students who play either Cricket or Badminton but not both:", eCeB(Cricket, Badminton))
    elif ch == 3:
        print("Number of students who play neither Cricket nor Badminton:", nCnB(SEComp, Cricket, Badminton))
    elif ch == 4:
        print("Number of students who play Cricket and Football but not Badminton:", CBnF(Cricket, Football, Badminton))
    elif ch == 5:
        print("Thanks for using this program!")
        flag = 0
    else:
        print("!! Wrong Choice !!")
    
    if flag:
        a = input("\nDo you want to continue (yes/no): ")
        if a.lower() != "yes":
            flag = 0
            print("Thanks for using this program!")