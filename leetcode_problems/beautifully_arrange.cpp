class Solution {
public:
    int count = 0;

    int countArrangement(int N) {
        vector<bool> visited(N + 1);

        beautifully_arrange(visited, N, 1);

        return count;
    }

    void beautifully_arrange(vector<bool>& visited,int n, int pos){
        if(pos > n) count++;

        for(int i = 1; i <= n; i++){
            if((i % pos == 0 || pos % i == 0) && !visited[i]) {
                visited[i] = true;
                beautifully_arrange(visited, n, pos + 1);
                visited[i] = false;
            }

        }

    }
};

