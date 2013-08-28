#include <iostream>
#include <string>

using namespace std;

/* ORIGINAL PROBLEM

A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.

Answer: 906609
*/

// Time Complexity: O(n^2)

bool isPalindrome(int cand)
{
	string temp = to_string(static_cast<long long>(cand));
	
	for (int i = 0; i < (temp.length())/2 + 1; i++)
	{
		if (temp[i] != temp[temp.length() - i - 1])
			return false;
	}
	return true;
}

int main()
{
	int cand;
	int pal = -1;
	for (int i = 999; i >= 100; i--)
	{
		for (int j = 999; j >= 100; j--)
		{
			cand = i * j;
			if (isPalindrome(cand))
			{
				if (cand > pal)
					pal = cand;
			}
		}
	}

	cout << "The largest palindrome is: " << pal << endl;
}