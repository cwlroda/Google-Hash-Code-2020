# Book Scanning

![alt text](https://raw.githubusercontent.com/cwlroda/Google-Hash-Code-2020/master/images/Libraries.png "Libraries")

| Test | Score Obtained |
| ---- | ---------- |
| A    | 21         |
| B    | 5,822,900  |
| C    | 4,966,742  |
| D    | 4,815,395  |
| E    | 4,164,635  |
| F    | 4,948,349  |
| **Total** | **24,718,042** |

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
<img src="https://raw.githubusercontent.com/cwlroda/Google-Hash-Code-2020/master/images/formula.png" width="120" height="80" title="Algorithm">
</p>
where i is the total number of books in the library, B is the score of each book, S is the number of books that can be scanned each day, and D is the number of days it takes to sign the library up for scanning.
<br>

Libraries are signed up as long as there are no other libraries signing up concurrently. Once the library is signed up, its books are scanned and it is removed from the database. The maximum number of books that can be scanned is given by
<p align="left">
<img src="https://raw.githubusercontent.com/cwlroda/Google-Hash-Code-2020/master/images/Screenshot%202020-02-21%20at%205.18.57%20PM.png" width="80" height="50" title="Algorithm">
</p>
where R is the number of days to the deadline.
<br>
If the total number of books in the library is less than this maximum, all the books can be scanned. If the total number exceeds the maximum, the first n books (where n corresponds to the maximum) are sent to be scanned.
<br>
Once certain books from a library are scanned, the remaining libraries are refreshed to remove these books if they contain them. This ensures that all libraries only contain unscanned books at each iteration. The weights of the remaining libraries are also updated to reflect these changes and the database is re-sorted.

## Future Improvements
1. Devising a more complex weighting algorithm to accurately reflect the data in each library
2. Introducing pipelining to increase efficiency when signing libraries up
3. Factoring in the exact number of books to be output if not all books in a library can be scanned within the time given
4. Improve time and space complexity by finding more efficient ways to iterate through the books and libraries when sorting
