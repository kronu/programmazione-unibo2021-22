#include "base_conversion.h"
#include <stdio.h>

void base_conversion_rc(unsigned int n, unsigned int b) {
    // Basi esclusivamente tra 2 e 16, 0 è escluso
    if (b < 2 || b > 16 || n == 0) return;
    // Salvare il resto, che diventa una cifra del numero nella nuova base
    // e dividere il numero per la base
    int resto = n % b;
    n /= b;
    // Eseguendo la stampa dopo la ricorsione, le cifre verranno stampare in
    // ordine invertito
    base_conversion_rc(n, b);
    if (resto > 9) printf("%c", resto+55);
    else printf("%c", resto+48);
}

void base_conversion_it(unsigned int n, unsigned int b) {
    // Basi esclusivamente tra 2 e 16
    if (b < 2 || b > 16) return;
    int temp = n, temp2 = n;
    
    // Per convertire un numero in base 10 in qualsiasi altra base, esiste un 
    // metodo che consiste nel trovare il modulo del numero rispetto alla base
    // scelta (e segnarselo) per poi dividere il numero per la base scelta,
    // ripetendo queste due operazioni finché il numero è piccolo abbastanza
    // da poter appartenere alla base, diventando così la prima cifra. 
    // Aggiungendo a ritroso i moduli ottenuti in precedenza si ha così il 
    // numero completo.
    
    // Per trovare la prima cifra
    // Se il numero è troppo grande per essere nella base, dividilo per la base
    while (temp >= b) {
        temp /= b;
    }
    // Stampa con ASCII
    if (temp > 9) printf("%c", temp+55);
    else printf("%c", temp+48);
    
    // Per trovare tutte le altre cifre
    int temp3;
    // Andando a ritroso
    while (temp < n) {
        if (temp2 / b == temp) {
            // Ottengo e stampo il modulo (convertito in ASCII)
            temp3 = temp2 % b;
            if (temp3 > 9) printf("%c", temp3+55);
            else printf("%c", temp3+48);
            temp = temp2;
            temp2 = n;
        }
        else {
            temp2 /= b;
        }
    }
    
} 
