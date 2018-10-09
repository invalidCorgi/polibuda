#include <stdio.h>
#include <math.h>

int main()
{
    int a,b,c;
    float delta;

    printf("a= ");
    scanf("%d",&a);
    printf("b= ");
    scanf("%d",&b);
    printf("c= ");
    scanf("%d",&c);

    delta = b*b-4*a*c;

    if(delta>0)
    {
        printf("Pierwiastki rownania: x1=%f, x2=%f",(-b-sqrt(delta))/(2*a),(-b+sqrt(delta))/(2*a));
    }
    if(delta==0)
    {
        printf("Pierwiastek rownania: x=%f",(float)-b/(2*a));
    }
    if(delta<0)
    {
        float x=(float)-b/(2*a);
        float i=sqrt(-delta)/(2*a);
        printf("Pierwiastki rownania: x1=%f+%fi, x2=%f-%fi",x,i,x,i);
    }

    return 0;
}
