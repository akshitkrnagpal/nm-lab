#include <iostream>
#include <cmath>

using namespace std;

#define MAX 5

void swap(long double &a, long double &b)
{
	long double temp;
	temp = a;
	a = b;
	b = temp; 
}

void row_interchange(long double A[MAX][MAX+1],int n,int m, int row1, int row2)
{
	for(int i=0;i<=m;i++)
	{
		swap(A[row1][i],A[row2][i]);
	}
}

void row_addition(long double A[MAX][MAX+1],int n,int m, int row1, int row2,long double c=1)
{
	for(int i=0;i<=m;i++)
	{
		A[row1][i]=A[row1][i]+c*A[row2][i];
	}
}

void row_multiply(long double A[MAX][MAX+1],int n,int m,int row,long double c=1)
{
	for(int i=0;i<=m;i++)
	{
		A[row][i]=A[row][i]*c;
	}
}

void row_divide(long double A[MAX][MAX+1],int n,int m,int row,long double c=1)
{
	for(int i=0;i<=m;i++)
	{
		A[row][i]=A[row][i]/c;
	}
}

void clean_array(long double A[MAX][MAX+1],int n,int m)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if(A[i][j]==0)
				A[i][j]=0;
		}
	}
}

void print_array(long double A[MAX][MAX+1],int n,int m)
{
	clean_array(A,n,m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<A[i][j]<<" ";
		}
		cout<<"| "<<A[i][m]<<endl;
	}
	cout<<endl;
}

void print_solution_by_gauss_elimination(long double A[MAX][MAX+1],int n,int m,bool debug)
{
	for(int i=0;i<m;i++)
	{
		int max=i;
		for(int j=i;j<n;j++)
		{
			if( A[max][i]==0 || A[max][i]<A[j][i]  )
			{
				row_interchange(A,n,m,max,j);
				print_array(A,n,m);
			}
		}

		for(int j=i+1;j<n;j++)
		{
			row_addition(A,n,m,j,i,-A[j][i]/A[i][i]);
			print_array(A,n,m);
		}

		if(A[i][i]==0)
		{
			cout<<"Inconistent"<<endl;
			return ;
		}
		
		row_divide(A,n,m,i,A[i][i]);
		print_array(A,n,m);
	}

	for(int i=m-1;i>0;i--)
	{
		for(int j=i-1;j>=0;j--)
		{
			row_addition(A,n,m,j,i,-A[j][i]/A[i][i]);
			print_array(A,n,m);
		}
	}

	for(int i=0;i<n;i++)
	{
		cout<<A[i][m]<<endl;
	}
}

int main()
{
	long double A[MAX][MAX+1]={
		{4,0,2,1,8},
		{3,2,2,0,7},
		{2,1,1,-2,-10},
		{1,0.5,0.5,-1,-5}
	};
	int n=4,m=4;

	print_array(A,n,m);

	print_solution_by_gauss_elimination(A,n,m,true);


}