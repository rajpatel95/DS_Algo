class Solution {
public:
    
    vector<vector<int>> ans;
    
    void dfs(vector<vector<int>>& graph, int n, vector<int> temp, vector<bool>& visited){
        if( n == graph.size() - 1){
            temp.push_back(n);
            ans.push_back(temp);
            return;
        }
        visited[n] = true;
        temp.push_back(n);
        
        for(int i = 0 ; i < graph[n].size(); i++ ){
            if( !visited[graph[n][i]] ){
                dfs(graph, graph[n][i], temp, visited);
            }
            
        }
        visited[n] = false;
        
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<bool> visited(graph.size(), false);
        vector<int> temp;
        dfs(graph, 0, temp, visited);
        
        return ans;
        
    }
};
