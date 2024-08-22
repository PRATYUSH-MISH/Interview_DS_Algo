/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Cloudera
    Leetcode Link               : https://leetcode.com/problems/number-complement
*/

/****************************************************************************** C++ ******************************************************************************/
//Approach-1 (Using bit magic of XOR)
//T.C : O(log2(num))
//S.C : O(1)
class Solution {
public:
    int findComplement(int num) {
        int number_of_bits = (int)(log2(num)) + 1;
        
        for(int i = 0; i<number_of_bits; i++) {
            num = num^(1<<i); //Take Xor to flip
        }
        return num;
    }
};


//Approach-2 (Using XOR mask)
//T.C : O(log2(num))
//S.C : O(1)
class Solution {
public:
    int findComplement(int num) {
        if (num == 0)
            return 1;

        int mask = 0;
        int temp = num;

        // Create a mask with all bits set to 1 that are of the same length as N
        while (temp) {
            mask = (mask << 1) | 1;
            temp >>= 1;
        }

        // XOR N with mask to get the complement
        return num ^ mask;
    }
};


//Approach-3 (iterate digit by digit and create complement)
//T.C : O(log2(num))
//S.C : O(1)
class Solution {
public:
    int findComplement(int num) {
        int i = 0, ans = 0;
        while (num) {
            // If the current bit is 0, set the corresponding bit in ans to 1
            if (!(num & 1))
                ans |= (1 << i);
            num >>= 1;
            i++;
        }
        return ans;
    }
};


/****************************************************************************** JAVA ******************************************************************************/
//Approach-1 (Using bit magic of XOR)
//T.C : O(log2(num))
//S.C : O(1)
class Solution {
    public int findComplement(int num) {
        int numberOfBits = (int)(Math.log(num) / Math.log(2)) + 1;
        
        for (int i = 0; i < numberOfBits; i++) {
            num = num ^ (1 << i); // Take XOR to flip
        }
        return num;
    }
}


// Approach-2 (Using XOR mask)
// T.C : O(log2(num))
// S.C : O(1)
class Solution {
    public int findComplement(int num) {
        if (num == 0)
            return 1;

        int mask = 0;
        int temp = num;

        // Create a mask with all bits set to 1 that are of the same length as num
        while (temp != 0) {
            mask = (mask << 1) | 1;
            temp >>= 1;
        }

        // XOR num with mask to get the complement
        return num ^ mask;
    }
}


// Approach-3 (Iterate digit by digit and create complement)
// T.C : O(log2(num))
// S.C : O(1)
class Solution {
    public int findComplement(int num) {
        int i = 0, ans = 0;
        while (num != 0) {
            // If the current bit is 0, set the corresponding bit in ans to 1
            if ((num & 1) == 0)
                ans |= (1 << i);
            num >>= 1;
            i++;
        }
        return ans;
    }
}