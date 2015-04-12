#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <pwd.h>
#include <fnmatch.h>
#include <dirent.h>
#include <glob.h>

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
#define AT __FILE__ ":" TOSTRING(__LINE__)

#define TRUE  1
#define FALSE 0

#define OK      1
#define ERRORS  0

#define ALIAS_DEF       1
#define CDHOME_DEF      2
#define CDPATH_DEF      3
#define UNALIAS_DEF     4
#define SETENV_DEF      5
#define PRINTENV_DEF    6
#define UNSETENV_DEF    7
#define ALIASPRINT_DEF  8

struct command {
  char **argv;
};

struct aliasStruct {
  char* name;
  char* word;
};

void  shell_init(void);

void  lineHeaderPath();
int   getCommand(void);
void  processCommand(void);
void  do_it(void);
void  execute_it(void);

void  unsetenv_function(char *text);
void  unalias_function (char *text);
void  setenv_function (char *text, char *text2);
void  alias_function(char *text, char *text2);
void  cd_home_function(void);
void  printenv_function(void);
void  cd_function(char *text);
void  alias_print_function(void);

void  yytextProcessor(char* text);
void  insertToWordTable (char *text);
void  processEnvironmentVariable(char* yyText);

int   getWords(void);

int   getAliasCount(void);

int   globerr(const char* path, int eerrno);
char* getDirectories(char *textmatch);
void  condenseSlashes(char* string);
void  quoteFunction(char* text);

char* tildeExpansion(char* text);
char* aliasResolve(char* string);
int   getAliasValue(char* aliasName, char* aliasValue);

void  condense(char* string, char toCondense);
void  resetGlobals(void);

void  execute(void);
void  cardsGoneWild(char* text, int position);
void  printWordArray();
char* fixText(char *orig, char *rep, char *with);
void  wordArrayAliasExpansion(char* text, int position);

char** wordArray; //words


char** z; //copied words
int wordCount; //number of words

// points to an array of strings called the `environment'.
extern char** environ; 

struct passwd* pwd; //contains result of getpwnam
char* myPath;
char* myHome;
int   savedOutput; //output channel
int   savedInput; //input channel
int   savedError; //error channel
int   addedWords;

int   builtin_type;

char* cdPath;
char* variable;
char* word;

// number of aliases
int   aliasCount; 

struct aliasStruct *aliases; 
struct command *commands; 

#endif
