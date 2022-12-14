// init: The initial user-level program

#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

char *argv[] = { "sh", 0 };
char *arg[] = { "print_trace", 0 };

int
main(void)
{
  int pid, wpid;
  if(open("console", O_RDWR) < 0){
    mknod("console", 1, 1);
    open("console", O_RDWR);
  }
  dup(0);  // stdout
  dup(0);  // stderr

  for(;;){
    if (fork() == 0)
    {
      exec("print_trace", arg);

    }
    else
    {
      printf(1, "init: starting sh\n");
      printf(1, "init: starting sh\n");
      printf(1, "***********************************\n");
      printf(1, "Group Members:\n");
      printf(1, "1- Melika Morafegh\n");
      printf(1, "2- Nazanin Yousefian\n");
      printf(1, "3- Hamidreza Khodadadi\n");
      printf(1, "***********************************\n");
      
      pid = fork();
      if(pid < 0){
        printf(1, "init: fork failed\n");
        exit();
      }
      if(pid == 0){
        exec("sh", argv);
        printf(1, "init: exec sh failed\n");
        exit();
      }
     
      while((wpid=wait()) >= 0 && wpid != pid)// && wpid != poo)
        printf(1, "zombie!\n");
    }
  }
}