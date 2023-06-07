#include <bits/stdc++.h>

// std::vector<std::string> words;
std::string t;
const int mod = 1e9 + 7;
struct Node
{
    int wordsEnded = 0;
    int wordsPassing = 0;
    Node *nextletters[26] = {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};
};

// ab tab gab trap t aba

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int sum = 0;
    Node *root = new Node;
    std::getline(std::cin, t, '$');
    for (int a = 0; a < t.length(); a++)
    {
        Node *op = root;

        for (; a < t.length() && t[a] != ' ' && t[a] != '\n'; a++)
        {
            op->wordsPassing++;
            sum += op->wordsEnded;
            sum = sum % mod;
            if (op->nextletters[t[a] - 'a'] != nullptr)
            {
                op = op->nextletters[t[a] - 'a'];
            }
            else
            {      
                op->nextletters[t[a] - 'a'] = new Node;
                op = op->nextletters[t[a] - 'a'];
            }
        }
        sum += op->wordsPassing + op->wordsEnded;
        op->wordsEnded++;
        sum = sum % mod;
    }

    std::cout << sum;
    return 0;
}
// re
// tre
// tr
// t
// u
// ur
// po
// op
// p
// o
// $
