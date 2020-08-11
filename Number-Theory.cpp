#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int power(int x, int n, int mod)
{
	if (!n)
		return 1;

	if (n & 1)
		return (power(x, n - 1, mod) * x) % mod;
	else
		return power((x * x) % mod, n / 2, mod);
}

int inverse(int x, int mod)
{
	return power(x, mod - 2, mod);
}

int factorial(int n, int p, int &cnt_p)
{
	if (!n)
		return 1;

	int np = n / p;
	
	cnt_p += np;

	int result = (np & 1) ? (p - 1) : 1;

	for (int i = 1; i <= n % p; i++)
		result = (result * i) % p;

	return (result * factorial(np, p, cnt_p)) % p;
}

int combination(int n, int k, int p)
{
	int cnt_num = 0, cnt_den = 0;

	int numerator = factorial(n, p, cnt_num);

	int denominator = factorial(k, p, cnt_den) * factorial(n - k, p, cnt_den);

	if (cnt_num > cnt_den)
		return 0;

	return (numerator * inverse(denominator % p, p)) % p;
}

int crt(vector <int> &rem, vector <int> &mod, int M)
{
	ll x = 0;

	for (unsigned i = 0; i < mod.size(); i++)
	{
		ll mi = M / mod[i];

		x += ( rem[i] * mi * inverse(mi % mod[i], mod[i]) ) % M;

		x %= M;
	}

	return x;
}

void sieve_with_lp(vector <int> &lp){
	
	int N = lp.size();
	
	for (ll i = 2; i < N; i++)
		if (!lp[i])
		{
			lp[i] = i;

			for (ll j = i * i; j < N; j += i)
				if (!lp[j])
					lp[j] = i;
		}

}

int main()
{
	

	return 0;
}