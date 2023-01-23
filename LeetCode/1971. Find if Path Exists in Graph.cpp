class Solution {
public:
    public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        queue<int> q;
        q.push(source);
        vector<bool> visited(n, false);
        visited[source] = true;
        while (!q.empty()) {
            int vertex = q.front();
            q.pop();
            if (vertex == destination) return true;
            for (int neighbor : graph[vertex]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
        return false;
    }

};
