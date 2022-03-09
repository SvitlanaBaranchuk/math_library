#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>


int factorial(int n)
{
    /* The Factorial function is created to calculate the factorial of a number. 
    
    The function is created using recursion. */
    // If n = 0, factorial n = 1
    // ((by the property of a  factorial)
    if (n == 0) 
    {
        return 1;
    }
    else
    {
        return factorial(n - 1) * n;
    }
}


int main()
{
    
    clock_t tic = clock();

    int n, fact;
    printf("\nn - the number from which you want to find the factorial. In this case n will be equal to 5. ");
    n = 5;
    fact = factorial(n);
    // Display result of function.
    printf("\nResult: %d", fact);

    clock_t toc = clock();
    // Output of program operation time.
    printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);

    return 0;

}