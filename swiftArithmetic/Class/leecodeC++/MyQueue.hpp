//
//  MyQueue.hpp
//  C++
//
//  Created by 张帅 on 2023/5/11.
//

#ifndef MyQueue_hpp
#define MyQueue_hpp

#include <stdio.h>
#include <stack>
#include <queue>
using namespace std;
class MyQueue {
    
public:
    stack<int> stIn;
    stack<int> stOut;
    
    MyQueue() {
        
    }
    void push(int x) {
        stIn.push(x);
    }
    
    int pop() {
        if (stOut.empty()) {
            while (!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
            
        }
        int result = stOut.top();
        stOut.pop();
        return result;
    }
    
    int peek() {
        int res = this->pop();
        stOut.push(res);
        return res;
    }
    bool empty() {
        return stIn.empty() && stOut.empty();
    }
};


using namespace std;
class MyStack {
public:
    queue<int> que1;
    queue<int> que2;
    MyStack() {
        
    }
    void push(int x) {
        que1.emplace(x);
    }
    int pop() {
        long size = que1.size();
        size--;
        while (size--) {
            que2.push(que1.front());
            que1.pop();
        }
        int result = que1.front();
        que1.pop();
        que1 = que2;
        return result;
        
    }
    int top() {
        return que1.back();
    }
};


class MyStack1 {
public:
    queue<int> que;
    MyStack1() {
        
    }
    void push(int x) {
        que.push(x);
    }
    
    int pop() {
        long size = que.size();
        size--;
        while (size--) {
            que.push(que.front());
            que.pop();
        }
        int result = que.front();
        que.pop();
        return result;
        
    }
    int top() {
        return que.back();
    }
    bool empty() {
        return que.empty();
    }
};

#endif /* MyQueue_hpp */
