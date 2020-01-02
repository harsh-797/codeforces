#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb(x) push_back(x)
#define fr(a,b) for(int a=0;a<b;a++)
int main()
{
    ll n,q,x;
    cin>>n>>q;
    vector <ll> a;
    vector <ll> k;
    ll sum=0;
    fr(i,n)
    {
        cin>>x;
        sum+=x;
        a.pb(sum);
    }
    fr(j,q)
    {
        cin>>x;
        k.pb(x);
    }
    ll s=0;
    fr(i,q)
    {
        s=(s+k[i]);
        if(s>=a[n-1])
        {
            s=0;
            cout<<n<<'\n';
            continue;
        }
        vector <ll> :: iterator it=upper_bound(a.begin(),a.end(),s);
        it--;
        cout<<int(a.end()-it)-1<<'\n';
    }
}
