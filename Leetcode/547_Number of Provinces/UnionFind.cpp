class Solution {
public:
    
    int parent[205];
    int size;
    
    int find_parent(int n){
        
        while( parent[n] != n ){
            parent[n] = parent[parent[n]];
            n = parent[n];
        }
        return n;
    }
    
    void make_parent(int x, int y){
        int x1 = find_parent(x);
        int y1 = find_parent(y);
        
        if( x1 != y1){
            parent[y1] = x1;
        }
        for( int i = 0 ; i < size; i++ ){
            parent[i] = parent[parent[i]];
        }
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        size = M.size();
        for( int i = 0 ; i < M.size(); i++ ){
            parent[i] = i;
        }
        vector<vector<int>> visited;
        for( int i = 0 ; i < M.size(); i++ ){
            vector<int> temp(M.size(), false);
            visited.push_back(temp);
        }
        
        set<int> s;
        
        for( int i = 0 ; i < M.size(); i++ ){
            for( int j = 0 ; j < M.size(); j++ ){
                if( i != j && !visited[j][i] && M[i][j] == 1 ){
                    make_parent(i,j);
                    visited[j][i] = true;
                }
            }
        }
        
        for( int i = 0 ; i < M.size(); i++ ){
           // cout<<parent[i]<<endl;
            s.insert(parent[i]);
        }
        return s.size();
    }
};
