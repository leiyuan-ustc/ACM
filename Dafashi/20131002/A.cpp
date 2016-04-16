#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const double dps=1e-6;
main()
{
	int a,b;
	double c;
	while (scanf("%d%d%lf",&a,&b,&c))
	{
		if (a==0 && b==0 ) break;
		printf("%d\n",a-1);
	}
}
