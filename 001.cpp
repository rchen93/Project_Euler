#include <iostream>
#include <string>
#include <sstream>
using namespace std;

/* ORIGINAL PROBLEM 

If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.

*/

/* GENERAL PROBLEM

Find the sum of all multiples of n1 or n2 below a max size

*/

// Basic Solution: Loop through entire array
// Time Complexity: O(n)
int basic(int size, int n1, int n2) 
{
	int *arr = new int[size];
	int sum = 0;

	for (int i = 0; i < size; i++)
		arr[i] = i+1;

	for (int i = 0; i < size - 1; i++)
	{
		if (arr[i] % n1 == 0 || arr[i] % n2 == 0)
			sum += arr[i];
	}

	delete [] arr;

	return sum;
}

// Better Solution: Use summation formula
// Time Complexity: O(1)
int better(int size, int n1, int n2)
{
	int sum_n1 = n1 * int((size-1)/n1) * int((size-1)/n1+1)/2;
	int sum_n2 = n2 * int((size-1)/n2) * int((size-1)/n2+1)/2;
	int sum_n1n2 = (n1*n2)* ((size-1)/(n1*n2)) * ((size-1)/(n1*n2)+1)/2;		// to prevent counting the same number twice

	return (sum_n1 + sum_n2 - sum_n1n2);
}

int main()
{	
	int n1 = 0;
	int n2 = 0;
	int size = 0;
	string input = "";

	while (true)
	{
		cout << "Enter the first number that you would like to find the sum of multiples for" << endl;
		getline(cin, input);

		// Converts a string to a number
		stringstream stream(input);
		if (stream >> n1 && n1 > 0)
			break;
		if (n1 < 0)
			cout << "Not a positive number, please try again" << endl;
		else
			cout << "Not a number, please try again" << endl;

	}
	cout << "You entered for n1: " << n1 << endl;

	while (true)
	{
		cout << "Enter the second number that you would like to find the sum of multiples for" << endl;
		getline(cin, input);

		// Converts a string to a number
		stringstream stream(input);
		if (stream >> n2 && n2 > 0)
			break;
		if (n2 < 0)
			cout << "Not a positive number, please try again" << endl;
		else
			cout << "Not a number, please try again" << endl;

	}
	cout << "You entered for n2: " << n2 << endl;

	while (true)
	{
		cout << "Enter the max range of numbers to go up to, e.g., all numbers up to 1000" << endl;
		getline(cin, input);

		// Converts a string to a number
		stringstream stream(input);
		if (stream >> size && size > 0)
			break;
		if (size < 0)
			cout << "Not a positive number, please try again" << endl;
		else
			cout << "Not a number, please try again" << endl;

	}
	cout << "You entered for size: " << size << endl;

	cout << "Sum_basic: " << basic(size, n1, n2) << endl;
	cout << "Sum_better: " << better(size, n1, n2) << endl;
}