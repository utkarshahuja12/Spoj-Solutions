#include <bits/stdc++.h>
using namespace std;
int  primecheck(int n)
{
	for(int i=2;i<=sqrt(n);++i)
	{
		if(n%i==0)
			return 0;
	}
	return 1;

}
int main(int argc, char const *argv[])
{
	long long primes[9000];
	int i,qq;
	for(i=1000;i<=9999;++i)
	{
		primes[i-1000]=0;
		if(primecheck(i))
			primes[i-1000]=1;
	}
	

	return 0;
}