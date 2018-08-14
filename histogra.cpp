#include <bits/stdc++.h>
using namespace std;
long long maxm=LLONG_MIN;
void divide(long long h[],long long start,long long end)
{
	if(start==end)
	{
		maxm=max(maxm,h[start]);
	}
	else
	{
		long long mid=(start+end)/2;
		divide(h,start,mid);
		divide(h,mid+1,end);
		maxm=max(maxm,*min_element(h+start,h+mid+1)*(mid-start+1));
		maxm=max(maxm,*min_element(h+mid+1,h+end+1)*(end-mid));
		maxm=max(maxm,*min_element(h+start,h+end+1)*(end-start+1));

	}
}
int main(int argc, char const *argv[])
{
	long long n,i;
	cin>>n;
	while(n!=0)
	{
		maxm=LLONG_MIN;
		long long a[n];
		for(i=0;i<n;++i)
			cin>>a[i];
		divide(a,0,n-1);
		printf("%lld\n",maxm);
		cin>>n;

	}
	return 0;
}