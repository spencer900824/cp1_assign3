#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
// function of action --------
int m_on(int , int); // move = 0 ; pile = 2 ; onto = 4 ; over = 8
int m_ov(int , int);
int p_on(int , int);
int p_ov(int , int);
//----------------------------
struct L
{
 int x;
 int y;
};
typedef struct L l;
// function to initialize-----
int n_box;
char mp[5];
char nv[5];
int ina;
int inb;
int command_code=-1;
int table[25][25];
//---------------------------------
int main()
{
	for( int i=0 ; i<25 ; i++)
		for( int j=0 ; j<25 ; j++)
			table[i][j] = -1;
	//creat the initial-------------------
	scanf("%d",&n_box);
	for( int i=0 ; i<n_box ; i++)
	{
		table[i][0]=i;
	}
	// start receive the command ----------
	while( scanf("%s",mp) != EOF)
	{
		if( mp[0]=='q')
		{
			for( int i=0 ; i<n_box ; i++)
			{
				printf("%d: ",i);
				for( int j=0 ; table[i][j] != -1;j++)
					printf("%d ",table[i][j]);
				printf("\n");
			}
			// initialize------------------
			for( int i=0 ; i<25 ; i++)
			for( int j=0 ; j<25 ; j++)
				table[i][j] = -1;
			//creat the initial-------------------
			scanf("%d",&n_box);
			for( int i=0 ; i<n_box ; i++)
			{
				table[i][0]=i;
			}
		}
		else
		{
				scanf("%d",&ina);
				scanf("%s",nv);
				scanf("%d",&inb);

			if(mp[0] == 'm')
				command_code+=1;
			if(mp[0] == 'p')
				command_code+=3;
			if(nv[1] == 'n')
				command_code+=4;
			if(nv[1] == 'v')
				command_code+=8;
		 	switch( command_code )
		 	{
		 		case 4:
		 			m_on(ina,inb);
		 			break;
		 		case 8:
		 			m_ov(ina,inb);
		 			break;
		 		case 6:
		 			p_on(ina,inb);
		 			break;
		 		case 10:
		 			p_ov(ina,inb);
		 			break;
			}
			command_code = -1;
		}
			
  	}
	return 0;
}

l find(int a)
{
	l loc;
	for( int i=0 ; i<25 ; i++)
		for( int j=0 ; j<25 ; j++)
		{
			if( table[i][j] == a)
			{
				loc.x=i;
				loc.y=j;
				return loc;
			}
		}
}
int* find_top( int a)
{
	for( int i=0 ; ;i++)
	{
		if( table[a][i] == -1)
			return &(table[a][i]) ;
	}
}
int m_on(int a, int b)
{
	l la = find(a);
	l lb = find(b);
	// error--------------------------
	if( la.x == lb.x)
		return 0;
	/*
	for( int i=la.y ; table[la.x][i] != -1 ; i++)
	{
		if(table[la.x][i] == lb.x)
			return 0;
	}
	for( int i=lb.y ; table[lb.x][i] != -1 ; i++)
	{
		if(table[lb.x][i] == la.x)
			return 0;
	*/
	//clean a-----------------------------------
	for(int i=la.y+1 ; table[la.x][i] != -1 ; )
	{
		int* top = find_top( table[la.x][i] );
		*(top) = table[la.x][i];
		table[la.x][i] = -1;
		i++;
	}
	//clean b----------------------------------
	for(int i=lb.y+1 ; table[lb.x][i] != -1 ; )
	{
		int* top = find_top( table[lb.x][i] );
		*(top) = table[lb.x][i];
		table[lb.x][i] = -1;
		i++;
	}
	// move a onto b----------------------------
	table[lb.x][lb.y+1] = table[la.x][la.y];
	table[la.x][la.y] = -1;
	return 1;
}
int m_ov(int a, int b)
{
	l la = find(a);
	l lb = find(b);
	// error--------------------------
	if( la.x == lb.x)
		return 0;
	//clean a-----------------------------------
	for(int i=la.y+1 ; table[la.x][i] != -1 ; )
	{
		int* top = find_top( table[la.x][i] );
		*(top) = table[la.x][i];
		table[la.x][i] = -1;
		i++;
	}
	//m a ov b-------------
	*(find_top(lb.x)) = table[la.x][la.y];
	table[la.x][la.y] = -1;
	return 1;
}
int p_on(int a, int b)
{
	l la = find(a);
	l lb = find(b);
	// error--------------------------
	if( la.x == lb.x)
		return 0;
	//clean b----------------------------------
	for(int i=lb.y+1 ; table[lb.x][i] != -1 ; )
	{
		int* top = find_top( table[lb.x][i] );
		*(top) = table[lb.x][i];
		table[lb.x][i] = -1;
		i++;
	}
	// p a on b---------------------
	for( int i= la.y ; ;i++)
	{
		if( table[la.x][i] == -1)
			break;
		int* btop = find_top(lb.x);
		*(btop) = table[la.x][i];
		table[la.x][i] = -1;
	}
	return 1;
}
int p_ov(int a, int b)
{
	l la = find(a);
	l lb = find(b);
	// error--------------------------
	if( la.x == lb.x)
		return 0;
	for( int i= la.y ; ;i++)
	{
		if( table[la.x][i] == -1)
			break;
		int* btop = find_top(lb.x);
		*btop = table[la.x][i];
		table[la.x][i] = -1;
	}
	return 1;
}
