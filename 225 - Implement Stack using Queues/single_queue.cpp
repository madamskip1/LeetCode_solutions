class MyStack {
public:
    MyStack() {

    }

    void push(int x) {
        queue.push(x);
        for (std::size_t i = 0; i < queue.size() - 1; ++i)
        {
            auto temp = top();
            queue.push(temp);
            queue.pop();
        }
    }

    int pop() {
        auto temp = top();
        queue.pop();
        return temp;
    }

    int top() {
        return queue.front();
    }

    bool empty() {
        return queue.empty();
    }

private:
    std::queue<int> queue;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */