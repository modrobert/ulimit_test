#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>

int main() {
 struct rlimit rl;
 unsigned long int of_max = 10000;

 /* Get open file limits. */
 getrlimit(RLIMIT_NOFILE, &rl);

 /* Check before change. */
 printf("Open files soft limit: %lu\n", rl.rlim_cur);
 printf("Open files hard limit: %lu\n", rl.rlim_max);

 /* Adjusting max open files limit according to of_max. */
 if (rl.rlim_cur < of_max) {

  /* Hard limit breached. */
  if (of_max > rl.rlim_max) {
   fprintf(stderr, "The max number of open files is: %lu\n", rl.rlim_max);
   fprintf(stderr, "Run 'ulimit -n %lu' command.\n", of_max);
   exit(9);
  }

  /* Set new soft limit. */
  rl.rlim_cur = of_max;
  setrlimit (RLIMIT_NOFILE, &rl);
  printf("Max open files for this process set to: %lu\n", of_max);

  /* Check after change. */
  printf("Open files soft limit: %lu\n", rl.rlim_cur);
  printf("Open files hard limit: %lu\n", rl.rlim_max);
 }

 return 0;
}
