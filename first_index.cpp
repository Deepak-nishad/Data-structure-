#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
int first_index(int arr[],int size,int x)
{
	if(size==0)
	return -1;
	if(arr[0]==x)
	return 0;
	int ans=first_index(arr+1,size-1,x);
	if(ans==-1)
	return -1;
	else
	return ans+1;
}
int main()
{
		int arr[]={9,8,10,4};
	int n=sizeof(arr)/sizeof(int);
	int output=first_index(arr,n,8);
	cout<<output<<" ";
	getch();
}
