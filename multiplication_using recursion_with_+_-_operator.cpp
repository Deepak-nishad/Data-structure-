#include <bits/stdc++.h>
using namespace std;

int mul(int m,int n)
{
	if(n==0)
	return 0;
	else
	return mul(m,n-1)+m;
}
int main()
{
	int a=4, b=5;
	int output=mul(a,b);
	cout<<output<<" ";
}
