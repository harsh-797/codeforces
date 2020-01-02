#include <bits/stdc++.h>
using namespace std;
int a[10][1000001];
int pre(int x)
{
    if(x<10)
        return x;
    int v=x;
    int m=1;
    while(v)
    {
        int z=v%10;
        if(z!=0)
            m=m*z;
        v/=10;
    }
    return pre(m);
}
int main()
{
    int q,x,l,r,k;
    cin>>q;
    for(int i=1;i<=1000000;i++)
    {
        x=pre(i);
        a[x][i]=1;
    }
    for(int i=0;i<10;i++)
    {
        for(int j=1;j<=1000000;j++)
            a[i][j]+=a[i][j-1];
    }
    while(q--)
    {
        cin>>l>>r>>k;
        if(l==1)
            cout<<a[k][r]<<'\n';
        else
            cout<<a[k][r]-a[k][l-1]<<'\n';
    }
}
