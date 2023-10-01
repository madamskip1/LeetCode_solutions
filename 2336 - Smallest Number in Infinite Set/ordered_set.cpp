class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {

    }

    int popSmallest() {
        if (addedNums.empty())
        {
            return cur++;
        }
        else
        {
            auto ans = *addedNums.begin();
            addedNums.erase(addedNums.begin());
            return ans;
        }
    }

    void addBack(int num) {
        if (num < cur)
        {
            addedNums.insert(num);
        }
    }

private:
    std::set<int> addedNums;
    int cur{ 1 };
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */