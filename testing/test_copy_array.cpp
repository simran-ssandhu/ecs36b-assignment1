#include <cstdlib>
#include <vector>
#include <algorithm>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "sorting.h"
#include "test_helpers.h"
#include "rapidcheck/gtest.h"

TEST(CopyArrayTests, SimpleValuesAreSame) {
    /*
     * Check that the values in the copy are the same as the values in the original array.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
  int* arr = new int[5]{1, 2, 3, 4, 5};

  int* copyArr = copy_array(arr, 5);

  EXPECT_EQ(arr[0], copyArr[0]);
  EXPECT_EQ(arr[1], copyArr[1]);
  EXPECT_EQ(arr[2], copyArr[2]);
  EXPECT_EQ(arr[3], copyArr[3]);
  EXPECT_EQ(arr[4], copyArr[4]);

  delete[] arr;
  delete [] copyArr;



}

TEST(CopyArrayTests, SimpleOriginalDoesNotChange) {
    /*
     * Check that the  values in the original array did not change.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
  int* arr = new int[5]{1, 2, 3, 4, 5};

  int* copyArr = copy_array(arr, 5);

  EXPECT_EQ(arr[0], 1);
  EXPECT_EQ(arr[1], 2);
  EXPECT_EQ(arr[2], 3);
  EXPECT_EQ(arr[3], 4);
  EXPECT_EQ(arr[4], 5);

  delete[] arr;
  delete [] copyArr;

}

TEST(CopyArrayTests, SimpleCopyWasMade) {
    /*
     * Check that a copy was actually made
     * (ar and copy point to different locations in memory and no parts of the two arrays overlap)
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
  int* arr = new int[5]{1, 2, 3, 4, 5};

  int* copyArr = copy_array(arr, 5);

  EXPECT_NE(arr, copyArr);
  
  delete[] arr;
  delete[] copyArr;

}


RC_GTEST_PROP(CopyArrayTests,
              PropertyValuesAreSame,
              (const std::vector<int>& values)
) {
    /*
     * Check that the values in the copy are the same as the values in the original array.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
  int* array = new int[values.size()];
  copy_vector_to_array(values, array);
  int* arrayCopy = copy_array(array, values.size());


  RC_ASSERT(elements_in_vector_and_array_are_same(values, arrayCopy));

  delete[] array;
  delete[] arrayCopy;

}

RC_GTEST_PROP(CopyArrayTests,
              PropertyOriginalDoesNotChange,
              (const std::vector<int>&values)
) {
    /*
     * Check that the  values in the original array did not change.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */

}

RC_GTEST_PROP(CopyArrayTests,
              PropertyCopyWasMade,
              (const std::vector<int>&values)
) {
    /*
  * Check that a copy was actually made
  * (ar and copy point to different locations in memory and no parts of the two arrays overlap)
  * Don't forget to free any memory that was dynamically allocated as part of your test.
  */

}



