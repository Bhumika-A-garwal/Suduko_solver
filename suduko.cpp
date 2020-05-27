#include<iostream>
#include<math.h>
using namespace std;
bool issafetoput(int mat[9][9],int i,int j,int number,int n)
{
	//check for row and column
	for(int k=0;k<n;k++)
	{
		if(mat[i][k]==number || mat[k][j]==number)
		{
			return false;
		}
	}
	//check for smaller box
	n=sqrt(n);
	int star_row=(i/n)*n;
	int star_col=(j/n)*n;
	for(int l=star_row;l<star_row;l++)
	{
		for(int m=star_col;m<star_col;m++)
		{
			if(mat[l][m]==number)
			{
				return false;
			}
		}
	}
	return true;
}
bool suduko(int mat[9][9],int i,int j,int n)
{
	//base case
	if(i==n)
	{
		//print the suduko
		for(int row=0;row<n;row++)
		{
			for(int col=0;col<n;col++)
			{
				cout<<mat[row][col]<<" ";
			}
			cout<<endl;
		}
		return true;
	}
	if(j==n)
	{
		return suduko(mat,i+1,0,n);
	}
	if(mat[i][j]!=0)
	{
		return suduko(mat,i,j+1,n);
	}
	//recursive case
	for(int number=1;number<=n;number++)
	{
		if(issafetoput(mat,i,j,number,n))
		{
			mat[i][j]=number;
			bool kyabakibaatbani=suduko(mat,i,j,n);
			if(kyabakibaatbani==true)
			{
				return true;
			}
			mat[i][j]=0;
		}
	}
	return false;
}
int main()
{
	int mat[9][9]={
		{3, 0, 6, 5, 0, 8, 4, 0, 0},  
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},  
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},  
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},  
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},  
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},  
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},  
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},  
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}	
	};
	suduko(mat,0,0,9);
	return 0;
}
