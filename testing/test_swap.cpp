#include <cstdlib>
#include <vector>
#include <algorithm>
#include "test_helpers.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "sorting.h"
#include "rapidcheck/gtest.h"


TEST(SwapTests, SimpleSwapTwoValues) {
    /*
     * Swap two values and see if the swap was successful.
     */
  int x = 12;
  int y = 34;
  int* firstValue = &x;
  int* secondValue = &y;
  swap(firstValue, secondValue);
  EXPECT_EQ(*firstValue, 34);
  EXPECT_EQ(*secondValue, 12);
}

TEST(SwapTests, SimpleSwapValuesInArray) {
    /*
     * Swap a few values in an array.
     * Check that the ones that swapped did swap and the ones that didn't swap
     * are still at the same locations
     */
  int arr[6] = {1, 10, 23, 9, 25, 50};
  // 1, 10, 10, 9, 25,
  // 0  1   2  3   4

  swap(&arr[1], &arr[3]);


//check swaped
  EXPECT_EQ(arr[1], 9);
  EXPECT_EQ(arr[3], 10);


  //check unswapped
  EXPECT_EQ(arr[0], 1);
  EXPECT_EQ(arr[5], 50);

}

RC_GTEST_PROP(SwapTests,
              PropertySwapTwoValues,
              (int a_start, int b_start)
) {
    /*
     * Swap two values and see if the swap was successful.
     */
  int a_startCopy = a_start;
  int b_startCopy = b_start;
  int* a_startP = &a_start;
  int* b_startP = &b_start;
  swap(a_startP, b_startP);
  RC_ASSERT(*a_startP == b_startCopy);

  RC_ASSERT(*b_startP == a_startCopy);

}


RC_GTEST_PROP(SwapTests,
              PropertySwapValuesInArray,
              (const std::vector<int>& values)
) {
    /*
     * Swap two values in an array. See that they swapped and the others did not
     */
    int* array = new int[values.size()];
    copy_vector_to_array(values, array);

  std::size_t i = *rc::gen::inRange<std::size_t>(0, values.size());
  std::size_t k = *rc::gen::inRange<std::size_t>(0, values.size());
  RC_PRE(i != k) ;

  swap(&array[i], &array[k]);
  RC_ASSERT(array[i] == values[k]);
  RC_ASSERT(array[k] == values[i]);

  for (std::size_t j = 0; j < values.size(); ++j) {
    if (j != k && j != i) {
      RC_ASSERT(array[j] == values[j]);
    }
  }

  delete [] array;
}
