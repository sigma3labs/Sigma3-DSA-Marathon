class Solution {
    public int minimumOperations(int[] nums) {
       HashSet<Integer> set = new HashSet<>();
        for (int a: nums)
            if (a > 0)
                set.add(a);
        return set.size();
    }
         
    }
