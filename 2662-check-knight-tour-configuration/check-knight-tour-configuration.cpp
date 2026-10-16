class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] != 0) {
            return false;
        }

        vector<pair<int, int>> pos(n * n);

        // Store the position of each move
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                pos[grid[r][c]] = {r, c};
            }
        }

        // Check consecutive knight moves
        for (int i = 1; i < n * n; i++) {
            int r1 = pos[i - 1].first;
            int c1 = pos[i - 1].second;

            int r2 = pos[i].first;
            int c2 = pos[i].second;

            int dr = abs(r2 - r1);
            int dc = abs(c2 - c1);

            if (!((dr == 2 && dc == 1) ||
                  (dr == 1 && dc == 2))) {
                return false;
            }
        }

        return true;
    }
};