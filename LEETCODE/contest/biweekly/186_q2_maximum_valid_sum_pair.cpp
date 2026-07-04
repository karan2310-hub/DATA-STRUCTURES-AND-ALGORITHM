// class Solution {
// public:
//     int maxValidPairSum(vector<int>& nums, int k) {
//         int n=nums.size();
//         int val=0;
//         vector<pair<int,int>>v(n);//value,idx
//         for(int i=0; i<n; i++){
//             v[i]={nums[i],i};
//         }
//         sort(v.begin(),v.end(),[](const auto &a,const auto &b){
//             return a.first>b.first;
//         });
//         val=val+v[0].first;
//         for(int i=1; i<v.size(); i++){
//             if(abs(v[i].second-v[0].second)<k) continue;
//             val=max(val, v[0].first+v[i].first);
//         }
        
//         return val;
//     }
// };

class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {

        int n = nums.size();

        long long ans = 0;
        long long best = nums[0];

        for (int j = k; j < n; j++) {

            // j-k index ab valid ho gaya
            best = max(best, (long long)nums[j - k]);

            // current j ke saath best pair banao
            ans = max(ans, best + nums[j]);
        }

        return ans;
    }
};
