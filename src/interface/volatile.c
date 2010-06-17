#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>

#define MAXLINE 100

char *getcmd(char *line, char **args);
int execcmd(char *cmd, char **args);
void initdata(int n);
void stddev();
void printstate();

int main(int argc, char *argv[])
{
     
     char line[MAXLINE], *cmd, *args[MAXLINE];

     while (1){
	  if (fgets(line, MAXLINE, stdin) == NULL) {
	       freopen(NULL, "r", stdin);
	  }
	  else if (!strcmp(line, "\\quit\n"))
	       break;
	  else if ((cmd = getcmd(line, args)) != NULL) {
	       execcmd(cmd, args);
	  }
	  else {
	       printf("Error, commands start with \\\n");
	  }
     }
     
     return 0;
}

char *getcmd(char *line, char **args)
{
     char *cmd;

     if (*line == '\\') {
	  ++line;
	  char *save = line;
	  while (!isblank(*line) && *line != '\n')
	       ++line;
	  *line++ = '\0';
	  cmd = save;
	  
	  while (*line != '\n' && *line != '\0') {
	       while (isblank(*line))
		    ++line;
	       save = line;
	       while (!isblank(*line) && *line != '\n')
		    ++line;
	       *line++ = '\0';
	       *args++ = save;
	  }
	  *args = '\0';
	  return cmd;
     }
     else
	  return NULL;
}

int execcmd(char *cmd, char **args)
{
     if (!strcmp(cmd, "initdata"))
	  initdata(atoi(args[0]));
     else if (!strcmp(cmd, "stddev"))
	  stddev();
     else if (!strcmp(cmd, "printstate"))
	  printstate();
     else
	  fprintf(stderr, "invalid command to execcmd\n");
}


	  
