#include <bits/stdc++.h>
// debug print combined macros
#define DEBUG 0
#define print_val(message, val) if(DEBUG) cout << message << val << endl;
#define print_l(a) if(DEBUG) cout << a << endl;
#define print_vec(a) if(DEBUG) for(int i =0; i <a.size();i++)cout << a <<", "; cout << endl;



using namespace std;

vector<string> split_string(string);


// Hackerrank maximum subarray sum Solution
// Runs in O( n log(n-1) )
// ======== SOLUTION =========
long maximumSum(vector<long> a, long m) {
    
    int n = a.size();
    long prefix =0;
    
    long maximum = 0;
    
    set<long> prefixes;

    for(int i = 0; i < n; i++){
        prefix  = (prefix + a[i])%m;
        maximum = max(maximum, prefix);
        
        auto it = prefixes.lower_bound(prefix+1);
        if(it!=prefixes.end()){
            maximum = max(maximum,prefix -(*it)+m);
        }
        prefixes.insert(prefix);
    }
    
    return ( maximum );
}

// ======== I/O handling =========
int main()
{
    int i, q;
    long n, m;

    cin >> q;
    
    while(q>0){
        cin >> n;
        cin >> m;
        
        vector<long> a(n);
        
        for( i = 0; i< n; i++)
            cin >> a[i];
        
        cout << maximumSum(a, m) <<endl;
        
        q--;
    }
    
}
