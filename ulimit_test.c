/* 
 ulimit_test - Example C program to set soft open files limit (ulimit).
 Copyright (C) 2021 by Robert <modrobert@gmail.com>

 Permission to use, copy, modify, and/or distribute this software for any
 purpose with or without fee is hereby granted.

 THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
 REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
 AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
 INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
 LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
 OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 PERFORMANCE OF THIS SOFTWARE.
*/

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
