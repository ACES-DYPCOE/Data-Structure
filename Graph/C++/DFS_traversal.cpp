#include<bits/stdc++.h>
using namespace std;




/* Function to do DFS of graph

g : adjacency list of graph
N : number of vertices

return a list containing the DFS traversal of the given graph
*/



void rec_dfs(vector<int> g[],vector<int> &result,int k,int *visit){
    
    result.push_back(k);
    visit[k] = 1;

        for(i:g[k]){
            if(visit[i] == 0){
                rec_dfs(g,result,i,visit);
            }
        }
    
    
    return;
}


vector <int> dfs(vector<int> g[], int N)
{
    vector<int> result;
    
    int visit[N] = {0};
    
    rec_dfs(g,result,0,visit);
    

    
    return result;

}



int main()
{
    int T;
    cin>>T;
    while(T--)
    {

        int N, E;
        cin>>N>>E;
        
        vector<int> g[N];
        bool vis[N];
        
        memset(vis, false, sizeof(vis));
        
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector <int> res = dfs(g, N);
        for (int i = 0; i < res.size (); i++)
            cout << res[i] << " ";
        cout<<endl;

    }
}