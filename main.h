#ifdef __MAIN_H__
#define __MAIN_H__


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


#define DLL_EXPORT __declspec(dllexport) 
                                         
#ifdef __cplusplus
extern "C"
{
#endif


int DLL_EXPORT power(int x, int n);
int DLL_EXPORT square_root(int n);
int DLL_EXPORT cube_root(int n);
int DLL_EXPORT factorial(int n);
int DLL_EXPORT combinations(int n, int k);
int DLL_EXPORT placing(int n, int k);
int DLL_EXPORT pascal_triangle(int n);
int DLL_EXPORT sum_arithmetic_progression(int a_1, int d, int n);
int DLL_EXPORT sum_geometric_progression(int b_1, int b_n, int q);
int DLL_EXPORT sum_infinity_geometric_progression(int b_1, int q);

#ifdef __cplusplus
}
#endif
#endif // __MAIN_H__