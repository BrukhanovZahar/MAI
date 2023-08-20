#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream idFile("/Users/br_zahar/CLionProjects/MAI/Computer science/kp6/ID.txt");
    ifstream idCompFile("/Users/br_zahar/CLionProjects/MAI/Computer science/kp6/ID_comp.txt");
    ifstream countPCFile("/Users/br_zahar/CLionProjects/MAI/Computer science/kp6/count_pc.txt");
    ifstream numberProcessorFile("/Users/br_zahar/CLionProjects/MAI/Computer science/kp6/number_of_processors.txt");
    ifstream RAMFile("/Users/br_zahar/CLionProjects/MAI/Computer science/kp6/random_access_memory.txt");
    ifstream videoRAMFile("/Users/br_zahar/CLionProjects/MAI/Computer science/kp6/video_memory_capacity.txt");
    ifstream diskFile("/Users/br_zahar/CLionProjects/MAI/Computer science/kp6/drive_type.txt");
    map<string, int> id;
    map<string, int> idComp;
    map<string, int> countPC;
    map<string, int[100]> ans;
    string s = "", key = "";
    int c = 0, i = 0;
    for (string str; idFile >> str;) {
        if (c % 2 == 0) {
            s = str;
        } else {
            id[s] = stoi(str);
        }
        c++;
    }
    c = 0, i = 0;
    for (string str; idCompFile >> str;) {
        if (c % 2 == 0) {
            s = str;
        } else {
            idComp[s] = stoi(str);
        }
        c++;
    }
    c = 0, i = 0;
    for (string str; countPCFile >> str;) {
        if (c % 2 == 0) {
            s = str;
        } else {
            countPC[s] = stoi(str);
        }
        c++;
    }
    while (getline(numberProcessorFile, s)){
        int i = 0;
        stringstream ss(s);
        string key, str;
        ss >> key;
        if(countPC[key] > 1){
            int i = countPC[key];
            for(int j = 0; j < i; j++){
                ss >> str;
                int x = ans[key][j];
                ans[key][j] = x + stoi(str) * 100;
            }
        }
    }
    while (getline(RAMFile, s)){
        int i = 0;
        stringstream ss(s);
        string key, str;
        ss >> key;
        if(countPC[key] > 1){
            int i = countPC[key];
            for(int j = 0; j < i; j++){
                ss >> str;
                int x = ans[key][j];
                ans[key][j] = x + stoi(str) * 50;
            }
        }
    }
    while (getline(videoRAMFile, s)){
        int i = 0;
        stringstream ss(s);
        string key, str;
        ss >> key;
        if(countPC[key] > 1){
            int i = countPC[key];
            for(int j = 0; j < i; j++){
                ss >> str;
                int x = ans[key][j];
                ans[key][j] = x + stoi(str) * 50;
            }
        }
    }
    while (getline(diskFile, s)){
        int i = 0;
        stringstream ss(s);
        string key, str;
        ss >> key;
        if(countPC[key] > 1){
            int i = countPC[key];
            for(int j = 0; j < i; j++){
                ss >> str;
                int x = ans[key][j];
                ans[key][j] = x + stoi(str);
            }
        }
    }
    for(auto elem : ans){
        for(int x : elem.second){
            if(x != 0) {
                cout << elem.first << " " << x << endl;
            }
        }
    }

    for(auto elem : ans){
        int num = 0, bal = 0, i = 1;
        for(int x : elem.second){
            if(x != 0) {
                if(x > bal){
                    bal = x;
                    num = i;
                }
            }
            i++;
        }
        for(auto comp : idComp){
            if(stoi(elem.first) == comp.second){
                for(auto ident : id){
                    if(ident.second == stoi(comp.first)){
                        cout << ident.first << " " << num << " " << bal << endl;
                        break;
                    }
                }
            }
        }
    }
}