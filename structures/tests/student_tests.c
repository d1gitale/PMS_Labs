#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../src/course.c"
#include "../src/student.c"

void positive_test_change_mean_grade(void) {
    Student student;
    student.mean_grade = 3.5;
    change_mean_grade(&student, 8.5);
    CU_ASSERT(student.mean_grade == 8.5);

    Student student2;
    student2.mean_grade = 8.5;
    change_mean_grade(&student2, 3.5);
    CU_ASSERT(student2.mean_grade == 3.5);

    Student student3;
    student3.mean_grade = 8.5;
    change_mean_grade(&student3, 8.5);
    CU_ASSERT(student3.mean_grade == 8.5);
}

void negative_test_change_mean_grade(void) {
    Student student;
    student.mean_grade = 3.5;
    change_mean_grade(&student, 11);
    CU_ASSERT(student.mean_grade == 3.5);

    Student student2;
    student2.mean_grade = 3.5;
    change_mean_grade(&student2, -1);
    CU_ASSERT(student2.mean_grade == 3.5);
}

void edge_test_change_mean_grade(void) {
    Student student;
    student.mean_grade = 3.5;
    change_mean_grade(&student, 0);
    CU_ASSERT(student.mean_grade == 0);

    Student student2;
    student2.mean_grade = 3.5;
    change_mean_grade(&student2, 10);
    CU_ASSERT(student2.mean_grade == 10);
}

void positive_test_is_perfectionist(void) {
    Student student;
    student.mean_grade = 3.5;
    CU_ASSERT(is_perfectionist(&student) == 0);

    Student student2;
    student2.mean_grade = 9.6;
    CU_ASSERT(is_perfectionist(&student2) == 1);
}

void negative_test_is_perfectionist(void) {
    Student student;
    student.mean_grade = -3.5;
    CU_ASSERT(is_perfectionist(&student) == 0);

    Student student2;
    student2.mean_grade = 11.5;
    CU_ASSERT(is_perfectionist(&student2) == 0);
}

void edge_test_is_perfectionist(void) {
    Student student;
    student.mean_grade = 8.6;
    CU_ASSERT(is_perfectionist(&student) == 1);

    Student student2;
    student2.mean_grade = 8.5999;
    CU_ASSERT(is_perfectionist(&student2) == 0);
}

int main()
{
    CU_initialize_registry();

    CU_pSuite change_mean_grade_suite = CU_add_suite("ChangeMeanGradeTestSuite", 0, 0);
    CU_add_test(change_mean_grade_suite, "positive test of change_mean_grade()", positive_test_change_mean_grade);
    CU_add_test(change_mean_grade_suite, "negative test of change_mean_grade()", negative_test_change_mean_grade);
    CU_add_test(change_mean_grade_suite, "edge test of change_mean_grade()", edge_test_change_mean_grade);
    
    CU_pSuite is_perfectionist_suite = CU_add_suite("IsPerfectionistTestSuite", 0, 0);
    CU_add_test(is_perfectionist_suite, "positive test of is_perfectionist()", positive_test_is_perfectionist);
    CU_add_test(is_perfectionist_suite, "negative test of is_perfectionist()", negative_test_is_perfectionist);
    CU_add_test(is_perfectionist_suite, "edge test of is_perfectionist()", edge_test_is_perfectionist);
    
    CU_basic_run_tests();
    CU_cleanup_registry();
    return 0;
}