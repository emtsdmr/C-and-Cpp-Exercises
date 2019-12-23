//program that enlarges the first letter of each sentence in a given paragraph
#include <stdio.h>
int main()
{
	char paragraph[100];
	int i=0;
	printf("enter paragraph:\n");
	gets(paragraph);
	
	if ((paragraph[0]<='z') && (paragraph[0]>='a'))	paragraph[0]=paragraph[0]-('a'-'A');
	
	while(paragraph[i]!='\0')
	{
		if ((paragraph[i]=='.') && (paragraph[i+1]<='z') && (paragraph[i+1]>='a'))
			paragraph[i+1]=paragraph[i+1]-('a'-'A');
		i++;
	}
	printf("%s\n",paragraph);
	
	return 0;
}
