#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../src/course.c"
#include "../src/student.c"

void positive_test_add_student(void) {
    Course course;
    course.title = "Test course";
    course.students_amount = 0;
    course.students_array = malloc(10 * sizeof(Student));

    Student student0;
    int id0 = add_student(&course, &student0);

    CU_ASSERT(id0 == 0);

    Student student1;
    int id1 = add_student(&course, &student1);

    CU_ASSERT(id1 == 1);

    free(course.students_array);
}

void negative_test_add_student(void) {
    Course course;
    course.title = "Test course";
    course.students_amount = 0;
    course.students_array = malloc(10 * sizeof(Student));

    for (int i = 0; i < 20; i++) {
        Student student;
        strcpy(student.name, "John Doe");
        student.age = i;
        student.mean_grade = 8.5;
        int id = add_student(&course, &student);
        CU_ASSERT(id == i);
    }

    CU_ASSERT(course.students_amount == 20);

    free(course.students_array);
}

void edge_test_add_student(void) {
    Course course;
    course.title = "Test course";
    course.students_amount = 0;
    course.students_array = malloc(10 * sizeof(Student));

    for (int i = 0; i < 10; i++) {
        Student student;
        strcpy(student.name, "John Doe");
        student.age = i;
        student.mean_grade = 8.5;
        int id = add_student(&course, &student);
        CU_ASSERT(id == i);
    }

    CU_ASSERT(course.students_amount == 10);

    free(course.students_array);
}

void positive_test_find_best_student(void) {
    Course course;
    course.title = "Test course";
    course.students_amount = 0;
    course.students_array = malloc(10 * sizeof(Student));

    Student student0;
    strcpy(student0.name, "Daniel");
    student0.mean_grade = 8.5;

    Student student1;
    strcpy(student1.name, "Cooler Daniel");
    student1.mean_grade = 9.5;

    add_student(&course, &student0);
    add_student(&course, &student1);

    Student *best_student = find_best_student(&course);
    CU_ASSERT(best_student->mean_grade == 9.5);
    CU_ASSERT(strcmp(best_student->name, "Cooler Daniel") == 0);

    free(course.students_array);
}

void negative_test_find_best_student(void) {
    Course course;
    course.title = "Test course";
    course.students_amount = 0;
    course.students_array = malloc(10 * sizeof(Student));

    Student student0;
    strcpy(student0.name, "Cool Daniel");
    student0.mean_grade = 8.5;

    Student student1;
    strcpy(student1.name, "Bad Daniel");
    student1.mean_grade = -8.5;

    add_student(&course, &student0);
    add_student(&course, &student1);

    Student *best_student = find_best_student(&course);
    CU_ASSERT(best_student->mean_grade == 8.5);
    CU_ASSERT(strcmp(best_student->name, "Cool Daniel") == 0);

    free(course.students_array);
}

void edge_test_find_best_student(void) {
    Course course;
    course.title = "Test course";
    course.students_amount = 0;
    course.students_array = malloc(10 * sizeof(Student));

    Student student0;
    strcpy(student0.name, "Cool Daniel1");
    student0.mean_grade = 8.5;

    Student student1;
    strcpy(student1.name, "Cool Daniel2");
    student1.mean_grade = 8.5;

    add_student(&course, &student0);
    add_student(&course, &student1);

    Student *best_student = find_best_student(&course);
    CU_ASSERT(best_student->mean_grade == 8.5);
    CU_ASSERT(strcmp(best_student->name, "Cool Daniel1") == 0);

    free(course.students_array);
}

int main()
{
    CU_initialize_registry();

    CU_pSuite add_student_suite = CU_add_suite("AddStudentTestSuite", 0, 0);
    CU_add_test(add_student_suite, "positive test of add_student()", positive_test_add_student);
    CU_add_test(add_student_suite, "negative test of add_student()", negative_test_add_student);
    CU_add_test(add_student_suite, "edge test of add_student()", edge_test_add_student);
    
    CU_pSuite find_best_student_suite = CU_add_suite("FindBestStudentTestSuite", 0, 0);
    CU_add_test(find_best_student_suite, "positive test of find_best_student()", positive_test_find_best_student);
    CU_add_test(find_best_student_suite, "negative test of find_best_student()", negative_test_find_best_student);
    CU_add_test(find_best_student_suite, "edge test of find_best_student()", edge_test_find_best_student);
    
    CU_basic_run_tests();
    CU_cleanup_registry();
    return 0;
}