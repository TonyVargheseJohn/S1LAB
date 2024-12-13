#include <stdio.h>
#include <conio.h>
int parent[10];
void main()
{
	int n,i,j,cost[10][10],count=1,edgecount,c,mincost=0,v1,rno,v2,cno;
	clrscr();
	printf("Enteer the number of vertices\n");
	scanf("%d",&n);
	printf("Enter cost adjacency matrix\n");
	for(i=1;i<=n;++i)
	{
		for(j=i;j<=n;++j)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
				cost[i][j]=999;
			cost[j][i]=cost[i][j];
		}
	}
	printf("Cost Adjacency matrix\n");
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
		{
			printf("%d  ",cost[i][j]);
		}                               \
		printf("\n");
	}
	//setting parent
	for(i=1;i<=n;++i)
		parent[i]=i;
	edgecount=n-1;
	while(count<=edgecount)
	{
		c=999;
		for(i=1;i<=n;++i)
		{
			for(j=1;j<=n;++j)
			{
				if(cost[i][j]<c)
				{
					c=cost[i][j];
					v1=rno=i;
					v2=cno=j;
				}
			}
		}
		rno=find(rno);
		cno=find(cno);
		if(uni(rno,cno))
		{
			count++;
			printf("Edge (%d,%d) - %d\n",v1,v2,c);
			mincost=mincost+c;
		}
		cost[v1][v2]=cost[v2][v1]=999;
	}
	printf("Mincost : %d",mincost);
	getch();
}
int find(int i)
{
	return parent[i];
}
int uni(int i,int j)
{
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	return 0;
}