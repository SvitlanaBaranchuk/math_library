def Power(x, n):
    '''
    This function is designed to raise a number to a power. The number
    that rises is x.Degree - n.

    The function is created using recursion.
    '''
    if n == 0:
        return 1
    if n < 0:
        return Power(1.0 / x, -n)
    return x * Power(x, n - 1)


def Square_root(n):
    '''
    The task of this function is to calculate the square root of a number.
    n is the number from which we will extract the root.
    '''
    if n < 0:
        return print(f'Sorry, you did not enter a natural number: {n}')
    else:
        root_2 = n ** (1 / 2)
        return root_2


def Cube_root(x):
    '''
    The task of this function is to calculate the cube root of a number.
    n is the number from which we will extract the root.
    '''
    if x > 0:
        return x**(1 / 3)
    elif x < 0:
        return -abs(x)**(1 / 3)
    else:
        return print("Error. Incorect value!")


def Factorial(n):
    '''
    The Factorial function is created to calculate the factorial of a number.
    '''
    if n < 0:
        return print(f'Sorry, you did not enter a natural number: {n}')
    else:
        factorial = 1
        list = range(1, n + 1)
        for x in list:
            factorial = factorial * x
        return factorial


def Combinations(n, k):
    '''
    The Combinations function is designed to calculate possible combinations from n to k.
    The function uses the previously written Factorial function.
    '''
    if n < 0 or k < 0:
        return print("Error. Incorect value!")
    if n == k:
        return 1
    if k == 0:
        return 1
    if k == 1:
        return n
    if k > n:
        return print("Error. Incorect value!")
    else:
        C = Factorial(n) / (Factorial(k) * Factorial(n - k))
        return C


def Placing(n, k):
    '''
    The Permutations_calculate function is designed to calculate possible permutations from n to k.
    The function uses the previously written Factorial function.
    '''
    if (n < 0 or k < 0 or k > n):
        return print("Error. Incorect value!")
    else:
        A = Factorial(n) / Factorial(n - k)
        return A


def Pascal_triangle(n):
    '''
    n - power entered by user.
    value-array to store generated Pascal triangle values.

    This function is used to create the Pascal's triangle.
    '''
    values = [[0 for m in range(n + 1)] for k in range(n + 1)]

    for l in range(0, n + 1):
        for i in range(0, l + 1):
            if i is 0 or i is l:
                values[l][i] = 1
                print(values[l][i], end=' ')

            else:
                values[l][i] = values[l - 1][i - 1] + values[l - 1][i]
                print(values[l][i], end=' ')
        print('\n', end='')


def Sum_arithmetic_progression(a_1, d, n):
    '''
    This function calculates the sum of the arithmetic progression
    with the known first term, the difference of the progression and the number of elements.

    The formula           2a_1 + d(n-1)
                    S_n = ------------- * n
                                2
    is used.
    '''
    S = ((2 * a_1 + d * (n - 1)) / 2) * n
    return S


def Sum_geometric_progression(b_1, b_n, q):
    '''
    This function calculates the sum of the geometric progression
    with the known first term, nth term and the denominator of the progression.

    The formula           b_1 - b_n * q
                    S_n = -------------
                              1 - q
    is used.
    '''
    if q == 1:
        return print("Error. Division by zero.")
    else:
        S = (b_1 - b_n * q) / (1 - q)
        return S


def Sum_infinity_geometric_progression(b_1, q):
    '''
    This function calculates the sum of the infinity geometric progression
    with the known first term and the denominator of the progression.

    The formula            b_1
                    S_n = ------
                          1 - q
    is used.
    '''
    if q == 1:
        return print("Error. Division by zero.")
    else:
        S = b_1 / (1 - q)
        return S


print("Additionally program for course work")
print("Theme: \"Mathematical library\"")
print("Performed by a st. gr. KM-04")
print("Baranchuk S.O.")
print("2021\n\n")

# Program "menu".
def main():
    while True:
        f = input('If you want to ' + "\033[1m" + 'raise the number to exponentiation, press 1.\n' + '\033[0m' +
                  'If you want to ' + "\033[1m" + 'find the square root of a number, press 2.\n'+ '\033[0m' +
                  'If you want to ' + "\033[1m" + 'find the cubic root of a number, press 3.\n'+ '\033[0m' +
                  'If you want to ' + "\033[1m" + 'find the factorial of a number, press 4.\n' + '\033[0m'
                  'If you want to ' + "\033[1m" + 'find the combinations from n to k, press 5.\n'+ '\033[0m' +
                  'If you want to ' + "\033[1m" + 'find the placing from n to k, press 6.\n'+ '\033[0m' +
                  'If you want to ' + "\033[1m" + 'print the Pascal triangle of a number, press 7.\n'+ '\033[0m' +
                  'If you want to ' + "\033[1m" + 'find the sum arithmetic progression, press 8.\n'+ '\033[0m' +
                  'If you want to ' + "\033[1m" + 'find the sum geometric progression, press 9.\n'+ '\033[0m' +
                  'If you want to ' + "\033[1m" + 'find the sum infinity geometric progression, press 10: ' + '\033[0m')

        while True:
            # Condition for exponentiation.
            if f == '1':
                while True:
                    while True:
                        x = input(('\nEnter a number, please: '))
                        n = input(('\nEnter a exponentiation, please: '))
                        try:
                            x = float(x)
                            n = float(n)
                        except ValueError:
                            print('Sorry, you you did not enter a number!')
                            continue
                        else:
                            break

                    while True:
                        r = Power(x, n)
                        print("\nResult: ", r)
                        break

                    end = input('\nIf you want to continue this part of program, press "0". If you want to exit, press any other key: ')
                    if end == '0':
                        continue
                    else:
                        print('This part of the program is completed.')
                        break

            # Condition for square root.
            elif f == '2':
                while True:
                    while True:
                        n = input(('\nEnter a number, please: '))

                        try:
                            n = float(n)
                        except ValueError:
                            print(f'Sorry, you you did not enter a number: {n}')
                            continue
                        else:
                            break

                    while True:
                        r = Square_root(n)
                        print("\nResult: ", r)
                        break

                    end = input('\nIf you want to continue this part of program, press "0". If you want to exit, press any other key: ')
                    if end == '0':
                        continue
                    else:
                        print('This part of the program is completed.')
                        break

            # Condition for cube root.
            elif f == '3':
                while True:
                    while True:
                        n = input(('\nEnter a number, please: '))

                        try:
                            n = float(n)
                        except ValueError:
                            print(f'Sorry, you you did not enter a number: {n}')
                            continue
                        else:
                            break

                    while True:
                        r = Cube_root(n)
                        print("\nResult: ", r)
                        break

                    end = input('\nIf you want to continue this part of program, press "0". If you want to exit, press any other key: ')
                    if end == '0':
                        continue
                    else:
                        print('This part of the program is completed.')
                        break

            # Condition for factorial.
            elif f == '4':
                while True:
                    while True:
                        n = input(('\nEnter a number, please: '))

                        try:
                            n = int(n)
                        except ValueError:
                            print(f'Sorry, you you did not enter a number: {n}')
                            continue
                        else:
                            break

                    while True:
                        r = Factorial(n)
                        print("\nResult: ", r)
                        break

                    end = input('\nIf you want to continue this part of program, press "0". If you want to exit, press any other key: ')
                    if end == '0':
                        continue
                    else:
                        print('This part of the program is completed.')
                        break

            # Condition for combinations.
            elif f == '5':
                while True:
                    while True:
                        n = input('\nEnter n - the number of elements of the set: ')
                        k = input('Enter k - plural compounds: ')

                        try:
                            n = int(n)
                            k = int(k)
                        except ValueError:
                            print(f'Sorry, you you did not enter a number.')
                            continue
                        else:
                            break

                    while True:
                        r = Combinations(n, k)
                        print("\nResult: ", r)
                        break

                    end = input('\nIf you want to continue this part of program, press "0". If you want to exit, press any other key: ')
                    if end == '0':
                        continue
                    else:
                        print('This part of the program is completed.')
                        break

            # Condition for placing.
            elif f == '6':
                while True:
                    while True:
                        n = input('\nEnter n - the number of elements of the set: ')
                        k = input('Enter k - plural compounds: ')

                        try:
                            n = int(n)
                            k = int(k)
                        except ValueError:
                            print(f'Sorry, you you did not enter a number.')
                            continue
                        else:
                            break

                    while True:
                        r = Placing(n, k)
                        print("\nResult: ", r)
                        break

                    end = input('\nIf you want to continue this part of program, press "0". If you want to exit, press any other key: ')
                    if end == '0':
                        continue
                    else:
                        print('This part of the program is completed.')
                        break

            # Condition for pascal triangle.
            elif f == '7':
                while True:
                    while True:
                        n = input('\nEnter n - exponent for binomial coefficients: ')
                        try:
                            n = int(n)
                        except ValueError:
                            print(f'Sorry, you you did not enter a number.')
                            continue
                        else:
                            break

                    while True:
                        Pascal_triangle(n)
                        break

                    end = input('\nIf you want to continue this part of program, press "0". If you want to exit, press any other key: ')
                    if end == '0':
                        continue
                    else:
                        print('This part of the program is completed.')
                        break

            # Condition for sum arithmetic progression.
            elif f == '8':
                while True:
                    while True:
                        a_1 = input("\nEnter a_1 - the first element of progression: ")
                        d = input("\nEnter d - progression difference: ")
                        n = input("\nEnter n - the number of elements in the progression: ")
                        try:
                            a_1 = float(a_1)
                            d = float(d)
                            n = int(n)
                        except ValueError:
                            print('Sorry, you you did not enter a number!')
                            continue
                        else:
                            break

                    while True:
                        r = Sum_arithmetic_progression(a_1, d, n)
                        print("\nResult: ", r)
                        break

                    end = input('\nIf you want to continue this part of program, press "0". If you want to exit, press any other key: ')
                    if end == '0':
                        continue
                    else:
                        print('This part of the program is completed.')
                        break

            # Condition for sum geometric progression.
            elif f == '9':
                while True:
                    while True:
                        b_1 = input("\nEnter b_1 - the first element of progression: ")
                        b_n = input("\nEnter b_n - the last element of progression: ")
                        q = input("\nEnter q - denominator of progression: ")
                        try:
                            b_1 = float(b_1)
                            b_n = float(b_n)
                            q = float(q)
                        except ValueError:
                            print('Sorry, you you did not enter a number!')
                            continue
                        else:
                            break

                    while True:
                        r = Sum_geometric_progression(b_1, b_n, q)
                        print("\nResult: ", r)
                        break

                    end = input('\nIf you want to continue this part of program, press "0". If you want to exit, press any other key: ')
                    if end == '0':
                        continue
                    else:
                        print('This part of the program is completed.')
                        break

            # Condition for sum infinity geometric progression.
            elif f == '10':
                while True:
                    while True:
                        b_1 = input("\nEnter b_1 - the first element of progression: ")
                        q = input("\nEnter q - denominator of progression: ")
                        try:
                            b_1 = float(b_1)
                            q = float(q)
                        except ValueError:
                            print('Sorry, you you did not enter a number!')
                            continue
                        else:
                            break

                    while True:
                        r = Sum_infinity_geometric_progression(b_1, q)
                        print("\nResult: ", r)
                        break

                    end = input('\nIf you want to continue this part of program, press "0". If you want to exit, press any other key: ')
                    if end == '0':
                        continue
                    else:
                        print('This part of the program is completed.')
                        break

            break

        # Completion of the program.
        end2 = input('\nIf you want to continue this program, press "0". If you want to exit, press any other key: ')
        if end2 == '0':
            continue
        else:
            print('The program is completed.')
            break


if __name__ == '__main__':
    main()
