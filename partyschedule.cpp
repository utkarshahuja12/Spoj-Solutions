#include <bits/stdc++.h>
using namespace std;
int knapsack(int wt[],int val[],int W,int n)
{
	int dp[n+1][W+1],i,w;
	for(i=0;i<=n;++i)
	{
		for(w=0;w<=W;++w)
		{
			if(i==0||w==0)
				dp[i][w]=0;
			else if(wt[i-1]<=w)
				dp[i][w]=max(val[i-1]+dp[i-1][w-wt[i-1]],dp[i-1][w]);
			else
				dp[i][w]=dp[i-1][w];
		}
	}
	for(i=0;i<=W;++i)
	{
		if(dp[n][i]==dp[n][W])
			break;
	}
	cout<<i<<" "<<dp[n][W]<<endl;
}
int main(int argc, char const *argv[])
{
	int n,W;
	cin>>W>>n;
	while(n!=0||W!=0)
	{
		int wt[n],val[n],i;
		for(i=0;i<n;++i)
			cin>>wt[i]>>val[i];
		knapsack(wt,val,W,n);
		cin>>W>>n;
	}
	return 0;
}