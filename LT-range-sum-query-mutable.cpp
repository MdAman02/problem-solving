class NumArray {
public:
    vector<int> bit;
    vector<int> num;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        bit.resize(n+2, 0);
        num.resize(n+2, 0);
        
        for (int i=0; i<n; i++)
            update(i, nums[i]);
    }
    
    void update(int index, int val) {
        index++;
        int diff = val - num[index];
        num[index] = val;
        while(index <= n+1) {
            bit[index] += diff;
            index += index & (-index);
        }
    }
    
    int sum(int n) {
        int r = 0;
        while(n > 0) {
            r += bit[n];
            n -= n & (-n);
        }
        return r;
    }
    
    int sumRange(int left, int right) {
        int ltCumSum = sum(left);
        int rtCumSum = sum(right+1);
        return rtCumSum - ltCumSum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */