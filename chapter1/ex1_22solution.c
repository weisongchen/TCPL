#include <stdio.h>

#define MAXCOL 50                /* maximum column of input */
#define TABINC 8                 /* tab increment size      */

char line[MAXCOL];

/* function prototypes */
int exptab(int pos);
int findblank(int pos);
int newpos(int pos);
void printl(int pos);

/* fold long input lines into two or more shorter lines */
int main()
{
    int c, pos;

    pos = 0;                            /* position in the line     */
    while ((c = getchar()) != EOF) {
        line[pos] = c;                  /* store current character  */
        if (c == '\t')                  /* expand tab character     */
            pos = exptab(pos);
        else if (c == '\n') {
            printl(pos);                /* print current input line */
            pos = 0;
        }else if (++pos >= MAXCOL) {
            pos = findblank(pos);
            printl(pos);
            pos = newpos(pos);
        }
    }

    return 0;
}


/* printl: pirnt line until pos column  */
void printl(int pos) {
    int i;
    for (i = 0; i < pos; ++i)
        putchar(line[i]);
    if (pos > 0)
        putchar('\n');
}

/* exptab: expand tab into blanks  */
int exptab(int pos) {
    line[pos] = ' ';               /* tab is at least one blanks */
    for (++pos; pos < MAXCOL && pos % TABINC != 0; ++pos)
        line[pos] = ' ';
    if (pos < MAXCOL)              /* room left in current line */
        return pos;
    else {
        printl(pos);               /* current line is full */
        return 0;
    }
}

/* findblank: find blank's position */
int findblank(int pos) {
    while (pos > 0 && line[pos] != ' ')
        --pos;
    if (pos == 0)               /* no blanks in the line ?  */
        return MAXCOL;
    else                        /* at least one blank       */
        return pos + 1;         /* position after the blank */
}

/* newpos: rearrange line with new position */
int newpos(int pos) {
    int i, j;

    if (pos <= 0 || pos >= MAXCOL)
        return 0;               /* nothing to arrange       */
    else {
        i = 0;
        for (j = pos; i < MAXCOL; j++) {
            line[i] = line[j];
            i++;
        }
        return i;               /* new position in line    */
    }
}