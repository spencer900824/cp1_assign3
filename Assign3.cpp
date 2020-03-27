#include<stdio.h>

int a[104];
int len;
int r( int s , int e , int turn)
{
	if( turn%2 == 0)
	{
		if( s == e)
			return a[s];
 	 else
  		{
			turn++;
			int cs = a[s]+r( s+1 , e ,turn),ce = a[e]+r( s , e-1 ,turn);
			return cs > ce ? cs : ce;

		}
	}
	else
	{
		if( s==e)
			return -1*a[s];
		else
		{
			turn++;
			int cs = -1*a[s]+r( s+1 , e ,turn) , ce = -1*a[e]+r( s , e-1 ,turn);
			return cs < ce ? cs:ce;

		}
	}

}

int main()
{
	while( scanf("%d",&len) != -1)
	{
		int s=0 , e=len-1;
		for( int i=s ; i<=e ; i++)
		{
			scanf("%d",&a[i]);
		}
		int ans = r( s,e,0);
		if( ans>=0)
			puts("True");
		else
			puts("False");
	}
	return 0;
}



