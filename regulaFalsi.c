#include <stdio.h>
#include <math.h>

float f(float x)
{
    // return (x * x * x - 9 * x + 1);
    return (x*log10(x) - 1.2);
}

int main()
{
    float x0, x1, x, aerror;
    int itr = 0, flag = 0;

    do
    {
        printf("Enter the x0 and x1 : ");
        scanf("%f %f", &x0, &x1);

        if (f(x0) * f(x1) < 0)
        {
            flag = 1;
            printf("Roots lie between %f anad %f", x0, x1);
        }
        else
        {
            printf("Wrong Intervals,try again!!");
        }
    } while (flag != 1);

    printf("\nEnter the allowed error : ");
    scanf("%f", &aerror);

    do
    {
        x = (x0 - (x0 - x1) * f(x0) / (f(x0) - f(x1)));

        if (f(x) * f(x0) < 0)
        {
            x1 = x;
        }
        if (f(x) * f(x1) < 0)
        {
            x0 = x;
        }
        itr++;
        printf("\nroot=%f \n", x);
        printf("no of iterations %d \n", itr);
        printf("Values of function = %f \n", (f(x)));
    } while (fabs(f(x)) > aerror);
    return 0;
}