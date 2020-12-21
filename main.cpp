#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

void output_mat(int** arr, int n);
void input_mat(int** arr, int n);
void vector_mat(int** arr, int n, int m);
int vec_max(int* arr, int n);
int vec_mult(int* vec_fir, int* vec_sec, int n);

int main()
{
	int n, m;
	srand(time(NULL));
	cout << "Input an dimension of matrix : ";
	cin >> n;
	cout << "Input your line : ";
	cin >> m;
	int** mat = new int* [n];
	for(int i = 0; i < n ; i++)
	{
		mat[i] = new int[n];
	}
	input_mat(mat, n);
	output_mat(mat, n);
	vector_mat(mat, n, m);

	return 0;
}

void input_mat(int **arr, int n)
{
	for (int i = 0; i < n; i++)
	{
      for(int j = 0; j < n; j++)
	  {
		  arr[i][j] = rand() % 9;
	  }
	}
}

void output_mat(int** arr, int n)
{
	cout << "Your matrix : " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(4) << arr[i][j];
		}
		cout << endl;
	}

}
void vector_mat(int** arr, int n, int m)
{
	int j = 0;
	int* vec_fir = new int[n];
	int* vec_sec = new int[n];
	for(int i = 0; i < n; i++)
	{
		vec_fir[j] = arr[m-1][i];
		j++;
	}
	
	j = 0;
	for (int i = 0; i < n; i++)
	{
		vec_sec[j] = arr[i][vec_max(vec_fir, n)];
		j++;
	}
	cout << "First vector : ";
	for (int i = 0; i < n; i++)
	{
		cout << setw(2) << vec_fir[i];
	}
	cout << endl;
	cout << "Second vector : ";
	for (int i = 0; i < n; i++)
	{
		cout << setw(2) << vec_sec[i];
	}
	cout << endl;
	cout << "Scalar product of vectors : ";
	cout << vec_mult(vec_fir, vec_sec, n) << endl;
}

int vec_max(int *arr, int n)
{
	int max_1 = arr[0];
	int max_2 = 0;
	for(int i = 1; i < n; i++)
	{
		if(arr[i] > max_1)
		{
			max_2 = i;
		}
	}
	return max_2;
}

int vec_mult(int* vec_fir, int* vec_sec, int n )
{
	int res = 0;
	for(int i = 0; i < n; i++)
	{
		res += vec_fir[i] * vec_sec[i];
	}
	return res;
}
