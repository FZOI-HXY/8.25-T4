#include <bits/stdc++.h>
#define ra register int
using namespace std;
int n,m,sx,sy,t;
string mp[55],dmp[55];
string go[1005];
void dfs(int step,int x,int y){
    if(step==n){
        dmp[x][y]='*';
        return;
    }
    int f;
    if(go[step]=="NORTH") f=1;
    if(go[step]=="SOUTH") f=2;
    if(go[step]=="WEST") f=3;
    if(go[step]=="EAST") f=4;
    if(f==1){
        for(ra i(1);i<=m;++i){
            if(mp[x][y+i]!='X'&&x<=n&&x>=1&&y<=n&&y>=1)
                dfs(step+1,x,y+i);
        }
    }
    if(f==2){
        for(ra i(1);i<=m;++i){
            if(mp[x][y-i]!='X'&&x<=n&&x>=1&&y<=n&&y>=1)
                dfs(step+1,x,y-i);
        }
    }
    if(f==3){
        for(ra i(1);i<=n;++i){
            if(mp[x-i][y]!='X'&&x>=1&&x<=n)
                dfs(step+1,x-i,y);
        }
    }
    if(f==4){
        for(ra i(1);i<=n;++i){
            if(mp[x+i][y]!='X'&&x<=n)
                dfs(step+1,x+i,y);
        }
    }
}
int main() {
    scanf("%d%d",&n,&m);
    for(ra i(1);i<=n;++i){
        for(ra j(1);j<=m;++j){
            cin>>mp[i][j];
            if(mp[i][j]=='*')
                sx=i,sy=j;
        }
    }
    mp[sx][sy]='.';
    for(ra i(1);i<=n;++i){
        for(ra j(1);j<=m;++j){
           dmp[i][j]=mp[i][j];
        }
    }
    scanf("%d",&t);
    for(ra i(1);i<=t;++i){
        cin>>go[i];
    }
    dfs(0,sx,sy);
    for(ra i(1);i<=n;++i){
        cout<<dmp[i]<<endl;
    }
    return 0;
}
