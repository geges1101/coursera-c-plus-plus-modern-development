class CombinationIterator {
public:
    vector<string> res;
    int i;
    CombinationIterator(string characters, int combinationlength):i(0) {
        backtrack(characters,combinationlength,0,"");
    }

    void backtrack(const string& c,int n,int idx,string ans){
        for(int i=idx;i<c.size() && ans.size()<n;i++)
            backtrack(c,n,i+1,ans + c[i]);
        if(ans.size()==n) res.push_back(ans);
    }

    string next() {return res[i++];    }
    bool hasNext(){return i<res.size();    }
};

