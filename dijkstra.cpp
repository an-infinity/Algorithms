//Implementation of Dijsktra's ALgorithm
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pr;
void print(map<int,int> p)
{
	for(auto x: p)
	{
		cout << x.first << " " << x.second << endl;;
	}
}
void dijkstra(vector<int> g[],int s,map<pair<int,int>,int> wt,int V,int dist[])
{
	multiset < pair < int , int > > p;
	p.insert({0,0});
	bool vis[V];
	memset(vis,false,sizeof(vis));
	while(!p.empty())
	{
		pr pt=*p.begin();
		p.erase(p.begin());
		int we=pt.first,u=pt.second;
		if(vis[u]) continue;
		vis[u]=true;
		for(auto x : g[u])
		{
		if(dist[u]+wt[{u,x}]<dist[x])
			{
				dist[x]=dist[u]+wt[{u,x}];
				p.insert({dist[x],x});
			}
		}
	}
}
int main()
{
	int n,m,a,b,w;
	cin >> n >> m;
	map<pair<int,int>,int> wt;
	vector<int> g[n];
	while(m--)
	{
		cin >> a >> b >> w;
		g[a-1].push_back(b-1);
		wt[{a-1,b-1}]=w;
	}
	int dist[n];
	memset(dist,1000000001,sizeof(dist));
	dist[0]=0;
	dijkstra(g,0,wt,n,dist);
	for(int i=1;i<n;++i)
	{
		if(dist[i]==1000000001)
		{
			cout << dist[i]-1 << " ";
		}
		else
		{
			cout << dist[i] << " ";
		}
	}
}
