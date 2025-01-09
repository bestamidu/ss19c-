#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STUDENTS 100

struct hocsinh {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
};
void printStudents(  struct hocsinh students[],int n ){
	for(int i=0 ; i<n ; i++){
		printf("id: %d, ten :%s ,Tuoi :%d,sdt : %s ",students[i].id,students[i].name,students[i].age,students[i].phoneNumber);
	}
}
void  addStudent( struct hocsinh students[],int n){
}


int main() {
    struct hocsinh students[MAX_STUDENTS];
    int currentLength = 0;
    int choice;
    
    do {
        printf("\nMENU\n");
        printf("1.show list\n");
        printf("2.them sinh vien\n");
        printf("3. sua tt svien\n");
        printf("4. xoa sv\n");
        printf("5. tim kiem sv\n");
        printf("6. sxeep dsach sv\n");
        printf("7. thoat\n");
        printf("nhap lua chon cua ban ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printStudents(students, currentLength);
                break;
            case 2:
                addStudent(students, &currentLength);
                break;
            case 3:
                updateStudent(students, currentLength);
                break;
            case 4:
                {
                    int id;
                    printf("Nhập ID của sinh viên cần xóa: ");
                    scanf("%d", &id);
                    deleteStudentById(id, students, &currentLength);
                }
                break;
            case 5:
                searchStudent(students, currentLength);
                break;
            case 6:
                sortStudentsByName(students, currentLength);
                printStudents(students, currentLength);
                break;
            case 7:
                printf("Thoát chương trình.\n");
                break;
            default:
                printf("Lựa chọn không hợp lệ! Vui lòng chọn lại.\n");
        }
    } while (choice != 7);

    return 0;
}
