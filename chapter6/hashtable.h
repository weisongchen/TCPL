#ifndef _hashtable_h
#define _hashtable_h

#define HASHSIZE 101

struct nlist {
    struct nlist *next;
    char *name;
    char *defn;
};

unsigned hash(char *s);
struct nlist *lookup(char *s);
struct nlist *install(char *name, char *defn);
void undef(char *name);
void freenlist(struct nlist *p);
void printHashtab(void);

#endif