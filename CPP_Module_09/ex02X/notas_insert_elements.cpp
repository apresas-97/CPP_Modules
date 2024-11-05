/*

GUIDE:

-pend: List of numbers that pending insertion in the mainchain
-mainchain: List of numbers that are currently handled in this iteration of merge-insertion.
-mainchainPositions: List of iterators to members of mainchain, these will accurately point to insertion points regardless
of insertions, deletions, etc. in the mainchain.

What insertElement does:
1. Initialises chainPosNext to the first position of mainchainPositions
2. Initialises k = 3, to get the kth Jacobsthal Number
3. Initialsies pendEndIndex to 0
  pendEndIndex is the index of the last element in the current iteration of pend.
  pend will be inserted following this sequence:
  b3, b2, b5, b4, b11, ..., b6, b21, b20, b19, ...
  Each iteration of insertions will be from bN to bN-1, bN-2, ... bM
  The index of pend at which bM is found is pendEndIndex
  The index of pend at which bN is found is pendStartIndex
4. Initialise pendStart, an LIterator, to hold pend.begin() and have the size of all LIterators in this iteration.
For that, we will need to bring into this function the size of LIterator start, for instance. And call it sizeIt.
So, pendStart will be LIterator(pend.begin(), sizeIt).
We will use this to have a reference to the beginning of pend in the shape of an LIterator, which will allow us to
work with it more comfortably.

5. While true loop starts
// loop

6. We initialise pendStartIndex to the kth Jacobsthal number

7. If pendStartIndex is >= than the size of pend, it means, that this iteration of insertions does not have enough elements
to follow the strict sequence of bN, bN-1, bN-2, ... bM, which is the point of merge-insertion. Therefore, we break the loop.
// continue loop
8. We initialise an LIterator pendIt to be pendStart + pendStartIndex.
  This will make it so the LIterator it will point to bN in the sequence of bN, bN-1, bN-2, ... bM

9. We initialise the mainchainPositionsIt to be chainPosNext, then we advance it by pendStartIndex.
  This will make it so the iterator mainchainPositionsIt will point to the aN in the sequence of aN, aN-1, aN-2, ... aM
  Where aX is the Xth element in the mainchain.

10. We start a for loop that will iterate i = pendStartIndex while i > pendEndIndex
// for loop
  We decrease i by one. This is to ensure that the loop actualy goes from bN to bM, but we cannot do that directly in the
  for loop saying i >= pendEndIndex, because pendEndIndex and i are unsigned, so if pendEndIndex is 0, i will always be
  greater than it, and the loop will never stop.

11. We perform a binarySearch, from mainchain.begin(), to *mainchainPositionsIt, seeking the value *pendIt.
In other words:
  We seek the value of bX in the mainchain, and the range that we seek in goes from a1 to aX - 1.
  Meaning, we perform the most efficient search possible, as we know that's the smallest range in which bX will be found.

12. We use insertLIterator to insert pendIt (bX) in the mainchain, at the position returned by binarySearch.

13. We decrease mainchainPositionsIt by one, so it points to the next element in the sequence aN, aN-1, aN-2, ... aM

14. We decrease pendIt by one, so it points to the next element in the sequence bN, bN-1, bN-2, ... bM

// end for loop

15. We reset pendEndIndex to pendStartIndex + 1.
  So, after inserting bN, bN-1, bN-2, ... bM. Where bM was the previous pendEndIndex, we now set pendEndIndex to bN + 1.
  For example, in the sequence:
  b3, b2, b5, b4, b11, ..., b6, b21, b20, b19, ..., b12, b43, b42, b41, ...
  After the iteration from b11 to b6, where:
    pendStartIndex was b11
    pendEndIndex was b6
    We now set
    pendEndIndex to b11 + 1 = b12

16. We increase k by 1, so we get the next Jacobsthal number in the next iteration.

// end loop

>> At this point, all the elements bX in pend have been inserted in the mainchain in the correct order.
>> Except for:
  Those which did not fit in the latest iteration, because there were not enough elements in pend.
  And the odd element that was left out, because it was not part of the sequence bN, bN-1, bN-2, ... bM
  For example:
  We go from:
    3 - 5 - 7
   /   /   /
  1   2   4   6
  To
  1 - 2 - 3 - 4 - 5 - 7
                         6
  In this case, 6 is the odd element that could not be paired.

17. We start a new while loop that will go while pendEndIndex < pend.size()
// loop
The reason for this is that we now don't care about the order in which the elements are inserted.
We just want to insert all the remaining pend elements in the mainchain.
And the range of insertion will be the complete mainchain.

18. We perform a binarySearch from mainchain.begin() to mainchain.end(), seeking the value pendIt[pendEndIndex]
In other words:
  We seek the value of bX in the whole mainchain.

19. We use insertLIterator to insert pendIt[pendEndIndex] in the mainchain, at the position returned by binarySearch.

20. We increase pendEndIndex by one.

// end loop

// end insertElement

What binarySearch does:

Receives:
  - An iterator to the beginning of the range in which to search, as a LIterator
  - An iterator to the end of the range in which to search, as a LIterator
  - A value to search for, as a LIterator ?

Returns:
  - An iterator to the position in which the value was found
    When inserting into a list using insertLIterator, the position we care about is the
    position of the first element of the LIterator. In other words, the .base() of the LIterator.
    So, binarySearch will return the .base() of the LIteator it found the value in.
    Which is a std::list<unsigned int>::iterator 

*/