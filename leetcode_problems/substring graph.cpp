#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void ParseWord(unordered_map <string,int>& combos, const string& line){
    for(int i = 0; i != line.size() - 2; i++){
        string word = "";
        string couple;

        for(int x = 0; x != 2; x++){
            for(int j = i; j != i + 3; j++){
                word += line[j];
            }
            couple += " ";
            couple += word;
        }


        if(combos.count(couple)) combos[couple]++;
        else combos[couple] = 1;

    }
}

int main(){
    int n;
    cin >> n;

    string line;
    unordered_map <string ,int> combos;

    while(n){
        cin >> line;
        ParseWord(combos, line);
        n--;
    }

    for(auto i : combos){
        cout << i.first << " " << i.second << endl;
    }
}
