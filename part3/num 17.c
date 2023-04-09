//
//  num 17.c
//  operatingSystem
//
//  Created by 조예빈 on 2023/04/09.
//

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

#define SIZE 5
int nums[SIZE] = {0,1,2,3,4};
int main(){
    int i;
    pid_t pid;
    pid = fork(); //자식 프로세스 생성
    if(pid == 0){ //pid의 값이 0이면 자식 프로세스임
        for(i=0;i<SIZE;i++){
            nums[i] *= -i; //자식 프로세스면 -i를 곱하여 배열에 저장
            printf("CHILD: %d",nums[i]); //LINE X
        }
    }else if(pid > 0){
        wait(NULL);
        for(i=0;i<SIZE;i++){
            printf("PARENT: %d",nums[i]); //LIKE Y
        }
    }
    return 0;
}
