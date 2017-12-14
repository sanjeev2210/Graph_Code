#include<bits/stdc++.h>
#define mp make_pair
#define ll long long int
using namespace std;
vector<pair<ll,ll> > v[1000006];
ll dist[100005];
bool marked[100005];
ll nodes,edges;
void initialize()
{
    memset(marked,false,sizeof(marked));
    for(ll i=0;i<=nodes;i++)
    {
        dist[i]=1e9;   //ll_MAX;
    }
}
void djikstra(ll source)
{
    initialize();
    priority_queue<pair<ll,ll> ,vector<pair<ll,ll> >, greater<pair<ll,ll> > > pq;
    pq.push(mp(0,source));
    dist[source]=0;
    pair<ll,ll> pr;
    while(!pq.empty())
    {
        pr=pq.top();
        pq.pop();
        ll x=pr.first;        //shortest distance to reach the node y so far
        ll y=pr.second;       //it is the node y
        /*if(marked[y])
        {
            continue;
        }*/
        marked[y]=true;
        for(ll i=0;i<v[y].size();i++)
        {
            ll m=v[y][i].first;     //second node of the edge connected to node y
            ll n=v[y][i].second;      // weight b/w the nodes m and y
            if((!marked[m])&&(dist[m]>x+n))
            {
                dist[m]=x+n;
                pq.push(mp(dist[m],m));
            }
        }
    }
}
int main()
{
    ll i,j,x,y,weight,temp;
    cin>>nodes>>edges;
    for(i=0;i<edges;i++)
    {
        cin>>x>>y>>weight;
        v[x].push_back(mp(y,weight));
        v[y].push_back(mp(x,weight));
    }
    djikstra(1);
    for(i=2;i<=nodes;i++)
    {
        cout<<dist[i]<<" ";
    }
    return 0;
}
//lets change if required






