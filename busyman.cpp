#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> a ,pair<int,int> b)
{
	if(a.second==b.second)
		return a.first<b.first;
	return a.second<b.second;
}
int main(int argc, char const *argv[])
{
	int qq;
	cin>>qq;
	int a=max(9,67);
	cout<<a;
	while(qq--)
	{
		int n;
		cin>>n;
		int i,j,cnt=1;
		pair <int,int> activities[n];
		for(i=0;i<n;++i)
			cin>>activities[i].first>>activities[i].second;
		sort(activities,activities+n,cmp);
		i=0;
		for(j=1;j<n;++j)
		{
			if(activities[j].first>=activities[i].second)
			{
				++cnt;
				i=j;
			}
		}
		printf("%d\n",cnt );


	}
	return 0;
}