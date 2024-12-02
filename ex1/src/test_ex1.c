#include <stdio.h>
#include <stdlib.h>
#include "unity.h"
#include "unity_internals.h"

#include "record_loader.h"
#include "comparator.h"
#include "sorter.h"

static record **test_records;
static long test_record_count;

void setUp(void) {
    test_records = NULL;
    test_record_count = 0;
}

void tearDown(void) {
    if (test_records != NULL) {
        free_records(test_records, test_record_count);
    }
}

void test_str_compare(void) {
    record r1 = {1, "Alpha", 0, 0.0};
    record r2 = {2, "Beta", 0, 0.0};
    TEST_ASSERT_EQUAL(-1, str_compare(&r1, &r2));
    TEST_ASSERT_EQUAL(1, str_compare(&r2, &r1));
    TEST_ASSERT_EQUAL(0, str_compare(&r1, &r1));
}

void test_int_compare(void) {
    record r1 = {1, "A", 10, 0.0};
    record r2 = {2, "B", 20, 0.0};
    TEST_ASSERT_EQUAL(-1, int_compare(&r1, &r2));
    TEST_ASSERT_EQUAL(1, int_compare(&r2, &r1));
    TEST_ASSERT_EQUAL(0, int_compare(&r1, &r1));
}

void test_double_compare(void) {
    record r1 = {1, "A", 0, 1.1};
    record r2 = {2, "B", 0, 2.2};
    TEST_ASSERT_EQUAL(-1, double_compare(&r1, &r2));
    TEST_ASSERT_EQUAL(1, double_compare(&r2, &r1));
    TEST_ASSERT_EQUAL(0, double_compare(&r1, &r1));
}

void test_create_record(void) {
    test_record_count = 1;
    test_records = malloc(test_record_count * sizeof(record *));
    test_records[0] = create_record(1, "Alpha", 1, 1.1);
    TEST_ASSERT_EQUAL(1, test_records[0]->id);
    TEST_ASSERT_EQUAL(1, test_records[0]->int_field);
    TEST_ASSERT_EQUAL(1.1, test_records[0]->double_field);
    TEST_ASSERT_EQUAL_STRING("Alpha", test_records[0]->char_field);
}

void test_quick_sort_on_null_array(void) {
    quick_sort((void **)test_records, test_record_count, int_compare);
    TEST_ASSERT_EQUAL(0, test_record_count);
}

void test_quick_sort_on_equal_elements(void) {
    test_record_count = 5;
    test_records = malloc(test_record_count * sizeof(record *));
    for (int i = 0; i < test_record_count; i++) {
        test_records[i] = create_record(i, "equal", 42, 3.14);
    }

    quick_sort((void **)test_records, test_record_count, int_compare);
    for (int i = 0; i < test_record_count; i++) {
        TEST_ASSERT_EQUAL(42, test_records[i]->int_field);
    }
}

void test_quick_sort_on_sorted_array(void) {
    test_record_count = 3;
    test_records = malloc(test_record_count * sizeof(record *));
    test_records[0] = create_record(1, "A", 10, 1.1);
    test_records[1] = create_record(2, "B", 20, 2.2);
    test_records[2] = create_record(3, "C", 30, 3.3);

    quick_sort((void **)test_records, test_record_count, int_compare);
    TEST_ASSERT_EQUAL(10, test_records[0]->int_field);
    TEST_ASSERT_EQUAL(20, test_records[1]->int_field);
    TEST_ASSERT_EQUAL(30, test_records[2]->int_field);
}

void test_merge_sort_on_null_array(void) {
    merge_sort((void **)test_records, test_record_count, int_compare);
    TEST_ASSERT_EQUAL(0, test_record_count);
}

void test_merge_sort_on_equal_elements(void) {
    test_record_count = 5;
    test_records = malloc(test_record_count * sizeof(record *));
    for (int i = 0; i < test_record_count; i++) {
        test_records[i] = create_record(i, "equal", 42, 3.14);
    }

    merge_sort((void **)test_records, test_record_count, int_compare);
    for (int i = 0; i < test_record_count; i++) {
        TEST_ASSERT_EQUAL(42, test_records[i]->int_field);
    }
}

void test_merge_sort_on_sorted_array(void) {
    test_record_count = 3;
    test_records = malloc(test_record_count * sizeof(record *));
    test_records[0] = create_record(1, "A", 10, 1.1);
    test_records[1] = create_record(2, "B", 20, 2.2);
    test_records[2] = create_record(3, "C", 30, 3.3);

    merge_sort((void **)test_records, test_record_count, int_compare);
    TEST_ASSERT_EQUAL(10, test_records[0]->int_field);
    TEST_ASSERT_EQUAL(20, test_records[1]->int_field);
    TEST_ASSERT_EQUAL(30, test_records[2]->int_field);
}

// Funzione principale per eseguire i test
int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_str_compare);
    RUN_TEST(test_int_compare);
    RUN_TEST(test_double_compare);

    RUN_TEST(test_create_record);

    RUN_TEST(test_quick_sort_on_null_array);
    RUN_TEST(test_quick_sort_on_equal_elements);
    RUN_TEST(test_quick_sort_on_sorted_array);

    RUN_TEST(test_merge_sort_on_null_array);
    RUN_TEST(test_merge_sort_on_equal_elements);
    RUN_TEST(test_merge_sort_on_sorted_array);

    return UNITY_END();
}