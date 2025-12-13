class Solution {
public:
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        
        int n = code.size();
        vector<pair<int, string>> valid;

        unordered_map<string, int> order = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };

        auto isValidCode = [&](const string& s) {
            if (s.empty()) return false;
            for (char c : s) {
                if (!isalnum(c) && c != '_')
                    return false;
            }
            return true;
        };

        for (int i = 0; i < n; i++) {
            if (!isActive[i]) continue;
            if (order.find(businessLine[i]) == order.end()) continue;
            if (!isValidCode(code[i])) continue;

            valid.push_back({order[businessLine[i]], code[i]});
        }

        sort(valid.begin(), valid.end(), [](auto& a, auto& b) {
            if (a.first != b.first)
                return a.first < b.first;
            return a.second < b.second;
        });

        vector<string> ans;
        for (auto& p : valid)
            ans.push_back(p.second);

        return ans;
    }
};
