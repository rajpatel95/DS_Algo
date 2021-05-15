class Solution {
public:

    int changeDir( int curr_dir, char change ){
        if( change == 'R' ){
            return (curr_dir + 1) % 4;
        }
        else{
           return (curr_dir + 3) % 4;
        }
    }
    
    pair<int,int> changePoints(int curr_dir, pair<int,int> p){
        pair<int,int> ret = p;
        
        if( curr_dir == 0 ){
            ret.second += 1;
        }
        else if( curr_dir == 1){
            ret.first += 1;
        }
        else if( curr_dir == 2 ){
            ret.second -= 1;
        }
        else{
            ret.first -= 1;
        }
        
        return ret;
    }
    
    bool isRobotBounded(string instructions) {
        
        int curr_dir = 0;
        pair<int,int> points;
        points.first = 0, points.second = 0;
        
        for( char x: instructions ){
            if( x == 'L' ||  x == 'R' ){
                curr_dir = changeDir(curr_dir, x);
                
            }
            else{
                points = changePoints(curr_dir, points);
            }
        }
        
        if( curr_dir != 0 || (points.first == 0 && points.second == 0) ){
            return true;
        }
        return false;
    }
};
