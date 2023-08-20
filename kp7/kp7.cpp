#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream in("/Users/br_zahar/CLionProjects/MAI/Computer science/kp7/input_kp7.txt");
    vector<vector<pair<float, float>>> data;
    string s;
    int i = 0;
    while (getline(in, s)) {
        vector<pair<float, float>> arr;
        stringstream ss(s);
        for (string str; ss >> str;) {
            if (str == "0") {
                arr.push_back({0, 0});
            } else {
                bool plus = false;
                string first = "", second = "";
                for (char c: str) {
                    if (c == '+' || c == '-') {
                        plus = true;
                        continue;
                    }
                    if (!plus) {
                        first += c;
                    } else {
                        if(c != 'i'){
                            second += c;
                        }
                    }
                }
                arr.push_back({stoi(first), stoi(second)});
            }
        }
        data.push_back(arr);
        i++;
    }
    for(i = 0; i < data.size(); i++){
        for(int j = 0; j < data[i].size(); j++){
            cout << data[i][j].first << "+" << data[i][j].second << "i ";
        }
        cout << endl;
    }
    cout << "Введите вектор строку: ";
    //1+2i 3+4i 5+6i
    getline(cin, s);
    stringstream ss(s);
    vector<pair<float, float>> arr;
    for (string str; ss >> str;) {
        if (str == "0") {
            arr.push_back({0, 0});
        } else {
            bool plus = false;
            string first = "", second = "";
            for (char c: str) {
                if (c == '+' || c == '-') {
                    plus = true;
                    continue;
                }
                if (!plus) {
                    first += c;
                } else {
                    if(c != 'i'){
                        second += c;
                    }
                }
            }
            arr.push_back({stoi(first), stoi(second)});
        }
    }
    for(int j = 0; j < arr.size(); j++){
        cout << arr[j].first << "+" << arr[j].second << "i ";
    }
    cout << endl;
    int n = data[0].size(), ans = 0;
    for(i = 0; i < n; i++){
        bool flag = false;
        for(int j = 0; j < arr.size(); j++){
            if((arr[j].first != 0 || arr[j].second != 0) && (data[j][i].first != 0 || data[j][i].second != 0)){
                flag = true;
            }
        }
        if(flag){
            ans++;
        }
    }
    cout << ans << endl;
}
