#include <iostream>
using namespace std;
#include <cstdio>
#include <cstring>
#include <map>
char s[1010];
int ans;
string anss;
map<string,int> w;
main()	
{
	while (gets(s)!=NULL)
	{
		if (s[0]=='#'&&s[1]=='#'&&s[2]=='#'&&s[3]=='#') 
		{
			cout<<anss<<":"<<ans<<endl;
			ans=0;
			anss="";
			w.clear();
			continue;
	    }
		int len=strlen(s);
		int state=0;
		s[len]='.';
		len++;
		s[len]='\0';
		string s1="",s2="";
		for (int i=0;i<len;i++)
		 if (s[i]>='a'&&s[i]<='z')
		 {
		 	s2=s2+s[i];
		 	state=0;
		 }
		 else
		 if (s[i]==','||s[i]=='.')
		 {
		 	state=0;
		 	if (s1!=""&&s2!="")	
			 {
			 	string s3=s1+' '+s2;
			 	w[s3]=w[s3]+1;
			 	if (ans<w[s3])
			 	{
			 		ans=w[s3];
			 		anss=s3;
				 }
				 else
				 if (ans==w[s3]&& s3<anss) anss=s3;
			 }
		 	s1="";
		 	s2="";
		 }
		 else
		 if (s[i]==' ')
		 {
		 	if (state==0) state=1;
		  	else continue;
		  	if (s1!=""&&s2!="")	
			 {
			 	string s3=s1+' '+s2;
			 	w[s3]=w[s3]+1;
			 	if (ans<w[s3])
			 	{
			 		ans=w[s3];
			 		anss=s3;
				 }
				 else
				 if (ans==w[s3]&& s3<anss) anss=s3;
			 }
		  	s1=s2;
		  	s2="";
		 }		 
	}
}
