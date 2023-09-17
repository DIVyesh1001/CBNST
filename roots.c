#include <stdio.h>
#include <math.h>
float f(float x)
{
    return (x * x * x - 9 * x + 1);
}
int main()
{
    float x, x1, x2, aerror;
    int flag = 0, itr = 0;
    do
    {
        printf("\nEnter the value of x1 and x2 : ");
        scanf("%f %f", &x1, &x2);
        if (f(x1) * f(x2) < 0)
        {
            flag = 1;
            printf("Roots lie between %f anad %f", x1, x2);
        }
        else
        {
            printf("Wrong Intervals,try again!!");
        }
    } while (flag != 1);

    printf("\nEnter allowed error: ");
    scanf("%f", &aerror);
    do
    {
        x = (x1 + x2) / 2;
        if (f(x1) * f(x) < 0)
        {
            x2 = x;
        }
        else if (f(x) * f(x2) < 0)
        {
            x1 = x;
        }
        else
        {
            break;
        }
        itr++;
        printf("\nno of iterations %d \n", itr);
        printf("root=%f \n", x);
        printf("Values of function = %f \n", (f(x)));
    } while ((x2 - x1) >= aerror);

    return 0;
}