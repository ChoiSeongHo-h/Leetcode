/*
https://leetcode.com/problems/sliding-window-maximum/
-> Accepted (Hard)
*/

// seg tree
class Solution 
{
public:
    void make_seg_tree(vector<int> &seg_tree, vector<int> &from, vector<int> &to, int idx)
    {
        if(2*idx >= seg_tree.size()/2)
        {
            seg_tree[idx] = max(seg_tree[2*idx], seg_tree[2*idx+1]);
            from[idx] = min(from[2*idx], from[2*idx+1]);
            to[idx] = max(to[2*idx], to[2*idx+1]);
            return;
        }

        make_seg_tree(seg_tree, from, to, 2*idx);
        make_seg_tree(seg_tree, from, to, 2*idx+1);
        seg_tree[idx] = max(seg_tree[2*idx], seg_tree[2*idx+1]);
        from[idx] = min(from[2*idx], from[2*idx+1]);
        to[idx] = max(to[2*idx], to[2*idx+1]);
    }
     
    int get_max(vector<int> &seg_tree, vector<int> &from, vector<int> &to, int from_i, int to_i, int idx)
    {
        if(from_i == from[idx] && to_i == to[idx])
            return seg_tree[idx];

        int mx = INT_MIN;
        if(from[2*idx]<=from_i && to_i<=to[2*idx])
            mx = max(mx, get_max(seg_tree, from, to, from_i, to_i, 2*idx));
        else if(from[2*idx+1]<=from_i && to_i<=to[2*idx+1])
            mx = max(mx, get_max(seg_tree, from, to, from_i, to_i, 2*idx+1));
        else
        {
            mx = max(mx, get_max(seg_tree, from, to, from_i, to[2*idx], idx));
            mx = max(mx, get_max(seg_tree, from, to, to[2*idx], to_i, idx));
        }
        
        return mx;
    }
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        if(nums.size() == 1)
            return nums;

        int base = 1;
        while(true)
        {
            if(base >= nums.size())
                break;
            
            base *= 2;
        }
        vector<int> seg_tree(2*base, INT_MIN);
        vector<int> from(2*base, nums.size()-1);
        vector<int> to(2*base, nums.size());
        for(int i = 0; i<nums.size(); ++i)
        {
            from[base+i] = i;
            to[base+i] = i+1;
        }

        for(int i = 0; i<nums.size(); ++i)
            seg_tree[base+i] = nums[i];

        make_seg_tree(seg_tree, from, to, 1);

        vector<int> ans;
        for(int from_i = 0; from_i+k-1<nums.size();  ++from_i)
        {
            int to_i = from_i+k;
            int mx = get_max(seg_tree, from, to, from_i, to_i, 1);
            ans.emplace_back(mx);
        }

        return ans;
    }
};

// dq
class Solution 
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        deque<int> dq;
        vector<int> ans;
        for (int i=0; i<nums.size(); i++) 
        {
            if (!dq.empty() && dq.front() == i-k)
                dq.pop_front();
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.push_back(i);
            if (i>=k-1)
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};

// dp
class Solution
{
	public:
		vector<int> maxSlidingWindow(vector<int> &nums, int k)
		{
			int i, j, n = nums.size(), wins;
			wins = n - k + 1;
			vector<int> lft(n), rgt(n);

			for (i = 0; i < n; i++)
			{
				lft[i] = nums[i];
				if (i % k !=0) 
					lft[i] = max(lft[i - 1], lft[i]);
			}

			rgt[n - 1] = nums[n - 1];
			for (i = n - 2; i >= 0; i--)
			{
				rgt[i] = nums[i];
				if (i % k != (k - 1))
					rgt[i] = max(rgt[i], rgt[i + 1]);
			}

			vector<int> ans;

			for (i = 0; i < wins; i++)
				ans.push_back(max(rgt[i], lft[i + k - 1]));

			return ans;
		}
};
