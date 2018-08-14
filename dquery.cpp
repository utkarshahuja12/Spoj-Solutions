#include <bits/stdc++.h>
using namespace std;
unordered_map<int,int> m;
int  cnt=0;
int a[30015];
int block_size;
struct que
{
	int l,r,index;
}queries[200010];
bool cmp(que c,que d)
{
	int a_blocksize=c.l/block_size;
	int b_blocksize=d.l/block_size;
	if(a_blocksize==b_blocksize)
		return c.r<d.r;
	return a_blocksize<b_blocksize;
}
void add(int idx)
{
	if(m[a[idx]]==0)
	{
		cnt+=1;
		m[a[idx]]=1;
	}
	else 
		m[a[idx]]++;
}
void remove(int idx)
{
	if(m[a[idx]]==1)
	{
		cnt-=1;
		m[a[idx]]=0;
	}
	else 
		m[a[idx]]--;

}
int main(int argc, char const *argv[])
{
	 ios_base::sync_with_stdio(false);
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;++i)
		scanf("%d",&a[i]);
	block_size=sqrt(n);

	int q;
	scanf("%d",&q);
	int answer[q];
	for(i=0;i<q;++i)
	{
		scanf("%d",&queries[i].l);
		scanf("%d",&queries[i].r);
		queries[i].index=i;
	}
	sort(queries,queries+q,cmp);
	int mo_left=0,mo_right=-1;
	for(i=0;i<q;++i)
	{
		int left=queries[i].l-1;
		int right=queries[i].r-1;
		while(mo_right < right) {
            mo_right++;
            add(mo_right);
        }
        while(mo_right > right) {
            remove(mo_right);
            mo_right--;
        }

        while(mo_left < left) {
            remove(mo_left);
            mo_left++;
        }
        while(mo_left > left) {
            mo_left--;
            add(mo_left);
        }

		answer[queries[i].index]=cnt;
		
	}
	for(i=0;i<q;++i)
		printf("%d \n",answer[i] );

	return 0;
}