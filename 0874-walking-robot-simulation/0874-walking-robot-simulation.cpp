class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // Directions: north, east, south, west
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int x = 0, y = 0, d = 0; // Start position and direction
        set<pair<int, int>> obstacleSet;
        
        // Convert obstacles to a set for fast lookup
        for (const auto& obs : obstacles) {
            obstacleSet.insert({obs[0], obs[1]});
        }

        int maxDistSquared = 0;

        for (int cmd : commands) {
            if (cmd == -1) {
                d = (d + 1) % 4; // Turn right
            } else if (cmd == -2) {
                d = (d + 3) % 4; // Turn left
            } else {
                // Move forward
                for (int k = 0; k < cmd; ++k) {
                    int newX = x + directions[d].first;
                    int newY = y + directions[d].second;

                    // Check for obstacles
                    if (obstacleSet.find({newX, newY}) == obstacleSet.end()) {
                        x = newX;
                        y = newY;
                        maxDistSquared = max(maxDistSquared, x * x + y * y);
                    }
                }
            }
        }

        return maxDistSquared;
    }
};