#include <bits/stdc++.h>
using namespace std;
bool cmp(pair< pair<int,int>,int> a,pair< pair<int,int>,int> b)
{
	return a.second<b.second;
}
int ar[1010];
int size[1010];
void initialize(int n)
{
	for(int i=0;i<=n;++i)
	{
		ar[i]=i;
		size[i]=1;
	}
}
int find(int val)
{
	while(ar[ar[val]]!=val)
		val=ar[ar[val]];
	return val;
}
void union_rank(int x,int y)
{
	if(size[x]<size[y])
	{
		ar[x]=ar[y];
		size[y]+=size[x];
	}
	else
	{
		ar[y]=ar[x];
		size[x]+=size[y];
	}

}
int main(int argc, char const *argv[])
{
	int t,i;
	scanf("%d",&t);
	while(t--)
	{
		int p,n,m,cnt=0;
		long long total=0;
		scanf("%d",&p);
		scanf("%d",&n);
		scanf("%d",&m);
		initialize(n);
		pair< pair<int,int>,int> streets[m];
		for(i=0;i<m;++i){
			cin>>streets[i].first.first>>streets[i].first.second>>streets[i].second;
			
		}
		sort(streets,streets+m,cmp);
		i=0;
		while(cnt<n-1)
		{
			if(find(streets[i].first.first)==find(streets[i].first.second));	
			else
			{
				total+=p*streets[i].second;
				++cnt;
				int x=find(streets[i].first.first);
			    int y=find(streets[i].first.second);
			    union_rank(x,y);

			}
			++i;
		}
		printf("%lld\n", total);

	}
	return 0;
}