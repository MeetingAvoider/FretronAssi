#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int totalSum(const vector<int>& apples) {
    int sum = 0;
    for(int weight : apples) {
        sum += weight;
    }
    return sum;
}

void solve(vector<int>& apples, int total,int share, vector<int>& temp) {
    int target = (total / 100) * share;
    vector<int> remainingApples;
    for(int weight : apples) {
        if(target - weight >= 0) {
            target -= weight;
            temp.push_back(weight);
        } else {
            remainingApples.push_back(weight);
        }
    }
    apples = remainingApples;
}

int main() {
    vector<int> apples;  //400 100 400 300 200 300 100 200
    int n;
    cout << "Enter apple weight in gram (-1 to stop): ";
    while(cin >> n && n != -1) {
        apples.push_back(n);
        cout << "Enter apple weight in gram (-1 to stop): ";
    }


    sort(apples.rbegin(), apples.rend());
    vector<int> ram, sham, rahim;
    int total = totalSum(apples);
    solve(apples,total, 50, ram);
    solve(apples,total, 30, sham);
    rahim = apples;
    cout << "Distribution Result:" << endl;
    cout << "Ram: ";
    for(int weight : ram) {
        cout << weight << " ";
    }
    cout << endl;
    cout << "Sham: ";
    for(int weight : sham) {
        cout << weight << " ";
    }
    cout << endl;

    cout << "Rahim: ";
    for(int weight : rahim) {
        cout << weight << " ";
    }
    cout << endl;
    return 0;
}