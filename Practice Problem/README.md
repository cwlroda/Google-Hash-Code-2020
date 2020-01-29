# More Pizza

![alt text](https://raw.githubusercontent.com/cwlroda/Google-Hash-Code-2020/master/Practice%20Problem/images/More%20Pizza.jpg "More Pizza")

| Test | Score      |
| ---- | ---------- |
| A    | 16         |
| B    | 100        |
| C    | 4500       |
| D    | 1000000000 |
| E    | 505000000  |
| **Total** | **1505004616**  |

## Execution
To run the program:
```
./test.sh
```

## Implementation
A greedy algorithm was initially implemented. The input vector containing the various pizza slices were already sorted in ascending order Thus, the algorithm started from the end of the input vector and worked its way backwards, summing the slices along the way. If an addition of an element exceeded the maximum number of slices allowed, the element would be skipped and the algorithm would move on and attempt to add the next element.

Using test A as an example,

```
Max Slices: 17
Index: 3
Elements: 2 5 6 8
Sum: 0
```

The algorithm begins at the last element, 8, which is added to the sum.

```
Max Slices: 17
Index: 3
Elements: 2 5 6 8
Sum: 8
```

Next, the iterator moves to the second last element, 6, which is also added to the sum.

```
Max Slices: 17
Index: 2
Elements: 2 5 6 8
Sum: 14
```

Upon the addition of 5 at the next iteration, the algorithm rejects it as the total sum exceeds 17.

```
Max Slices: 17
Index: 1
Elements: 2 5 6 8
Sum: 19 X
```

Finally, 2 is added which gives a maximum total of 16 slices.

```
Max Slices: 17
Index: 0
Elements: 2 5 6 8
Sum: 16
```

However, this algorithm was not foolproof as it achieved a score of only 999999932 out of a maximum score of 1000000000 for test C. This was because the algorithm did not test all possible combinations of elements. To enhance the effectiveness of the algorithm, an element was removed from the vector at each iteration before running the algorithm. Though this slowed down the performance of the algorithm, it was able to achieve the maximum score possible.
