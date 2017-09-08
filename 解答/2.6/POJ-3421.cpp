
#include<iostream>
#include<vector>
#include<numeric>
#include<map>
using namespace std;

typedef unsigned long long ULL;

//************************************
// Method:    divisor
// FullName:  divisor
// Access:    public
// Returns:   vector<int> 约数
// Qualifier: 约数枚举
// Parameter: const int & n 目标数n
//************************************
vector<int> divisor(const int& n)
{
	vector<int> res;
	for (int i = 1; i * i <= n; ++i)
	{
		if (n % i == 0)
		{
			res.push_back(i);
			if (i != n / i)
			{
				res.push_back(n / i);
			}
		}
	}

	return res;
}

//************************************
// Method:    prime_factor
// FullName:  prime_factor
// Access:    public
// Returns:   map<int, int>
// Qualifier: 整数分解
// Parameter: int n
//************************************
map<int, int> prime_factor(int n)
{
	map<int, int> res;
	for (int i = 2; i * i <= n; ++i)
	{
		while (n % i == 0)
		{
			++res[i];
			n /= i;
		}
	}
	if (n != 1)
	{
		res[n] = 1;
	}
	return res;
}

//************************************
// Method:    prime_factor_time
// FullName:  prime_factor_time
// Access:    public
// Returns:   vector<int>
// Qualifier: 只求解整数分解的因子的幂
// Parameter: int n
//************************************
vector<int> prime_factor_time(int n)
{
	vector<int> res;
	for (int i = 2; i * i <= n; ++i)
	{
		int time = 0;
		while (n % i == 0)
		{
			++time;
			n /= i;
		}
		res.push_back(time);
	}
	if (n != 1)
	{
		res.push_back(1);
	}

	return res;
}

//************************************
// Method:    factor
// FullName:  factor
// Access:    public
// Returns:   int
// Qualifier: 阶乘，n!
// Parameter: const int & n
//************************************
ULL factor(const int& n)
{
	ULL res = 1;
	for (int i = 1; i <= n; ++i)
	{
		res *= i;
	}
	return res;
}

///////////////////////////SubMain//////////////////////////////////
int main(int argc, char *argv[])
{

	int X;
	while (cin >> X)
	{
		vector<int> f = prime_factor_time(X);
		int length = accumulate(f.begin(), f.end(), 0);	// 幂之和是长度
		ULL number = factor(length);					// 全排列
		for (vector<int>::const_iterator it = f.begin(); it != f.end(); ++it)
		{
			number /= factor(*it);						// 去重复
		}

		cout << length << ' ' << number << endl;
	}

	return 0;
}
///////////////////////////End Sub//////////////////////////////////
