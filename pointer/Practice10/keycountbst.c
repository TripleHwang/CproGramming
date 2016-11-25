#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100

struct tnode {
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *);
struct tnode *sorttree(struct tnode *);
void treeprint(struct tnode *);
int getword(char *, int);

char *blacklist[] = { "a", "the", "is" ,"was", "are", "were", "have", "had", "they", "you", "your", "it", "don't", "of", "in", "with", "that", "witch" };

/* word frequency count */
int main() {
	struct tnode *root;
	char word[MAXWORD];
	int is_blacklist = 0;

	root = NULL;
	while (getword(word, MAXWORD) != EOF) {
		is_blacklist = 0;
		for (int i = 0; i < 18 && !is_blacklist; i++) {
			is_blacklist = !strcmp(blacklist[i], word);
		}
		if (isalpha(word[0]) && !is_blacklist)
		{
			root = addtree(root, word);
		}
	}
	treeprint(root);
	return 0;
}

struct tnode *talloc(void);
char *mystrdup(char *);

/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w) {
   int cond;

   if (p == NULL) {
      p = talloc();
      p->word = strdup(w);
      p->count = 1;
      p->left = p->right = NULL;
   }
   else if ((cond = strcmp(w, p->word)) == 0)
      p->count++;
   else if (cond < 0)
      p->left = addtree(p->left, w);
   else
      p->right = addtree(p->right, w);
   return p;
}

struct tnode *sorttree(struct tnode *p){
	if(p != NULL)
		sorttree(p->left);
	if((p->right->count) > (p->count)){
		struct tnode temp;
		temp = p->right;
		p->right = p;
		p = temp;
		sorttree(p);
	}
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p) {
	if (p != NULL) {
		if(p->count > 1){
     		treeprint(p->left);
      		printf("%4d %s\n", p->count, p->word);
      		treeprint(p->right);
      	}
    }
}

#include <stdlib.h>

/* talloc: make a tnode */
struct tnode *talloc(void) {
   return (struct tnode *) malloc(sizeof(struct tnode));
}

/* strdup: make a duplicate of s */
char *mystrdup(char *s) {
   char *p;

   p = (char *) malloc(strlen(s)+1); /* +1 for '\0' */
   if (p != NULL)
      strcpy(p, s);
   return p;
}

#define BUFSIZE  100

static char buf[BUFSIZE];   /* buffer for ungetch */
static int bufp = 0;        /* bext free position in buf */

int getch(void) {    /* get a (possibly pushed back) character */
   return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {   /* push character back on input */
   if (bufp >= BUFSIZE)
      printf("ungetch: too many characters\n");
   else
      buf[bufp++] = c;
}

int getword(char *word, int lim) {
   int c, getch(void);
   void ungetch(int);
   char *w = word;

   while (isspace(c = getch())){
   	if('A' < c && c < 'Z'){
   		c += 32;
   	}
   }
   if (c != EOF)
      *w++ = c;
   if (!isalpha(c)) {
      *w = '\0';
      return c;
   }
   for ( ; --lim > 0; w++)
      if (!isalnum(*w = getch())) {
         ungetch(*w);
         break;
      }
   *w = '\0';
   return word[0];
}








