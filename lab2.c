#include <stdio.h>
#include <string.h>

int main() {
    char s[] = "nobody noticed him at virat";  
    char pattern[] = "virat";  
    int i, j, n, m;

    n = strlen(s); 
    m = strlen(pattern); 

 
    for (i = 0; i <= n - m; i++) {
        j = 0;  
        while (j < m && s[i + j] == pattern[j]) {
            j++;
        }
        

        if (j == m) {
            printf("Pattern found at index %d\n", i);
            return 0;  
        }
    }

    printf("Pattern not found\n");
    return 0;
}
