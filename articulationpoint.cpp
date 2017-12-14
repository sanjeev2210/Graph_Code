#include<bits/stdc++.h>
using namespace std;
vector<int> adj[10000];
int lowt[10000],vist[10000],parent[10000];
bool marked[10000],ap[10000];
int tim=0,nodes,edges;
void initialize()
{
    memset(marked,false,sizeof(marked));
    memset(ap,false,sizeof(ap));
    memset(parent,-1,sizeof(parent));
    memset(lowt,0,sizeof(lowt));
    memset(vist,0,sizeof(vist));
}
void dfs(int u)
{
    marked[u]=true;
    lowt[u]=vist[u]=tim++;
    int subchild=0;  //no. of subtrees from the node
    for(int i=0;i<adj[u].size();i++)
    {
        int v=adj[u][i];
        if(!marked[v])
        {
            subchild++;
            parent[v]=u;
            dfs(v);
            lowt[u]=min(lowt[u],lowt[v]);
            if(parent[u]!=-1 && lowt[v]>=vist[u])
            {
                ap[u]=true;
            }
            if(parent[u]==-1 && subchild>1)
            {
                ap[u]=true;
            }
        }
        else if(v!=parent[u])
        {
            lowt[u]=min(lowt[u],lowt[v]);
        }
    }
}
int main()
{
    initialize();
    int x,y,i,j,temp;
    cin>>nodes>>edges;
    for(i=0;i<edges;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(0);
    for(i=0;i<nodes;i++)
    {
        if(ap[i])
        {
            cout<<i<<" ";
        }
    }
    printf(" are the articulation point in the given graph\n");
    return 0;
}



