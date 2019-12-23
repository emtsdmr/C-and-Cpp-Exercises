// string decimal number to a float variable
#include <stdio.h>
int main()
{
    char number[20],dummy;
    float result=0,element,j=1.0;
	int i=0;
	printf("String Number\n");
	gets(number);
	printf("Number:%s",number);
	while (number[i]!='.')
	{
		result=result*10;
		result=result+(number[i]-'0');
		i++;
	}
	i++;
	while  (number[i]!=0)
	{
		j=j/10;
		element=number[i]-'0';
		element=element*j;
		result=result+element;
		i++;
	}
	printf("Result:%f",result);
	return 0;
}
