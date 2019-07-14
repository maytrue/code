//
// Created by zouguowei on 2019-06-21.
//

#include <iostream>

// Calculate the a^n % b where a, b and n are all 32bit non-negative integers.
// a^n % b = (a^(n/2) * a^(n/2)) % b = (a^(n/2) % b)*(a^(n/2) % b)%b

class Solution {
public:
    /**
     * @param a: A 32bit integer
     * @param b: A 32bit integer
     * @param n: A 32bit integer
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
        // write your code here
        if (a == 0) {
            return 0;
        }

        if (n == 0) {
            return (1 % b);
        }

        if (n == 1) {
            return (a % b);
        }
        int result = fastPower(a, b, n / 2);
        result = result * result % b;
        if (n % 2 == 1) {
            result = (result * a) % b;
        }
        return result;
    }
};


int main(int argc, char *argv[])
{

    {
        int a = 2;
        int b = 3;
        int n = 4;

        Solution solution;
        std::cout << solution.fastPower(a, b, n) << std::endl;

        // fast(2, 3, 3) -> fast(2, 3, 1)
        // fast(2, 3, 6) -> fast(2, 3, 3)
        // fast(2, 3, 4) -> fast(2, 3, 2) -> fast(2, 3, 1)
    }


    return 0;
}
