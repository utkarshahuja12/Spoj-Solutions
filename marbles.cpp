#include <bits/stdc++.h>
using namespace std;
long long nCr(long long n,long long r)
{
	if(r>n-r)
		r=n-r;
	long long ans=1,i;
	for(i=0;i<r;++i)
		ans=ans*(n-i)/(i+1);
	return ans;
}
int main(int argc, char const *argv[])
{
	int qq;
	cin>>qq;
	while(qq--)
	{
		long long n,k;
		cin>>n>>k;
		cout<<nCr(n-1,k-1)<<endl;

	}
	return 0;
}