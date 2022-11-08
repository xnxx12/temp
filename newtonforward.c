#include<stdio.h>
void forward(float x[10], float y[10][10], int n)
{
    float a;
    scanf("%f",&a); 
    float h, u;
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
        }
    }
    // table
    for (int i = 0; i < n; i++) {
        printf("\n");
        for (int j = 0; j < n - i; j++) {
            printf("%f\t", y[i][j]);
        }
    }

  
    float p = 1.0;
    float sum = y[0][0];
    h = x[1] - x[0];
    u = (a - x[0]) / h;
    for (int j = 1; j < n; j++) {
        p = p * (u - j + 1) / j;
        sum = sum + p * y[0][j];
    }
    printf("\nThe value of y at x=%f is %f", a, sum);
}

int main(){
    int n;scanf("%d",&n);
    float x[10];
    float y[10][10];
    for(int i=0;i<n;i++){
        scanf("%f",&x[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%f",&y[i][0]);
    }
    forward(x,y,n);
}
