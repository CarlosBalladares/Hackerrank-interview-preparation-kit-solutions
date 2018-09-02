// Hackerrank Sorting: comparator Solution
// Runs in O(c) 
// ======== SOLUTION =========
class Checker{
public:
    static int comparator(Player a, Player b){
        if(a.score == b.score)
            if (a.name == b.name)
                return 0;
            else
                return  ( a.name > b.name )? -1:1;
         
        return (a.score<b.score)?-1:1;
    }
};