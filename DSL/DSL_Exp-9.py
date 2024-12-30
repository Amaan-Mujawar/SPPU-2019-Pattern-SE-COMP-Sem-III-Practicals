/*
Write a Python program to compute following computation on matrix:
a) Addition of two matrices 
b) Subtraction of two matrices
c) Multiplication of two matrices 
d) Transpose of a matrix
*/


def accept(matrix, row, col):
    for i in range(row):
        row_values = []
        for j in range(col):
            no = int(input(f"Enter the value of matrix[{i}][{j}]:: "))
            row_values.append(no)
        print("--------------------")
        matrix.append(row_values)


def show(matrix, row, col):
    for i in range(row):
        for j in range(col):
            print(matrix[i][j], end=" ")
        print()


def add_mat(m1, m2, res, row, col):
    for i in range(row):
        for j in range(col):
            res[i][j] = m1[i][j] + m2[i][j]


def sub_mat(m1, m2, res, row, col):
    for i in range(row):
        for j in range(col):
            res[i][j] = m1[i][j] - m2[i][j]


def mul_mat(m1, m2, res, row1, col1, col2):
    for i in range(row1):
        for j in range(col2):
            res[i][j] = 0
            for k in range(col1):
                res[i][j] += m1[i][k] * m2[k][j]


def trans_mat(m, res, row, col):
    for i in range(row):
        for j in range(col):
            res[j][i] = m[i][j]


def main():
    print("Basic Matrix Operations using Python")

    m1 = []
    m2 = []
    res = [[0 for _ in range(5)] for _ in range(5)]

    print("For matrix operations, we require some inputs.")
    row1 = int(input("Enter number of rows in first matrix: "))
    col1 = int(input("Enter number of columns in first matrix: "))
    row2 = int(input("Enter number of rows in second matrix: "))
    col2 = int(input("Enter number of columns in second matrix: "))

    while True:
        print("\n----------MENU-----------\n")
        print("1. Accept two matrices from user")
        print("2. Show the matrices values")
        print("3. Addition of two matrices")
        print("4. Subtraction of two matrices")
        print("5. Multiplication of two matrices")
        print("6. Transpose of first matrix")
        print("7. Exit")

        choice = int(input("Enter your choice: "))

        if choice == 1:
            print("Please enter the values for the first matrix:")
            accept(m1, row1, col1)
            print("Please enter the values for the second matrix:")
            accept(m2, row2, col2)

        elif choice == 2:
            print("\nFirst Matrix:")
            show(m1, row1, col1)
            print("\nSecond Matrix:")
            show(m2, row2, col2)

        elif choice == 3:
            if row1 == row2 and col1 == col2:
                add_mat(m1, m2, res, row1, col1)
                print("\nThe addition of two matrices is:")
                show(res, row1, col1)
            else:
                print("Sorry! Addition is not possible. Dimensions do not match.")

        elif choice == 4:
            if row1 == row2 and col1 == col2:
                sub_mat(m1, m2, res, row1, col1)
                print("\nThe subtraction of two matrices is:")
                show(res, row1, col1)
            else:
                print("Sorry! Subtraction is not possible. Dimensions do not match.")

        elif choice == 5:
            if col1 == row2:
                res = [[0 for _ in range(col2)] for _ in range(row1)]
                mul_mat(m1, m2, res, row1, col1, col2)
                print("\nThe multiplication of two matrices is:")
                show(res, row1, col2)
            else:
                print("Sorry! Multiplication is not possible. Column count of the first matrix must equal row count of the second matrix.")

        elif choice == 6:
            print("\nBefore Transpose, the first matrix is:")
            show(m1, row1, col1)
            res = [[0 for _ in range(row1)] for _ in range(col1)]
            trans_mat(m1, res, row1, col1)
            print("\nAfter Transpose, the first matrix is:")
            show(res, col1, row1)

        elif choice == 7:
            print("Thank you for using this program!")
            break

        else:
            print("Please enter a valid choice...")

main()
