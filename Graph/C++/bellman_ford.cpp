// You are given a directed graph, and your task is to find out if it contains a negative cycle,
// and also give an example of such a cycle.

// a , b, and c: there is an edge from node a to node b whose length is c.

/*
1≤n≤2500
1≤m≤5000
1≤a,b≤n
−10^9≤c≤10^9

Input:
4 5
1 2 1
2 4 1
3 1 1
4 1 -3
4 3 -2

Output:
YES
1 2 4 1

*/

#include<bits/stdc++.h>
 
using namespace std;
 
const long long INF = 1e9;
 
// creating a new struct edge

struct edge{
	int a,b,c;
};
 

// bellman ford algorithm to detect negative cycle in a directed graph
void bellman_ford(vector<edge> &edges, int n){
 
	int m = edges.size();
 
	vector<int> p(n, -1);
	vector<long long> d(n,INF);
 
	d[0] = 0;
	int x;
	for(int i=0; i<n; i++){
		x = -1;
		for(int j = 0; j<m; j++){
		
			if(d[edges[j].b] > d[edges[j].a] + edges[j].c){
				d[edges[j].b] = max(-INF ,d[edges[j].a] + edges[j].c);
				p[edges[j].b] = edges[j].a;
				x = edges[j].b;
			}
			
		}
	}

	// Time Complexity - O(nm)
	// Space Complexity - O(m + n)
 
	if (x==-1){
		cout<<"NO"<<endl;
	}
 
	else{
		for(int i=0; i<n; i++){
			x = p[x];
		}
 
		vector<int> cycle;
 
		int v = x;
		while(!(v==x && cycle.size()>1)){
			cycle.push_back(v);
			v = p[v];
		}
 
		reverse(cycle.begin(), cycle.end());
 
		cout<<"YES"<<endl;
		for(int v : cycle){
			cout<<v+1 <<" ";
		}
		if(cycle[0]!=cycle[1]){
			cout<<cycle[0]+1;
		}
		cout<<endl;
 
	}
 
 
}
 
int main(){
 
 
	int n, m;
	cin>>n>>m;
	vector<edge> edges;
	for(int i=0; i<m; i++){
		int u, v, c;
		cin>>u>>v>>c;
		edge a = {u-1,v-1,c};
		edges.push_back(a);
 
	}
 
	bellman_ford(edges, n);
	
}