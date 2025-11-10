#include <stdio.h>
#include <math.h>



double togiA(double x,double y)
{
    double A;
    A=(2*cos(x-M_PI/6))/(1/2+sin(y)*sin(y));
    
return A;
}
double togiB(double z)
{
  double B;
B=(1+(z*z)/(3+(z*z/5)));

return B;  
}

int main(){
    double A=0 , B=0;
    double x= 1.426, y= -1.22, z= 3.5;
A=togiA(x,y);
B=togiB(z);
    printf("A=%f\n",A);
    printf("B=%f\n",B);

    return 0;
}
