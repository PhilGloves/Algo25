/**
 * File to test the #edit_distance and the #edit_distance_dyn functions
 */

#include <stdio.h>
#include <stdlib.h>
#include "unity.h"
#include "unity_internals.h"

#include "edit_distance.h"


void test_edit_distance_on_empty_strings(void) {
    const char *s1 = "";
    const char *s2 = "";
    TEST_ASSERT_EQUAL_INT(0, edit_distance(s1, s2));
    TEST_ASSERT_EQUAL_INT(0, edit_distance_dyn(s1, s2));
}

void test_edit_distance_on_null_strings(void) {
    const char *s1 = NULL;
    const char *s2 = NULL;
    TEST_ASSERT_EQUAL_INT(-1, edit_distance(s1, s2));
    TEST_ASSERT_EQUAL_INT(-1, edit_distance_dyn(s1, s2));
}

void test_edit_distance_on_one_empty_string(void) {
    const char *s1 = "cassa";
    const char *s2 = "";
    TEST_ASSERT_EQUAL_INT(length(s1), edit_distance(s1, s2));
    TEST_ASSERT_EQUAL_INT(length(s1), edit_distance_dyn(s1, s2));
}

void test_edit_distance_on_one_null_string(void) {
    const char *s1 = NULL;
    const char *s2 = "";
    TEST_ASSERT_EQUAL_INT(-1, edit_distance(s1, s2));
    TEST_ASSERT_EQUAL_INT(-1, edit_distance_dyn(s1, s2));
}

void test_edit_distance_on_same_strings(void) {
    const char *s1 = "casa";
    const char *s2 = "casa";
    TEST_ASSERT_EQUAL_INT(0, edit_distance(s1, s2));
    TEST_ASSERT_EQUAL_INT(0, edit_distance_dyn(s1, s2));
}

void test_edit_distance_normal_case1(void) {
    const char *s1 = "tassa";
    const char *s2 = "passato";
    TEST_ASSERT_EQUAL_INT(4, edit_distance(s1, s2));
    TEST_ASSERT_EQUAL_INT(4, edit_distance_dyn(s1, s2));
}

void test_edit_distance_normal_case2(void) {
    const char *s1 = "vino";
    const char *s2 = "vinaio";
    TEST_ASSERT_EQUAL_INT(2, edit_distance(s1, s2));
    TEST_ASSERT_EQUAL_INT(2, edit_distance_dyn(s1, s2));
}


int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_edit_distance_on_empty_strings);
    RUN_TEST(test_edit_distance_on_null_strings);
    RUN_TEST(test_edit_distance_on_one_empty_string);
    RUN_TEST(test_edit_distance_on_one_null_string);
    RUN_TEST(test_edit_distance_on_same_strings);
    RUN_TEST(test_edit_distance_normal_case1);
    RUN_TEST(test_edit_distance_normal_case2);
    
    return UNITY_END();
}
