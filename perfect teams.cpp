#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin>>q;
    long long int c,m,x,p,n,l,r,mid,k;
    while(q--)
    {
        long long int ans=0;
        cin>>c>>m>>x;
        ans=min(c,min(m,x));
        c=c-ans;
        m=m-ans;
        x=x-ans;
        if(c>0 && m>0)
        {
            n=min(c,m);
            p=max(c,m);
            l=1;r=n;
            while(l<=r)
            {
                mid=(l+r)/2;
                if(mid*2<=p)
                {
                    k=mid;
                    l=mid+1;
                }
                else
                {
                    r=mid-1;
                }
            }
            ans+=k;
        }
        cout<<ans<<'\n';
    }
}
