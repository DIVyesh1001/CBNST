#include <stdio.h>
#include <math.h>

// Define the function whose root is to be found
double f(double x)
{
    // Example: f(x) = x^3 - 2x - 5
    return pow(x, 3) - 2 * x - 5;
}

// Define the bisection method
double bisection(double a, double b, double tol)
{
    // Check if the initial interval is valid
    if (f(a) * f(b) >= 0)
    {
        printf("Invalid interval. The function must have opposite signs at the endpoints.\n");
        return NAN;
    }

    // Initialize the variables
    double c;  // The midpoint of the interval
    int n = 0; // The number of iterations

    // Repeat until the interval is smaller than the tolerance
    while ((b - a) >= tol)
    {
        // Find the midpoint
        c = (a + b) / 2;

        // Check if the midpoint is the root
        if (f(c) == 0)
        {
            break;
        }
        // Check which subinterval contains the root
        else if (f(c) * f(a) < 0)
        {
            b = c;
        }
        else
        {
            a = c;
        }

        // Increment the iteration count
        n++;
    }

    // Print the number of iterations and the final interval
    printf("The number of iterations is %d\n", n);
    printf("The final interval is [%f, %f]\n", a, b);

    // Return the midpoint as the root
    return c;
}

// Define the main function
int main()
{
    // Define the initial interval and the tolerance
    double a = 2;        // The lower bound of the interval
    double b = 3;        // The upper bound of the interval
    double tol = 0.0001; // The desired accuracy

    // Call the bisection method and print the result
    double root = bisection(a, b, tol);
    printf("The root of the equation is %f\n", root);

    return 0;
}
