#include<conio.h>
using namespace std;
#include<iostream>
#include<iomanip>
#include<math.h>
int main()
{
	for(int i=1;i<=10;i++)
	{
		for( int j=2;j<=10;j++)
		{
			if(i%j==0&&i>1)
			{
			cout<<i<<" ";	
			}
		}
	}
}
