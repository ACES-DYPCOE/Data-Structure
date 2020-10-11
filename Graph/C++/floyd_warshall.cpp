#include<bits/stdc++.h>
#define ll long long 
using namespace std;
 

// There are n cities and m roads between them. 
// Your task is to process q queries where you have to determine 
// the length of the shortest route between two given cities.
 

// 1≤n≤500
// 1≤m≤n^2
// 1≤q≤10^5
// 1≤a,b≤n
// 1≤c≤10^9

'''
Input:
4 3 5
1 2 5
1 3 9
2 3 3
1 2
2 1
1 3
1 4
3 2

Output:
5
5
8
-1
3

'''

const ll int INF = LONG_MAX;
 
int main(){

	// n, m and q: the number of cities, roads, and queries.

	int n,m,q;

	cin>>n>>m>>q;
 
 	// Let d be the matrix of distances, i.e., d[u][v] tells us the distance between u and v

	vector<vector<ll int>> d(n, vector<ll int>(n,INF));
 
	for(int i=0; i<m; i++){
		int u,v;
		ll c;
		cin>>u>>v>>c;
		d[u-1][v-1] = min(d[u-1][v-1],c);
		d[v-1][u-1] = min(d[v-1][u-1],c);
	}
 

	for(int i=0; i<n; i++) d[i][i] = 0; //d[u][u] = 0 as distance between u and u is zero
  
 
 	// Floyd-Warshall Algorthim for all pair shortes paths 

	for(int k=0; k<n; k++){
		for(int i =0; i<n; i++){
			for(int j = 0; j<n; j++){
				if(d[i][k]<INF && d[k][j]<INF)
				d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
			}
		}
	}

 
 	// answering queries
	vector<pair<int, int>> vp;
	for(int i=0; i<q; i++){
		int u,v;
		cin>>u>>v;
		vp.push_back({u,v});
 
	}
 
	for(auto e : vp){
		int u = e.first;
		int v = e.second;
		if(d[u-1][v-1]!=INF) cout<<d[u-1][v-1]<<endl; //printing distance
		else cout<<-1<<endl; //if no path, print -1
	}
 
 
}