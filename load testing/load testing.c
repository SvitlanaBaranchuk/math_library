#define _CRT_SECURE_NO_WARNINGS
/*Symbols with the following ASCII codes 
are used to draw the frame: 218 (upper left corner), 
196 (horizontal line), 191 (upper right corner), 
179 (vertical line), 192 (lower left corner), 
217 (lower right corner)*/
#define UPPER_LEFT_CORNER 218
#define HORIZONTAL_LINE 196
#define UPPER_RIGHT_CORNER 191
#define VERTICAL_LINE 179
#define LOWER_LEFT_CORNER 192
#define LOWER_RIGHT_CORNER 217
/*MAXIMUM is the maximum number of calls to a function 
while it is still running. Larger values have not been verified.*/
#define MAXIMUM 2000000000
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <string.h>
#include <math.h>
#include "text_function.h"

/*All the functions required for the program are in the file 
"text_function.h" */

////////////////////////////////////////////////////////////

//This function creates a frame for the initial window.
void GoToXY(int column, int line)
{
    COORD coord;
    coord.X = column;
    coord.Y = line;

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    if (!SetConsoleCursorPosition(hConsole, coord))
    {
    }
}


// Function for checking integers.
int IsInt(int var)
{
    /*The user enters a value, then the function checks it for correctness.
    If everything fits the conditions - the entered value is 
    returned to the program. If not - enter again.*/
    char Str[20];
    scanf("%s", &Str);
    int count = 0;
    // 1 - true
    while (1)
    {
        count = 0;
        for (int i = 0; i < strlen(Str); i++)
        {
            if (isdigit(Str[i]))
            {
                count++;
            }
        }
        if (count == strlen(Str))
        {
            break;
        }
        else
        {
            printf("%s", "Error. Enter number: ");
            scanf("%s", &Str);
        }
    }
    var = atoi(Str);
    return var;
}


// Function for checking floats.
float IsFloat(float var)
{
    /*The user enters a value, then the function checks it for correctness.
    If everything fits the conditions - the entered value is 
    returned to the program. If not - enter again.*/
    char Str[20];
    scanf("%s", &Str);
    // 1 - true
    while (1)
    {
        int count = 0;
        if (Str[0] == '-')
        {
            count++;
        }
        for (int i = 0; i < strlen(Str); i++)
        {
            if (isdigit(Str[i]) || Str[i] == '.')
            {
                count++;
            }
        }
        if (count != strlen(Str) | (Str[0] == '-' & strlen(Str) == 1))
        {
            printf("%s", "Error, enter again: ");
            scanf("%s", &Str);
        }
        else
        {
            break;
        }

    }
    var = atof(Str);
    return var;
}


////////////////////////////////////////////////////////////////////////////

void start()
{
    // Creating and outputting information about the author.
    // The main window is displayed using printf, loops and ASCII characters.
    system("cls");
    printf("%c", UPPER_LEFT_CORNER);
    for (int i = 0; i < 118; i++) 
    {
        printf("%c", HORIZONTAL_LINE);
    }
    printf("%c", UPPER_RIGHT_CORNER);
    for (int j = 0; j < 28; j++) 
    {
        printf("%c", VERTICAL_LINE);
        for (int k = 0; k < 15; k++) 
        {
            printf("\t");
        }
        printf("%c", VERTICAL_LINE);
    }
    printf("%c", LOWER_LEFT_CORNER);
    for (int p = 0; p < 118; p++) 
    {
        printf("%c", HORIZONTAL_LINE);
    }
    printf("%c\n", LOWER_RIGHT_CORNER);

    system("chcp 1251");
    GoToXY(48, 4);
    printf("  Program for course work");

    GoToXY(40, 10);
    printf("\tTheme: \"Mathematical library\"");

    GoToXY(10, 18);
    printf("Performed by a st. gr. KM-04");

    GoToXY(98, 18);
    printf("Baranchuk S.O.");

    GoToXY(57, 28);
    printf("2021\n\n");

    // Waiting for any character to be entered.
    system("pause");
    // After the main window is displayed - the program clears its field of work.
    system("cls");
}


void menu()
{
    // Menu in program.
    // The user must then enter the selected item.
    printf("Select an option:\n");
    printf("1. Check function power.\n");
    printf("2. Check function square_root.\n");
    printf("3. Check function cube_root.\n");
    printf("4. Check function factorial.\n");
    printf("5. Check function combinations.\n");
    printf("6. Check function placing.\n");
    printf("7. Check function pascal triangle.\n");
    printf("8. Check function sum_arithmetic_progression.\n");
    printf("9. Check function sum_geometric_progression.\n");
    printf("10.Check function sum_infinity_geometric_progression.\n");
    printf("Enter number:\n");
}

////////////////////////////////////////////////////////////////////////
/*Each function in this block will contain a description of the 
function it is checking and the purpose of the function itself.*/


float power_result()
{
    /* Function result is designed to raise a number to a power.
    The number that rises is x. Degree - n.
    The function is created using loop.*/
    
    /*The power_result function checks the maximum load on the described function.*/
    float x, n, p;
    printf("Let's test this function with the built-in math.h library");
    printf("\nEnter x - the number to be raised to the power: ");
    x = IsFloat(x);

    printf("Enter n - power: ");
    n = IsFloat(n);

    for (int i = 1; i < MAXIMUM; i++)
    {
        printf("%d. %0.2f  \n", i,  power(x, n));
    }
}


float square_root_result()
{
    /* The task of function square_root is to calculate the square root of a number.
    n is the number from which we will extract the root.

    To calculate the root, enter the number (double)i.
    Using a loop cycle, we check the number that can be the result.
    The (double)precision variable is introduced for the precision of the 
    fractional part. */
    
    /*The square_root_result function checks the maximum load on the described function.*/
    float n, r;
    printf("Let's test this function with the built-in math.h library");
    printf("\nEnter n - the number from which you want to get the square root: ");
    n = IsFloat(n);
    if (n < 0)
    { 
        printf("Error!");
    }

    for (int i = 1; i < MAXIMUM; i++)
    {
        printf("%d. %0.2f  \n", i,  square_root(n));
    }
}


float cube_root_result()
{
    /* The task of function cube_root is to calculate the cube root of a number.
    n is the number from which we will extract the root.

    To calculate the root, enter the number (double)i.
    Using a loop cycle, we check the number that can be the result.
    The (double)precision variable is introduced for the precision of the fractional part. */
    
    /*The cube_root_result function checks the maximum load on the described function.*/
    float n, r;
    printf("Let's test this function with the built-in math.h library");
    printf("\nEnter n - the number from which you want to get the cube root: ");
    n = IsFloat(n);

    for (int i = 1; i < MAXIMUM; i++)
    {
        printf("%d. %0.2f  \n", i,  cube_root(n));
    }
}


int factorial_result()
{
    /* The Factorial function is created to calculate the factorial of a number.

    The function is created using recursion. */
    
    /*The factorial_result function checks the maximum load on the described function.*/
    int n, fact;
    printf("\nn - the number from which you want to find the factorial: ");
    n = IsInt(n);

    for (int i = 1; i < MAXIMUM; i++)
    {
        printf("%d. %d  \n", i,  factorial(n));
    }
}


int combanations_result()
{
    /* The Combinations function is designed to calculate possible combinations from n to k.
    The function uses the previously written Factorial function. */
    
    /*The combanations_result function checks the maximum load on the described function.*/
    int n, k, c;
    printf("\nn - the number of elements of the set: ");
    n = IsInt(n);

    printf("\nk - plural compounds: ");
    k = IsInt(k);

    for (int i = 1; i < MAXIMUM; i++)
    {
        printf("%d. %d  \n", i,  combinations(n, k));
    }
}


int placing_result()
{
    /* The Placing function is designed to calculate possible permutations from n to k.
    The function uses the previously written Factorial function. */
    
    /*The placing_result function checks the maximum load on the described function.*/
    int n, k, c;
    printf("\nn - the number of elements of the set: ");
    n = IsInt(n);

    printf("\nk - plural compounds: ");
    k = IsInt(k);

    for (int i = 1; i < MAXIMUM; i++)
    {
        printf("%d. %d  \n", i,  placing(n, k));
    }
}


int pascal_triangle_result()
{
    /* The task of the Pascal_triangle function is to output
    a Pascal triangle by the specified number of lines.
    The elements of this triangle are binomial coefficients.*/
    
    /*The pascal_triangle_result function checks the maximum load on the described function.*/
    int n, p;
    printf("\nn - exponent for binomial coefficients: ");
    n = IsInt(n);

    printf("\nResult of function: \n");
            
    for (int i = 1; i < MAXIMUM; i++)
    {
        printf("%d. %d  \n", i,  pascal_triangle(n));
    }
}


float sum_arithmetic_progression_result()
{
    /* This function calculates the sum of the arithmetic progression
    with the known first term, the difference of the progression and the number of elements.

    The formula           2a_1 + d(n-1)
                    S_n = ------------- * n
                                2
    is used. */
    
    /*The sum_arithmetic_progression_result function checks the maximum load on the described function.*/
    float a_1, d, s;
    int n;
    printf("\na_1 - the first element of progression: ");
    a_1 = IsFloat(a_1);

    printf("\n d - progression difference: ");
    d = IsFloat(d);

    printf("\nn - the number of elements in the progression: ");
    n = IsInt(n);

    for (int i = 1; i < MAXIMUM; i++)
    {
        printf("%d. %0.2f  \n", i,  sum_arithmetic_progression(a_1, d, n));
    }
}


float sum_geometric_progression_result()
{
    /* This function calculates the sum of the geometric progression
    with the known first term, nth term and the denominator of the progression.

    The formula           b_1 - b_n * q
                    S_n = -------------
                              1 - q
    is used.*/
    
    /*The sum_geometric_progression_result function checks the maximum load on the described function.*/
    float b_1, b_n, q, s;
    printf("\nb_1 - the first element of progression: ");
    b_1 = IsFloat(b_1);

    printf("\nb_n - the last element of progression: ");
    b_n = IsFloat(b_n);

    printf("\nq - denominator of progression: ");
    q = IsFloat(q);

    for (int i = 1; i < MAXIMUM; i++)
    {
        printf("%d. %0.2f  \n", i,  sum_geometric_progression(b_1, b_n, q));
    }
}


float sum_infinity_geometric_progression_result()
{
    /* This function calculates the sum of the infinity geometric progression
    with the known first term and the denominator of the progression.

    The formula            b_1
                    S_n = ------
                          1 - q
    is used.*/
    
    /*The sum_infinity_geometric_progression_result function checks the maximum load on the described function.*/
    float b_1, q, s;
    printf("\nb_1 - the first element of progression: ");
    b_1 = IsFloat(b_1);

    printf("\nq - denominator of progression: ");
    q = IsFloat(q);

    for (int i = 1; i < MAXIMUM; i++)
    {
        printf("%d. %0.2f  \n", i,  sum_infinity_geometric_progression(b_1, q));
    }
               
}

////////////////////////////////////////////////////////////////////////////////////////

/* This function reads the menu item entered by the user and calls
   up the required function.

   If the user enters an incorrect menu item, the program will display a message about 
   incorrect input and allow you to enter the value again.*/
int function_calls()
{
    int choice = 1;
    scanf(" %d", &choice);
    while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7 && choice != 8
           && choice != 9 && choice != 10) 
    {
        printf("Error. Enter again: \n");
        scanf(" %d", &choice);
    }
    // The selected menu item is displayed using the "switch" multiple choice operator.
    switch (choice)
    {
        case 1:
            power_result();
            break;
        case 2:
            square_root_result();
            break;
        case 3:
            cube_root_result();
            break;
        case 4:
            factorial_result();
            break;
        case 5:
            combanations_result();
            break;
        case 6:
            placing_result();
            break;
        case 7:
            pascal_triangle_result();
            break;
        case 8:
            sum_arithmetic_progression_result();
            break;
        case 9:
            sum_geometric_progression_result();
            break;
        case 10:
            sum_infinity_geometric_progression_result();
            break;
    }
}


int main(void) 
{
    // Display information about author.
    start();

    int choice = 1;
    while (choice != 0) 
    {
        // Display menu.
        menu();
        // Reads the menu item entered by the user and calls up 
        //the required function.
        function_calls();

        // Completion of the program.
        int choice = 0;
        // Exit condition from the program - input 0.
        printf("\nIf you want return to the main menu, press 1, to end the program, press 0: \n");
        scanf(" %d", &choice);
        /* If the user enters an incorrect menu item, the program will display a message about 
        incorrect input and allow you to enter the value again.*/
        while (choice != 1 && choice != 0)
        {
            printf("Error. Enter again: \n");
            scanf(" %d", &choice);
        }
        if (choice == 0)
        {
            exit(1);
        }
        // After work - the program clears its field of work.
        system("cls");
    }
}