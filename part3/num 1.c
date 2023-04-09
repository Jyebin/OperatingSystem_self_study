//
//  num 3.c
//  operatingSystem
//
//  Created by 조예빈 on 2023/04/09.
//

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int value = 5; //전역변수로 정수형 변수 value를 5로 초기화
int main(){
    pid_t pid; //pid 변수 선언
    pid = fork(); //fork() 함수를 통해 자식 프로세스 생성
    if (pid == 0){ //child process
        value += 15;
        return 0;
    }else if(pid > 0){ //parent process
        wait(NULL); //child process가 끝날 때 까지 기다림
        printf("PARENT: value = %d\n",value);
        return 0;
    }
}
