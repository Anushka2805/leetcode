class Solution {
public:
    // using maxheap + greedy
    //tc = O(n)
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        priority_queue<int> pq;
        for (char& ch : tasks) {
            freq[ch - 'A']++;
        }
        int time = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                pq.push(freq[i]);
            }
        }
        while(!pq.empty()){
            vector<int> temp;
            for(int i = 1;i<=n+1;i++){
                if(!pq.empty()){
                    int curr = pq.top();
                    pq.pop();
                    curr--;
                    temp.push_back(curr);
                }
            }
            for(int &it : temp){
                if(it>0){
                    pq.push(it);
                }
            }
            if(pq.empty()){
                time += temp.size();
            }else{
                //considering idle tasks
                time += n+1;
            }
        }
        return time;
    }
};