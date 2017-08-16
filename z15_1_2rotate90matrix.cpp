#include<iostream>
#include<vector>
using namespace std;


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
void rotate90matrix(vector<vector <int> >&matrix)
{
	int row = matrix.size();
	int col = matrix[0].size();

	int lu_x = 0, lu_y = 0;
	int rd_x = row - 1, rd_y = col - 1;
	while (lu_x < rd_x || lu_y < rd_y)
	{
		int i = lu_x, j = lu_y;
		while (j < rd_y)
		{
			int temp = matrix[i][j];
			matrix[i][j] = matrix[col-1 - j][i];
			matrix[col - 1 - j][i] = matrix[col - 1 - i][col - 1 - j];
			matrix[col - 1 - i][col - 1 - j] = matrix[j][col - 1 - i];
			matrix[j][col - 1 - i] = temp;
			j++;
		}
		lu_x++;
		lu_y++;
		rd_x--;
		rd_y--;
	}

}
int main()
{
	int arr[9][9];
	int m = 0;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			arr[i][j] = m;
			m++;
		}
	}

	vector<vector<int> >vv(9, vector<int>(9));
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			vv[i][j] = arr[i][j];
		}
	}
	cout << endl;
	Printmatrix(vv);

	cout << "--------------rotate90------------------" << endl;
	rotate90matrix(vv);
	Printmatrix(vv);
	return 0;
}