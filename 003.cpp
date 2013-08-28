#include <iostream>
#include <sstream>
#include <string>

using namespace std;

/* ORIGINAL PROBLEM
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143?
Answer: 6857
*/

/* GENERAL PROBLEM

What is the largest prime factor of a given number?
*/

// Sieve of Eratosthenes
// Time Complexity: O(n log log n)		Taken from Wikipedia

int main()
{
	int n;
	string input = "";

	while (true)
	{
		cout << "Enter the number you would like to find the largest prime factor of" << endl;
		getline(cin, input);

		// Converts a string to a number
		stringstream stream(input);
		if (stream >> n && n > 0)
			break;
		if (n < 0)
			cout << "Not a positive number, please try again" << endl;
		else
			cout << "Not a number, please try again" << endl;

	}

	cout << "You entered for n: " << n << endl;

	unsigned long long int factor = n;

	for (int i = 2;;)
	{
		if (factor <= i)
			break;
		if (factor % i == 0)
			factor = factor/i;
		else
			i++;
	}

	cout << "The largest prime factor of " << n << " is " << factor << endl;
}