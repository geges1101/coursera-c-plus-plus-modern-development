class Solution {
public:
    string frequencySort(string s) {
        unordered_map <char,int> map;
        for(char& c : s){
            map[c]++;
        }
        priority_queue <pair<int,char>> max_heap;

        for(auto item : map){
            max_heap.push(make_pair(item.second,item.first));
        }

        string res;

        while(!max_heap.empty()){
            auto item = max_heap.top();

            max_heap.pop();

            while(item.first){
                res.push_back(item.second);
                item.first--;
            }

        }
        return res;
    }
};