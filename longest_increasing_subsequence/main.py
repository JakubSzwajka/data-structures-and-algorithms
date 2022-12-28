
def lis(seq, index=0):
    # list storing max lis for every node (subproblem)
    # L[2] will be longest increasing subsequence for 3th
    # element (8). That means will be equal to 1 since longest 
    # subsequence is: 5 -> 8. 
    # At the beggining, LIS for every element is 1.  
    L = [1] * len(seq)

    for i in range(1, len(L)):
        # for every element define and calculate a set of subproblems
        # the condition is that previous element is smaller then given element
        subproblems = [L[k] for k in range(i) if seq[k] < seq[i]]

        # In list update value of LIS as the biggest subproblem result
        # (The longest subsequence).        
        L[i] = 1 + max(subproblems, default=0)
            
    # Element with highest value in L has the longest subsequence 
    # as it is the sum of the biggest subproblems
    return max(L, default=0)


if __name__ == "__main__":
    sequence = [5,2,8,6,3,6,9,5]

    assert(lis(sequence) == 4)