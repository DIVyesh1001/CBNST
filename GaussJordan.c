#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    printf("Enter thr size of matrix : ");
    scanf("%d", &n);
    float ans[n+1];


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
        if (matrix[i][i] == 0.0)
        {
            printf("Mathematical Error!");
            return 0;
        }
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
            {
                x = matrix[j][i] / matrix[i][i];
                for (int k = 1; k <= (n + 1); k++)
                {
                    matrix[j][k] = matrix[j][k] - x * matrix[i][k];
                }
            }
        }
    }
    printf("\n");

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%0.2f ", matrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 1; i <= n; i++)
    {
        ans[i] = matrix[i][n + 1] / matrix[i][i];
    }

    for(int i=1;i<=n;i++)
    {
        printf("\nx[%d] = %0.2f\n",i,ans[i]);
    }
    return 0;
}