
def lis(seq):
    """
        L is a list of dict with: 
            val - length of the longest incresing subsequence fot this index
            prev_index - index of previous item in longest inceasing subsequence
            index - index of corresponding item in given sequence
    """
    L = []
    for i in range(len(seq)):
        L.append(dict(val=1, prev_index=None, index=i))

    for i in range(1, len(L)):
        # for every element define and calculate a set of subproblems
        # the condition is that previous element is smaller then given element
        subproblems = [L[k] for k in range(i) if seq[k] < seq[i]]

        # In list update value of LIS as the biggest subproblem result
        # (The longest subsequence).    
        # also update index of max subproblem as prev index in sequence 
        max_subproblem = max(subproblems, key=lambda x: x.get("val"), default=dict(val=0, prev_index=None, index=None))
        L[i] = dict(
            val=max_subproblem.get('val') + 1,
            prev_index=max_subproblem.get('index'),
            index=i
        )
        
    # Element with highest val in L has the longest subsequence 
    # as it is the sum of the biggest subproblems
    last_element =  max(L, default=dict(val=None, prev_index=None, index=None), key=lambda x: x.get("val"))
    
    # To obtain sequence we need to follow back the L with prev index starting
    # from seq[last_element['index']]
    result = []
    while last_element.get('prev_index') is not None:
        result.insert(0,seq[last_element['index']])
        last_element = L[last_element.get('prev_index')]
    result.insert(0, seq[last_element['index']])
            
    return result


def test_lis():
    # Test case 1
    assert lis([9, 3, 6, 2, 5, 1, 8, 10, 4, 7]) == [3, 6, 8, 10]
    
    # Test case 2
    assert lis([10, 9, 8, 7, 6, 5, 4, 3, 2, 1]) == [10]
    
    # Test case 3
    assert lis([1, 2, 3, 4, 5, 6, 7, 8, 9, 10]) == [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    
    # Test case 4
    assert lis([10, 9, 2, 3, 4, 5, 6, 7, 8, 1]) == [2, 3, 4, 5, 6, 7, 8]
    
    # Test case 5
    assert lis([1, 3, 5, 7, 9, 2, 4, 6, 8, 10]) == [1, 3, 5, 7, 9, 10]

if __name__ == "__main__":
    test_lis()