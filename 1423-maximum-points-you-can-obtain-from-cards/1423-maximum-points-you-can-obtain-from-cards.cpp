class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = accumulate(cardPoints.begin(),cardPoints.end(),0);
        int lo = 0;
         k = cardPoints.size()-k;
        int add = 0;
        for(lo=0;lo<k;lo++){
            add +=cardPoints[lo];
        }
        int res = 0;
        res = max(res , sum-add);
        int slow = 0;
        for(lo;lo<cardPoints.size();lo++){
            add = add + cardPoints[lo] - cardPoints[slow++];
            res = max(res,sum-add);
        }
        return res;
    }
};