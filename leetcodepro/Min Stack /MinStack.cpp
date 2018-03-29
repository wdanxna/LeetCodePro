////
////  MinStack.cpp
////  leetcodepro
////
////  Created by drakeDan on 11/10/14.
////  Copyright (c) 2014 bravo. All rights reserved.
////
//
#include "MinStack.h"
//
//class MinStack {
//private:
//    vector<int> min;
//    vector<int> data;
//public:
//    void push(int x) {
//        data.push_back(x);
//        if (min.size() == 0 || data[min.at(min.size()-1)] > x) {
//            min.push_back((int)data.size()-1);
//        }
//    }
//
//    void pop() {
//        if (data.size()) {
//            if (min.size() > 0 && min.at(min.size()-1) == data.size()-1) {
//                min.pop_back();
//            }
//            data.pop_back();
//        }
//    }
//
//    int top() {
//        if (data.size() > 0)
//            return data.at(data.size()-1);
//        return INT_MIN;
//    }
//
//    int getMin() {
//        return data.at(min.at(min.size()-1));
//    }
//};
//
//void minStackTest() {
//    MinStack ms;
//    ms.push(3);
//    ms.push(5);
//    ms.push(2);
//    ms.push(1);
//    ms.pop();
//    cout << ms.getMin() << endl;
//}


//#include <vector>
//class MinStack {
//    std::vector<int> _data;
//    int _min;
//
//    void updateMin() {
//        for (auto i : _data) {
//            if (i < _min) {
//                _min = i;
//            }
//        }
//    }
//public:
//    /** initialize your data structure here. */
//    MinStack() {
//        _min = 2147483647;
//    }
//
//    void push(int x) {
//        _data.push_back(x);
//        updateMin();
//    }
//
//    void pop() {
//        int t = top();
//        _data.pop_back();
//        if (t == _min) {
//            _min = 2147483647;
//            updateMin();
//        }
//    }
//
//    int top() {
//        return _data.at(_data.size()-1);
//    }
//
//    int getMin() {
//        return _min;
//    }
//};


/**
 using insertion sort like data structure
 */
class MinStack {
    int _data[];
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
    }
    
    void pop() {
    }
    
    int top() {
        return 0;
    }
    
    int getMin() {
        return 0;
    }
};

void minStackTest() {
    MinStack ms;
    ms.push(2147483647);
    ms.push(2147483647);
    ms.push(2);
    ms.push(1);
    ms.pop();
    cout << ms.getMin() << endl;
}

