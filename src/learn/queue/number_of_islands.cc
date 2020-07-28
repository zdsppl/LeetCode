//Problem: https://leetcode.com/explore/learn/card/queue-stack/231/practical-application-queue/1374/

//solution1: recursive solution, dfs
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        if (0 == grid.size() || 0 == grid[0].size()) {
            //empty grid, do nothing
        } else {
            int m = grid.size();
            int n = grid[0].size();
            vector<vector<bool>> visited(m, vector<bool>(n));
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (('0' == grid[i][j]) || (visited[i][j])) {
                        //do nothing
                    } else {
                        visit(grid, visited, i, j);
                        ++res;
                    }
                }
            }
        }
        return res;
    }
    
private:
    void visit(vector<vector<char>> &grid, vector<vector<bool>> &visited, int x, int y)
    {
        if ((x < 0 || x >= grid.size())
            || (y < 0 || y >= grid[0].size())
            || (visited[x][y])
            || ('0' == grid[x][y])) {
            //do nothing   
        } else {
            visited[x][y] = true;
            visit(grid, visited, x - 1, y);
            visit(grid, visited, x + 1, y);
            visit(grid, visited, x, y - 1);
            visit(grid, visited, x, y + 1);
        }
    }
};

//solution2: bfs
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        if (0 == grid.size() || 0 == grid[0].size()) {
            //empty grid, do nothing
        } else {
            int x_max = grid.size();
            int y_max = grid[0].size();
            vector<vector<bool>> visited(x_max, vector<bool>(y_max));
            queue<int> position_queue;
            int tmp_x = 0;
            int tmp_y = 0;
            int tmp_position = 0;
            int direction_x[] = {-1, 0, 1, 0};
            int direction_y[] = {0, -1, 0, 1};
            for (int x = 0; x < x_max; ++x) {
                for (int y = 0; y < y_max; ++y) {
                    if (visited[x][y] || ('0' == grid[x][y])) {
                        //empty grid, do nothing
                    } else {
                        ++res;
                        position_queue.push(x * y_max + y);
                        visited[x][y] = true;
                        while (!position_queue.empty()) {
                            tmp_position = position_queue.front();
                            position_queue.pop();
                            for (int k = 0; k < 4; ++k) {
                                tmp_x = tmp_position / y_max + direction_x[k];
                                tmp_y = tmp_position % y_max + direction_y[k];
                                if (tmp_x < 0 || tmp_x >= x_max || tmp_y < 0 || tmp_y >= y_max
                                    || visited[tmp_x][tmp_y] || '0' == grid[tmp_x][tmp_y]) {
                                    //do nothing
                                } else {
                                    position_queue.push(tmp_x * y_max + tmp_y);
                                    visited[tmp_x][tmp_y] = true;
                                }
                            }
                        }
                    }
                }
            }
        }
        
        return res;
    }
    
};
