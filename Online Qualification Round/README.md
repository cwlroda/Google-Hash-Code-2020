# More Pizza

![alt text](https://raw.githubusercontent.com/cwlroda/Google-Hash-Code-2020/master/images/Libraries.png "Libraries")

| Test | Score Obtained |
| ---- | ---------- |
| A    | 21         |
| B    | 5,822,900  |
| C    | 4,940,693  |
| D    | 4,812,990  |
| E    | 4,021,186  |
| F    | 4,915,464  |
| **Total** | **24,513,254** |

## Build
To build the program:
```
make all
```

## Execution
To run all tests:
```
./run.sh
```

To run program on an individual file:
```
./solver {input-file} {output-file}
```

## Implementation
Initially, the books in each library are sorted in descending order based on their scores. Then, the libraries are sorted in descending "weight" using a simple algorithm. The weight of a library is given by:
<p align="left">
<img src="https://raw.githubusercontent.com/cwlroda/Google-Hash-Code-2020/master/images/formula.png" width="100" height="80" title="Algorithm">
</p>
where i is the total number of books in the library, B is the score of each book, S is the number of books that can be scanned each day, and D is the number of days it takes to sign the library up for scanning.

## Future Improvements
1. Devising a more complex weighting algorithm to accurately reflect the data in each library
2. Introducing pipelining to increase efficiency when signing libraries up
3. Factoring in the exact number of books to be output if not all books in a library can be scanned within the time given
4. Improve time and space complexity by finding more efficient ways to iterate through the books and libraries when sorting
