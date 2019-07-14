//
// Created by zouguowei on 2019-06-21.
//

#include <iostream>
#include <string>
#include <algorithm>

class Solution {
public:
    /**
     * @param s: A string
     * @return: Whether the string is a valid palindrome
     */
    bool isPalindrome(std::string &s) {
        // write your code here
        bool result = true;
        int start = 0;
        int end = s.length() - 1;
        while (start <= end) {
            if (!std::isalpha(s[start]) && !std::isdigit(s[start])) {
                start++;
                continue;
            }

            if (!std::isalpha(s[end]) && !std::isdigit(s[end])) {
                end--;
                continue;
            }

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
        std::string s = "A man, a plan, a canal: Panama";
        Solution solution;
        std::cout << s  << " is " << solution.isPalindrome(s) << std::endl;
    }

    {
        std::string s = "race a car";
        Solution solution;
        std::cout << s  << " is " << solution.isPalindrome(s) << std::endl;
    }

    return 0;
}