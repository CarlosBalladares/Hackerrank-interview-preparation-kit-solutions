#include <bits/stdc++.h>
// debug print combined macros
#define DEBUG 0
#define print_val(message, val) if(DEBUG) cout << message << val << endl;
#define print_l(a) if(DEBUG) cout << a << endl;
#define print_vec(a) if(DEBUG) for(int i =0; i <a.size();i++)cout << a <<", "; cout << endl;



using namespace std;

vector<string> split_string(string);


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

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        int n = stoi(nm[0]);

        long m = stol(nm[1]);

        string a_temp_temp;
        getline(cin, a_temp_temp);

        vector<string> a_temp = split_string(a_temp_temp);

        vector<long> a(n);

        for (int i = 0; i < n; i++) {
            long a_item = stol(a_temp[i]);

            a[i] = a_item;
        }

        long result = maximumSum(a, m);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
