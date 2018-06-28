#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the minimumSwaps function below.
// Hackerrank Arrays: Minimum Swaps 2 Solution
// Solution runs in O(n)

// ======== SOLUTION =========

int minimumSwaps(vector<int> arr) {
    int n = arr.size();
    int visited[n]={0};

    int swaps=0;

    int init_index;
    int elements_in_path;
    int next_index;

    for(int i=0; i<n;i++){
        if(!visited[i]){
            init_index=i;

            visited[init_index]=1;
            elements_in_path=1;
            next_index=arr[init_index]-1;

            while(next_index != init_index){
                visited[next_index]=1;
                elements_in_path++;
                next_index=arr[next_index]-1;
            }

            swaps+=(elements_in_path-1);
        }
    }


    return swaps;
}

// ======== HACKERRANK JUNK =========
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int res = minimumSwaps(arr);

    fout << res << "\n";

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
