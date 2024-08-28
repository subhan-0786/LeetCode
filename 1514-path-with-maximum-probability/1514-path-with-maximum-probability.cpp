class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        // Create adjacency list
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            double prob = succProb[i];
            graph[u].push_back({v, prob});
            graph[v].push_back({u, prob});
        }
        
        // Initialize probabilities
        vector<double> maxProb(n, 0.0);
        maxProb[start] = 1.0;
        
        // Priority queue to store {probability, node}
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start});
        
        while (!pq.empty()) {
            double prob = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if (node == end) return prob;
            
            // If we've found a path with lower probability, skip
            if (prob < maxProb[node]) continue;
            
            // Explore neighbors
            for (auto& neighbor : graph[node]) {
                int nextNode = neighbor.first;
                double edgeProb = neighbor.second;
                double newProb = prob * edgeProb;
                
                if (newProb > maxProb[nextNode]) {
                    maxProb[nextNode] = newProb;
                    pq.push({newProb, nextNode});
                }
            }
        }
        
        return 0.0;  // No path found
    }
};