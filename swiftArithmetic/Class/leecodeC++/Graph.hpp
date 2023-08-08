//
//  Graph.hpp
//  swiftArithmetic
//
//  Created by admin on 2023/7/28.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
#include "CPlusHeader.h"

class AllPath {
    
    /*
     
     797. 所有可能的路径
     给你一个有 n 个节点的 有向无环图（DAG），请你找出所有从节点 0 到节点 n-1 的路径并输出（不要求按特定顺序）

      graph[i] 是一个从节点 i 可以访问的所有节点的列表（即从节点 i 到节点 graph[i][j]存在一条有向边）。

     输入：graph = [[1,2],[3],[3],[]]
     输出：[[0,1,3],[0,2,3]]
     解释：有两条路径 0 -> 1 -> 3 和 0 -> 2 -> 3

     来源：力扣（LeetCode）
     链接：https://leetcode.cn/problems/all-paths-from-source-to-target
     著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
     */
public:
    vector<vector<int>>result;
    vector<int>path;
    void dfs (vector<vector<int>>& graph, int x) {
        if (x == graph.size() -1) {
            result.push_back(path);
            return;
        }
        for (int i = 0; i <graph[x].size(); i ++) {
            path.push_back(graph[x][i]);
            dfs(graph, graph[x][i]);
            path.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        path.push_back(0);
        dfs(graph, 0);
        return result;
    }
};


class NumIslands {
    
    /*
     给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
     
     岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
     
     此外，你可以假设该网格的四条边均被水包围。
     
     示例 1：
     
     输入：grid = [
     ["1","1","1","1","0"],
     ["1","1","0","1","0"],
     ["1","1","0","0","0"],
     ["0","0","0","0","0"]
     ]
     输出：1
     示例 2：
     
     输入：grid = [
     ["1","1","0","0","0"],
     ["1","1","0","0","0"],
     ["0","0","1","0","0"],
     ["0","0","0","1","1"]
     ]
     输出：3
     
     来源：力扣（LeetCode）
     链接：https://leetcode.cn/problems/number-of-islands
     著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
     */
public:
    
    int dir[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
    
    void dsf(vector<vector<char>> grid,vector<vector<bool>>& visited, int x, int y){
        for (int i = 0; i < 4; i ++) {
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            if (nextx < 0 || nextx>= grid.size() || nexty < 0 || nexty >= grid[0].size() ) {
                continue;
            }
            if (!visited[nextx][nexty] && grid[nextx][nexty] == '1') {
                visited[nextx][nextx] = true;
                dsf(grid, visited, nextx, nexty);
            }
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>>visited(grid.size(), vector<bool>(grid[0].size(),false));
        int result = 0;
        for (int i = 0; i < grid.size(); i ++) {
            for (int j = 0; j < grid[0].size(); j ++) {
                if(!visited[i][j] && grid[i][j] == '1') {
                    visited[i][j] = true;
                    result++;
                    dsf(grid, visited, i, j);
                }
            }
        }
        return result;
    }
};

class NumIslandsBSF {
    
    
public:
    
    int dir[4][2] = {0,1, 1, 0, -1,0, 0, -1};
    
    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
        queue<pair<int, int>>que;
        que.push({x, y});
        visited[x][y] = true;
        while (!que.empty()) {
            pair<int, int>cur = que.front(); que.pop();
            int curX = cur.first;
            int curY = cur.second;
            for (int i = 0; i <4; i ++) {
                int nextX = curX + dir[i][0];
                int nextY = curY + dir[i][1];
                if (nextX < 0 || nextX >= grid.size() ||  nextY < 0 ||  nextY >= grid[0].size()) {
                    continue;
                }
                if (!visited[nextX][nextY] && grid[nextX][nextY] == '1') {
                    que.push({nextX, nextY});
                    visited[nextX][nextY] = true;
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        int n = (int)grid.size();
        int m = (int)grid[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j <m; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    result += 1;
                    bfs(grid, visited, i, j);
                }
            }
        }
        
        return result;
    }
};


class Arealands {
    
public:
    
    int count = 0;
    int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1}; // 四个方向
    
    void dfs(vector<vector<int>> & grid,vector<vector<bool>>& visited, int x, int y) {
        for (int i = 0; i < 4; i ++) {
            int nextX = x + dir[i][0];
            int nextY = y + dir[i][1];
            if (nextX < 0 || nextX >= grid.size() || nextY < 0 || nextY >= grid[0].size()) {
                continue;
            }
            if (!visited[nextX][nextY] && grid[nextX][nextY] == 1) {
                visited[nextX][nextY] = true;
                count += 1;
                dfs(grid, visited, nextX, nextY);
            }
            
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int n = (int)grid.size();
        int m = (int)grid[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m, false));
        int result = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    count = 1;
                    visited[i][j] = true;
                    dfs(grid,visited, i, j);
                    result = max(result, count);
                }
                
            }
            
        }
        return result;
    }
    
};


class MumEnclaves {
    /*
     
     1020. 飞地的数量
     给你一个大小为 m x n 的二进制矩阵 grid ，其中 0 表示一个海洋单元格、1 表示一个陆地单元格。

     一次 移动 是指从一个陆地单元格走到另一个相邻（上、下、左、右）的陆地单元格或跨过 grid 的边界。

     返回网格中 无法 在任意次数的移动中离开网格边界的陆地单元格的数量。
     */
    
public:
    int count;
    int dir[4][2] =  {-1,0, 0, -1, 1,0, 0, 1};
    
    void dfs(vector<vector<int>>& grid, int x, int y) {
        grid[x][y] = 0;
        count ++;
        for (int i = 0; i <4; i ++) {
            int nextX = x + dir[i][0];
            int nextY = y + dir[i][1];
            if (nextX < 0 ||  nextX >= grid.size() ||  nextY < 0 ||  nextY >= grid[0].size()) {
                continue;
            }
            if (grid[nextX][nextY] == 0) continue;
            
            dfs(grid, nextX, nextY);
                
        }
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int n = (int)grid.size(), m = (int)grid[0].size();
        for (int i = 0; i <n; i ++) {
            if (grid[i][0] == 1) dfs(grid, i, 0);
            if (grid[i][ m - 1] == 1) {
                dfs(grid, i, m -1);
            }
        }
        
        for (int j = 0; j <grid[0].size(); j ++) {
            if (grid[0][j] == 1) dfs(grid, 0, j);
            if(grid[n -1][j] == 1) dfs(grid, n -1, j);
        }
        count = 0;
        for (int i = 0; i <n; i ++) {
            for (int j = 0; j <m; j ++) {
                if(grid[i][j] == 1) dfs(grid, i, j);
            }
        }
        return count;
        
    }
    
};

class Solve {
    /*
     参与本项目，贡献其他语言版本的代码，拥抱开源，让更多学习算法的小伙伴们收益！

     130. 被围绕的区域
     题目链接

     给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' ，找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。



     输入：board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
     输出：[["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
     解释：被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。

     */
    
public:
    int dir[4][2] = {-1, 0, 0, -1, 1, 0, 0, 1}; // 保存四个方向
    void dfs(vector<vector<char>>& board, int x, int y) {
        board[x][y] = 'A';
        for (int i = 0; i < 4; i++) { // 向四个方向遍历
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            // 超过边界
            if (nextx < 0 || nextx >= board.size() || nexty < 0 || nexty >= board[0].size()) continue;
            // 不符合条件，不继续遍历
            if (board[nextx][nexty] == 'X' || board[nextx][nexty] == 'A') continue;
            dfs (board, nextx, nexty);
        }
    }
    
    void solve(vector<vector<char>>& board) {
          int n = board.size(), m = board[0].size();
          // 步骤一：
          // 从左侧边，和右侧边 向中间遍历
          for (int i = 0; i < n; i++) {
              if (board[i][0] == 'O') dfs(board, i, 0);
              if (board[i][m - 1] == 'O') dfs(board, i, m - 1);
          }

          // 从上边和下边 向中间遍历
          for (int j = 0; j < m; j++) {
              if (board[0][j] == 'O') dfs(board, 0, j);
              if (board[n - 1][j] == 'O') dfs(board, n - 1, j);
          }
          // 步骤二：
          for (int i = 0; i < n; i++) {
              for (int j = 0; j < m; j++) {
                  if (board[i][j] == 'O') board[i][j] = 'X';
                  if (board[i][j] == 'A') board[i][j] = 'O';
              }
          }
      }

};
#endif /* Graph_hpp */
