#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int n;
    while(t--)
    {
        cin>>n;
        int g=0;
        int a[n+1];
        for(int i=1;i<=n;i++)
        {

            cin>>a[i];
            if(a[i]>0)
                g++;
        }
        if((g==n-1 && (a[1]==0|| a[n]==0)) || g==n)
        {
            cout<<"YES"<<endl;
            continue;
        }
        long long int sum=0;
        for(int i=1;i<=n;i++)
        {
            sum=sum+a[i];
        }
        long long int s=0;
        long long int maxx=INT_MIN;
        int l=1,r=0;
        for(int i=1;i<=n;i++)
        {
            if(s+a[i]>0){
                s=s+a[i];
                r++;}
            else{
                s=0;
                l=i+1;
                r=i+1;
            }
            maxx=max(maxx,s);
            if(maxx>=sum && (l>1 || r<n)){
                cout<<"NO"<<endl;
                goto z;
            }
        }
        if(l==1 && r==n && maxx==sum)
            cout<<"YES"<<endl;
        else{
        if(sum>maxx)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
       z:65;}
    }
}
