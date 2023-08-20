#include <bits/stdc++.h>

using namespace std;

vector<string> simpleInsertion(vector<string> arr) {
    for (int i = 1; i < arr.size(); i++) {
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
            swap(arr[j - 1], arr[j]);
        }
    }
    return arr;
}

string binSearch(vector<string> arr, string elem) {
    int left = 0, right = arr.size() - 1, mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (arr[mid] == elem) {
            return arr[mid];
        }
        if (arr[mid] > elem) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return "Error";
}

int main() {
    ifstream in("/Users/br_zahar/CLionProjects/MAI/Computer science/kp9/ASCII_OUT.txt");
    vector<string> data;
    for (string str; in >> str;) {
        data.push_back(str);
    }
    ofstream out("/Users/br_zahar/CLionProjects/MAI/Computer science/kp9/ASCII_OUT.txt");
    data = simpleInsertion(data);
    string ans = binSearch(data, "80");
    cout << ans << " " << char(stoi(ans)) << endl;
    for (string s: data) {
        out << s << " " << char(stoi(s)) << endl;
    }
    in.close();
    out.close();
}