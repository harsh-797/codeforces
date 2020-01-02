#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n;
ll pre(ll x){
    ll s=0;
    ll j=n;
    while(j){
        if(j<x)
            return s+j;
        s+=x;
        j-=x;
        j-=(j/10);
    }
    return s;
}
int main()
{
    cin>>n;
    ll l=1,r=n,m=0,ans=0;
    while(l<=r){
        m=l+(r-l)/2;
        if(pre(m)>=((n+1)/2)){
            r=m-1;
            ans=m;
        }
        else
            l=m+1;
    }
    cout<<ans;
}


