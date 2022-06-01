#include <iostream>
#include <stdlib.h>
#include <chrono>

using namespace std;

void Merge(int* A, int first, int last, int* s, int* c, int* n) //�������� ��������
{
	int m = *n + 1;
	int middle, start, final, j;
	int* mas = new int[m];
	middle = (first + last) / 2; //������� �������
	start = first; //������ ����� �����
	final = middle + 1; //������ ������ �����
	for (j = first; j <= last; j++)
	{
		*c += 1;
		if ((start <= middle) && ((final > last) || (A[start] < A[final])))
		{
			mas[j] = A[start];
			start++;
			*s += 1;
		}
		else
		{
			mas[j] = A[final];
			final++;
			*s += 1;
		}
	}
	for (j = first; j <= last; j++) A[j] = mas[j]; 	//����������� ���������� � ������
	delete[] mas;
};

void MergeSort(int* A, int first, int last, int* s, int* c, int* n) //����������� ��������� ����������
{
	{
		if (first < last)
		{
			MergeSort(A, first, (first + last) / 2, s, c, n); //���������� ����� �����
			MergeSort(A, (first + last) / 2 + 1, last, s, c, n); //���������� ������ �����
			Merge(A, first, last, s, c, n); //������� ���� ������
			*c += 1;
		}
	}
};
//������� �������
void main()
{
	setlocale(LC_ALL, "RUS");


	int i, n = 0;
	cout << "������ �������" << endl;
	cin >> n;
	int* A = new int[n];
	int c = 0;
	int s = 0;

	for (int i = 0; i <= n; ++i)
	{
		A[i] = rand();
		//cout << a[i] << endl;
	}

	auto start = chrono::steady_clock::now();
	MergeSort(A, 1, n, &s, &c, &n);
	auto end = chrono::steady_clock::now();
	auto diff = end - start;

	/*for (int i = 0; i <= n; ++i)
	{
		cout << A[i] << " ";
		
	}
	cout << endl;*/

	cout << chrono::duration <double>(diff).count() << " s" << endl;
	cout << "s = " << s << endl;
	cout << "c = " << c << endl;
	cout << s + c << endl;


	//system("pause");
}