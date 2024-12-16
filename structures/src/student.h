#ifndef STUDENT_H
#define STUDENT_H

typedef struct {
    char* name;
    uint8_t age;
    double mean_grade;
} Student;

void change_mean_grade(Student *student, double grade);

int is_perfectionist(Student *student);

#endif