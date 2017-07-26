#include<iostream>
#include<cmath>
using namespace std;

bool judgeSquareSum(int c) {
	bool istrue = false;
	int sqrt_c = static_cast<int>(sqrt(c));
	for (int a = 1; a < sqrt_c; a++)
	{
		int power_a = a*a;
		int b = static_cast<int>(sqrt(c-power_a));
		int power_b = b*b;
		if (c == power_a + power_b)
		{
			istrue = true;
			break;
		}
	}
	return istrue;
}

int main()
{
	int c = 9;
	cout << sqrt(9)<<'\t'<<sqrt(8);
	return 0;
}