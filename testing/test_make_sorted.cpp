#include <cstdlib>
#include <vector>
#include "gtest/gtest.h"
#include "sorting.h"
#include "rapidcheck/gtest.h"
#include "test_helpers.h"

TEST(MakeSortedTests, SimpleSortSortedArray) {
    /*
     * Check that we can sort an array that is already sorted.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
  int* arr = new int[5]{1, 2, 3, 4, 5};

  make_sorted(arr, 5);

  EXPECT_EQ(arr[0], 1);
  EXPECT_EQ(arr[1], 2);
  EXPECT_EQ(arr[2], 3);
  EXPECT_EQ(arr[3], 4);
  EXPECT_EQ(arr[4], 5);

  delete[] arr;

}

TEST(MakeSortedTests, SimpleSortReverseSortedArray) {
    /*
     * Check that we can sort an array that is reverse sorted order.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
  int* arr = new int[5]{5, 4, 3, 2, 1};

  make_sorted(arr, 5);


  EXPECT_EQ(arr[0], 1);
  EXPECT_EQ(arr[1], 2);
  EXPECT_EQ(arr[2], 3);
  EXPECT_EQ(arr[3], 4);
  EXPECT_EQ(arr[4], 5);

  delete[] arr;

}


TEST(MakeSortedTests, SimpleSortAverageArray) {
    /*
     * Check that we can sort an array where the elements in it are in random order.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
  int* arr = new int[5]{1, 10, 23, 0, 4};
  // 0, 1, 4, 10, 23

  make_sorted(arr, 5);

  EXPECT_EQ(arr[0], 0) << "array index 0 is: " << arr[0];
  EXPECT_EQ(arr[1], 1) << "array index 1 is: " << arr[1];
  EXPECT_EQ(arr[2], 4) << "array index 2 is: " << arr[2];
  EXPECT_EQ(arr[3], 10) << "array index 3 is: " << arr[3];
  EXPECT_EQ(arr[4], 23)<< "array index 4 is: " << arr[4];
  //4, 1, 10, 23, 0,

  // try 1
  //  0, 10, 23, 1, 4
  //try2: 10, 23, 1, 4 0
  //try3: 0, 10, 23, 1, 4
  //try4:4, 10, 23, 0, 1


  delete[] arr;
}

TEST(MakeSortedTests, SimpleSortArrayWithDuplicates) {
    /*
     * Check that we can sort an array where there are duplicate elements in it.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
}

RC_GTEST_PROP(MakeSortedTests,
              PropertyAfterSortingValuesAreInAscendingOrder,
              ( std::vector<int> values)
) {
    /* Test that after sorting an array, the values are in ascending order
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
}
