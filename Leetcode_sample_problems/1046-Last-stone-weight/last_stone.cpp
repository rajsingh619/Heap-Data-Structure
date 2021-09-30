class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap;
        for(int i=0;i<stones.size();i++){
            heap.push(stones[i]);
        }
        int s1,s2;
        
        while(heap.size()>1){
            s1=heap.top();
            heap.pop();
            s2=heap.top();
            heap.pop();
            if(s1-s2>0){
                heap.push(s1-s2);
            }
        }
        
        if(!heap.empty()){
            return heap.top();
        }
        else return 0;
    }
};