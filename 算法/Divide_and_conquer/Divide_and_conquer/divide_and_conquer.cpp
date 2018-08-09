#include<iostream>
using namespace std;

#define MARTIX_SIZE 2

//BINARY_SEARCH 
int binary_search(int *array,int left,int right,int findnum)
{
	int temp_mid;
	if (left >= right)
		return -1;
	else
	{
		temp_mid = (left + right)/2+1; //此处加一，使temp_mid的取值向后取整，保证递归不进入死循环
		if (array[temp_mid] == findnum)
			return temp_mid;
		else if (array[temp_mid] > findnum)
			binary_search(array, left, temp_mid, findnum);
		else
			binary_search(array, temp_mid,right ,findnum);
	}		
}
void Binary_search_main()
{
	int array[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int result;
	result= binary_search(array, 0, 9, 4);
	if (result == -1)
		cout << "NO FIND ELEMENT!" << endl;
	else
		cout << "ELEMENT is " << result+1 << "th IN ARRAY!" << endl;
}



//POWERING_NUMBER
double powering_a_number(double number,int power_num)
{
	if (power_num == 1)
		return number;
	else if (power_num % 2 == 0)
		return powering_a_number(number, power_num / 2)*powering_a_number(number, power_num / 2);
	else
		return powering_a_number(number, (power_num - 1) / 2)*powering_a_number(number, (power_num - 1) / 2)*number;
}
void powering_a_number_main()
{
	double number,result;
	int power_num;
	cin >> number >> power_num;
	result = powering_a_number(number,power_num);
	cout << number << "的" << power_num << "次方是：" << result << endl;
}

//MARTIX MULTIPICATION

//重点是二维数组传参问题
void martix_multipication_naive_alg(int martix_a[][MARTIX_SIZE],int martix_b[][MARTIX_SIZE],int martix_result[][MARTIX_SIZE])
{
	int i, j;
	for(i=0;i<MARTIX_SIZE;i++)
		for ( j = 0; j < MARTIX_SIZE; j++)
		{
			martix_result[i][j] = 0;
			for (int k = 0;k < MARTIX_SIZE;k++)
				martix_result[i][j] = martix_result[i][j] + martix_a[i][k] * martix_b[k][j];
		}
}


void martix_multipication_main()
{
	int martix_a[MARTIX_SIZE][MARTIX_SIZE] = { { 1,2 },{ 3,4 } }, martix_b[MARTIX_SIZE][MARTIX_SIZE]={ { 1,2 },{ 3,4 } }, martix_result[MARTIX_SIZE][MARTIX_SIZE];
	martix_multipication_naive_alg(martix_a, martix_b, martix_result);
	for (int i = 0;i < MARTIX_SIZE;i++)
	{
		for (int j = 0;j < MARTIX_SIZE;j++)
			cout << martix_result[i][j] << ' ';
		cout << endl;
	}
}



//FIBONACCI NUMBERS
int fibonacci_naive_alg(int number)
{
	if (number == 0)
		return 0;
	else if (number == 1)
		return 1;
	else
		return fibonacci_naive_alg(number - 1) + fibonacci_naive_alg(number - 2);
}

int fibonacci_bottom_up_array[1000] = {-1};

void fibonacci_bottom_up_alg(int number)
{
	int i;
	fibonacci_bottom_up_array[0] = 0;
	fibonacci_bottom_up_array[1] = 1;
	for (i = 2;i < number;i++)
	{
		fibonacci_bottom_up_array[i] = fibonacci_bottom_up_array[i-1] + fibonacci_bottom_up_array[i-2];
	}
}


void fbonacci_main()
{
	int number, result,i;
	cin >> number;
	//result = fbonacci_naive_alg(number);
	//cout << "斐波那契数列的第" << number << "个数是：" << result << endl;

	//fibonacci_bottom_up_alg(number);

	int Fibonacci_martix[MARTIX_SIZE][MARTIX_SIZE] = { { 1,1 },{ 1,0 } };

	cout << "斐波那契数列:" ;
	for (i = 0;i < number ; i++)
		//cout << fbonacci_naive_alg(i) << ' ';	
		cout << fibonacci_bottom_up_array[i] << ' ';
}


int main()
{
	//Binary_search_main();
	//powering_a_number_main();
	//fbonacci_main();
	martix_multipication_main();
	return 0;
}