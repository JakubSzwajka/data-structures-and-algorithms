For a sequence a1, a2, ..., an, find the length of the longest increasing subsequence ai1, ai2, ..., aik.

Constraints: i1 < i2 < ... < ik; ai1 < ai2 < ... < aik

```
LIS([3, 1, 8, 2, 5]) -> 3
// [1,2,5]
```

1. Visualize problem

- a graph?

2. Find subproblem:

Find LIS to x index. I.e.

```
LIS[3]([3,1,8,2,5]) = [1,2] || [3,8] -> 2
```

3. Find relationships among subproblems:

```
LIS[n] = 1 + max{LIS[k] | k <n, A[k] < A[n]>}
```

4. Generalize the relationship

```
LIS[n] = 1 + max{LIS[k] | k <n, A[k] < A[n]>}
```
