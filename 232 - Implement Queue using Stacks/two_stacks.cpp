class MyQueue {
public:
    MyQueue() {

    }

    void push(int x) {
        inStack.push(x);
    }

    int pop() {
        if (outStack.empty())
        {
            rearrangeStacks();
        }

        auto returnValue = outStack.top();
        outStack.pop();
        return returnValue;
    }

    int peek() {
        if (outStack.empty())
        {
            rearrangeStacks();
        }
        return outStack.top();
    }

    bool empty() {
        return inStack.empty() && outStack.empty();
    }

private:
    std::stack<int> inStack;
    std::stack<int> outStack;

    void rearrangeStacks()
    {
        while (!inStack.empty())
        {
            auto temp = inStack.top();
            inStack.pop();
            outStack.push(temp);
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */