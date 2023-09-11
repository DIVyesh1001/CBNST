#include <stdio.h>
#include <math.h>

float f(float x)
{
    return (cos(x) - 3 * x + 1);
}

float phi(float x)
{
    return ((cos(x) + 1) / 3);
}

float dphi(float x)
{
    return (sin(x) / 3);
}

int main()
{
    float x0, x1, aerror;
    int itr = 0;
    printf("Enter the value of x0 : ");
    scanf("%f", &x0);
    printf("Enter allowed error : ");
    scanf("%f", &aerror);
    if (dphi(x0) > 1)
    {
        printf("ERROR!!! Change the phi function!!!");
        return 0;
    }
    do
    {
        x1 = phi(x0);
        itr++;
        printf("\nItration : %d", itr);
        printf("\nROOT : %f", x1);
        x0 = x1;
    } while (fabs(f(x1)) > aerror);
    return 0;
}