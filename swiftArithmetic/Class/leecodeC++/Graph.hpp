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
#endif /* Graph_hpp */
