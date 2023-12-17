#include <stdio.h>
int main()
{
    int n, h, X,p=1,val;
    scanf("%d", &n);
    int x[n], y[n][n];
    printf("Enter the values of x and y:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d\t%d", &x[i], &y[i][0]);
    }

    h = x[1] - x[0];

    printf("Enter the value to be determined: ");
    scanf("%d", &X);

    int u = (X - x[0]) / h;
    val=y[0][0];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
        }
        p=p*(u-i+1)/i;
        val=val+p*y[0][i];
    }

    for (int i = 0; i < n; i++)
    {
        printf("\n");
        for (int j = 0; j < n - i; j++)
        {
            printf("%d\t", y[i][j]);
        }
    }

    printf("\n value %d",val);
}