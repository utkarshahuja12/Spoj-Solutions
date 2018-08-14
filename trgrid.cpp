#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int qq;
	cin>>qq;
	while(qq--)
	{
		long long m,n;
		cin>>m>>n;
		if(m>n)
		{
			if(n%2)
				cout<<"D";
			else
				cout<<"U";
		}
		else
		{
			if(m%2)
				cout<<"R";
			else
				cout<<"L";
		}
		cout<<endl;
	}
	return 0;
}