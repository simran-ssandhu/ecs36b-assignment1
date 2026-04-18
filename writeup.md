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

### Description

Describe the bug

### Fix 

Explain how you fixed the bug

```c++
Copy of the fixed code
```

### Bug 2

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