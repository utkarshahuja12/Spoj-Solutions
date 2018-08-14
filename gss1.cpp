#include <bits/stdc++.h>
using namespace std;

struct node
{
	long long maxsum,prefixsum,suffixsum,sum;
};
node tree[4*50001];
int a[50010];
void build(int  index,int start,int end)
{
	if(start==end)
	{
		tree[index].sum=a[start];
		tree[index].sum=tree[index].suffixsum=tree[index].prefixsum=tree[index].maxsum;
		return;
	}
	long long mid=(start+end)/2;
	build(2*index,start,mid);
	build(2*index+2,mid+1,end);
	tree[index].sum=tree[2*index+1].sum+tree[2*index+2].sum;
	tree[index].prefixsum=max(tree[2*index+1].prefixsum,tree[2*index+1].sum+tree[2*index+2].prefixsum);
	tree[index].suffixsum=max(tree[2*index+2].suffixsum,tree[2*index+2].sum+tree[2*index+1].suffixsum);
	tree[index].maxsum=max(tree[index].prefixsum,max(tree[index].suffixsum,max(tree[2*index+1].maxsum,max(tree[2*index+2].maxsum,tree[2*index+1].suffixsum+tree[2*index+2].prefixsum))));


}
node query(int  l,int  r, int  s,int  e,int index)
{
	node result;
	result.maxsum=result.sum=result.prefixsum=result.suffixsum=LLONG_MIN;
	if(r<s || e<l)
		return result;
	else if(l<=s&&r>=e)
		return tree[index];
	long long mid=(s+e)/2;
	node left = query(l,r,s,mid,2*index+1);
	node right = query(l,r,mid+1,e,2*index+2);
	result.sum = left.sum + right.sum;
	result.prefixsum = max(left.prefixsum, left.sum + right.prefixsum);
	result.suffixsum = max(right.suffixsum, right.sum + left.suffixsum );
	result.maxsum = max(result.prefixsum,max(result.suffixsum,max(left.maxsum,max(right.maxsum, left.suffixsum + right.prefixsum))));
	return result;
}
int main(int argc, char const *argv[])
{
	int  n,i,q,c,b;
	cin>>n;
	for(i=0;i<n;++i)
		cin>>a[i];
	build(0,0,n-1);
	cin>>q;
	for(i=0;i<q;++i)
	{
		cin>>c>>b;
		cout<<query(c-1,b-1,0,n-1,0).maxsum<<endl;
		
	}
	return 0;
}
