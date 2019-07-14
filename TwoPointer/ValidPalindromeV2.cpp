//
// Created by zouguowei on 2019-06-21.
//

#include <iostream>
#include <string>
#include <algorithm>

class Solution {
public:
    /**
     * @param s: a string
     * @return bool: whether you can make s a palindrome by deleting at most one character
     */
    bool validPalindrome(std::string &s) {
        // Write your code here
        int start = 0;
        int end = s.length() - 1;

        bool result = true;
        while (start <= end) {
            if (std::tolower(s[start]) == std::tolower(s[end])) {
                start ++;
                end --;
            } else {
                break;
            }
        }

        if (start <= end) {
            result = isPalindrome(s, start + 1, end);
            if (!result) {
                result = isPalindrome(s, start, end - 1);
            }
        }
        return result;
    }

private:

    bool isPalindrome(std::string &s, int start, int end) {
        bool result = true;
        while (start <= end) {
            if (std::tolower(s[start]) == std::tolower(s[end])) {
                start ++;
                end --;
            } else {
                result = false;
                break;
            }
        }
        return result;
    }
};


int main(int argc, char *argv[])
{
    {
        std::string s = "aba";
        Solution solution;
        std::cout << solution.validPalindrome(s) << std::endl;
    }

    {
        std::string s = "abca";
        Solution solution;
        std::cout << solution.validPalindrome(s) << std::endl;
    }

    {
        std::string s = "abc";
        Solution solution;
        std::cout << solution.validPalindrome(s) << std::endl;
    }

    return 0;
}
