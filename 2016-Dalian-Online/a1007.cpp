#include <iostream>
using namespace std;
main()
{
	long long m,n;
	while (cin>>n>>m)
	{
		long long n1=n/2,n2=n-n1;
		if (m>=n1*n2) cout<<"T"<<endl;
		else cout<<"F"<<endl;
	}
}
