#include <ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[]){
        int i, c;
        while ((s[0] = c = getch()) == ' ' || c == '\t')
                ;
        s[1] = '\0';
        if(!isdigit(c) && c != '.')
                return c; //not a num
        i = 0;
        if(isdigit(c)) //collect int part
                while(isdigit(s[++i] = c = getch ()))
                        ;
        if(c == '.') //collect fract
                while(isdigit(s[++i] = c = getch()))
                        ;
        s[i] = '\0';
        if(c != EOF)
                ungetch(c);
        return NUMBER;
}
