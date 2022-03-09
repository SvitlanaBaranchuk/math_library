from ctypes import *
from sys import platform


print('*'*76)
shared_lib_path = "./add.so"
if platform.startswith('win32'):
    shared_lib_path = "./library.dll"
try:
    add_lib = CDLL(shared_lib_path)
    print("Successfully loaded! ", add_lib)
except Exception as e:
    print(e)

print('*'*76)

#####################################################################
print('')
print("Hello! It's program for testing CDLL library in Python!")
print("In this program, we test some features from the library library.dll")
print("But note that this program has one downside: some functions work with non-negative numbers and the result is rounded numbers.")
print("Okay, let's start)")
print('\n')

print("I will start with 'Factorial' function")
# result1 :: Integer Number → Integer Number
result1 = add_lib.factorial(c_int(5))
print(f"Factorial 5 is {result1}.")
print('')

print("Okay, let's move on!) Functions for combinatorics:")
# result2 :: Integer Number → Integer Number
result2 = add_lib.combinations(c_int(9), c_int(5))
print(f"1. Combination from 9 to 5 is {result2}")
# result3 :: Integer Number → Integer Number
result3 = add_lib.placing(c_int(9), c_int(5))
print(f"2. Placing from from 9 to 5 is {result3}")

print('')
print("Next :)")
# result4 :: Integer Number → Integer Number
result4 = add_lib.power(c_int(2), c_int(10))
print(f"2^10 is {result4}")
# result5 :: Integer Number → Integer Number
result5 = add_lib.square_root(c_int(81))
print(f"81^(1/2) is {result5}")
# result6 :: Integer Number → Integer Number
result6 = add_lib.cube_root(c_int(-27))
print(f"-27^(1/3) is {result6}")

print('')
print("Sum of progression:")
# result7 :: Integer Number → Integer Number
result7 = add_lib.sum_arithmetic_progression(c_int(1), c_int(1), c_int(10))
print(f"Sum arithmetic progression from a_1 = 1, n = 10 and d = 1: {result7}")
# result8 :: Integer Number → Integer Number
result8 = add_lib.sum_geometric_progression(c_int(1), c_int(50), c_int(2))
print(f"Sum geometric progression b_1 = 1, b_n = 50 and q = 2: {result8}")
# result9 :: Integer Number → Integer Number
result9 = add_lib.sum_infinity_geometric_progression(c_int(1), c_int(2))
print(f"Sum infinity geometric progression b_1 = 1 and q = 2: {result9}")
print('')

print("Pascal traingle for number 4:")
# result10 :: Integer Number → Integer Number
result10 = add_lib.pascal_triangle(c_int(4))

print("It is all)")
