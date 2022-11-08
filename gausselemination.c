#include <stdio.h>
void GaussElimination(float arr[][4], int n)
{
    printf("Augmented Matrix\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%f\t", arr[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i > j)
            {
                float c = arr[i][j] / arr[j][j];
                for (int k = 0; k <= n; k++)
                {
                    arr[i][k] = arr[i][k] - (arr[j][k] * c);
                }
            }
        }
    }
    printf("Final Matrix\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%f\t", arr[i][j]);
        }
        printf("\n");
    }
    float x[n];
    x[n - 1] = arr[n - 1][n] / arr[n - 1][n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        int sum = 0;
        for (int j = i + 1; j < n; j++)
        {
            sum = sum + arr[i][j] * x[j];
        }
        x[i] = (arr[i][n] - sum) / arr[i][i];
    }
    printf("\nThe solution is: \n");
    for (int i = 0; i < n; i++)
    {
        printf("\nx%d=%f\t", i, x[i]);
    }
}
int main()
{
    int n;

    printf("Enter the number of equations:");
    scanf("%d", &n);
    float arr[n][4];
    printf("Enter the EQUATION in form ax+by+cz=d :\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter the equation-%d:", i + 1);
        scanf("%fx%fy%fz=%f", &arr[i][0], &arr[i][1], &arr[i][2], &arr[i][3]);
    }
    GaussElimination(arr, 3);
    return 0;
}
