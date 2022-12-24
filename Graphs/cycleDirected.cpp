//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        bool visited[V];
        bool s[V];
        for(int i = 0; i < V; i++)
        {
            visited[i] = false;
            s[i] = false;
        }
        for(int i =0;i<V;i++)
        {
            if(!visited[i])
            {
                if(dfs(visited, adj, i, s))
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(bool visited[], vector<int> adj[], int source, bool s[])
    {
        if(visited[source] != true) 
        { 
            visited[source] = true;
            s[source] = true;
            auto neighbours = adj[source];
            for( auto node : neighbours)
            {
                if(!visited[node])
                {
                    if(dfs(visited, adj, node, s))
                    {
                        return true;
                    }
                }
                else if(s[node])
                    return true;
            }
        }
        s[source] = false;
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
