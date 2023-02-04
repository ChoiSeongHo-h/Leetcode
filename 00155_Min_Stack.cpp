"""
https://leetcode.com/problems/min-stack/
-> Accepted (Medium)
"""
  
class MinStack 
{
public:
    vector<array<int, 2>> data;
  
    MinStack() 
    {
        data.emplace_back(array<int, 2>{INT_MAX, INT_MAX});
    }
    
    void push(int val) 
    {
        int before = data.back()[1];
        data.emplace_back(array<int, 2>{val, min(val, before)});
    }
    
    void pop() 
    {
        data.pop_back();
    }
    
    int top() 
    {
        return data.back()[0];
    }
    
    int getMin() 
    {
        return data.back()[1];
    }
};
