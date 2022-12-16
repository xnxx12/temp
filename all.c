//bisection
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
float func(float a){
    float eq1=a*a*a - 5*a +1;
    return eq1;
}
int main(){
    float a,b,x;
    do{
        printf("\nEnter the values of a and b ");
        scanf("%f%f",&a,&b);
        if(func(a)*func(b)>0){
            printf("\nInvalid roots  ");
            continue;
        }
        else{
            printf("\nRoot lies between %f and %f ",a,b);
            break;
        }
    }while(1);
    float prev=(a+b)/2;
    x=prev;
    int i=1;
    while(1){
        if(func(a)*func(x)<0)
            b=x;
        else
            a=x;
        printf("\nFor iteration %d root is %f ",i,x);
        x=(a+b)/2;
        if(fabs(prev-x)<.0001){
            printf("\nRoot is %f",x);
            return 0;
        }
        prev=x;
        i++;
    }
    return 0;
}


//newton_rapson
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
float f(float x){
	return (x*sin(x)+cos(x));
}
float g(float x){
	return x*cos(x);
}
int main(){
	float x0,x1,f1,g1,f2;
	printf("\nEnter the value of x0 ");
	scanf("%f",&x0);
	int i=1;
	while(1){
		f1=f(x0);
		g1=g(x0);
		if(g1==0){
			printf("\nError");
			exit(0);
		}
		x1=x0-(f1/g1);
		f2=f(x1);
		printf("\nAt iteration %d root is %f",i,x1);
		if(fabs(f2-f1)<=.0001){
			printf("\nRoot is %f",x1);
			return 0;
		}
		x0=x1;
		i++;
	}
	return 0;
}



//regular_falsi_method
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
float func(float a){
   float eq1=(a*a*a)-(5*a)+3;
   return eq1;
}
int main(){
   float x0,x1,x;
   while(1){
      printf("\nEnter the value of x0 and x1  ");
      scanf("%f%f",&x0,&x1);
      if(func(x0)*func(x1)<0)
         break;
      else{
         printf("\nEnter the values again ");
         continue;
      }
   }
   float prev=x0-((x1-x0)*func(x0)/(func(x1)-func(x0)));
   x=prev;
   printf("for iteration %d x= %f x0=%f x1=%f  f0=%f  f1=%f\n",1,x,x0,x1,func(x0),func(x1));
   int i=2;
   while(1){
      if(func(x0)*func(x)<0)
         x1=x;
      else
         x0=x;
      x=x0-((x1-x0)/(func(x1)-func(x0)))*func(x0);
      printf("for iteration %d x= %f x0=%f x1=%f  f0=%f  f1=%f\n",i,x,x0,x1,func(x0),func(x1));
      if(fabs(prev-x)<0.0001)
      {
         printf("\nThe root is %f",x);
         return 0;
      }
      prev=x;
      i++;
   }
}



//gauss elimination
#include<stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    printf("equations\n");
    printf("2x1 + 3x2 = 4\n");
    printf("5x1 + 6x2 = 1\n");
    int n;
    printf("enter the no. of unknowns\n");
    scanf("%d",&n);
    float arr[n][n+1];
    printf("enter the matrix\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            scanf("%f",&arr[i][j]);
        }
    }
    for(int i=0;i<=n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            float ratio=arr[j][i]/arr[i][i];
            for(int k=0;k<=n;k++)
            {
                arr[j][k]=arr[j][k]-ratio*arr[i][k];
            }
        }
    }
    printf("upper triangular matrix\n");
     for(int i=0;i<n;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            printf("%f ",arr[i][j]);
        }
        printf("\n");
    }
    float x[n];
    float s;
    x[n-1]=arr[n-1][n]/arr[n-1][n-1];
    for(int i=n-2;i>=0;i--)
    {
        s=0;
        for(int j=i+1;j<n;j++)
        {
            s += (arr[i][j]*x[j]);
            x[i] = (arr[i][n]-s)/arr[i][i];
        }
    }
     printf("\nThe result is :\n");
    for(int i=0; i<n ; i++)
    {
        printf("\nx%d = %.2f",i+1,x[i]);
    }
}


//jordon
#include<stdio.h>
#include<math.h>
int main()
{
    printf("x+2y+3z-w=10\n");
    printf("2x+3y-3z-w=1\n");
    printf("2x-y+2z+3w=7\n");
    printf("3x+2y-4z+3w=2\n");
    int n;
    printf("enter n0. of unknown\n");
    scanf("%d",&n);
    float arr[n][n+1];
    printf("enter the matrix\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            scanf("%f",&arr[i][j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i!=j)
            {
            float ratio=arr[j][i]/arr[i][i];
            for(int k=0;k<n+1;k++)
            {
                arr[j][k]=arr[j][k]-ratio*arr[i][k];
            }
            }
        }
    }
    printf("diagonal matrix\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            printf("%f ",arr[i][j]);
        }
        printf("\n");
    }
    float x[n];
    for(int i=0;i<n;i++)
    {
        x[i]=arr[i][n]/arr[i][i];
    }
    printf("result\n");
    for(int i=0; i<n ; i++)
    {
        printf("\nx%d = %.2f",i+1,x[i]);
    }
}



//seidel
#include<stdio.h>
#include<math.h>
float f1(float y,float z)
{
    return (17-y+2*z)/20;
}
float f2(float x,float z)
{
    return (-18-3*x+z)/20;
}
float f3(float x,float y)
{
    return (25-2*x+3*y)/20;
}
int main()
{
   printf("3x + 20y - z = -18\n");
   printf("2x - 3y + 20z = 25\n");
   printf("20x + y - 2z = 17\n");
   printf("equations in diagonally dominant form\n");
   printf("20x + y - 2z = 17\n");
   printf("3x + 20y - z = -18\n");
   printf("2x - 3y + 20z = 25\n");
   float x0=0,y0=0,z0=0,x1,y1,z1,e=0.0001;
   while(1)
   {
    x1=f1(y0,z0);
    y1=f2(x0,z0);
    z1=f3(x0,y0);
    printf("x= %0.4f y= %0.4f z= %0.4f\n",x1,y1,z1);
    if(fabs(x0-x1)<=e&&fabs(y0-y1)<=e&&fabs(z0-z1)<=e)
    {
        x0=x1;
        y0=y1;
        z0=z1;
        break ;
    }
    x0=x1;
    y0=y1;
    z0=z1;
  }
   printf("result:\n");
   printf("x= %0.3f y= %0.3f z= %0.3f\n",x0,y0,z0);
}




//Newton forward
#include <bits/stdc++.h>
using namespace std;
 
// calculating u mentioned in the formula
float u_cal(float u, int n)
{
    float temp = u;
    for (int i = 1; i < n; i++)
        temp = temp * (u - i);
    return temp;
}
 
// calculating factorial of given number n
int fact(int n)
{
    int f = 1;
    for (int i = 2; i <= n; i++)
        f *= i;
    return f;
}
 
int main()
{
    // Number of values given
    int n = 4;
    float x[] = { 45, 50, 55, 60 };
     
    // y[][] is used for difference table
    // with y[][0] used for input
    float y[n][n];
    y[0][0] = 0.7071;
    y[1][0] = 0.7660;
    y[2][0] = 0.8192;
    y[3][0] = 0.8660;
 
    // Calculating the forward difference
    // table
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++)
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
    }
 
    // Displaying the forward difference table
    for (int i = 0; i < n; i++) {
        cout << setw(4) << x[i]
             << "\t";
        for (int j = 0; j < n - i; j++)
            cout << setw(4) << y[i][j]
                 << "\t";
        cout << endl;
    }
 
    // Value to interpolate at
    float value = 52;
 
    // initializing u and sum
    float sum = y[0][0];
    float u = (value - x[0]) / (x[1] - x[0]);
    for (int i = 1; i < n; i++) {
        sum = sum + (u_cal(u, i) * y[0][i]) /
                                 fact(i);
    }
 
    cout << "\n Value at " << value << " is "
         << sum << endl;
    return 0;
}



//Newton backward
#include <bits/stdc++.h>
using namespace std;
 
// Calculation of u mentioned in formula
float u_cal(float u, int n)
{
    float temp = u;
    for (int i = 1; i < n; i++)
        temp = temp * (u + i);
    return temp;
}
 
// Calculating factorial of given n
int fact(int n)
{
    int f = 1;
    for (int i = 2; i <= n; i++)
        f *= i;
    return f;
}
 
int main()
{
    // number of values given
    int n = 5;
    float x[] = { 1891, 1901, 1911,
                  1921, 1931 };
                   
    // y[][] is used for difference
    // table and y[][0] used for input
    float y[n][n];
    y[0][0] = 46;
    y[1][0] = 66;
    y[2][0] = 81;
    y[3][0] = 93;
    y[4][0] = 101;
 
    // Calculating the backward difference table
    for (int i = 1; i < n; i++) {
        for (int j = n - 1; j >= i; j--)
            y[j][i] = y[j][i - 1] - y[j - 1][i - 1];
    }
 
    // Displaying the backward difference table
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++)
            cout << setw(4) << y[i][j]
                 << "\t";
        cout << endl;
    }
 
    // Value to interpolate at
    float value = 1925;
 
    // Initializing u and sum
    float sum = y[n - 1][0];
    float u = (value - x[n - 1]) / (x[1] - x[0]);
    for (int i = 1; i < n; i++) {
        sum = sum + (u_cal(u, i) * y[n - 1][i]) /
                                     fact(i);
    }
 
    cout << "\n Value at " << value << " is "
         << sum << endl;
    return 0;
}



//Lagrange’s

#include<stdio.h>
#include<conio.h>

void main()
{
	 float x[100], y[100], xp, yp=0, p;
	 int i,j,n;
	 clrscr();
	 /* Input Section */
	 printf("Enter number of data: ");
	 scanf("%d", &n);
	 printf("Enter data:\n");
	 for(i=1;i<=n;i++)
	 {
		  printf("x[%d] = ", i);
		  scanf("%f", &x[i]);
		  printf("y[%d] = ", i);
		  scanf("%f", &y[i]);
	 }
	 printf("Enter interpolation point: ");
	 scanf("%f", &xp);
	 /* Implementing Lagrange Interpolation */
	 for(i=1;i<=n;i++)
	 {
		  p=1;
		  for(j=1;j<=n;j++)
		  {
			   if(i!=j)
			   {
			    	p = p* (xp - x[j])/(x[i] - x[j]);
			   }
		  }
		  yp = yp + p * y[i];
	 }
	 printf("Interpolated value at %.3f is %.3f.", xp, yp);
	 getch();
}





//trapozodial
#include<stdio.h>
#include<math.h>
 
/* Define the function to be integrated here: */
double f(double x){
  return x*x;
}
 
/*Program begins*/
main(){
  int n,i;
  double a,b,h,x,sum=0,integral;
  /*Ask the user for necessary input */
  printf("\nEnter the no. of sub-intervals: ");
  scanf("%d",&n);
  printf("\nEnter the initial limit: ");
  scanf("%lf",&a);
  printf("\nEnter the final limit: ");
  scanf("%lf",&b);
  /*Begin Trapezoidal Method: */
  h=fabs(b-a)/n;
  for(i=1;i<n;i++){
    x=a+i*h;
    sum=sum+f(x);
  }
  integral=(h/2)*(f(a)+f(b)+2*sum);
  /*Print the answer */
  printf("\nThe integral is: %lf\n",integral);
}


//simpsons 1/3
#include<stdio.h>
#include<stdlib.h>
float eq(float x){
	return 1/(1+x*x);
}
int main(){
	int a,b,s;
	float h;
	printf("\nEnter the intervals  ");
	scanf("%d%d",&a,&b);
	printf("\nEnter the number of strips ");
	scanf("%d",&s);
	h=(b-a)/(float)s;
	printf("%f",h);
	float x[s+1],y[s+1];
	x[0]=0;
	y[0]=eq(x[0]);
	for(int i=1;i<s+1;i++){
		x[i]=x[i-1]+h;
		y[i]=eq(x[i]);
	}
	float ans=0;
	ans+=y[0]+y[s];
	for(int i=1;i<s;i++){
		if(i%2==0)
			ans+=y[i]*2;
		else
			ans+=y[i]*4;
	}
	ans=ans*(h/3);
	printf("\n%f",ans);
	return 0;
}



//simpsons 3/8
#include<stdio.h>
#include<stdlib.h>
float eq(float x){
	return 1/(1+x*x);
}
int main(){
	int a,b,s;
	float h;
	printf("\nEnter the intervals  ");
	scanf("%d%d",&a,&b);
	printf("\nEnter the number of strips ");
	scanf("%d",&s);
	h=(b-a)/(float)s;
	printf("%f",h);
	float x[s+1],y[s+1];
	x[0]=0;
	y[0]=eq(x[0]);
	for(int i=1;i<s+1;i++){
		x[i]=x[i-1]+h;
		y[i]=eq(x[i]);
	}
	float ans=0;
	ans+=y[0]+y[s];
	for(int i=1;i<s;i++){
		if(i%3==0)
			ans+=y[i]*2;
		else
			ans+=y[i]*3;
	}
	ans=ans*(3*h/8);
	printf("\n%f",ans);
	return 0;
}


