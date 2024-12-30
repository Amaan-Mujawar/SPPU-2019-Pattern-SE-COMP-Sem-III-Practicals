/*
Write a Python Program for magic square. A magic square is an n * n matrix of the 
integers 1 to n2 such that the sum of each row, column, and diagonal is the same. 
The figure given below is an example of magic square for case n=5. 
In this example, the common sum is 65.
*/


def generate_magic_square(size):
    magic_square = [[0 for x in range(size)] for y in range(size)]

    i = size // 2
    j = size - 1
    num = 1

    while num <= (size * size):
        if i == -1 and j == size:
            j = size - 2
            i = 0
        else:
            if j == size:
                j = 0
            if i < 0:
                i = size - 1
        
        if magic_square[int(i)][int(j)]:
            j = j - 2
            i = i + 1
            continue
        else:
            magic_square[int(i)][int(j)] = num
            num += 1
        
        j = j + 1
        i = i - 1

    magic_sum = size * (size * size + 1) // 2
    print("\nSum of each row or column is: ", magic_sum)
    print("Magic Square of size", size, "x", size, "is: \n")

    for i in range(size):
        for j in range(size):
            print('%3d' % magic_square[i][j], end=' | ')
        print()

flag = 1
while flag == 1:
    n = int(input("\nEnter the size of the magic square (odd number only): "))
    
    if n % 2 == 0:
        print("Error: Size must be an odd number!")
    else:
        generate_magic_square(n)

    a = input("\nDo you want to generate another magic square (yes/no): ").lower()
    if a == 'yes':
        flag = 1
    else:
        flag = 0
        print("\nThanks for using the program!")
