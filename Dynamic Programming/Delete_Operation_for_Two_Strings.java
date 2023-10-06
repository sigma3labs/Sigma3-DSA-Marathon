/*
 * Question : Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same. 
 * In one step, you can delete exactly one character in either string.
 * 
 * Language : Java
 */

class Delete_Operation_for_Two_Strings {
    public static int minDistance(String word1, String word2) {
        int dp[][] = new int[word1.length() + 1][word2.length() + 1];
        for (int i = 0; i <= word1.length(); i++) {
            for (int j = 0; j <= word2.length(); j++) {
                if (i == 0) {
                    dp[i][j] = j;
                } else if (j == 0) {
                    dp[i][j] = i;
                } else if (word1.charAt(i - 1) == word2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = Math.min(dp[i][j - 1] + 1, dp[i - 1][j] + 1);
                }
            }
        }
        return dp[word1.length()][word2.length()];
    }

    public static void main(String args[]) {
        // word1 = "sea", word2 = "eat"
        int res = minDistance("sea", "eat");
        System.out.println(res);
    }
}

/*
 * Approach:

Create a 2D integer array dp with dimensions (word1.length() + 1) by (word2.length() + 1). This array will be used to store the minimum edit distance values for various substrings of word1 and word2.

Initialize the dp array with base cases:
	When i (the length of word1) is 0, it means that word1 is an empty string. In this case, the minimum edit distance is equal to the length of word2. So, initialize dp[0][j] for all j from 0 to word2.length() with values from 0 to word2.length() (inclusive).
	Similarly, when j (the length of word2) is 0, it means that word2 is an empty string. In this case, the minimum edit distance is equal to the length of word1. So, initialize dp[i][0] for all i from 0 to word1.length() (inclusive) with values from 0 to word1.length() (inclusive).

Iterate through the dp array using nested loops, with i ranging from 1 to word1.length() and j ranging from 1 to word2.length().

Inside the loop, compare the characters at the current positions i and j in word1 and word2 respectively:
	If the characters are the same (word1.charAt(i - 1) == word2.charAt(j - 1)), there is no need to perform any edit operation, so set dp[i][j] equal to the value in the diagonal cell dp[i-1][j-1].
	If the characters are different, calculate the minimum edit distance by taking the minimum of the following three values:
		dp[i-1][j] + 1: This represents the cost of deleting a character from word1.
		dp[i][j-1] + 1: This represents the cost of inserting a character into word1 to match word2.
		dp[i-1][j-1] + 1: This represents the cost of replacing a character in word1 to match word2.

Continue the loop until you have filled the entire dp array.

Finally, return dp[word1.length()][word2.length()], which contains the minimum edit distance between word1 and word2.
 */