﻿#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 3^a * 5^b * 7^c <= x - задача
// a <= log(3, x), b <= log(5, x), c <= log(7, x) 
// x <= 10^18

vector <int> v;
int main()
{
	int x = 100000000, ta = 1, tb, tc, i = 0; // ta = 3^a etc.
	
	while (ta <= x)
	{
		tb = ta;
		while (tb <= x)
		{
			tc = tb;
			while (tc <= x)
			{
				v.push_back(tc);
				i++;
				tc *= 7;
			}
			tb *= 5;
		}
		ta *= 3;
	}

	sort(v.rbegin(), v.rend());

	for (int k = 0; k < i; k++)
		cout << v[k] << " ";
}