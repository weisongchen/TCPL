int getLine(char *s, int len);

void strCat(char *s, char *t);
void strNcat(char *s, char *t, int n);

void strCpy(char *s, char *t);
void strNcpy(char *s, char *t, int n);

int strCmp(char *s, char *t);
int strNcmp(char *s, char *t, int n);

int strEnd(char *s, char *t);

int strLen(char *s);

void swap(char *v[], int i, int j);

char *alloc(int n);
void afree(char *p);