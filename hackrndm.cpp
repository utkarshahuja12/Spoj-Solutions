#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	long long n,k,i;
	cin>>n>>k;
	long long a,cnt=0;
	map<long long,long long> m;
	for(i=0;i<n;++i)
	{
		cin>>a;
		m[a]=1;
	}
	for(auto it=m.begin();it!=m.end();++it)
	{
		if(m.count(it->first+k))
			cnt+=1;
	}

	cout<<cnt;
	return 0;
}