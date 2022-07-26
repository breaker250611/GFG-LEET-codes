class ProductOfNumbers {
public:
    vector<unsigned long long> last;
    ProductOfNumbers() {
        last.push_back(1);
    }
    
    void add(int num) {
        
        if (num == 0){
            last.clear(); last.push_back(1);
        }
        else {
            last.push_back(last.back()*num);   
        }
    }
    
    int getProduct(int k) {
        
        int n = last.size();
        while (n-1 < k)
            return 0;
        return last[n-1] / last[n-k-1];
        
        
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */