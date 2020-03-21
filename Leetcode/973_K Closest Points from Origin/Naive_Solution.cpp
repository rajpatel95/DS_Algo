class Solution {
public:
    
    
    //Very Naive approach
    // Solve using Heap / Divide and Conquer
    
    double findDist(int x, int y){
        double sum = x * x + y * y;
        return sqrt(sum);
    }
    
     struct point{
        int x_cor,y_cor;
        double dist;
        
    };
    
    
    
    vector<point> cor_points;
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> ans;
        
        for( int i = 0 ; i < points.size() ; i++ ){
            point temp;
            temp.x_cor = points[i][0];
            temp.y_cor = points[i][1];
            temp.dist = findDist(points[i][0], points[i][1]);
            cor_points.push_back(temp);
        } 
        
        sort(cor_points.begin(), cor_points.end(), 
             []( const point &left, const point &right )
                 { return ( left.dist < right.dist ); } );
        
        for( int i = 0 ; i < K ; i++ ){
            vector<int> temp;
            temp.push_back(cor_points[i].x_cor);
            temp.push_back(cor_points[i].y_cor);
            ans.push_back(temp);
        }
        
        return ans;
    }
};
