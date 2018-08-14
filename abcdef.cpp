#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n, cnt=0,i,j,k;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;++i)
		scanf("%d",&a[i]);
	std::unordered_map<int, int> m;
	for(i=0;i<n;++i)
		for(j=0;j<n;++j)
			for(k=0;k<n;++k)
				{
					if (m[a[i]*a[j]+a[k]]==0)
						m[a[i]*a[j]+a[k]]=1;
					else
						m[a[i]*a[j]+a[k]]++;
				}
	for(i=0;i<n;++i)
		for(j=0;j<n;++j)
			for(k=0;k<n;++k)
			{
				if(a[i]!=0)
					cnt+=m[a[i]*(a[j]+a[k])];

			}
	printf("%d\n",cnt );
	return 0;
}