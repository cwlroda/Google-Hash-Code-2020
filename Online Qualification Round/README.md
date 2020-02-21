# More Pizza

![alt text](https://raw.githubusercontent.com/cwlroda/Google-Hash-Code-2020/master/images/More%20Pizza.jpg "More Pizza")

| Test | Score Obtained | Max Possible Score |
| ---- | ---------- | ---------- |
| A    | 16         | 16         |
| B    | 100        | 100        |
| C    | 4500       | 4500       |
| D    | 1000000000 | 1000000000 |
| E    | 505000000  | 505000000  |
| **Total** | **1505004616** | 1505004616 |

## Build
To build the program:
```
make all
```

## Execution
To run the program:
```
make run
```
**OR**
```
./test.sh
```

## Implementation
A greedy algorithm was initially implemented. The input vector containing the various pizza slices were already sorted in ascending order Thus, the algorithm started from the end of the input vector and worked its way backwards, summing the slices along the way. If an addition of an element exceeded the maximum number of slices allowed, the element would be skipped and the algorithm would move on and attempt to add the next element.

Using test A as an example,

```
Max Slices: 17
Elements: 2 5 6 8
```

The algorithm begins at the last element, 8, which is added to the sum.

```
Max Slices: 17
Elements: 2 5 6 8
Index: 3
Sum: 8
Output Vector: 3
```

Next, the iterator moves to the second last element, 6, which is also added to the sum.

```
Max Slices: 17
Elements: 2 5 6 8
Index: 2
Sum: 14
Output Vector: 3 2
```

Upon the addition of 5 at the next iteration, the algorithm rejects it as the total sum exceeds 17.

```
Max Slices: 17
Elements: 2 5 6 8
Index: 1
Sum: 19 X
Output Vector: 3 2
```

Finally, 2 is added which gives a maximum total of 16 slices.

```
Max Slices: 17
Elements: 2 5 6 8
Index: 0
Sum: 16
Output Vector: 3 2 0
```

However, this algorithm was not foolproof as it achieved a score of only 999999932 out of a maximum score of 1000000000 for test C. This was because the algorithm did not test all possible combinations of elements. To enhance the effectiveness of the algorithm, the algorithm was put through even more iterations. This time, the last two elements of the previous solution found was removed from the vector.

```
Max Slices: 17
Elements: 2 5 6 8
Index: 0
Sum: 8
Output Vector: 3 2̶ ̶0̶
```

Then, the iteration begins at the index of the element before the last element in the previous solution.

```
Max Slices: 17
Elements: 2 5 6 8
Index: 1
Sum: 13
Output Vector: 3 1
```

The iteration continues normally as mentioned in the first part.

```
Max Slices: 17
Elements: 2 5 6 8
Index: 0
Sum: 15
Output Vector: 3 1 0
```

As observed, the current sum of 15 is less than the previous sum of 16. Hence, the current sum is rejected and the previous sum remains as the maximum sum until the iterations are complete. This completion is signalled when the starting index is the first element of the input vector and there are no other values to consider.
