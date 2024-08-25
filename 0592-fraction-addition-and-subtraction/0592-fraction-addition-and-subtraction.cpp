class Solution {
public:
    string fractionAddition(string expression) {
        int numerator = 0, denominator = 1; // Start with 0/1
        
        for (int i = 0, n = expression.size(); i < n;) {
            
            int sign = 1;
            if (expression[i] == '+' || expression[i] == '-') {
                sign = (expression[i] == '-') ? -1 : 1;
                i++;
            }
            
            
            int num = 0;
            while (i < n && isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            
            
            i++;
            
            
            int denom = 0;
            while (i < n && isdigit(expression[i])) {
                denom = denom * 10 + (expression[i] - '0');
                i++;
            }
            
            numerator = numerator * denom + sign * num * denominator;
            denominator *= denom;
            
            
            int gcd = abs(__gcd(numerator, denominator));
            numerator /= gcd;
            denominator /= gcd;
        }
        
        return to_string(numerator) + "/" + to_string(denominator);
    }
};