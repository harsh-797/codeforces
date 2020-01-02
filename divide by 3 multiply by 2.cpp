#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n,z,y,t;
set <ll> s;
vector <ll> v;
bool pre(ll x)
{
    if(x%3==0)
        y=x/3;
    else
        y=-1;
    z=x*2;
    if(t==n-1)
    {
        if(s.find(y)!=s.end())
            v.push_back(y);
        else if(s.find(z)!=s.end())
            v.push_back(z);
        else
            return false;
        return true;
    }
    if(s.find(y)!=s.end())
    {
        v.push_back(y);
        ll l=t;
        t++;
        if(pre(y)){
            return true;}
        t=l;
    }
    else if(s.find(z)!=s.end())
    {
        v.push_back(z);
        ll p=t;
        t++;
        if(pre(z)){
            return true;}
        t=p;
    }
    else return false;
}
int main()
{
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        s.insert(a[i]);
    }
    for(int i=0;i<n;i++)
    {
        t=0;
        v.push_back(a[i]);
        bool g=pre(a[i]);
        if(v.size()==n){
        for(int j=0;j<v.size();j++)
                cout<<v[j]<<" ";
        return 0;}
        v.clear();
    }
}
