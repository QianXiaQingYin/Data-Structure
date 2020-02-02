#include<iostream>
#include<algorithm>
using namespace std;
int a[100], n;
int divide(int left, int right);
int onLine();

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	cout << onLine();

}

int divide(int left, int right)
{
	int middle = (left + right) / 2;
	if (left >= right)
		return a[left];
	int leftAnswer = divide(left, middle);
	int rightAnswer = divide(middle + 1, right);
	
	int add = leftAnswer + rightAnswer;
	
	int b = max(leftAnswer, rightAnswer);

	return max(b, add);
}

int onLine()
{
	int current = 0, lastMax = 0;

	for (int i = 0; i < n; i++)
	{
		current += a[i];
		if (current > lastMax)
			lastMax = current;
		if (current < 0)
			lastMax = 0;
	}

	return lastMax;
}



