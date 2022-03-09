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


print("Hello! It's program for load testing library.dll")

print('The first load: perform the function "Factorial" from 5 100 times')
for i in range(0, 101):
    print(f"{i}. {add_lib.factorial(c_int(5))}")

print('The second load: perform the function "Factorial" from 5 1000 times')
for k in range(0, 1001):
    print(f"{k}. {add_lib.factorial(c_int(5))}")

print('And the thrird load: perform the function "Combinations" from 9 to 5 1000 times')
for l in range(0, 1001):
    print(f"{k}. {add_lib.combinations(c_int(9), c_int(5))}")