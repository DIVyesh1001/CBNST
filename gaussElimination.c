#include <stdio.h>
int main()
{
    int n;
    printf("Enter the size of matrix : ");
    scanf("%d", &n);

    float matrix[n + 1][n + 2];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n + 1; j++)
        {
            scanf("%f", &matrix[i][j]);
        }
    }

    float x = 0.0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n + 1; j++)
        {
            x = matrix[j][i] / matrix[i][i];
            for (int k = 1; k <= (n + 1); k++)
            {
                matrix[j][k] = matrix[j][k] - x * matrix[i][k];
            }
        }
    }

    float ul[n+1]; 
    ul[n]= matrix[n][n + 1] / matrix[n][n];
    printf("\n");

    for (int i = n-1; i >= 1; i--)
    {
        ul[i] = matrix[i][n + 1];
        for (int j = i + 1; j <= n ; j++)
        {
            ul[i] = ul[i] - matrix[i][j] * ul[j];
        }
        ul[i] = ul[i] / matrix[i][i];
    }

    printf("\n");

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n + 1; j++)
        {
            printf("%0.2f ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for(int i=1;i<=n;i++)
    {
        printf("x[%d] = %f\n",i,ul[i]);
    }

    return 0;
}