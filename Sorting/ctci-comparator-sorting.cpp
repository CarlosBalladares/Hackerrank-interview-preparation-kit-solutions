// Hackerrank Sorting: comparator Solution
// Runs in O(n) where n is the length of string a
// ======== SOLUTION =========
class Checker{
public:
  	// complete this method
    static int comparator(Player a, Player b)  {
        int a_len = a.name.size();
        int b_len = b.name.size();
        const char* a_chars = a.name.c_str();
        const char* b_chars = b.name.c_str();
        
        if(a.score ==  b.score){
            for(int i = 0; i < a_len; i++){
                if(i < b_len){
                    if(a_chars[i]-'a' != b_chars[i]-'a'){
                        return (a_chars[i]-'a' > b_chars[i]-'a')? -1:1;
                    }
                }else{
                    return ( -1 );
                }
            }
            return 0;
        } 
        
        return (a.score<b.score)?-1:1;
    }
};