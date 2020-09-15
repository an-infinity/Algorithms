#include <bits/stdc++.h>
using namespace std;

int *parent,*rnk;

int find(int u)
{
	while(u!=parent[u])
	{
		u=parent[u];
	}
	return u;
}
void Union(int x,int y)
{
	int a=find(x),b=find(y);
	if(rnk[a]>rnk[b])
	{
		parent[b]=a;
	}
	else
	{
		parent[a]=b;
		if(rnk[a]==rnk[b]) rnk[a]++;
	}
}
int main()
{
	int n,m;
	cin >> n >> m;
	vector<pair<int,pair<int,int>>> edges;
	int a,b,c;
	for(int i=0;i<m;++i)
	{
		cin >> a >> b >> c; 
		edges.push_back({c,{a-1,b-1}});
	}

	parent=new int[n];
	rnk=new int[n];
	for(int i=0;i<n;++i)
	{
		parent[i]=i;
		rnk[i]=0;
	}
	sort(edges.begin(),edges.end());
	int wt=0;
	for(int i=0;i<m;++i)
	{
		int a=edges[i].second.first;
		int b=edges[i].second.second;
		if(find(a)!=find(b))
		{
			wt+=edges[i].first;
			Union(a,b);
		}
	}
	cout << wt;
}
