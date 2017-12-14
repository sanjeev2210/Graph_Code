#include<bits/stdc++.h>
using namespace std;
vector<int> v[10002],vrev[10002];
bool visited[10002];
stack<int> s;
int nodes,edges;
int dfs(int vtx)
{
    visited[vtx]=true;
    for(int i=0;i<v[vtx].size();i++)
    {
        int u=v[vtx][i];
        if(!visited[u])
        {
            dfs(u);
        }
    }
    s.push(vtx);
    //cout<<vtx<<" pushed\n";
}
void revdfs(int source)
{
    visited[source]=true;
    for(int i=0;i<vrev[source].size();i++)
    {
        if(!visited[vrev[source][i]])
        {
            revdfs(vrev[source][i]);
        }
    }
}
int main()
{
    int i,j,m,n;
    cin>>nodes>>edges;
    for(i=0;i<edges;i++)
    {
        cin>>m>>n;
        v[m].push_back(n);
        vrev[n].push_back(m);
    }
    int cntno=0;
    memset(visited,false,sizeof(visited));
    dfs(0);
    memset(visited,false,sizeof(visited));
    /*while(!s.empty())
    {
        int u=s.top();
        cout<<u<<" ";
        s.pop();
    }*/
    while(!s.empty())
    {
        int u=s.top();
        s.pop();
        cout<<u<<" ";
        if(!visited[u])
        {
            revdfs(u);
            cntno++;
        }
    }
    printf("\nthe no of strongly connected components are %d\n",cntno);
    return 0;
}
