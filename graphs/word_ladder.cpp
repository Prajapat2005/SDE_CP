#include <bits/stdc++.h>
using namespace std;

int bfs(vector<string> w, string begin, string end)
{

    // string,level
    queue<pair<string, int>> q;
    q.push({begin, 1});

    int ans = 0;

    unordered_set<string> st(w.begin(), w.end());

    st.erase(begin);

    while (!q.empty())
    {
        int n = q.size();

        while (n--)
        {
            string s = q.front().first;
            int level = q.front().second;

            q.pop();

            if (s == end)
            {
                ans = level;
                break;
            }

            for (int i = 0; i < s.size(); i++)
            {
                char original = s[i];
                for (char j = 'a'; j <= 'z'; j++)
                {

                    s[i] = j;

                    auto it = st.find(s);

                    if (it != st.end())
                    {
                        q.push({s, level + 1});
                        st.erase(s);
                    }
                }

                s[i] = original;
            }
        }
    }

    return ans;
}
int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{

    return bfs(wordList, beginWord, endWord);
}

int main(){
    
}