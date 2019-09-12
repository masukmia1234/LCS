#include<stdio.h>
#include<iostream>
#include<string.h>
#define max 50
using namespace std;
char a[max],b[max];
int c[max][max],d[max][max];
void lcs(int m,int n)
{
	int i,j;
	for(i=1;i<=m;i++)
		c[i][0]=0;
	for(i=0;i<=n;i++)
		c[0][i]=0;
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{

			if(a[i-1]==b[j-1]){
				c[i][j]=c[i-1][j-1]+1;
				d[i][j]=1;
			}
			else
			{
				if(c[i-1][j]>=c[i][j-1])
				{
					c[i][j]=c[i-1][j];
					d[i][j]=2;

				}
				else
				{
					c[i][j]=c[i][j-1];
					d[i][j]=3;
				}
				}
		}
	}

}
int print(int i,int j)
{
   if(i==0 || j==0)
	   return 0;
   if(d[i][j]==1)
   {
	   print(i-1,j-1);
	   printf("%c",a[i-1]);
   }
   else if(d[i][j]==2)
	   print(i-1,j);
   else
	   print(i,j-1);
}
int main()
{
	while(1){
	gets(a);
	gets(b);

	int l,m;
	l=strlen(a);

	m=strlen(b);
	lcs(l,m);
     print(l,m);
	 cout<<endl;
	}

}
