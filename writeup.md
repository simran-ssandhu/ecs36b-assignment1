# Google Test And Debugging Writeup

## Things I Thought To Test
1. Testing the swap function to see if it actually swaps two values
2. Testing the find min index function to see if it actually returns the minimum index
3. Test if the copy_array function is actually copying each value in the array
...

## Bugs

### Bug 1

### Location

Line number(s) of the bugs.
51-55
```c++
Copy of the buggy code
for (int i = 1; i < len; ++i) {
    if (ar[i] > ar[min_index]) {
      min_index = i;
    }
  }
return ar[min_index];
```

### How the bug was located

Explain how you found the bug
I located this bug by running the minimum index tests and reviewing the results of my expected values versus what the function was actually returning. By examining these results, I first realized it was giving back the maximum value, and then I realized it wasn't actually giving me the index and instead the actual value. 


### Description

Describe the bug
I realized that the array was returning the max value not the minimum, additionally it was returning the actual minimum of the array and not the minimum index of the array.

### Fix 

Explain how you fixed the bug
I changed the for loop to check if the current index is less than the min_index, if it is than change the min_index to the current index. Then I returned the min_index instead of the ar[min_index], which gives back the actual value. 

```c++
Copy of the fixed code
  int min_index = 0;
//changed for loop
  for (int i = 1; i < len; ++i) {
    if (ar[i] < ar[min_index]) {
      min_index = i;
    }
  }
  //changed this: was originally arr[min_index] WHICH GIVES VALUE
  return min_index;
}
```

### Bug 2

### Location

Line number(s) of the bugs. 74-77

```c++
Copy of the buggy code

  int* temp = a;
  a = b;
  b = temp;
```

### How the bug was located

Explain how you found the bug
After running the swap tests I realized that the values weren't actually changing and the integers weren't being swapped. 

### Description

Describe the bug
This function swaps a and b but since it is a void function it doesn't return these values and they don't actually get changed after the function call. 

### Fix

Explain how you fixed the bug
I changed the function to actually use pointers so now the value at a is equal to the value at b and the value at b is equal to the value at a. This use of pointers actually changes the values of the variables outside the function. 

```c++
Copy of the fixed code
int temp = *a;
  *a = *b;
  *b = temp;
```

### Bug 3

### Location

Line number(s) of the bugs. 40-44

```c++
Copy of the buggy code
 int* copy = ar;
  return copy;
```

### How the bug was located

Explain how you found the bug
The complier warned that the parameter len wasn't being used, which is when I reviewd the function and realized that each value in the array wasn't actually being copied over. 

### Description

Describe the bug
This function is just returning a copy of the pointer of the array and not returning the actual array. 

### Fix

Explain how you fixed the bug
I created a new array by dynamically allocating memory and making the new array the size of the original array. Then I set each ith element of the copy ar to the ith element of the original array. This actually fills out the array with the correct elements. 


```c++
Copy of the fixed code
int* copy = new int[len];
  for (int i = 0; i < len; i++) {
    copy[i] = ar[i];
  }
  return copy;
```

### Bug 4

### Location

Line number(s) of the bugs. 27-30

```c++
Copy of the buggy code
 for (int i = 0; i < len; ++i) {
    int min_index = min_index_of_array(ar + i, len);
    swap(ar + i, ar + min_index);
  }
```

### How the bug was located

Explain how you found the bug
The make_sorted and get_sorted tests were failing, I used the debugger and traced each function call and stepped through it which is when I realized 
### Description

Describe the bug
The indexing of this array is wrong, since the len of the original array doesn't change but the index is advancing it is actually returning the wrong index regarding the original array. Additionally, the indexes when calling the swap function are also wrong since they don't advance to the current index.

### Fix

Explain how you fixed the bug
I changed the min_index so it would decrease the length as the for loop advanced so it returned an accurate minimum index since we shift it and start looking at ar+i, we are only looking at a subarray. I changed the swap call so that it deals with the original array, adding i to the min_index shifts it back to the original array. 

```c++
Copy of the fixed code
for (int i = 0; i < len; i++) {
    int min_index = min_index_of_array(ar + i, len-i);
    swap(ar + i, ar + min_index + i);
  }
```

### Bug 4

### Location

Line number(s) of the bugs. 27-30

```c++
Copy of the buggy code
 for (int i = 0; i < len; ++i) {
    int min_index = min_index_of_array(ar + i, len);
    swap(ar + i, ar + min_index);
  }
```

### How the bug was located

Explain how you found the bug
The make_sorted and get_sorted tests were failing, I used the debugger and traced each function call and stepped through it which is when I realized
### Description

Describe the bug
The indexing of this array is wrong, since the len of the original array doesn't change but the index is advancing it is actually returning the wrong index regarding the original array. Additionally, the indexes when calling the swap function are also wrong since they don't advance to the current index.

### Fix

Explain how you fixed the bug
I changed the min_index so it would decrease the length as the for loop advanced so it returned an accurate minimum index since we shift it and start looking at ar+i, we are only looking at a subarray. I changed the swap call so that it deals with the original array, adding i to the min_index shifts it back to the original array.

```c++
Copy of the fixed code
for (int i = 0; i < len; i++) {
    int min_index = min_index_of_array(ar + i, len-i);
    swap(ar + i, ar + min_index + i);
  }

```




### Bug 5

### Location

Line number(s) of the bugs.
13-16

```c++
Copy of the buggy code
int* sorted_ar = copy_array(ar, len);
make_sorted(ar, len);
return sorted_ar;
```

### How the bug was located

Explain how you found the bug
The get sorted array tests were failing even after I had fixed the make_sorted function and ran those tests. After looking through the get_sorted function I noticed the bug, since my get_sorted tests were just giving me the original unchanged array. 

### Description

Describe the bug
The make_sorted function calls the wrong array, it calls the original array and then returns the sorted_ar, which is just a copy of the unsorted array. 
### Fix

Explain how you fixed the bug
I called the make_sorted function with the sorted_ar array instead of the ar parameter. 
```c++
Copy of the fixed code
  int* sorted_ar = copy_array(ar, len);
  make_sorted(sorted_ar, len);
  return sorted_ar;
```



### Bug 6

### Location

Line number(s) of the bugs.
17-19 of formatting.cpp
```c++
Copy of the buggy code
i for(int i = 0; i < len; --i){
    printf("%d ", ar[i]);
  }
}
```


### How the bug was located

Explain how you found the bug
After all my function tests passed, I ran the main function which kept on giving me an error and exited the function early before running the sorting. While printing the inputs I entered, it kept printing zeros and then exiting the program early. 
### Description

Describe the bug
The for loop decreases instead of incrementing which doesn't make sense for printing out the array.
### Fix

Explain how you fixed the bug
I changed the for loop to increment each instead of decreasing. 
```c++
Copy of the fixed code
  for(int i = 0; i < len; ++i){
    printf("%d ", ar[i]);
  }
}
```

### Bug 7

### Location

Line number(s) of the bugs.
14-16 of main.cpp
```c++
Copy of the buggy code
  int* given_numbers;
  int len;
```


### How the bug was located

Explain how you found the bug
While running main.cpp, I got complier warnings that given_numbers was declared but wasn't initialized anywhere.

### Description

Describe the bug
given_numbers and len are declared but aren't used, given_numbers is an array of the numbers entered into the command line but in main.cpp it isn't given a length which causes an error. 
### Fix

Explain how you fixed the bug
The amount of numbers entered is always one less then the total command line arguments, so len would be equal to argc-1. Since given_numbers is supposed to be the array for the command line arguments it needs to be the size of the amount of numbers so I used dynamic allocation to fix that. 
```c++
Copy of the fixed code
  int len = argc - 1;
  int* given_numbers = new int[len];
```


