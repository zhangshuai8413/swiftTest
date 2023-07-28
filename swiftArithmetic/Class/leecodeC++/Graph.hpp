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

#endif /* Graph_hpp */
