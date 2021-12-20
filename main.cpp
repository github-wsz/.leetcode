#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> mem{};
bool operator<(pair<int, int> &l, pair<int, int> &r)
{
    return (double)(l.first / l.second) < (double)(r.first / r.second);
}
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 2)
            return n;
        int n1, n2;
        if (mem.count(n - 1))
            n1 = mem[n - 1];
        else
        {
            n1 = climbStairs(n - 1);
            mem[n - 1] = n1;
        }
        if (mem.count(n - 2))
            n2 = mem[n - 2];
        else
        {
            n2 = climbStairs(n - 2);
            mem[n - 2] = n2;
        }

        return n1 + n2;
    }

    vector<string> ans;
    int n;
    void dfs(int l, int r, string s)
    {
        if (l == 3 && r == 3)
        {
            ans.emplace_back(move(s));
            return;
        }
        if (l < n)
            dfs(l + 1, r, s + '(');
        if (l > r)
            dfs(l, r + 1, s + ')');
    }

    vector<string> generateParenthesis(int n)
    {
        this->n = n;
        dfs(1, 0, "(");
        return move(ans);
    }

    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
    {
        priority_queue<pair<int, int>> q;
        int n1 = arr.size() - 1;
        int n2 = n1 + 1;
        for (int i = 0; i < n1; ++i)
        {
            for (int j = i + 1; j < n2; ++j)
            {
                q.emplace(arr[i], arr[j]);
            }
        }

        k -= 1;
        for (int i = 0; i < k; ++i)
        {
            q.pop();
        }

        return {q.top().first, q.top().second};
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
