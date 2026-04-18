#include <cstdlib>
#include "gtest/gtest.h"
#include "sorting.h"
#include "test_helpers.h"
#include "rapidcheck/gtest.h"

TEST(GetSortedTests, SimpleSortSortedArray) {
    /*
     * Check that we can sort an array that is already sorted.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */

  int* arr = new int[5]{1, 2, 3, 4, 5};

  int* sortedArray = get_sorted(arr, 5);

  EXPECT_EQ(sortedArray[0], 1);
  EXPECT_EQ(sortedArray[1], 2);
  EXPECT_EQ(sortedArray[2], 3);
  EXPECT_EQ(sortedArray[3], 4);
  EXPECT_EQ(sortedArray[4], 5);

  delete[] arr;
    delete[] sortedArray;


}

TEST(GetSortedTests, SimpleSortReverseSortedArray) {
    /*
     * Check that we can sort an array that is reverse sorted order.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */

  int* arr = new int[5]{5, 4, 3, 2, 1};

    int * sortedArray = get_sorted(arr, 5);

  EXPECT_EQ(sortedArray[0], 1);
  EXPECT_EQ(sortedArray[1], 2);
  EXPECT_EQ(sortedArray[2], 3);
  EXPECT_EQ(sortedArray[3], 4);
  EXPECT_EQ(sortedArray[4], 5);

  delete[] arr;
    delete[] sortedArray;

}

TEST(GetSortedTests, SimpleSortAverageArray) {
    /*
     * Check that we can sort an array where the elements in it are in random order.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int* arr = new int[5]{1, 10, 23, 0, 4};
    // 0, 1, 4, 10, 23

    int* sortedArray = get_sorted(arr, 5);


    EXPECT_EQ(sortedArray[0], 0);
    EXPECT_EQ(sortedArray[1], 1);
    EXPECT_EQ(sortedArray[2], 4);
    EXPECT_EQ(sortedArray[3], 10);
    EXPECT_EQ(sortedArray[4], 23);

    delete[] arr;
    delete[] sortedArray;

}

TEST(GetSortedTests, SimpleSortArrayWithDuplicates) {
    /*
     * Check that we can sort an array where there are duplicate elements in it.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int* arr = new int[5]{12, 23, 2, 12, 1};
    // 1, 2, 12, 12, 23
    int* sortedArray = get_sorted(arr, 5);


    EXPECT_EQ(sortedArray[0], 1);
    EXPECT_EQ(sortedArray[1], 2);
    EXPECT_EQ(sortedArray[2], 12);
    EXPECT_EQ(sortedArray[3], 12);
    EXPECT_EQ(sortedArray[4], 23);

    delete[] arr;
    delete[] sortedArray;

}

TEST(GetSortedTests, SimpleOriginalDoesNotChange) {
    /*
     * Check that the original array was not modified.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */

    int* arr = new int[5]{12, 23, 2, 12, 1};
    // 1, 2, 12, 12, 23
    int* sortedArray = get_sorted(arr, 5);


    EXPECT_EQ(arr[0], 12);
    EXPECT_EQ(arr[1], 23);
    EXPECT_EQ(arr[2], 2);
    EXPECT_EQ(arr[3], 12);
    EXPECT_EQ(arr[4], 1);

    delete[] arr;
    delete[] sortedArray;


}

TEST(GetSortedTests, SimpleCopyWasMade) {
    /*
     * Check that the sorted array is copy of the original array in sorted order.
     * (ar and copy point to different locations in memory and no parts of the two arrays overlap)
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int* arr = new int[5]{1, 2, 3, 4, 5};

    int* copyArr = get_sorted(arr, 5);

    EXPECT_NE(arr, copyArr);

    delete[] arr;
    delete[] copyArr;



}


RC_GTEST_PROP(GetSortedTests,
              PropertyAfterSortingValuesAreInAscendingOrder,
              ( std::vector<int> values)
) {
    /* Check that after sorting an array, the values are in ascending order
     * Don't forget to free any memory that was dynamically allocated as part of this test
    */
    int* array = new int[values.size()];
    copy_vector_to_array(values, array);
    int* sortedArray = get_sorted(array, values.size());

    for (std::size_t i = 0; i+1 < values.size(); i++) {
        RC_ASSERT(sortedArray[i] <= sortedArray[i + 1]);
    }

    delete[] sortedArray;
    delete[] array;

}

RC_GTEST_PROP(GetSortedTests,
              PropertyOriginalDoesNotChange,
              (const std::vector<int>&values)
) {
    /*
     * Check that the original array was not modified.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    ;
    int* array = new int[values.size()];
    copy_vector_to_array(values, array);

    int* arrCopy = new int[values.size()];
    copy_vector_to_array(values, arrCopy);

   get_sorted(array, values.size());


    for (std::size_t i = 0; i + 1 < values.size(); i++) {
        RC_ASSERT(array[i] == arrCopy[i]);
    }

    //RC_ASSERT(sortedArray != array);

    //delete[] sortedArray;
    delete[] arrCopy;
    delete[] array;

}

RC_GTEST_PROP(GetSortedTests,
              PropertyCopyWasMade,
              (const std::vector<int>&values)
) {
    /*
     * Check that the sorted array is copy of the original array in sorted order.
     * (ar and copy point to different locations in memory and no parts of the two arrays overlap)
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int* array = new int[values.size()];
    copy_vector_to_array(values, array);

    int* sortedArray = get_sorted(array, values.size());




    RC_ASSERT(array != sortedArray);



    delete[] sortedArray;
    delete[] array;



}











