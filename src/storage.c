#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXDATA 1000
#define MAXLINE 100

static double numbers[MAXDATA];
static double *pos = numbers; /* next free position */

void initdata(int n)
{
     char line[MAXLINE];
     if (numbers + MAXDATA - pos < n) {
	  /* not enough space left */
	  fprintf(stderr, "not enough space for initdata\n");
	  return;
     }

     while (n--) {
	  if (fgets(line, MAXLINE, stdin) == NULL) {
	       /* KLUDGE: because fgets doesn't like \0's. */
	       /* should perhaps be a while loop instead of an if */
	       freopen(NULL, "r", stdin);
	       fgets(line, MAXLINE, stdin);
	  }
	  *pos++ = atof(line);
     }
}

void stddev()
{
     double avg, var;
     avg = var = 0;

     int i;
     for (i=0; numbers+i != pos; i++)
	  avg += numbers[i];
     avg /=  i;

     printf("average is %g\n", avg);
     while (i--)
	  var += pow(numbers[i] - avg, 2);

     printf("Standard deviation is %g\n", sqrt(var));
}

void printstate()
{
     printf("Currently storing the following data:\n");

     int i;
     for (i=0; numbers+i != pos; i++)
	  printf("%f\n", numbers[i]);
}
