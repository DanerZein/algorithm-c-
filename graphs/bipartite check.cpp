#include <bits/stdc++.h>

using namespace std;
typedef vector<int>vi;
vector<vi>G;
int c[10000];

bool dfs(int u,int p){
    bool ans =true;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(v!=p){
            int cadj=1-c[u];
            if(c[v]==-1){
            	c[v]=cadj;
                ans= ans and dfs(v,u);
            }else{
                if(c[v]==c[u]){
                    return false;
                }
            }
        }
    }
    return ans;

}
int main()
{
int N,e;
cin>>N>>e;
G.resize(N+1);
memset(c,-1,sizeof c);
for(int i=0;i<e;i++){
    int u,v;
    cin>>u>>v;
    G[u].push_back(v);
    G[v].push_back(u);
}
bool esB=true;
for(int i=1;i<=N;i++){
    if(c[i]==-1){
        c[i]=0;
        esB=esB and dfs(i,i-1);
    }
}
if(esB)
    cout<<"YES"<<endl;
else
    cout<<"NO"<<endl;
 for(int i=1;i<=N;i++){
 	cout<<c[i]<<" ";
 }
 cout<<endl;
}
