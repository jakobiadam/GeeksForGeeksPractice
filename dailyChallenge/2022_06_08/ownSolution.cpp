class Solution
{
    public:
    //Function to return the sorted array.
    
    void divideAndConquerKSort(int arr[], int arrCopy[], int left, int right, int K)
    {
        if ((right - left) == 0) {return;}
        
        int mid {(int)(ceil((left + (float)right) / 2))};
        divideAndConquerKSort(arr, arrCopy, left, mid - 1, K);
        divideAndConquerKSort(arr, arrCopy, mid, right, K);
        
        if ((right - left) <= 2*(K+2))
        {
            int i {left};
            int j {mid};
            int k {left};
            while ((i < mid) && (j <= right))
            {
                if (arr[i] <= arr[j])
                {
                    arrCopy[k] = arr[i];
                    ++k;
                    ++i;
                }
                else
                {
                    arrCopy[k] = arr[j];
                    ++k;
                    ++j;
                    
                }
            }
            
            int l {};
            if (i < mid) {l = i;}
            else {l = j;}
            while (k <= right)
            {
                arrCopy[k] = arr[l];
                ++k;
                ++l;
            }
            
            for (int m = left; m <= right; ++m)
            {
                arr[m] = arrCopy[m];
            }
            
        }
        
        
    }
    
    vector <int> nearlySorted(int arr[], int num, int K){
        // Your code here
        int arrCopy[num];
        int left {0};
        int right {num - 1};
        
        divideAndConquerKSort(arr, arrCopy, left, right, K);
        
        vector <int> arrSol;
        
        for (int i = 0; i < num; ++i)
        {
            arrSol.push_back(arr[i]);
        }
        
        return arrSol;
    }
    
};
