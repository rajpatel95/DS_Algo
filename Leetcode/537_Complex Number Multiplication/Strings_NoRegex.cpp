class Solution {
public:
	
	vector<int> getNumbers(string a){
		vector<int> ret;
		vector<int> temp;
		bool flag = true;
		int cnt = 0, i = 0;
        
        if(a[i] == '-'){
            i++;
            flag = false;
        }
		
		while(1){
			if(a[i] == '+'){
				break;
			}
			temp.push_back(a[i++] - '0');
		}
		
		int num = 0, size = temp.size() - 1;
		for(int j = 0; j < temp.size(); j++){
			num += temp[j] * pow(10,size - j);
		}
		
		if(flag){
			ret.push_back(num);
		}
		else{
			ret.push_back(-num);
		}
		
        i++;
		if(a[i] == '-'){
			flag = false;
			i++;
		}
		else{
			flag = true;
		}
		
		temp.clear();
		while(1){
			if(a[i] == 'i'){
				break;
			}
			temp.push_back(a[i++] - '0');
		}
		size = temp.size() - 1;
		num = 0;
		for(int j = 0; j < temp.size(); j++){
            
			num += temp[j] * pow(10,size - j);
		}
		if(flag){
			ret.push_back(num);
		}
		else{
			ret.push_back(-num);
		}
		
		return ret;
	}
	
	string IntToComplexString(int a, int b){
		vector<int> temp;
		int i = 0;
		string s = "";
        
        if( a < 0 ){
            s += '-';
        }
        
        if( a == 0){
            temp.push_back(0);
        }
		
		while(a != 0){
			temp.push_back( a % 10);
			a /= 10;
		}
        
		for( int j = temp.size() - 1; j >= 0; j--){
            s += to_string(abs(temp[j]));
		}
		
        s += '+';
        
		temp.clear();
        
        if(b < 0 ){
            s += '-';
        }
        
        if( b == 0 ){
            temp.push_back(0);
        }
        
		while(b != 0){
			temp.push_back(b % 10);
			b /= 10;
		}
		
		for( int j = temp.size() - 1; j >= 0; j--){
			s += to_string(abs(temp[j]));
		}
        
        s += 'i';
		
		return s;
		
		
	}

    string complexNumberMultiply(string a, string b) {
        string ans;
        vector<int> c1 = getNumbers(a);
		int r1 = c1[0],  i1 = c1[1];
        //cout<<r1<<": "<<i1<<endl;
        
		
		vector<int> c2 = getNumbers(b);
		int r2 = c2[0],  i2 = c2[1];
        //cout<<r2<<": "<<i2<<endl;
        
		
		int r ,i;
		
		r = r1*r2 - i1*i2;
		i = r1*i2 + r2*i1;
        //cout<<r<<":"<<i<<endl;
		
		ans = IntToComplexString(r,i);
		
		return ans;
		
    }
};
