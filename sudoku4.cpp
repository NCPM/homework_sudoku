#include<iostream>
#include<ctime>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include<stdio.h>
using namespace std;
//判断这个数是否可以放此位置  行列宫 
bool valid(int sudoku[][9],int m,int n)
{
	int tmp=sudoku[m][n];
	int i,j;
	for(i=0;i<9;i++)
	{
		if (i!= m&&sudoku[i][n]==tmp)
			return false;
	}
	for (j=0;j<9;j++)
	{
		if (j!=n&&sudoku[m][j]==tmp)
			return false;
	}
	for (i=m/3*3; i<m/3*3+3; i++)
	{
		for (j=n/3*3;j<n/3*3+3; j++)
		{
			if((i!=m||j!=n)&&sudoku[i][j]==tmp)
				return false;
		}
	}
	return true;
}
//构造数组并输出 
void create_sudoku(int sudoku[][9])
{
	int i,j;
	int k=1;
	while(1)
	{
		i=k/9;
		j=k%9;
		while(1)
		{
			sudoku[i][j]++;
			if (sudoku[i][j]==10)
			{
				sudoku[i][j]=0;
				if(k>1)k--;
				break;
			}
			else if(valid(sudoku,i,j))
			{
				k++;
				break;
			}
		}
		if (k==81)
		{
			for(i=0;i<9;i++)
			{
				for(j=0;j<9;j++)
					cout<<sudoku[i][j]<<' ';
				cout<<endl;
			}
			break;
		}
	}
}

int main(int argc, char *argv[])
{
	//传入参数 
	int D = atoi(argv[argc-1]);
	if (D>1000000||D<1)
	{
		cout<<"error"<<endl;
		return 0;
	}
	else
		cout <<"传入成功"<<endl;
	//写入文件 
	freopen("sudoku.txt","w",stdout);
	int i, t;
	int sudoku[9][9]={0};
	sudoku[0][0]=9;
	srand((unsigned)time(0));
	for(i=1;i<=9;i++)
	{
		t=rand()%81;
		if(t==0)
		{
			++t;
		}
		sudoku[t/9][t%9]=i;
	}
	for(i=0;i<D;i++)
	{
		create_sudoku(sudoku);
		printf("\n");
	}
	int a=0;
	cin>>a;
	return 0;
}
