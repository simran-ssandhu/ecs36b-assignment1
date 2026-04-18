#include <cstdlib>
#include <string>
#include "gtest/gtest.h"
#include "formatting.h"
#include "test_helpers.h"
#include "rapidcheck/gtest.h"

auto word_generator() {
    /* Creates a generator for a string made up of
     * characters from [a - z]
     */
  return  rc::gen::container<std::string>(
    rc::gen::inRange('a', 'z')
  );

}

auto vector_of_ints_to_vector_of_strings(const std::vector<int>& numbers) {
    /* Create a vector of strings from a vector of ints
     */
  std::vector<std::string> strings;
  strings.reserve(numbers.size());

  for (int number : numbers) {
    strings.push_back(std::to_string(number));
  }
  return strings;



}


TEST(ParseArgsTests, SimpleCheckArgumentsParsedSuccessfully) {
    /*
     * Check that you parse the command line arguments correctly.
     * (ar_out and len_out are set to the right values).
     * Don't forget to free any memory that was dynamically allocated as part of your test.'
     */
  //PARSE ARGS
  /**
  * Transform the command line arguments from their string representations to their numeric values
  * @param argc: the number of the command line arguments
  * @param argv: the command line arguments
  * @param ar_out: An output parameter. The array to store the command line arguments into. It is assumed that
    * no space has been made for the values so this function will allocate the space for the values inside of ar_out.
    * If there are no command line arguments ar_out should be set to NULL.
  * @param len_out:  An output parameter. The number of elements placed into ar_out.
  */

  const char* commandLine[] = {"program", "10", "20", "3"};
  int argc = 4;

  int len_out = 0;

  int* ar_out = new int[argc - 1];

  parse_args(argc, const_cast<char **>(commandLine), ar_out, &len_out);

  EXPECT_EQ(ar_out[0], 10);
  EXPECT_EQ(ar_out[1], 20);
  EXPECT_EQ(ar_out[2], 3);
  EXPECT_EQ(len_out, 3);



  delete[] ar_out;


}

TEST(ParseArgsTests, SimpleCheckParseNoArgs) {
    /*
     * Check that you parse you can successfully parse "no" command line arguments.
     */
  const char* commandLine[] = {"program"};
  int argc = 1;

  int len_out = -10;
  int holder =0;

  int* ar_out = &holder;

  parse_args(argc, const_cast<char**>(commandLine), ar_out, &len_out);


  //EXPECT_STREQ(ar_out[0], " ");
  //EXPECT_EQ(ar_out[1], "");
  //EXPECT_EQ(ar_out[2], "");
  EXPECT_EQ(len_out, 0);

}


RC_GTEST_PROP(ParseArgsTests,
              PropertyCheckArgumentsParsedSuccessfully,
              ()
) {
    /* Check that we can correctly parse the command line
     * arguments when we receive 1 or more arguments.
     * Don't forget to free any memory that was dynamically allocated as part of this test
     */
}

RC_GTEST_PROP(ParseArgsTests,
              PropertyCheckParseNoArgs,
              ()
) {
    /*
     * Check that you parse you can successfully parse "no" command line arguments.
     */
}
