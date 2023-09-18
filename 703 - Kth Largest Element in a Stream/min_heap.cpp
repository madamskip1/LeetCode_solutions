class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : k{ k }
    {
        for (const auto& num : nums)
        {
            heap.push(num);
            if (heap.size() > k)
            {
                heap.pop();
            }
        }
    }

    int add(int val) {
        heap.push(val);
        if (heap.size() > k)
        {
            heap.pop();
        }

        return heap.top();
    }
private:
    int k;
    std::priority_queue<int, std::vector<int>, std::greater<int>> heap;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */