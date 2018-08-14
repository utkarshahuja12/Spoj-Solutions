#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n;
	while(n!=0)
	{
		int a[n],i;
		for(i=0;i<n;++i)
			scanf("%d",&a[i]);
		int m,j,sum1=0,sum2=0,ans=0;
		cin>>m;
		int b[m];
		for(j=0;j<m;++j)
			scanf("%d",&b[j]);
		i=0,j=0;
		while(i<n&&j<m)
		{
			if(a[i]>b[j])
			{
				while(j<m&&a[i]>b[j]){
					sum2+=b[j];
					++j;
					
				}

			}
			else if(a[i]<b[j])
			{
				
				while(i<n&&a[i]<b[j]){
					sum1+=a[i];
					++i;
				}
			}
			else if(a[i]==b[j])
			{
				
					ans+=max(sum1,sum2)+a[i];
				
				sum1=sum2=0;
				++i;
				++j;
			}

		}
		for(;i<n;++i)
			sum1+=a[i];
		for(;j<m;++j)
			sum2+=b[j];
		ans+=max(sum1,sum2);
		printf("%d\n", ans);
		cin>>n;

	}
	return 0;
}