#include <stdio.h>
#include <math.h>

float f(float x)
{
    return (x*exp(x)-cos(x));
}

int main()
{
    float x, x0, x1, aerror;
    int flag = 0, itr = 0;
    do
    {
        printf("Enter the value of x0 and x1 : ");
        scanf("%f %f", &x0, &x1);
        if (f(x0) * f(x1) < 1)
        {
            flag = 1;
            printf("The root lie between x0 and x1 ");
        }
        else
        {
            printf("The root does not lie between x0 and x1.Enter correct intervals");
        }
    } while (flag != 1);
    printf("Enter allowed error : ");
    scanf("%f", &aerror);

    do
    {
        x = x1 - (((x1 - x0) / (f(x1) - f(x0))) * f(x1));
        itr++;
        printf("\nItration : %d",itr);
        printf("\nRoot : %f",x);

        x0=x1;
        x1=x;

    }while(fabs(f(x1))>aerror);
    return 0;
}