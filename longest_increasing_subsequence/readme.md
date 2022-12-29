When solving the 2022 Advent Of Code, I really got into algorithmic problems and decided to learn some more techniques like dynamic programming. The first example I found was a LIS problem. Here is a short “how to” solve it with some key points for later reference.

The longest increasing subsequence (LIS) problem is a well-known problem in computer science that involves finding the length of the longest subsequence of a given sequence such that all the elements in the subsequence are in increasing order. For example, for the sequence [3, 1, 8, 2, 5], the longest increasing subsequence is [1, 2, 5], which has a length of 3.

Dynamic programming is a technique for solving problems by breaking them down into smaller subproblems and storing the solutions to them to avoid recomputing them.

To solve the LIS problem using dynamic programming, we can follow these steps:

1. **Find the subproblems:**

   To solve the LIS problem, we can define subproblems as finding the LIS to a certain index x in the sequence.

   I.e. subproblems for LIS from `[3,1,8,2,5]` will be:

   - LIS([3,1,8])
   - LIS([3,1,8,2])
   - LIS([3,1])
   - …

2. **Find the relationships among the subproblems:**

   To solve a subproblem LIS[n], we can consider all the subproblems LIS[k] for which k < n and the value at index k is smaller than the value at index n. The value of LIS[n] can then be calculated as 1 + the maximum value of LIS[k] over all such subproblems.

3. **Generalize the relationship:** Once we have found the relationships among the subproblems, we can use these relationships to calculate the value of LIS[n] for all n.

The last step would be to find the index (n) of the biggest value. This way we can find where does the LIS ends.
