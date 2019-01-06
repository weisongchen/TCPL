#ifndef _getch_h
#define _getch_h

int getch(void);
void ungetch(int c);
void ungets(char s[]);

#endif