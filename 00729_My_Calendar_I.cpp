"""
https://leetcode.com/problems/my-calendar-i/
-> Accepted (Medium)
"""

class MyCalendar 
{
public:
    map<int, int> se_map;
    MyCalendar() 
    {
    }
    
    bool book(int start, int end) 
    {
        if(se_map.find(start) != se_map.end())
            return false;
        
        se_map.emplace(start, end);
        auto it = se_map.find(start);
        if(it != se_map.begin())
        {
            auto before = prev(it);
            if(before->second > start)
            {
                se_map.erase(it);
                return false;
            }
        }
        if(it != prev(se_map.end()))
        {
            auto after = next(it);
            if(end > after->first)
            {
                se_map.erase(it);
                return false;
            }
        }

        return true;
    }
};
