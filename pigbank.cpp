#include <bits/stdc++.h>
using namespace std;
void knapsack(int val[],int wt[],int W,int n)
{
	int dp[W+1],i,j;
	memset(dp,0,sizeof(dp));
	for(i=0;i<=W;++i)
		for(j=0;j<n;++j)
		{
			
			if(wt[j]<=i){
				dp[i]=max(dp[i],dp[i-wt[j]]+val[j]);
			}
		}
	if(dp[W]!=INT_MAX)
		cout<<dp[W];
	else
		cout<<"ki";
}
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		int e,f;
		cin>>e>>f;
		int n;
		cin>>n;
		int val[n],wt[n],i;
		for(i=0;i<n;++i)
			cin>>val[i]>>wt[i];
		knapsack(val,wt,f-e,n);

	}
	return 0;
}