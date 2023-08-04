#include<iostream>
using namespace std;
int main()
{string s;
    int i, j;
    getline(cin, s);
    int n = s.size();
    for (i = 0, j = n - 1; i < j; i++, j--)
    {
        if (s[i] >= 65 && s[i] <= 90)
        {
            if (s[i] == s[j] || (s[i] - 65 == s[j] - 97))
                continue;
            else
                break;
        }
        else if (s[i] >= 97 && s[i] <= 123)
        {
            if (s[i] == s[j] || (s[i] - 97 == s[j] - 65))
                continue;
            else
                break;
        }
    }
    if (i >= j)
        cout << "String is Palindrome" << endl;
    else
        cout << "String is not a Palindrome" << endl;

    return 0;

}
