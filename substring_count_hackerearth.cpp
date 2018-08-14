#include <bits/stdc++.h>
using namespace std;
string s[10001];
int cnt[500005];
int  block_size;
pair< pair<int ,int> ,pair<string,int> > queries[500005];
bool cmp(pair<pair<int,int>,pair<string,int> >a, pair<pair<int,int>,pair<string,int> >b)
{
	int block_size_a=a.first.first/block_size;
	int block_size_b=b.first.first/block_size;
	if(block_size_a==block_size_b)
		return a.first.second<b.first.second;
	return block_size_a<block_size_b;
}
int mo_left=0,mo_right=-1;
int main(int argc, char const *argv[])
{
	std::map<string, int > m;
	int n,i,h=0;
	cin>>n;
	for(i=0;i<n;++i){
		cin>>s[i];
	}
	block_size=sqrt(n);

	int q;
	cin>>n;
	for(i=0;i<q;++i)
	{
		cin>>queries[i].first.first;
		cin>>queries[i].first.second;
		cin>>queries[i].second.first;
		queries[i].second.second=i;
		if(!m[queries[i].second.first])
		m[queries[i].second.first]=h++;
	}
	sort(queries,queries+q,cmp);
	for(i=0;i<q;++i)
	{
		int left=queries[i].first.first-1;
		int right=queries[i].first.second-1;
		while(left>mo_left)
		{
			remove(s[left]);
			mo_left++;
		}
		while(left<mo_left)
	}
	
	return 0;
}