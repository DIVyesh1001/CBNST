#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    printf("Enter the number of obsesrvation: ");
    scanf("%d", &n);
    float x[n];
    float matrix[n][n];
    printf("Enter the values of x: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &x[i]);
    }

    printf("enter the value of y : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &matrix[i][0]);
    }
    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < n - j; i++)
        {
            matrix[i][j] = matrix[i + 1][j - 1] - matrix[i][j - 1];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            printf("%0.4f ", matrix[i][j]);
        }
        printf("\n");
    }

    float a;

    printf("\nEnter the value of interpolation point : ");
    scanf("%f", &a);

    float p,h,sum;
    float u=1.0;
    h=x[1]-x[0];
    p=(a-x[0])/h;
    sum=matrix[0][0];

    for (int j = 1; j < n; j++)
    {
        u=u*(p-j+1)/j;
        sum=sum+u*matrix[0][j];
    }

    printf("\nThe value of ya at x=%0.2f is %0.4f",a,sum);
}