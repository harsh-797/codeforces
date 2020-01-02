#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
ll int a,b,c;
cin>>a>>b>>c;
ll int ans;
ans=min(a/3,min(b/2,c/2));
a=a-ans*3;
b=b-ans*2;
c=c-ans*2;
ans=ans*7;
ll int best=INT_MIN,y;
y=ans;
int aa=a,bb=b,cc=c;
for(int i=1;i<=7;i++){
    int x=1;
    a=aa;
    b=bb;
    c=cc;
    for(int j=i;x<=7;x++){
        if((a==0 &&(j==1 || j==4 || j==7)) || (b==0 && (j==2 || j==6)) || (c==0 && (j==3 || j==5)))
            break;
        if((j==1 || j==4 || j==7) && a>0){
            a--;
            ans++;
        }
        if((j==2 || j==6) && b>0){
            b--;
            ans++;
        }
        if((j==3 || j==5) && c>0){
            c--;
            ans++;
        }
        j++;
        j=j%8;
    }
    best=max(best,ans);
    ans=y;
}
cout<<best;
}
