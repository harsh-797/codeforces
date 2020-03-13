#include <bits/stdc++.h>
using namespace std;
int cnt;
vector <int> v[50];
int check[50]={0};
int vis[49]={0};
set <int> single;
vector <int> group;
void dfs(int i){
    if(check[i]==0){
            return;
    }
    group.push_back(i);
    cnt++;
    vis[i]=1;
    for(int x=0;x<v[i].size();x++){
        if(vis[v[i][x]]==0)
            dfs(v[i][x]);
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    int x,y;
    vector < vector <int> > ans;
    while(m--){
        cin>>x>>y;
        check[x]++;
        check[y]++;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
        if(check[i]==0)
            single.insert(i);
    for(int i=1;i<=n;i++){
        if(vis[i]==0 && check[i]){
            dfs(i);
            if(cnt>3){
                cout<<"-1"<<endl;
                return 0;
            }
            if(cnt<3){
                int x=3-cnt;
                while(x--){
                    if(single.empty())
                    {
                        cout<<"-1"<<endl;
                        return 0;
                    }
                    group.push_back(*(single.begin()));
                    vis[*(single.begin())]=1;
                    single.erase(*(single.begin()));
                }
            }
            cnt=0;
            ans.push_back(group);
            group.clear();
        }

    }
    if(single.size()%3!=0){
        cout<<"-1"<<endl;
        return 0;
    }
    for(set <int> :: iterator it=single.begin();it!=single.end();it++){
        vector <int> h;
        h.push_back(*it);
        it++;
        h.push_back(*it);
        it++;
        h.push_back(*it);
        ans.push_back(h);
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<endl;
    }
}
