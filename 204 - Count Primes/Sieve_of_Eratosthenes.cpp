class Solution {
public:
    int countPrimes(int n) {
        if (n < 2)
        {
            return 0;
        }

        auto primes = std::vector<bool>(n, true);
        primes[0] = false;
        primes[1] = false;

        for (int i = 2; i * i < n; ++i)
        {
            if (primes[i])
            {
                for (int j = i * i; j < n; j += i)
                {
                    primes[j] = false;
                }
            }
        }

        return std::count(primes.cbegin(), primes.cend(), true);
    }
};