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
ll inf=1e18;
vector <int>rail[401];
set <int> road[401];
int n;
void fill_road()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(j!=i)
                road[i].insert(j);
    for(int i=1;i<=n;i++)
        for(int j=0;j<rail[i].size();j++)
            road[i].erase(rail[i][j]);
}
int main()
{
    int m;
    int x,y;
    cin>>n>>m;
    pair <int,int> p;
    bool g=false;
    while(m--){
        cin>>x>>y;
        if((x==1 && y==n)||(x==n && y==1)){
            g=true;
        }
        rail[x].pb(y);
        rail[y].pb(x);
    }
    queue <int> q;
    int vis[n+1]={0};
    int level[n+1]={0};
    if(g==true){
        fill_road();
        q.push(1);
        vis[1]=1;
        while(!q.empty()){
            x=q.front();
            q.pop();
            set <int> :: iterator it=road[x].begin();
            for(;it!=road[x].end();it++){
                if(vis[*it]==0){
                    level[*it]=level[x]+1;
                    q.push(*it);
                    vis[*it]=1;
                }
            }
        }
    }
    else{
        q.push(1);
        vis[1]=1;
        while(!q.empty()){
            x=q.front();
            q.pop();
            for(int i=0;i<rail[x].size();i++){
                if(vis[rail[x][i]]==0){
                    level[rail[x][i]]=level[x]+1;
                    q.push(rail[x][i]);
                    vis[rail[x][i]]=1;
                }
            }
        }
    }
    if(level[n]==0)
        cout<<"-1";
    else
        cout<<level[n];
}
