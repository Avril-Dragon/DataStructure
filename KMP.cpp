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
		return(i-t.length+1);
	else
		return -1;
}

int KMP(Str s,Str t,int next[])
{
	int i=0,j=0;
	while(i<s.length&&j<t.length)
	{
		if(j==-1||s.data[i]==t.data[j])
		{
			i++;
			j++; 
		}
		else
		{
			j=next[j];
		}
	}
	if(j>=t.length)
		return(i-t.length+1);
	else
		return -1;
}

void GetNext(Str t,int next[])
{
	int j=0,k=-1;
	next[0]=-1;
	while(j<t.length)
	{
		if(k==-1||t.data[j]==t.data[k])
		{
			j++;
			k++;
			next[j]=k;
		}
		else
			k=next[k];	//k back 
	}
	printf("The next[] for %s is:\n",t);
	for(int i=0;i<5;i++)
		printf("%d",next[i]);
	printf("\n");
	
}

int main()
{
	Str s,t;
	int next[5];
	strcpy(s.data,"aaabaaaab");
	s.length=9;
	strcpy(t.data,"aaaab");
	t.length=5;
	
	//printf("%d",BF(s,t)); 
	GetNext(t,next); 
	printf("index:%d",KMP(s,t,next)); 
}
