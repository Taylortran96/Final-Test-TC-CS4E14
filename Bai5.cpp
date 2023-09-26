// https://leetcode.com/problems/rotting-oranges/description/

#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        int total_oranges = 0;
        queue<pair<int, int>> rotten_oranges;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    total_oranges++;
                }
                else if (grid[i][j] == 2)
                {
                    rotten_oranges.push(make_pair(i, j));
                }
            }
        }

        int minutes = 0;
        int rotten_oranges_count = rotten_oranges.size();
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        while (!rotten_oranges.empty())
        {
            pair<int, int> rotten_orange = rotten_oranges.front();
            rotten_oranges.pop();
            rotten_oranges_count--;

            for (int i = 0; i < 4; i++)
            {
                int x = rotten_orange.first + dx[i];
                int y = rotten_orange.second + dy[i];

                if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != 1)
                {
                    continue;
                }

                grid[x][y] = 2;
                total_oranges--;
                rotten_oranges.push(make_pair(x, y));
            }

            if (rotten_oranges_count == 0)
            {
                minutes++;
                rotten_oranges_count = rotten_oranges.size();
            }
        }

        return total_oranges == 0 ? minutes - 1 : -1;
    }
};