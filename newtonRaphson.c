#include <stdio.h>
#include <math.h>

float f(float x)
{
    // return (x * x * x - 5 * x + 1);
    return (x*x*x-17);
}

float fdif(float x)
{
    // return (3 * x * x - 5);
    return (3*x*x);
}

int main()
{
    float x, x0, x1, aerror, h;
    int flag = 0, itr = 0;

    printf("Enter the value of x0: ");
    scanf("%f", &x0);

    printf("\nEnter allowed error :");
    scanf("%f", &aerror);

    do
    {
        h = (f(x0) / fdif(x0));
        x1 = (x0 - h);

        itr++;
        printf("\nItration : %d", itr);
        printf("\nRoot : %f \n", x1);
        x0 = x1;
    } while (fabs(f(x1)) > aerror);

    return 0;
}