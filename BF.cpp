#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MaxSize 10

typedef struct SqString
{
	char data[MaxSize];
	int length;
}Str;

int BF(Str s,Str t)
{
	//printf("%s\n%s\n",s,t);
	int i=0,j=0;
	while(i<s.length&&j<t.length)
	{
		if(s.data[i]==t.data[j])
		{
			//printf("s:%c\nt:%c\n",s.data[i],t.data[j]);
			i++;
			j++;
		}
		else
		{
			i=i-j+1;
			j=0;
		}
	}
	if(j>=t.length)
		return(i-t.length);
	else
		return -1;
}

int main()
{
	Str s,t;
	strcpy(s.data,"aaabaabc");
	s.length=8;
	strcpy(t.data,"baabc");
	t.length=5;
	
	printf("%d",BF(s,t)); 
}
