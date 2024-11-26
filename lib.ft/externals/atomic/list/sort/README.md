## Sort by comparison
- bubble sort
- insertion sort
- selection sort
- merge sort
- quick sort
- heap sort
- shell sort

## Sorted by data properties
- Counting sort
- Radix Sort
- Bucket sort
- Geometric Sort

## hybride algorithm
- Timsort => between insertion and merging sort
- Bitonic sort => parralel network
- Odd-Even Sort => parrallel architecture
- IntroSort => start with quick sort, and then toggle toward heap if the partionning become efficient

## probabilistic Algorithms
- Bogo sort => use all the permutations til obtain the sorted list


# best approach to choose one of those algorithm
## 1. if the datas are light
- insertion Sort
- Shell Sort
- Bubble Sort
## 2. if we treat big datas
- quick sort
- merge sort
- heap sort
## 3. if datas are almost sorted
- Insertion Sort
- Tim Sort
## 4. if the memory is limited
- Quick sort
- Heap Sort
- Merge Sort
## 5. if the stability is important
- Merge Sort
- Tim Sort
- Counting Sort / Radix Sort / Bucket Sort (but depends on constraints as below).
## 6. if datas have specific constraints
- counting sort
- Radix Sort
- Bucket Sort