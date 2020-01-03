#include <bits/stdc++.h>
using namespace std;
int a[402][22][22];
int x[21],y[21];
int n,m,z=1;
pair <int,int> t[21][21];
void pre(int i,int j)
{
    if((i<1 || i>n) || (j<1 || j>m) || a[z][i][j]==1)
        return;
    a[z][i][j]=1;
    int f=i+t[i][j].second;
    int g=j+t[i][j].first;
    pre(i,g);
    pre(f,j);

}
int main()
{
    string s1,s2;;
    cin>>n>>m;
    cin>>s1;
    cin>>s2;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1]=='<')
                t[i][j].first=-1;
            else
                t[i][j].first=1;
            if(s2[j-1]=='^')
                t[i][j].second=-1;
            else
                t[i][j].second=1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            pre(i,j);
            z++;
        }
    }
    int sum=0;
    for(int i=1;i<=z;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=m;k++)
            {
                sum+=a[i][j][k];
            }
        }
    }
    if(sum==n*n*m*m)
        cout<<"YES";
    else
        cout<<"NO";
}
