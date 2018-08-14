#include <bits/stdc++.h>
using namespace std;
int current_answer=0,mo_left=0,mo_right=-1;
pair<pair<pair <int,int> ,string>,int> queries[100000];
string s[100000]; 
int answers[100000];
int block_size;
int cnt[100005];
bool cmp(pair<pair<pair <int,int> ,string>,int>a , pair<pair<pair <int,int> ,string>,int> b)
{
	int block_a=a.first.first.first/block_size;
	int block_b=b.first.first.first/block_size;
	if(block_a!=block_b)
		return block_a<block_b;
	return a.first.first.second< b.first.first.second;
}
inline void add(int x)
{
	cnt[x]++;
}
inline void remove(int x)
{
	cnt[x]--;
}
unordered_map<string,int> m;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	block_size=sqrt(n);
	int i,h=1;
	for(i=0;i<n;++i){
		cin>>s[i];
		if (m[s[i]])
			continue;
		m[s[i]]=h++;

	}
	int q;
	cin>>q;
	for(i=0;i<q;++i)
	{
		cin>>queries[i].first.first.first>>queries[i].first.first.second>>queries[i].first.second;
		queries[i].second=i;
	}
	sort(queries,queries+q,cmp);
	for(i=0;i<q;++i)
	{
		int left=queries[i].first.first.first-1;
		int right=queries[i].first.first.second-1;
		string st=queries[i].first.second;
		while(mo_right < right) {
            mo_right++;
            add(m[s[mo_right]]);
        }
        while(mo_right > right) {
            remove(m[s[mo_right]]);
            mo_right--;
        }

        while(mo_left < left) {
            remove(m[s[mo_left]]);
            mo_left++;
        }
        while(mo_left > left) {
            mo_left--;
            add(m[s[mo_left]]);
        }
        answers[queries[i].second]=cnt[m[queries[i].first.second]];

	}
	for ( i = 0; i < q; ++i)
	{
		cout<<answers[i]<<endl;
	}

	return 0;
}