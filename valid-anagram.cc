class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> map;
        
        for (const auto&elem : s) {
            if (map.find(elem) == map.end()) {
                map[elem] = 1;
            } else {
                map[elem]++;
            }
        }
        
        for (const auto&elem : t) {
            if (map.find(elem) == map.end())    return false;
            
            map[elem]--;
        }
        
        for (const auto&elem : map) {
            if (elem.second > 0)    return false;
        }
        
        return true;
    }
};
