class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        /*
            [2,1,3,1,2,3,3]
            [4,2,7,2,4,4,5]
        */
        
        std::vector<long long> res(arr.size(), 0);
        std::unordered_map<int, std::vector<int>> map;
        std::vector<int> diff;
        std::vector<int> sum;
        
        for (int i = 0; i < arr.size(); i++) {
            map[arr[i]].push_back(i);
        }
        
        for (const auto& i : map) {
            auto& v = i.second;
            long long sum = 0;
            for (auto x : v) sum += x;
            long long n = v.size();
            for (int j = 0; j < v.size(); j++) {
                res[v[j]] = sum - (n - 2 * j) * v[j];
                sum -= 2 * v[j];
            }
        }
        
        return res;
        
    }
};
