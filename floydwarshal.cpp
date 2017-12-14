#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
//vector<pair<int,int> > v[10000];   no need of vector for this purpose
int dist[100][100];
int nodes,edges;
void initialize()
{
    for(int i=0;i<nodes;i++)
    {
        for(int j=0;j<nodes;j++)
        {
            if(i==j)        //making diagonal entries zero
            {
                dist[i][j]=0;
                continue;
            }
            dist[i][j]=99999;
        }
    }
}
void floydwarsh()
{
    for(int k=0;k<nodes;k++)            //considering this node as intermediate node to reach from node i to node j;
    {
        for(int i=0;i<nodes;i++)        //considering this node as starting node;
        {
            for(int j=0;j<nodes;j++)    //taking this node as ending node;
            {
                if(dist[i][j]>dist[i][k]+dist[k][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }

}
int main()
{
    int i,j,x,y,weight,temp;
    cin>>nodes>>edges;
    initialize();
    for(i=0;i<edges;i++)
    {
        cin>>x>>y>>weight;
        //v[x].push_back(mp(y,weight));   //no need of vector here;
        dist[x][y]=weight;
    }
    floydwarsh();
    for(i=0;i<nodes;i++)
    {
        for(j=0;j<nodes;j++)
        {
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
