#include <bits/stdc++.h>
using namespace std;
int color[1000];
long long dp[1000][1000];

int sumcolor(int s,int e)
{
	int ans=0;
	for(int i=s;i<=e;++i)
		ans=(ans%100+color[i]%100)%100;
	return ans;
}

long long solveMixtures(int s,int e)
{
	if(s>=e)
		return 0;
	else if(dp[s][e]!=-1)
		return dp[s][e];
	else{
		dp[s][e]=LLONG_MAX;
		for(int k=s;k<=e;++k)
			dp[s][e]=min(dp[s][e],solveMixtures(s,k)+solveMixtures(k+1,e)+sumcolor(s,k)*sumcolor(k+1,e));
		return dp[s][e];
	}
}

int main(int argc, char const *argv[])
{
	int n,i,j;
	while(cin>>n)
	{
		
		for(i=0;i<n;++i)
			cin>>color[i];
		for(i=0;i<n;++i)
			for(j=0;j<n;++j)
				dp[i][j]=-1;
		cout<<solveMixtures(0,n-1)<<endl;


	}
	return 0;
}