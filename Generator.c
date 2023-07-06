#include <stdio.h>
int numrows;
int numcolumns;

//easy= 8*8 contains 10 potholes
//medium=9*9 contains 30 potholes
//hard=10*10 contains  50 potholes
int numpot;
int area; //map size
int pots[numpot]; //array of positions of potholes

int map[numrows][numcolumns];

//first for loop makes an array of positions of potholes
for(int i=0;i<=numpot;i++)
{
	numpot[i]=rand(0,area); //randomizes postions of potholes
}
//this for loop makes the map
for(int i=0;i<=numcolumns;i++)
{
	for(int j=0;j<=numrows;j++)
	{
		for(int k=0;k<numpot;k++)
		{
			if(pots[k]==i+j)
				map[j][i]=1;
			else
				map[j][i]=0;
		}
		printf("%d\t", matrix[i][j]);
	}
	printf("\n");
}