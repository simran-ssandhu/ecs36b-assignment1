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

```c++
Copy of the fixed code
```