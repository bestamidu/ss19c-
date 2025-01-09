#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 5

struct hocsinh {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
};
void nhaphs( struct  hocsinh students[], int *currentLength) {
          students[0] = (struct hocsinh) {1, "embedays", 20, "0123456789"};
          students[1] = (struct hocsinh) {2, "babyboo", 21, "0987654321"};
          students[2] = (struct hocsinh) {3, "haitu", 22, "0123987654"};
          students[3] = (struct hocsinh) {4, "co be toc do", 19, "0987123456"};
          students[4] = (struct hocsinh) {5, "ozawa", 23, "0912345678"};
    *currentLength = 5;
}

void printStudents(struct  hocsinh students[], int currentLength) {
    printf("Dds sv htai:\n");
    for (int i = 0; i < currentLength; i++) {
        printf("%d ,%s, %d ,%s ",students[i].id,students[i].name,students[i].age,students[i].phoneNumber);
    }
}

void deleteStudentById(int id,struct hocsinh students[], int *currentLength) {
    int found = 0;
    for (int i = 0; i < *currentLength; i++) {
        if (students[i].id == id) {
            found = 1;
            for (int j = i; j < *currentLength - 1; j++) {
                students[j] = students[j + 1];
            }
            (*currentLength)--;
            break;
        }
    }
    if (!found) {
        printf("khong thya id", id);
    }
}

int main() {
   struct  hocsinh students[MAX_STUDENTS];
    int currentLength = 0;

   nhaphs(students, &currentLength);
    printStudents(students, currentLength);

    int idToDelete;
    printf("Nhap id sv : ");
    scanf("%d", &idToDelete);

    deleteStudentById(idToDelete, students, &currentLength);
    printStudents(students, currentLength);

    return 0;
}
