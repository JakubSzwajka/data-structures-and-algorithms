# Box stacking - no rotation

The box stacking problem is a problem in which given a set of boxes with different dimensions, the goal is to stack the boxes on top of each other such that the height of the stack is maximized. In this example, boxes **cannot be rotated** and can be placed on top of any other box as long as the dimensions of the bottom box are larger than the dimensions of the top box. The dimensions of a box are represented by its length, width, and height.

1. **Find the subproblem:**

   The subproblem here is answering which box B should we stack box A to have the tallest possible stack if A.width < B.width and A.length < B.length.

2. **Find the relationship among subproblems:**

   When solving the subproblem above, save some reference to the box below the top box. This way, instead of getting height on a single top box, we can solve the same subproblem, considering stack height as the heigh of the box on its top.

3. **Generalize:**

   Iterate over all boxes and find the tallest one with reference to the one below. Iterate over the “below” boxes to the bottom to obtain ids. of boxes to be stacked on each other.
