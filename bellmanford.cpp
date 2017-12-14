#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
pair<int,pair<int,int> > p[1000];
int dist[1000];
int nodes,edges;
void initialize()
{
    for(int i=0;i<=nodes;i++)
    {
        dist[i]=99999;  // INT_MAX
    }
}
void bellman(int start)
{
    initialize();
    dist[start]=0;
    for(int i=1;i<=nodes-1;i++)
    {
        for(int j=1;j<=edges;j++)
        {
            if(dist[p[j].second.first]>(dist[p[j].first]+p[j].second.second))
            {
                dist[p[j].second.first]=dist[p[j].first]+p[j].second.second;
            }
        }
       /* for(int k=1;k<=nodes;k++)
        {
            cout<<dist[k]<<" ";
        }
        cout<<endl;*/
    }
}
int main()
{
    int n,i,j,x,y,weight,temp;
    cin>>nodes>>edges;
    for(i=1;i<=edges;i++)
    {
        cin>>x>>y>>weight;
        p[i]=mp(x,mp(y,weight));
    }
    /*for(i=1;i<=edges;i++)
    {
        cout<<p[i].first<<" "<<p[i].second.first<<" "<<p[i].second.second<<endl;
    }*/
    bellman(1);  //considering source vertex as 1
    for(i=1;i<=nodes;i++)
    {
        cout<<dist[i]<<" ";
    }
    return 0;
}
