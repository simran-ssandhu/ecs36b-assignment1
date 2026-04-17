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
  // swap 9 and 10,  1, 9, 23, 10, 25
  // swap 23 and 10,  1, 9, 23, 10, 25
                    //0  1  2.  3.  4
  //swap(&arr[4], &arr[3]);
  // swap 23 and 25,  1, 9, 10, 23, 25
                    //0  1  2.  3.  4

//check swaped
  EXPECT_EQ(arr[1], 9);
  EXPECT_EQ(arr[3], 10);
  //EXPECT_EQ(arr[3], 25);
 // EXPECT_EQ(arr[4], 23);

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
}


RC_GTEST_PROP(SwapTests,
              PropertySwapValuesInArray,
              (const std::vector<int>& values)
) {
    /*
     * Swap two values in an array. See that they swapped and the others did not
     */
}
