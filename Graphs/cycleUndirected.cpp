//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        bool visited[V] = {0};
        for(int i =0;i<V;i++)
        {
            visited[i]=0;
        }
        for(int i =0;i<V;i++)
        {
            if(visited[i] != true) 
           { 
               if(dfs(visited, adj, i, -1))
                return true;
           }
        }
        return false;
    }
    bool dfs(bool visited[], vector<int> adj[], int source, int par)
    {
        visited[source] = true;
        bool loop = false;
        auto neighbours = adj[source];
        for( auto node : neighbours)
        {
            if(node != par && visited[node]) return true;;
            if(visited[node] != true) 
            loop |= dfs(visited, adj, node, source);
        }
        return loop;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
