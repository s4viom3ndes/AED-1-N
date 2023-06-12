#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N); 
    
    while (N > 0) {
        int L;
        scanf("%d", &L);  
        int i, j, k, valor, hash = 0;
        char entrada[50];
        
        for (i = 0; i < L; i++) {
            scanf("%s", entrada);  
            
            for (j = 0; entrada[j] != '\0'; j++) {
                valor = (entrada[j] - 'A') + i + j; 
                hash += valor;  
            }
        }
        
        printf("%d\n", hash); 
        N--; 
    }
    
    return 0;
}
