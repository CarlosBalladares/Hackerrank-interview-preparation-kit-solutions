#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;

// Complete the hourglassSum function below.
// Hackerrank 2d Array Solution
// ======== Solution =========
int hourglassSum(vector<vector<int>> arr) {
    int sum=-1;

    int temp_sum1;
    int temp_sum2;
    int temp_sum3;
    int t_sum;

    for (int i=0;i<=3; i++){
        for(int j=0; j<=3;j++){
            temp_sum1 = arr[i][j]+arr[i][j+1]+arr[i][j+2];
            temp_sum2 = arr[i+1][j+1];
            temp_sum3 = arr[i+2][j]+arr[i+2][j+1]+arr[i+2][j+2];
            t_sum =temp_sum1+temp_sum2+temp_sum3;
            if(i==0 && j==0 || t_sum >sum)
                sum = t_sum;
        }
    }
    return sum;
}
// ======== HACKERRANK JUNK =========
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
