class Solution {
public:
    
   
    void dfs(vector<vector<int>>& adj_list, int x, vector<bool>& visited){
        
        visited[x] = true;
        
        for(int i = 0 ; i < adj_list[x].size(); i++ ){
            if( !visited[adj_list[x][i]]){
                dfs(adj_list, adj_list[x][i], visited);
            }
            
        }
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;
        vector<bool> visited(n, false);
        vector<vector<int>> adj_list;
        
        for(int i = 0 ; i < n ; i++ ){
            vector<int> temp;
            adj_list.push_back(temp);
        }
        
        for(int i = 0 ; i < edges.size(); i++ ){
            int a = edges[i][0];
            int b = edges[i][1];
            adj_list[a].push_back(b);
            adj_list[b].push_back(a);
        }
        
        for(int i = 0 ; i < adj_list.size(); i++ ){
            if( !visited[i] ){
                dfs(adj_list, i, visited);
                ans++;
            }
        }
        
        return ans;
        
    }
};
