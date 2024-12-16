#include "student.h"
#include "course.h"
#include <stdlib.h>

int add_student(Course *course, Student *student) {
    if (course->students_amount == 10) {
        course->students_array = realloc(course->students_array, (course->students_amount + 10) * sizeof(Student));

        if (course->students_array == NULL) {
            return 1;
        }
    }
    
    course->students_array[course->students_amount++] = *student;
    return course->students_amount;
}

Student* find_best_student(Course *course) {
    Student *best_student = &course->students_array[0];
    for (int i = 1; i < course->students_amount; ++i) {
        if (best_student->mean_grade < course->students_array[i].mean_grade) {
            best_student = &course->students_array[i];
        }
    }
    return best_student;
}