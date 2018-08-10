#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<math.h>
#include<windows.h>
#include<cstring>

#define Array_size 100
#define MAX 1000000
#define NUM_MAX 1000
using namespace std;

int Generate_ramdom(int low, int upper)
{
	srand((unsigned)time(NULL));
	Sleep(1);                    
	return (rand() % (upper - low + 1) + low);
}

int Partition(int *a, int left, int right)
{
	int temp, i, j, exchange, random, swap;
	swap = Generate_ramdom(left, right); //rondom partition
	exchange = a[swap];
	a[swap] = a[left];
	a[left] = exchange;

	random = left;//naive partition
	temp = a[random];
	i = left;
	for (j = left + 1;j <= right;j++)
		if (a[j] <= temp)
		{
			i = i + 1;
			exchange = a[i];
			a[i] = a[j];
			a[j] = exchange;
		}
	exchange = a[i];
	a[i] = a[random];
	a[random] = exchange;
	return i;
}

int Randomized_Select(int *a, int p, int r, int i)
{
	if (p == r)
	{
		return a[p];
	}
	int q,k;
	q = Partition(a, p, r);
	k = q - p + 1;
	if (i == k)
		return a[q];
	else if (i < k)
		return Randomized_Select(a, p, q-1, i);
	else
		return Randomized_Select(a, q+1, r, i-k);
}


int main()
{
	int a[Array_size];

	// read int_array from files
	int num_length = 0;
	ifstream in("int_array.txt");
	cout << "initial array:" << endl;
	while (!in.eof())
	{
		in >> a[num_length];
		cout << a[num_length] << ' ';
		num_length++;
	}
	cout << endl;

	for (int j = 0;j < 100;j++)
		cout << Randomized_Select(a, 0, num_length - 1, 4) << endl;

	//Partition(a, 0, num_length - 1);

	return 0;
}
