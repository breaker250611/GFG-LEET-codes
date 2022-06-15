class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {     
        int left = 1, right = *max_element(piles.begin(), piles.end());

        while (left <= right) {
            int middle = (left + right) / 2;
            long long int hourSpent = 0;

            for (int pile : piles) {
                hourSpent += pile / middle + (pile % middle != 0);
            }

            if (hourSpent <= h) {
                right = middle-1;
            } else {
                left = middle + 1;
            }
        }

        return left;
    }
};
