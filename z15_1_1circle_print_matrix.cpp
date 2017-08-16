#include<iostream>
#include<vector>
using namespace std;

/*
题目：1给定一个整形矩阵matrix,请按照转圈的方式打印它。

例如：

1   2    3    4

5   6    7    8

9  10  11  12

13 14 15  16

打印结果为：

1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10

要求额外空间复杂度为：O(1)

*/
void Printmatrix(vector<vector<int> >a)
{
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < a[0].size(); j++)
		{
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
}

void circle_print_matrix(int matrix[][4], int m, int n)
{
	int row = 0, col = 0;
	int last_row = m - 1,last_col = n - 1;
	while (row <= last_row || col <= last_col)
	{
		int i = row, j = col;
		while (j <= last_col)
		{
			cout << matrix[i][j] << '\t';
			j++;
		}
		j--;
		while (i < last_row)
		{
			i++;
			cout << matrix[i][j] << '\t';
		}
		while (j > col)
		{
			j--;
			cout << matrix[i][j] << '\t';
		}
		while (i > row+1)
		{
			i--;
			cout << matrix[i][j] << '\t';
		}
		
		row++;
		col++;
		last_row--;
		last_col--;
	}
}

void circleprintmatrix2(vector<vector<int > >matrix)
{
	int row = matrix.size();
	int col = matrix[0].size();
	int lu_x = 0, lu_y = 0;
	int rd_x = row-1, rd_y = col-1;
	while (lu_x <= rd_x && lu_y <= rd_y)
	{
		int i = lu_x, j = lu_y;
		while (j <= rd_y)
		{
			cout << matrix[i][j] << '\t';
			j++;
		}
		j--;
		while (i < rd_x)
		{
			i++;
			cout << matrix[i][j] << '\t';
		}
		while (j > lu_y)
		{
			j--;
			cout << matrix[i][j] << '\t';
		}
		while (i > lu_x+1)
		{
			i--;
			cout << matrix[i][j] << '\t';
		}
		lu_x++;
		lu_y++;
		rd_x--;
		rd_y--;
	}

}
/*
int main()
{
	//int a[4][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
	int a[3][4] = { { 1,2,3,4 },{ 5,6,7,8 },{ 9,10,11,12 } };
	circle_print_matrix(a, 3, 4);

	int b[4][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 },{10, 11, 12} };
	circle_print_matrix(b, 4, 3);
	return 0;
}

*/
int main(){
	//int a[4][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
	int a[3][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } };
	vector<vector<int> >b(3, vector<int>(4));
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			b[i][j] = a[i][j];
		}
	}
	Printmatrix(b);
	cout << "-----------------circle print matrix------------------" << endl;
	circleprintmatrix2(b);

	int c[5][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 }, { 10, 11, 12 }, { 13, 14, 15 } };
	vector<vector<int> >d(5, vector<int>(3));
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			d[i][j] = c[i][j];
		}
	}
	cout << endl;
	cout << "-----------------matrix--------------------------------" << endl;
	Printmatrix(d);
	cout << "-----------------circle print matrix------------------" << endl;
	circleprintmatrix2(d);


	int arr[5][5];
	int m = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			arr[i][j] = m;
			m++;
		}
	}

	vector<vector<int> >vv(5, vector<int>(5));
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			vv[i][j] = arr[i][j];
		}
	}
	cout << endl;
	cout << "-----------------matrix--------------------------------" << endl;
	Printmatrix(vv);
	cout << "-----------------circle print matrix------------------" << endl;
	circleprintmatrix2(vv);
	return 0;
}


