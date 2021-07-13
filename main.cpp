#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pb push_back
#define pob pop_back
#define mp make_pair
#define ff first
#define ss second
#define pi 3.14159265
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <ll, ll> pll;
const ll M=1e9+7;
ll expo(ll a,ll b){if(b==0)return 1;if(b%2==0){ll ret=expo(a,b/2);ret=(ret*ret)%mod;return ret;}else{ll ret=expo(a,b/2);ret=(ret*ret)%mod;ret=(ret*a)%mod;return ret;}}
ll inf=1e18;
int main()
{
    fast;
	string s;
	cin>>s;
	int n=s.length();
    bool h=true;
    for(int i=0;i<n;i++)
        if(s[i]=='a' || s[i]=='b')
            h=false;
    if(h){
        cout<<0;
        return 0;
    }
	for(int i=0;i<s.length();i++)
    if(s[i]>'b'){
        s=s.substr(0,i)+s.substr(i+1);
    }
	vector <pair<char,ll> >v;
	ll y=0;
	for(int i=0;i<n;i++){
        int j;
        for(j=i;j<n;j++){
            if(s[j]==s[i]){
                y=(y+1)%mod;
                if(j==n-1 && (s[i]=='a' || s[i]=='b'))
                v.pb({s[i],y});
            }
            else{
                if(s[i]=='a' || s[i]=='b')
                v.pb({s[i],y});
                y=0;
                break;
            }
        }
        i=j-1;
	}
	int t=v.size();
	ll ans=1;
	int i;
	if(v[0].ff=='a')
        i=0;
    else
        i=1;
    for(;i<t;i+=2){
        ans=(ans*((v[i].ss+1LL)%mod))%mod;
    }
    cout<<ans-1;
}
