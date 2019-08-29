
#include <vector>
#include <iostream>

using namespace std;

void BubbleSort(float  *p, int length, int * ind_diff)
{
	for (int m = 0; m < length; m++)
	{
		ind_diff[m] = m;
	}

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length- i - 1; j++)
		{
			if (p[j] > p[j + 1])
			{
				float temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;

				int ind_temp = ind_diff[j];
				ind_diff[j] = ind_diff[j + 1];
				ind_diff[j + 1] = ind_temp;
			}
		}
	}
}


int main()
{
	float a[8] = { 1.0, 1.8, 1.5, 1.1, 4.3, 5.5, 2.2, 8.8 };

	int ind[8] = { 0 };

	BubbleSort(a, 8, ind);

	for (int i = 0; i < 8; i++)
	{
		cout << "value: " << a[i] << " Index: " << ind[i] << endl;
	}
    return 0;
}
