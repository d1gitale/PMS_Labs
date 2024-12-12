#ifndef STUDENT_H
#define STUDENT_H

typedef struct {
    char* name;
    uint8_t age;
    uint8_t mean_grade;
} Student;

void change_mean_grade(Student *student);

int is_perfectionist(Student *student);

#endif