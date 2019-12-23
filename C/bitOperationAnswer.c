/* 16 questions yes / no test is being done
take the answer key in the form of yes / no Keep in 16bit answers
 get the person's answer as short
 write as short how many questions is true */
#include <stdio.h>
int main()
{ 
	unsigned short correctanswers = 0,answer2=0,testanswer,result; 
	short int j,score=0; 
	char c; 
	printf("sizeof short %d\n",sizeof(j));
	/* if the first question is kept in the leftmost bit*/
	/*for (j=0; j <= 15; j++)
	{ 
		scanf ("%c", &c); 
		if (c == 'y' || c == 'Y') 
		{
			answer2=1<<(15-j);
			correctanswers = answer2 | correctanswers;
			answer2=0;
		}
	}
	*/
	/* eger ilk soru en sað bitte tutuluyorsa*/
	answer2=1;
	for (j=0; j <= 15; j++)
	{ 
		c=getch();
		putch(c);
		if (c == 'y' || c == 'Y') 
			correctanswers = answer2 | correctanswers;
		answer2<<=1;
	}
	
	
	printf( "Correct answers :%d\n",correctanswers);
	printf("Client's Answers?\n");
	scanf("%d",&testanswer);
	result=testanswer^correctanswers;  //same 0 different 1
	printf("result:%d",result);
	answer2=1;
	for (j=0; j <= 15; j++)
	{ 
		if (answer2&result)
			score++;
		answer2=answer2<<1;
	}
	printf("score:%d\n",16-score);
	
}
