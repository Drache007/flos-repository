#include <stdio.h>
#include <string.h>

int main () {
    char *s = NULL;
    size_t size = 0;
    
    getline(&s, &size, stdin);

    printf("%s", s);
    return 0;
}