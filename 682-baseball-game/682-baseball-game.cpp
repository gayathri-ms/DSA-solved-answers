class Solution {
public:
    int calPoints(vector<string>& ops) {
        
        stack<int> x;
        for(int i=0;i<ops.size();i++)
        {
            if(ops[i] == "C")
                x.pop();
            else if(ops[i] == "D")
            {
                int y = x.top();
                x.push(y*2);
            }
            else if(ops[i]=="+")
            {
                int num1 = x.top();
                x.pop();
                int num2 = x.top();
                int sum  = num1  + num2;
                x.push(num1);
                x.push(sum);
            }
            else
                x.push(stoi(ops[i]));
            // cout<<x.top();
        }
        int total=0;
        while(!x.empty())
        {
            total += x.top();
            // cout<<total;
            x.pop();
        }
        return total;
    }
};