#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pb push_back
#define pob pop_back
#define mp make_pair
#define ff first
#define ss second
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <ll, ll> pll;
const ll M=1e9+7;
ll inf=1e18;
map <int,int> v[200000+1];
vector <int> g[2000001];
int main()
{
    fast;
    int prime[200000+1]={0};
    for(int i=2;i*i<=200000;i++){
        if(prime[i]==0){
            for(int j=i;j<=200000;j+=i)
                prime[j]=i;
        }
    }
    for(int i=2;i<=200000;i++)
        if(prime[i]==0)
            prime[i]=i;
    for(int i=2;i<=200000;i++){
        int x=i,z=i;
        while(x>1){
            if(v[z].find(prime[x])!=v[z].end())
                v[z][prime[x]]++;
            else
                v[z][prime[x]]=1;
            x/=prime[x];
        }
    }
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int d[200000+1]={0};
    for(int i=0;i<n;i++){
        int x=a[i];
        map <int,int> :: iterator it=v[x].begin();
        for(;it!=v[x].end();it++){
            d[(*it).first]++;
            g[(*it).first].pb((*it).second);
        }
    }
    for(int i=2;i<=200000;i++)
        sort(g[i].begin(),g[i].end());
    ll ans=1;
    for(int i=2;i<=200000;i++){
        if(d[i]==n)
            ans*=pow(i,g[i][1]);
        else if(d[i]==n-1)
            ans*=pow(i,g[i][0]);
    }
    cout<<ans;
}
