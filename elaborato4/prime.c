#include "prime.h"

static int count = 0;

unsigned short int is_prime(unsigned short int n) {
    // 0 e 1 non sono numeri primi
    if (n == 0 || n == 1) {
        return 0;
    }
    // Dividi n per ogni numero più piccolo della sua metà
    int i, half = n / 2;
    for (i = 2; i <= half; i++) {
        if (n % i == 0) {
            return  0;
        }
    }
    return 1;
}


unsigned short int nth_prime(unsigned short int n) {
    int j, temp = -1;
    // Controlla fino a USHRT_MAX
    for (j = 2; j < 65535; j++) {
        // Per ogni primo la potenza raggiunta aumenta di uno
        if (is_prime(j)) {
            temp++;
            if (temp == n) {
                return j;
            }
        }
    }
    return 0;
}


unsigned short int succ_prime(int reset) {
    // Reset 
    if (reset != 0) count = 0;
    // Il prossimo numero primo è restituito
    while (count <= 65535) {
        count++;
        if (is_prime(count)) return count;
    }
    count = 0;
}


unsigned short int co_prime(unsigned short int m, unsigned short int n) {
    // 0 e 0 non sono coprimi
    if (m == 0 && n == 0) return 0;
    // Prendi il maggiore tra i due numeri
    int i, test;
    if (m >= n) test = m;
    else test = n;
    // Se divisi da qualsiasi numero dopo l'1 non hanno resto allora non sono coprimi
    for (i = 1; i <= test; i++) {
        if (m % i == 0 && n % i == 0) {
            if (i == 1) continue;
            else return 0;
        }
    }
	return 1;
}
