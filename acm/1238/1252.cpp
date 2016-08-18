#include <iostream>
#include <string>
using namespace std;
int main()
{
    string a,b,ans,tmp;
    int carry=0;
    cin>>a>>b;
    int k=0;
    if(a.length()>1&&a[0]=='0')
    {
        while(a[0]!=0 && a.length()>1)
            a.erase(a.begin());
    }
    if(b.length()>1&&b[0]=='0')
    {
        while(b[0]!=0 && b.length()>1)
            b.erase(b.begin());
    }
    int minLength=a.size();
    if(minLength>b.length())
    {
        minLength=b.length();
        tmp=a;
        a=b;
        b=tmp;
    }
    for(int i=minLength-1; i>=0; i--)
    {
        if(carry==0)
        {
            if((a[i]-'0')+(b[i+b.length()-a.length()]-'0')==0)
            {
                carry=0;
                ans='0'+ans;
            }
            else if((a[i]-'0')+(b[i+b.length()-a.length()]-'0')==1)
            {
                carry=0;
                ans='1'+ans;
            }
            else
            {
                carry=1;
                ans='0'+ans;
            }
        }
        else //carry=1;
        {
            if((a[i]-'0')+(b[i+b.length()-a.length()]-'0')==0)
            {
                carry=0;
                ans='1'+ans;
            }
            else if((a[i]-'0')+(b[i+b.length()-a.length()]-'0')==1)
            {
                carry=1;
                ans='0'+ans;
            }
            else
            {
                carry=1;
                ans='1'+ans;
            }
        }
    }
    if(a.length()==b.length())
    {
        if(carry==1)
            ans='1'+ans;
    }
    else
    {
        int i=b.length()-a.length()-1;
        while(i>=0)
        {
            if(carry==0)
                ans=b[i]+ans;
            else//carry==1
            {
                if(b[i]=='1')
                {
                    carry=1;
                    ans='0'+ans;
                }
                else //b[i]=='0'
                {
                    carry=0;
                    ans='1'+ans;
                }
            }
            i--;
        }
        if(i==-1&&carry==1)
            ans='1'+ans;
    }
    cout<<ans<<endl;
}