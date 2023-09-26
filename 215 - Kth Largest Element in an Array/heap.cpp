class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        auto heap = std::priority_queue<int, std::vector<int>, std::greater<int>>{};
        for (const auto& num : nums)
        {
            heap.push(num);
            if (heap.size() > k)
            {
                heap.pop();
            }
        }
        return heap.top();
    }
};