// 241. Different Ways to Add Parentheses
class Solution {
public:
    // Cache to store results of subproblems (memoization)
    unordered_map<string, vector<int>> memo;
    
    vector<int> diffWaysToCompute(string expression) {
        // If we have already computed this subexpression, return the cached result
        if (memo.find(expression) != memo.end()) {
            return memo[expression];
        }
        
        vector<int> result;
        
        // Split the expression at every operator
        for (int i = 0; i < expression.size(); i++) {
            char ch = expression[i];
            
            // If it's an operator, split the expression into two parts
            if (ch == '+' || ch == '-' || ch == '*') {
                // Left part of the expression
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                // Right part of the expression
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));
                
                // Combine results of left and right parts using the operator
                for (int l : left) {
                    for (int r : right) {
                        if (ch == '+') {
                            result.push_back(l + r);
                        } else if (ch == '-') {
                            result.push_back(l - r);
                        } else if (ch == '*') {
                            result.push_back(l * r);
                        }
                    }
                }
            }
        }
        
        // If the expression is just a number, return it as the only result
        if (result.empty()) {
            result.push_back(stoi(expression));
        }
        
        // Cache the result for the current expression
        memo[expression] = result;
        return result;
    }
};
