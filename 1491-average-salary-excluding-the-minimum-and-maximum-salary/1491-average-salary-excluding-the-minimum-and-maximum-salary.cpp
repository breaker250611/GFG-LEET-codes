class Solution {
public:
    double average(vector<int>& salary) {
        double sum = accumulate(salary.begin(),salary.end(),0);
        sort(salary.begin(),salary.end());
        int n = salary.size();
        cout<<sum;
        double minus = salary[0]+salary[salary.size()-1];
        sum =sum-minus;
        sum /=(n-2);
        return sum;
    }
};