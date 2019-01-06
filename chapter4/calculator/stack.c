#include <stdio.h>

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}


double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty!\n");
        return 0.0;
    }
}


/* get the top value without poping it from stack */
double getTop(void) {
    if (sp > 0) {
        return val[sp - 1];
    } else {
        printf("error: stack empty!\n");
        return 0.0;
    }
}

/* print top value without poping it */
void printTop(void) {
    if (sp > 0)
        printf("top value is %g\n", val[sp - 1]);
    else
        printf("error: stack empty!\n");
}

void duplicateTop(void) {
    if (sp > 0)
        push(val[sp - 1]);
    else
        printf("error: stack empty!\n");
}

/* swap two top value on the stack */
void swapTop(void) {
    if (sp <= 1)
        printf("error: not enough value!\n");
    else {
        double p1, p2;
        p1 = pop();
        p2 = pop();
        push(p1);
        push(p2);
    }
}

/* delete all element on the stack */
void clear(void) {
    sp = 0;
}