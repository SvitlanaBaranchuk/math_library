double power(double x, double n) 
{
    /* This function is designed to raise a number to a power.
    The number that rises is x. Degree - n.
    
    The function is created using recursion. */
    int result = 1;

    while (n != 0) 
    {
        result *= x;
        --n;
    }
    // if n = 0, result = 1 
    // (by the property of a power with zero exponent)
    
    return result;
}


double square_root(double n)
{
    /* The task of this function is to calculate the square root of a number. 
    n is the number from which we will extract the root.

    To calculate the root, enter the number (double)i. 
    Using a loop cycle, we check the number that can be the result. 
    The (double)precision variable is introduced for the precision of the fractional part. */
    double i;
    double precision = 0.000001;
    
    // If n < 0 - value does not exist.
    if (n < 0)
    {
        return 0;
    }
    
    //Integer part
    for (i = 1; (i * i) <= n; ++i);
    {  
        //Fractional part       
        for (--i; (i * i) < n; i += precision);
        {
            return i;
        }
    }     
}


double cube_root(double n) 
{
    /* The task of this function is to calculate the cube root of a number. 
    n is the number from which we will extract the root.

    To calculate the root, enter the number (double)i. 
    Using a loop cycle, we check the number that can be the result. 
    The (double)precision variable is introduced for the precision of the fractional part. */
    double i;
    double precision = 0.000001;

    if (n < 0)
    {
        n = n * (-1);
   
        //Integer part
        for (i = 1; (i * i * i) <= n; ++i);
        {       
            //Fractional part
            for (--i; (i * i * i) < n; i += precision);
            {
                return -i;
            }
        }
    }
    else
    {
        //Integer part
        for (i = 1; (i * i * i) <= n; ++i);
        {       
            //Fractional part
            for (--i; (i * i * i) < n; i += precision);
            {
                return i;
            }
        }
    }
}


int factorial(int n)
{
    /* The Factorial function is created to calculate the factorial of a number. 
    
    The function is created using recursion. */
    if (n == 0) 
    {
        return 1;
    }
    else
    {
        return factorial(n - 1) * n;
    }
}


int combinations(int n, int k)
{
    /* The Combinations function is designed to calculate possible combinations from n to k.
    The function uses the previously written Factorial function. */
    int C;
    
    // if n = k -> C = 1 (combination property)
    if (n == k) 
    {
        return 1;
    }
    // if k = 0 -> C = 1 (combination property)
    if (k == 0) 
    {
        return 1;
    }
    // if k = 1 -> C = n (combination property)
    if (k == 1) 
    {
        return n;
    }
    // if n < k -> C = 0 (combination property)
    if (k > n) 
    {
        return printf("Error. Incorrect value!"); 
    } 
    else 
    {
        C = factorial(n) / (factorial(k) * factorial(n - k));
        return C;
    }
}


int placing(int n, int k)
{
    /* The Placing function is designed to calculate possible permutations from n to k.
    The function uses the previously written Factorial function. */ 
    int A;
    
    // if n < 0 or k < 0 or k > n -> C = 0 (placing property)
    if (n < 0 || k < 0 || k > n) 
    {
        return printf("Error. Incorrect value!");
    }
    else 
    {
        A = factorial(n) / factorial(n - k);
        return A;
    }
}


int pascal_triangle(int n)
{
    /* The task of the Pascal_triangle function is to output 
    a Pascal triangle by the specified number of lines. 
    The elements of this triangle are binomial coefficients. */
    int coef = 1;
    int space, i, j;

    // If n < 0 - value does not exist.
    if (n < 0)
    {
        return 0;
    }
    // if n = 0, result = 1 
    // (by the property of a power with zero exponent)
    if (n == 0) 
    {
        return printf("%d", 1);
    }
    else 
    {
        for (i = 0; i < n + 1; i++) 
        {
            for (space = 1; space <= n + 1 - i; space++)
            {
                printf("  ");
            }
            for (j = 0; j <= i; j++) 
            {
                if (j == 0 || i == 0)
                {
                    coef = 1;
                }
                else
                {
                    coef = coef * (i - j + 1) / j;
                }
                printf("%4d", coef);
            }
            printf("\n");
        }
    }
}


float sum_arithmetic_progression(float a_1, float d, int n)
{
    /* This function calculates the sum of the arithmetic progression 
    with the known first term, the difference of the progression and the number of elements.
    
    The formula           2a_1 + d(n-1)
                    S_n = ------------- * n
                                2
    is used. */
    float S;
    S = ((2 * a_1 + d * (n - 1)) / 2) * n;
    return S;
}


float sum_geometric_progression(float b_1, float b_n, float q)
{
    /* This function calculates the sum of the geometric progression 
    with the known first term, nth term and the denominator of the progression.
    
    The formula           b_1 - b_n * q
                    S_n = ------------- 
                              1 - q
    is used.*/
    float S;
    if (q == 1) 
    {
        return printf("Error. Division by zero.");
    }
    else 
    {
        S = (b_1 - b_n * q) / (1 - q);
        return S;
    }
}


float sum_infinity_geometric_progression(float b_1, float q)
{
    /* This function calculates the sum of the infinity geometric progression 
    with the known first term and the denominator of the progression.
    
    The formula            b_1 
                    S_n = ------
                          1 - q
    is used.*/
    float S;
    if (q == 1) 
    {
        return printf("Error. Division by zero.");
    }
    else 
    {
        S = b_1 / (1 - q);
        return S;
    }
}
