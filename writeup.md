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
```

### How the bug was located

Explain how you found the bug

### Description

Describe the bug

### Fix

Explain how you fixed the bug

```c++
Copy of the fixed code
```

### Bug 3

### Location

Line number(s) of the bugs.

```c++
Copy of the buggy code
```

### How the bug was located

Explain how you found the bug

### Description

Describe the bug

### Fix

Explain how you fixed the bug

```c++
Copy of the fixed code
```