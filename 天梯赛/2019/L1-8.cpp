#include <iostream>
#include <regex>
using namespace std;
int main(void)
{
    int n;
    cin >> n;
    getchar();
    while (n--)
    {
        string s;
        getline(cin, s);
        cout << s << endl;
        s = regex_replace(s, regex(R"(\s+)"), " ");
        if (s.front() == ' ')
            s.erase(s.begin());
        if (s.back() == ' ')
            s.pop_back();
        s = regex_replace(s, regex(R"( !)"), "!");
        s = regex_replace(s, regex(R"( ,)"), ",");
        s = regex_replace(s, regex(R"( \.)"), ".");
        s = regex_replace(s, regex(R"( \?)"), "?");
        s = regex_replace(s, regex(R"( ')"), "'");
        for (auto &c : s)
        {
            if (c != 'I')
                c = tolower(c);
        }
        s = regex_replace(s, regex(R"(\bcan you\b)"), "_I can");
        s = regex_replace(s, regex(R"(\bcould you\b)"), "_I could");
        s = regex_replace(s, regex(R"(\bI\b)"), "you");
        s = regex_replace(s, regex(R"(\bme\b)"), "you");
        s = regex_replace(s, regex(R"(\?)"), "!");
        s = regex_replace(s, regex(R"(\b_I\b)"), "I");
        cout << "AI: " << s << endl;
    }
    return 0;
}