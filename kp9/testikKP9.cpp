#include <bits/stdc++.h>

using namespace std;

int main() {
    ofstream out("/Users/br_zahar/CLionProjects/MAI/Computer science/kp9/ASCII_OUT.txt");
    vector<int> arr;
    for(int i = 65; i < 91; i++){
        arr.push_back(i);
    }
    random_device rd;
    mt19937 gr(rd());
    shuffle(arr.begin(), arr.end(), gr);
    for(int i = 0; i < arr.size(); i++) {
        out << arr[i] << endl;
    }
}
