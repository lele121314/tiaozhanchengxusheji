#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

map<string, int> dp;
int direction[4] = { 1, -1, 4, -4 };

//************************************
// Method:    bfs
// FullName:  bfs
// Access:    public
// Returns:   void
// Qualifier: ��0���������ִ�
//************************************
void bfs()
{
    queue<string> que;
    que.push("01234567");
    dp["01234567"] = 0;
    while (!que.empty())
    {
        string now = que.front(); que.pop();
        // p��'0'��λ��
        int p = 0;
        for (int j = 0; j < 8; ++j)
        {
            if (now[j] == '0')
            {
                p = j;
                break;
            }
        }

        for (int i = 0; i < 4; ++i)
        {
            int n = p + direction[i];
            if (0 <= n && n < 8 &&
                !(p == 3 && i == 0) && // ���Ͻǲ�����������
                !(p == 4 && i == 1))   // ���½ǲ�����������
            {
                string next = now;
                swap(next[p], next[n]);
                if (dp.find(next) == dp.end())
                {
                    dp[next] = dp[now] + 1;
                    que.push(next);
                }
            }
        }
    }
}

///////////////////////////SubMain//////////////////////////////////
int main(int argc, char *argv[])
{

    bfs();
    string line;
    while (getline(cin, line))
    {
        line.erase(remove(line.begin(), line.end(), ' '), line.end());
        cout << dp[line] << endl;
    }

    return 0;
}
///////////////////////////End Sub//////////////////////////////////
