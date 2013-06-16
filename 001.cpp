#include <iostream>
using namespace std;

/* 

If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
*/

// Basic Solution: Loop through entire array
// Time Complexity: O(n)
int basic(int arr[], int size) 
{
	int sum = 0;
	for (int i = 0; i < size - 1; i++)
	{
		if (arr[i] % 3 == 0 || arr[i] % 5 == 0)
			sum += arr[i];
	}
	return sum;
}

// Better Solution: Use summation formula
// Time Complexity: O(1)
int better(int size)
{
	int sum_three = 3*int((size-1)/3)*int(((size-1)/3+1))/2;
	int sum_five = 5*int((size-1)/5)*((size-1)/5+1)/2;
	int sum_fifteen = 15*((size-1)/15)*((size-1)/15+1)/2;		// need to prevent counting the same number twice;

	return (sum_three + sum_five - sum_fifteen);
}

int main()
{	
	int thousand[1000];
	for (int i = 0; i < 1000; i++)
		thousand[i] = i+1;
	cout << "Sum_basic: " << basic(thousand, 1000) << endl;
	cout << "Sum_better: " << better(1000) << endl;
}