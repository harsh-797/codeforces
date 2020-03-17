#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int sze[150001];
int arr[150001];
vector <int> v[150001];
int vis[150001];
bool g=true;
int vis1[150001];
int d;
int dfs1(int z)
{
    vis1[z]=1;
    if(sze[z]>sze[d])
        d=z;
    for(int i=0;i<v[z].size();i++)
        if(vis1[v[z][i]]==0)
            dfs1(v[z][i]);
}
void dfs(int z,int s)
{
    vis[z]=1;
    if(v[z].size()!=s)
        g=false;
    for(int i=0;i<v[z].size();i++)
        if(vis[v[z][i]]==0)
            dfs(v[z][i],s);
}
int root(int i)
{
    while(arr[i]!=i)
        i=arr[arr[i]];
    return i;
}
void unionn(int u,int v)
{
    int a=root(u);
    int b=root(v);
    if(a==b)
        return;
    if(sze[a]>sze[b])
        swap(a,b);
    arr[a]=arr[b];
    sze[b]+=sze[a];
}
int main()
{
    for(int i=1;i<=150000;i++)
        sze[i]=1;
    for(int i=1;i<=150000;i++)
        arr[i]=i;
    int n,m;
    cin>>n>>m;
    int x,y;
    while(m--){
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
        unionn(x,y);
    }
    vector <int> parent;
    for(int i=1;i<=n;i++){
        if(vis1[i]==0){
            d=i;
            dfs1(i);
            parent.pb(d);
        }
    }
    for(int i=0;i<parent.size();i++)
    {
            dfs(parent[i],sze[parent[i]]-1);
            if(g==false){
                cout<<"NO"<<endl;
                return 0;
            }
    }
    cout<<"YES"<<endl;
    return 0;
}
