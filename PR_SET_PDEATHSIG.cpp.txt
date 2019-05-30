 #include <stdlib.h>                                 
 #include <unistd.h>                                 
 #include <signal.h>                                 
 #include <sys/prctl.h>                               
 #include <err.h>                                  
                                           
 void sigusr1_handler(int dummy)                           
 {                                          
     printf("Parent died, child now exiting\n");                 
     exit(0);                                  
 }                                          
                                           
 int main()                                     
 {                                          
     pid_t pid;                                 
                                           
     pid = fork();                                
     if (pid < 0)                                
         err(1, "fork failed");                       
     if (pid == 0) {                               
         /* Child */                             
         if (signal(SIGUSR1, sigusr1_handler) == SIG_ERR)          
             err(1, "signal failed");                  
         if (prctl(PR_SET_PDEATHSIG, SIGUSR1) < 0)              
             err(1, "prctl failed");                   
                                           
         for (;;)                              
             sleep(60);                         
     }                                      
     if (pid > 0) {                               
         /* Parent */                            
         sleep(5);                              
         printf("Parent exiting...\n");                   
     }                                      
                                           
     return 0;                                  
 } 