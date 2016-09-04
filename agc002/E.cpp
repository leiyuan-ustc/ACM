#include <iostream>
#include <algorithm>
using namespace std;
int x,y,n,a[100010],i,flag;
main()
{
	cin>>n;
	for (i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	i=1;
	while (a[i]+i<n+1) i++;
	x=i;y=n+1-i;
	flag=-1;
	if ((a[x]-y)%2==1) 
	{
		cout<<"First"<<endl;
		return 0;
	}
	while (y==a[i-1])
	{
		i--;
		flag*=-1;
	}
	if (flag==-1) cout<<"Second"<<endl;
	else cout<<"First"<<endl;
}
