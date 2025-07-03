// 3 5 1 2 3
 //    m
   // Find the rotation pivot: the first index i such that nums[i] < nums[i-1].
    // If the array is not rotated, returns 0.
    int findPivot(const std::vector<int>& nums)
    {
        int n  = static_cast<int>(nums.size());
        int lo = 0, hi = n - 1;

        /* 1️⃣  First, push the search space toward *a* minimum value.  */
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            if (nums[mid] > nums[hi])          // pivot strictly right of mid
                lo = mid + 1;
            else if (nums[mid] < nums[hi])     // pivot ≤ mid
                hi = mid;
            else                               // nums[mid] == nums[hi] – duplicates
                --hi;                          // shrink safely
        }
        int pivotCandidate = lo;               // some minimum value

        /* 2️⃣  Ensure we pick the *first* minimum that follows the drop.
               (Handles “… 2, 1, 1, 1 …” where the first min sits at index 0.)   */
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[i - 1]) {       // real rotation point
                pivotCandidate = i;
                break;
            }
        }
        return pivotCandidate;                 // 0 … n-1
    }
