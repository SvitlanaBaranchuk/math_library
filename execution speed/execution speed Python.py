import time


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


start_time = time.clock()

print("\nn - the number from which you want to find the factorial. \nIn this case n will be equal to 12. \nResult:")
for i in range (0, 1000):
    print(f"{i}. {Factorial(12)}")
print(time.clock() - start_time, "seconds")