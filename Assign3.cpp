#include<stdio.h>

int a[104];
int ta[104][104];
int ini = 100111;
int len;
int r( int s , int e , int turn)
{
	if( turn==0 && e%2==1)
		return 1;
	if( turn%2 == 0)
	{
		if( s == e)
			return a[s];
 	 else
  		{
			if( ta[s][e] == ini)
			{
				turn++;
				int cs = a[s]+r( s+1 , e ,turn) , ce = a[e]+r( s , e-1 ,turn);
				if(cs > ce)
					ta[s][e] = cs;
				else
					ta[s][e] = ce;
			}
			return ta[s][e];
		}
	}
	else
	{
		if( s==e)
			return -1*a[s];
		else
		{
			if( ta[e][s] == ini)
			{
   				turn++;
				int cs = -1*a[s]+r( s+1 , e ,turn) , ce = -1*a[e]+r( s , e-1 ,turn);
				if(cs < ce )
					ta[e][s] = cs;
				else
				 	ta[e][s] = ce;
			}
			return ta[e][s];
		}
	}
}

int main()
{
	while( scanf("%d",&len) != -1)
	{
		for( int i=0 ; i<104 ; i++)
			for( int j=0 ; j<104 ; j++)
				ta[i][j] = ini;
		//--------------------------------------
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
