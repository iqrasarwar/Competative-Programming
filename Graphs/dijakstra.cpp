//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        set<pair<int,int>> q;
        vector<int> dist(V,INT_MAX);
        // vector<bool> vis(V,0);
        
        dist[S] = 0;
        q.insert({0,S});
        while(!q.empty())
        {
            auto p = *(q.begin());
            q.erase(q.begin());
            int node = p.second;
            // if(vis[node]) continue;
            // vis[node] = 1;
            auto neighbours = adj[node];
            for(auto i : neighbours)
            {
                int j = i[0];
                int wt = i[1];
                if(wt+dist[node] < dist[j])
                {
                    dist[j] = wt+dist[node];
                    q.insert({dist[j],j});
                }
            }
        }
        return dist;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends
