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

int Generate_ramdom(int low,int upper)
{
	srand((unsigned)time(NULL));
	Sleep(1);                     //特别有意思的地方，思考为什么自己设置Sleep；
	return (rand() % (upper - low  + 1) + low);
}

//insertion sorting
void insertion_sort(int *a, int num)
{
	int j, key, i, k;
	for (j = 1;j<num;j++)
	{
		key = a[j];
		i = j - 1;
		while (i >= 0 && (a[i]>key))
		{
			a[i + 1] = a[i];
			i = i - 1;
		}
		a[i + 1] = key;

		//cout<<"第"<<j-1<<"次排序："<<endl;
		//for(k=0;k<num;k++)
		//cout<<a[k]<<' ';
		//cout<<endl;
	}
}

// Merge  2 sorted lists
void Merge(int *a, int left, int mid, int right)
{
	int left_temp[Array_size] = { 0 }, right_temp[Array_size] = {0};
	int temp1, temp2,i,j,k;
	temp1 = mid - left + 1;
	temp2 = right - mid;
	for (i = 0;i < temp1;i++)
		left_temp[i] = a[left + i];
	for (j = 0;j < temp2;j++)
		right_temp[j] = a[mid + j + 1];
	left_temp[temp1] = MAX;
	right_temp[temp2] = MAX;
	i = 0;
	j = 0;
	//cout << "-----------------------------" << endl;
	for (k = left;k <=right;k++)
	{
		if (left_temp[i] <= right_temp[j])
		{
			a[k] = left_temp[i];
			i++;
		}
		else
		{
			a[k] = right_temp[j];
			j++;
		}
		//cout << k <<"           "<< a[k] << endl;
	}

}

// Merge sorting
void Merge_sort(int *a, int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;
		Merge_sort(a, left, mid);
		Merge_sort(a, mid +1, right);
		Merge(a, left, mid, right);
	}

}


//QUICKSORT
int Partition(int *a, int left, int right)
{
	int temp,i,j,exchange,random;
	random = Generate_ramdom(left,right); //rondom partition
	//random= left;//naive partition
	temp=a[random];
	i = left;
	for(j=left+1;j<=right;j++)
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

//Hoare_Partition

int Hoare_Partition(int *a, int left, int right)
{
	int temp,i,j,exchange;
	temp = a[left];
	i = left;
	j = right;
	while (true)
	{
		while (a[j] > temp)
			j = j - 1;
		while (a[i] < temp)
			i = i + 1;
		if (i < j)
		{
			exchange = a[i];
			a[i] = a[j];
			a[j] = exchange;
		}
		else
		{
			return j;
		}
	}

}



void Quciksort(int *a, int left, int right)
{
	int temp;
	if (left < right)
	{
		temp = Hoare_Partition(a, left, right);
		Quciksort(a, left, temp);
		Quciksort(a, temp + 1,right );
	}
}

//COUNTING SORTING
void Counting_sorting(int *a,int array_length)
{
	int temp[NUM_MAX],storge[Array_size];
	memset(temp, 0, sizeof(int)*NUM_MAX);
	int i, j;
	for (i = 0;i < array_length;i++)
	{
		temp[a[i]]++;
	}
	for (j = 1;j < NUM_MAX;j++)
		temp[j] = temp[j] + temp[j - 1];
	for (i = array_length - 1;i >= 0;i--)
	{
		storge[temp[a[i]]-1]= a[i];
		temp[a[i]]--;
	}
	for (i = 0;i < array_length;i++)
	{
		a[i]= storge[i];
	}

}


void radixusing_sorting(int *a, int array_length,int digit)
{
	int temp[NUM_MAX], storge[Array_size];
	int digit_num=0;
	digit_num = pow(2, digit);
	memset(temp, 0, sizeof(int)*NUM_MAX);
	int i, j;
	for (i = 0;i < array_length;i++)
	{
		temp[a[i]&digit_num]++;
	}
	for (j = 1;j < NUM_MAX;j++)
		temp[j] = temp[j] + temp[j - 1];
	for (i = array_length - 1;i >= 0;i--)
	{
		storge[temp[a[i] & digit_num] - 1] = a[i];
		temp[a[i] & digit_num]--;
	}
	for (i = 0;i < array_length;i++)
	{
		a[i] = storge[i];
	}

}



//RADIX SORTING
//此处仅做为基数排序练习，故按十进制位排序，实际中为了提高算法的效率，需要合理选择位数
void radix_sorting(int *a,int digit,int array_length)
{
	int i;
	for (i = 0;i < digit;i++)
	{
		radixusing_sorting(a, array_length, i);
	}
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


	int i;

	//insertion sorting
	//insertion_sort(a, num_length);
	//cout << "insertion sorting:" << endl;


	//Merge sorting
	//Merge_sort(a, 0,num_length-1);
	//cout << "Merge sorting:" << endl;


	//Quick sorting
	//Quciksort(a, 0, num_length - 1);
	//cout << "Quick sorting:" << endl;

	//counting sorting
	//Counting_sorting(a, num_length);
	//cout << "counting sorting:" << endl;

	//radix sorting
	radix_sorting(a,32,num_length);
	cout << "radix sorting:" << endl;

	// print sored arrays.
	for (i = 0;i<num_length;i++)
		cout << a[i] << ' ';
	cout << endl;
}