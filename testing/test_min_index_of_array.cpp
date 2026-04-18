#include <vector>
#include <algorithm>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "rapidcheck/gtest.h"
#include "sorting.h"
#include "test_helpers.h"

TEST(MinIndexOfArrayTests, SimpleMinIndexAtFrontOfArray) {
    /*
     * See if we can find the index of the minimum value when it is at the front of the array
     */
  int* arr = new int[5]{1, 10, 45, 3, 23};
  int minIndex = min_index_of_array(arr, 5);
  EXPECT_EQ(minIndex, 0) << "MININDEX IS: " << minIndex;

  delete[] arr;

}

TEST(MinIndexOfArrayTests, SimpleMinIndexAtEndOfArray) {
    /*
     * See if we can find the index of the minimum value when it is at the end of the array
     */

    int* arr = new int[5]{5, 4, 3, 10, 1};
    int minIndex = min_index_of_array(arr, 5);
    EXPECT_EQ(minIndex, 4);

    delete[] arr;
}

TEST(MinIndexOfArrayTests, SimpleMinIndexAtMiddleOfArray) {
    /*
     * See if we can find the index of the minimum value when it is somewhere
     * in the "middle" of the array.
     */
    int* arr = new int[5]{3, 4, 1, 10, 5};
    int minIndex = min_index_of_array(arr, 5);
    EXPECT_EQ(minIndex, 2);

    delete[] arr;
}

TEST(MinIndexOfArrayTests, SimpleDuplicateMinimums) {
    /*
     * See if we return the index of the first minimum in the array
     * When there are multiple values that are the minimum.
     */
    int* arr = new int[5]{1, 1, 3, 1, 5};
    int minIndex = min_index_of_array(arr, 5);
    EXPECT_EQ(minIndex, 0);

    delete[] arr;
}

TEST(MinIndexOfArrayTests, SimpleArrayDoesNotChange) {
    /*
     * Check that finding the minimum of the array did not change the contents of the array.
     */
    int* arr = new int[5]{34, 4, 1, 10, 5};
    int minIndex = min_index_of_array(arr, 5);
    EXPECT_EQ(minIndex, 2);

    //check everything is same
    EXPECT_EQ(arr[0], 34);
    EXPECT_EQ(arr[1], 4);
    EXPECT_EQ(arr[2], 1);
    EXPECT_EQ(arr[3], 10);
    EXPECT_EQ(arr[4], 5);

    delete[] arr;
}


RC_GTEST_PROP(MinIndexOfArrayTests,
              PropertyFindMinIndex,
              ()) {
    /* Check that the value at the location of the minimum index
     * is not larger than any of the other values in the array
     */


    const auto randomInts = *rc::gen::arbitrary<std::vector<int>>();
    int* arr = new int[randomInts.size()];
    copy_vector_to_array(randomInts, arr);
    int minIndex = min_index_of_array(arr, randomInts.size());

    for (std::size_t i = 0; i < randomInts.size(); i++) {
        RC_ASSERT(arr[minIndex] <= arr[i]);
    }

    delete [] arr;

}

RC_GTEST_PROP(MinIndexOfArrayTests,
              PropertyArrayDoesNotChange,
              ()) {
    /*
     * Check that finding the minimum of the array did not change the contents of the array.
     */
    const auto randomInts = *rc::gen::arbitrary<std::vector<int>>();
    int* arr = new int[randomInts.size()];
    int* arrCopy = new int[randomInts.size()];
    copy_vector_to_array(randomInts, arr);
    copy_vector_to_array(randomInts, arrCopy);
    min_index_of_array(arr, randomInts.size());

    for (std::size_t i = 0; i < randomInts.size(); i++) {
        RC_ASSERT(arr[i] == arrCopy[i]);
    }

    delete[] arr;
    delete[] arrCopy;
}
