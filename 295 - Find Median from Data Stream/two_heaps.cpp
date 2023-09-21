class MedianFinder {
public:
    MedianFinder() {

    }

    void addNum(int num) {
        if (minHeap.empty())
        {
            minHeap.push(num);
            return;
        }

        if (minHeap.top() > num)
        {
            maxHeap.push(num);
            if (maxHeap.size() > (minHeap.size() + 1))
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        }
        else
        {
            minHeap.push(num);
            if (minHeap.size() > (maxHeap.size() + 1))
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
    }

    double findMedian() {
        if (minHeap.size() == maxHeap.size())
        {
            return static_cast<double>(minHeap.top() + maxHeap.top()) / 2.0;
        }
        else if (minHeap.size() > maxHeap.size())
        {
            return static_cast<double>(minHeap.top());
        }
        else
        {
            return static_cast<double>(maxHeap.top());
        }
    }

    std::priority_queue<int> maxHeap;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */