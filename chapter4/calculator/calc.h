#if !defined(CALC)
#define CALC

#define MAXOP 100     /* max size of operand or operator */
#define NUMBER '0'    /* signal that a number was found  */
#define NAME   'n'    /* signal that a name was found    */


void push(double d);
double pop(void);
double top(void);
double getTop(void);
void printTop(void);
void duplicateTop(void);
void swapTop(void);
void clear(void);

int getop(char s[]);
void mathfnc(char s[]);

int getch(void);
void ungetch(int n);
void ungets(char s[]);

#endif