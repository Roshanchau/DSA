#include <iostream>
using namespace std;

bool checkEqual(int arr1[26], int arr2[26])
{
    for (int i = 0; i < 26; i++)
    {
        if (arr1[i] != arr2[i])
        {
           return false;
        }
    }
    return true;
}

bool checkPermutation(string s1, string s2)
{
    // get the count of the s1 string for each characters.
    int count1[26] = {0};

    for (int i = 0; i < s1.length(); i++)
    {
        int index = s1[i] - 'a';
        count1[index]++;
    }

    // traverse string s2 in window size of length and compare with s1's count


    int i = 0;
    int count2[26] = {0};
    int windowLen = s1.length();

    // for first window eg: ei
    while (i < windowLen && i<s2.length())
    {
        int index = s2[i] - 'a';
        count2[index]++;
        i++;
    }

    if (checkEqual(count1, count2))
    {
        return true;
    }
    // for rest of the s2 string to get next charcter to insert in the window and remove the previous charcter i.e e for first iteration.

    while (i < s2.length())
    {
        int index = s2[i] - 'a';
        count2[index]++;

        index = s2[i - windowLen] - 'a';
        count2[index]--;
        if (checkEqual(count1, count2))
        {
            return true;
        }
        i++;
    }
    return false;
}

int main()
{
    string s1;
    cout << "Enter string 1: " << s1 << endl;
    cin >> s1;
    string s2;
    cout << "Enter string 2: " << s2 << endl;
    cin >> s2;
    bool res = checkPermutation(s1, s2);
    cout << res << endl;
    return 0;
}