#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;
void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
int boolpos(int b[], int n)
{
	for (int i = 0; i < n; i++)
	{
		b[i] = 0;
	}
	return 0;
}
void trya(int a[], int isapear[], int b[], int k, int n, int count)
{
	for (int i = 0; i < n; i++)
	{
		if (isapear[i] == 0)
		{
			isapear[i] = 1;
			b[count-1] = a[i];
			if (count == k)
			{
				output(b, k);
			}
			else
			{
				trya(a, isapear, b, k, n, count + 1);
			}
			isapear[i] = 0;
		}
	}
}

void Try(int* a, int* Bool, int* b, int sum, int n, int k, int count)
{
	for (int i = 0; i < n; i++)
	{
		if (k < sum)
		{
			if (Bool[i] == 0)
			{
				k = k + a[i];
				if (k == sum)
				{
					Bool[i] = 1;
					b[count - 1] = a[i];
					output(b, count);
				}
				else if (k < sum)
				{
					Bool[i] = 1;
					b[count - 1] = a[i];
					Try(a, Bool, b, sum, n, k, count + 1);
				}
				k = k - a[i];
				Bool[i] = 0;
			}
		}
	}
}
void cau41617(int a[], int isapear[], int b[], int n, int count)
{
	for (int i = 0; i < n; i++)
	{
		if (isapear[i] == 0)
		{
			isapear[i] = 1;
			b[count - 1] = a[i];
			output(b, count);
			cau41617(a, isapear, b, n, count + 1);
			isapear[i] = 0;
		}
	}
}
void cau4fix(int* a, int* Bool, int* b, int n, int count, int k)
{
	if (count == 0)
	{
		output(b, 0);
		cau4fix(a, Bool, b, n, count + 1, k);
		return;
	}
	for (int i = k; i < n; i++)
	{
		if (Bool[i] == 0)
		{
			Bool[i] = 1;
			b[count-1] = a[i];
			k = k + i;
			if (count <= n)
			{
				output(b, count);
				cau4fix(a, Bool, b, n, count + 1, k);
			}
			Bool[i] = 0;
		}
	}
}
int main()
{
	int k=0, n=0;
	int* a;
	int* b;
	int* c;
	cout << "n= ";
	cin >> n;
	cout << "k= ";
	cin >> k;
	int sum = 0;
	cout << "sum= ";
	cin >> sum;
	a = new int[n];
	b = new int[n];
	c = new int[n];
	for (int i = 0; i < n; i++) a[i] = i;
	boolpos(c, n);
	cau4fix(a, c, b, n, 0, 0);
	//Try(a, c, b, sum, n, 0, 1);
	delete []a;
	a = nullptr;
	delete []b;
	b = nullptr;
	delete []c;
	c = nullptr;
	return 0;
}