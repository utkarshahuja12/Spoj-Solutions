#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int l,m,k;
	cin>>l>>k>>m;
	int i;
	long long n;
	int a[1000001];
	int latest=1;
	int cnt=0;
	a[0]=1;

	for(int j=0;j<m;++j)
	{
		cin>>n;
		for(i=latest;i<=n;++i)
		{
			if(i<k)
			{
				if(i>=l)
				{
					if(a[i-l]==0&&a[i-1]==0)
						a[i]=1;
					else
						a[i]=0;
				}
				else
				{
					a[i]=(a[i-1]+1)%2;
				}
			}
			else
				{
					if(a[i-k]==0&&a[i-1]==0 && a[i-l]==0)
						a[i]=1;
					else
						a[i]=0;
									}
		}
		latest=n;
		char ch=a[n]%2==0 ?'A': 'B';
		printf("%c",ch );
		

	}



	return 0;
}