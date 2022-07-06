class Solution{
public:
    
    long long KbelowN(long long K, long long N)
    {
        long long res {1};
        long long j {1};
        for (long long i = N + 1; i <= K; ++i)
        {
            res = res * i;
            while (((res / j) == ((float)(res) / j)) && j <= (K - N))
            {
                res = res / j;
                ++j;
            }
        }
        
        return res;
    }
    
    long long posIntSol(string s)
    {

        //Calculate N and K
        long long length = s.size();
        long long N {1};
        long long kStart {};
        for (long long i = 0; i < length; ++i)
        {
            if (s[i] == '+')
            {
                ++N;
            }
            if (s[i] == '=')
            {
                kStart = i + 1;
                break;
            }
        }
        char kString[length - kStart];
        for (long long i = kStart; i < length; ++i)
        {
            kString[i - kStart] = s[i];
        }
        
        long long K = atoi(kString);
        
        if (N > K) {return 0;}
        
        //Combination (K - 2 place to cut)
        return KbelowN(K - 1, N - 1);
        
        
        
        
    }
};
