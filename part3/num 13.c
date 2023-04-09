//
//  num 13.c
//  operatingSystem
//
//  Created by 조예빈 on 2023/04/09.
//

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    pid_t pid, pid1; //프로세스 ID를 저장할 변수 선언
    pid = fork(); //fork a child process. 생성된 자식 프로세스 ID를 pid에 저장
    if(pid < 0){ //error occurred
        fprintf(stderr, "Fork Failed");
        return 1; //pid 변수가 음수인 경우 오류 메세지를 출력한 후 프로그램 종료
    }else if(pid == 0){ //child process인 경우
        printf("child: pid = %d\n",pid); //A. 자식 프로세스의 ID 출력
        printf("child: pid1 = %d\n",pid1); //B. 초기화 된 값이 아니기 때문에 쓰레기 값 출력
    }else{ //parent process인 경우
        pid1 = getpid(); //현재 프로세스의 ID를 pid1에 저장
        printf("parent: pid = %d\n",pid); //C. 부모 프로세스의 ID를 출력
        printf("parent: pid1 = %d\n",pid1); //D. 부모 프로세스의 ID를 출력.
        wait(NULL); //자식 프로세스가 끝날 때 까지 대기
    }
    return 0;
}
