#include<iostream>
#include<vector>
using namespace std;

/*
给定一个矩阵matrix，按照“之”字形的方式打印这个矩阵。例如：

1   2   3   4

5   6   7   8

9  10  11 12

“之”字形打印的结果为：1,2,5,9,6,3,4,7,10,11,8,12

要求额外的空间复杂度为O(1)。
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

void zigzagPrintLine(vector<vector<int> >mat, int tx, int ty, int dx, int dy, bool fromUp)
{
	if (fromUp)
	{
		while (ty >= dy)
			cout << mat[tx++][ty--] << " ";
	}
	else
	{
		while (dy <= ty && dy >= 0)
			cout << mat[dx--][dy++] << " ";
	}
}

void zigzagPrintMatrix(vector<vector<int> >mat)
{
	int row = mat.size();
	int col = mat[0].size();
	if (row == 0)
		return;
	int tx = 0, ty = 0;
	int dx = 0, dy = 0;
	bool fromUp = false;
	while (tx<=row-1&&dy<=col-1)
	{
		zigzagPrintLine(mat, tx, ty, dx, dy, fromUp);
		if (++ty > col-1)
		{
			tx++;
			ty = col - 1;
		}
		if (++dx > row-1)
		{
			dx = row - 1;
			dy++;
		}
		fromUp = !fromUp;
	}
}

int main()
{
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
	cout << "-------------------------zigzag----------------------------" << endl;
	zigzagPrintMatrix(b);


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
	cout << "-----------------zigzag------------------" << endl;
	zigzagPrintMatrix(d);


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
	cout << "-----------------zigzag------------------" << endl;
	zigzagPrintMatrix(vv);
	return 0;
}