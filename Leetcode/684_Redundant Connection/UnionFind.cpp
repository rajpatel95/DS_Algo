class Solution {
public:
    
    int parent[1005];
    int size;
    
    int find_parent(int n){
        
        if( parent[n] != n){
            parent[n] = find_parent(parent[n]);
        }
        return parent[n];
    }
    
    bool check_if_same(int x, int y){
        int x1 = find_parent(x);
        int y1 = find_parent(y);
        
        if( x1 == y1 ){
            return true;
        }
        return false;
    }
    
    void make_parent(int x, int y){
        int x1 = find_parent(x);
        int y1 = find_parent(y);
        
        parent[y1] = x1;
        
        for( int i = 1 ; i <= size; i++ ){
            parent[i] = parent[parent[i]];
        }
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        
        for( int i = 1 ; i <= edges.size(); i++ ){
            parent[i] = i;
        }
        size = edges.size();
        
        vector<vector<int>> temp;
        
        for( int i = 0 ; i < edges.size(); i++ ){
            if(check_if_same(edges[i][0],edges[i][1])){
                temp.push_back(edges[i]);
            }
            else{
                make_parent(edges[i][0],edges[i][1]);
            }
        }
        
        return temp[temp.size()-1];
    }
};
