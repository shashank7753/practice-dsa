class Solution {
public:
    int mapFun(int i, vector<int> &mapping ){
        stack<int> st;
        if(i == 0) st.push(mapping[0]);
        while(i>0){
            int digit = i%10;
            i=i/10;
            st.push( mapping[digit]);
        }
        int ans=0;
        while(!st.empty()){
            int n = st.size()-1;
            int i = st.top();
            int mul = pow(10,n);
            ans = ans+ i*mul;
            // cout<<ans<<endl;
            st.pop();
        }
        return ans;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<int> ans;

        // cout<<mapFun(nums[2],mapping);
        vector<pair<int,int>> vec;

        for(int i=0;i<nums.size();i++){
            pair<int,int> p;
            p.first = mapFun(nums[i],mapping);
            p.second = i; 
            vec.push_back(p);
        }
        sort(vec.begin(),vec.end());

        for(int i =0;i<vec.size();i++){
            ans.push_back(nums[vec[i].second]);
        }


        return ans;
    }
};

// 991 338 38 