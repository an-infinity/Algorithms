#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;
	vector<pair<int,int>> g[n];
	int a,b,c;
	for(int i=0;i<m;++i)
	{
		cin >> a >> b >> c; 
		g[a-1].push_back({c,b-1});
		g[b-1].push_back({c,a-1});
	}
	int key[n];
	int parent[n];
	bool vis[n];
	for(int i=0;i<n;++i)
	{
		parent[i]=-1;
		key[i]=0x3f3f3f3f;
		vis[i]=false;
	}
	priority_queue< pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
	pq.push({0,0});
	long long wt=0;
	key[0]=0;
	while(!pq.empty())
	{
		pair<int,int> t=pq.top();
		pq.pop();
		if(!vis[t.second]) wt+=t.first;
		vis[t.second]=true;
		for(auto x : g[t.second])
		{
			if(!vis[x.second] and x.first<key[x.second])
			{
				key[x.second]=x.first;
				pq.push(make_pair(key[x.second],x.second));
				parent[x.second]=t.second;
			}
		}
	}

	cout << wt;
}
