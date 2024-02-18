#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
	
    int num=0;
    int num1=0;
    
    float n = 0;
    float n1 = 0;
    
    scanf("%d %d\n", &num, &num1);
    scanf("%f %f\n", &n, &n1);
    
    int sum = num + num1;
    int diff = num - num1;
    
    float s = n + n1;
    float d = n - n1;
    
    printf("%d %d\n", sum, diff);
    printf("%.1f %.1f", s, d);
    
 
}
