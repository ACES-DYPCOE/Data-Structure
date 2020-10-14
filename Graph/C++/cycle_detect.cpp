// Given an undirected graph having A nodes labelled from 1 to A with M edges given in a form of matrix B
// of size M x 2 where (B[i][0], B[i][1]) represents two nodes B[i][0] and B[i][1] connected by an edge.

// Find whether the graph contains a cycle or not, return 1 if cycle is present else return 0.


// Input:
//  A = 5
//  B = [  [1. 2]
//         [1, 3]
//         [2, 3]
//         [1, 4]
//         [4, 5]
//      ]

// Output:
// 1

#include<bits/stdc++.h>

using namespace std;


bool dfs(int u, std::vector<std::vector<int> > &adj, std::vector<bool>& visited, int parent){

    visited[u] =true;
    
    for(int v : adj[u]){

        if(!visited[v]){      
            if(dfs(v, adj, visited, u))
                return true;
        }
        else if(v!=parent) return true;
    }
    return false;
}


int main()
{
    int A;                     // number of edges
    vector<vector<int>> B;     //edges

    cin>>A;
    for (int i =0; i<A; i++){
        vector<int> x(2);
        cin>>x[0];
        cin>>x[1];
        B.push_back(x);
    }
    
    vector<vector<int>> adj(A); //adjacency list 

    for(int i=0; i<B.size(); i++){
        int u, v;
        u = B[i][0]-1;
        v = B[i][1]-1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    

    vector<bool> visited(A,false);

    for(int i=0; i<A; i++){
        if(!visited[i])
            if(dfs(i, adj, visited, -1)){
                cout<<1<<endl;
                return 0;
            } 
    }

    // Time Complexity - O(n+m)
    
    cout<<0<<endl;
    return 0;
}