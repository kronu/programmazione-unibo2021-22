#include <stdlib.h>
#include <time.h>
#include "board.h"


/*
 * Fills the rows*cols board with num_mines random mines
 * leaving free the neighborhood of position i,j
 */
void random_board(int board[][GAME_COLS], unsigned int rows, unsigned int cols, unsigned int i, unsigned int j, unsigned int num_mines) {
    int count, iter, jter, x, y;
    // Settare tutte le caselle come UNKN_FREE
    for (iter = 0; iter < rows; iter++) {
        for (jter = 0; jter < cols; jter++) {
            board[iter][jter] = UNKN_FREE;
        }
    }
    // Mettere un numero num_mines di mine tra le caselle
    srand(time(NULL));
    for (count = 0; count < num_mines; count++) {
        do {
            x = rand() % rows;
            y = rand() % cols;
        } while (((x == i || x == i - 1 || x == i + 1) && (y == j || y == j - 1 || y == j + 1)) || (board[x][y] == UNKN_MINE));
        board[x][y] = UNKN_MINE;
    }
    return;
}


/*
* Flags/unflags the i,j position in the board. Returns
* - -1 if the position was flagged. Removes the flag
* -  0 if the position is already displyed
* -  1 if the position is not flagged and not already
*    displayed. Puts a flag in position i,j.
*/
int flag_board(int board[][GAME_COLS], unsigned int rows, unsigned int cols, unsigned int i, unsigned int j) {
    // Se flaggato, torna casella "coperta"
    if (board[i][j] == FLAG_FREE) {
        board[i][j] = UNKN_FREE;
        return -1;
    }
    else if (board[i][j] == FLAG_MINE) {
        board[i][j] = UNKN_MINE;
        return -1;
    }
    // Se "coperta", flagga
    else if (board[i][j] == UNKN_FREE) {
        board[i][j] = FLAG_FREE;
        return 1;
    }
    else if (board[i][j] == UNKN_MINE) {
        board[i][j] = FLAG_MINE;
        return 1;
    }
    // Se "scoperta", non fare nulla
    else {
        return 0;
    }
}


/*
* Displays position i,j in the board. Returns the number of
* displayed cells or -1 if i,j contains a mine.
*/
int display_board(int board[][GAME_COLS], unsigned int rows, unsigned int cols, unsigned int i, unsigned int j) {
    // Se clicca su mina nascosta, svela la mina e ritorna
    if (board[i][j] == UNKN_MINE) {
        board[i][j] = MINE;
        return -1;
    }
    // Se non mina, guarda quante ce ne sono attorno
    else if (board[i][j] == UNKN_FREE) {
        // Controlla ogni casella attorno per contare il numero di mine
        int iter_i = i + 2, iter_j = j + 2, reset_i = i, reset_j = j, copia_i, copia_j, mine = 0, pos_rivelate = 0;
        // Ogni casella clickata è una posizione rivelata
        pos_rivelate++;
        if (i != 0) i--;
        if (j != 0) j--;
        copia_i = i;
        copia_j = j;
        // Dalla più in alto a sinistra alla più in basso a destra
        for (i = copia_i; i < iter_i; i++) {
            if (i >= rows) break;
            for (j = copia_j; j < iter_j; j++) {
                if (j >= cols) continue;
                if (board[i][j] == UNKN_MINE || board[i][j] == FLAG_MINE) mine++;
            }
        }
        // Resetta i e j ai loro valori iniziali
        i = reset_i;
        j = reset_j;

        switch (mine) {
            // In caso non ci sono mine attorno, svela le caselle adiacenti
        case 0:
            board[i][j] = C0;
            // Guarda le caselle attorno
            int iter_i = i + 2, iter_j = j + 2, reset_i = i, reset_j = j, copia_i, copia_j, mine = 0;
            if (i != 0) i--;
            if (j != 0) j--;
            copia_i = i;
            copia_j = j;
            for (i = copia_i; i < iter_i; i++) {
                if (i >= rows) break;
                for (j = copia_j; j < iter_j; j++) {
                    if (j >= cols) continue;
                    // Svela ogni casella e aggiorna posizioni
                    pos_rivelate += display_board(board, rows, cols, i, j);
                }
            }
            i = reset_i;
            j = reset_j;
            break;

            // Se ci sono mine, contale e indicale sulla casella
        case 1: board[i][j] = C1; break;
        case 2: board[i][j] = C2; break;
        case 3: board[i][j] = C3; break;
        case 4: board[i][j] = C4; break;
        case 5: board[i][j] = C5; break;
        case 6: board[i][j] = C6; break;
        case 7: board[i][j] = C7; break;
        case 8: board[i][j] = C8; break;
        default: return 0;
        }
        return pos_rivelate;
    }
    // Se casella già mostrata o flaggata, interrompi
    else {
        return 0;
    }
}


/*
 * Expands all the free cells sourrounding  position i,j in
 * the board. Returns the number of expanded cells or -1 if
 * one contains a mine.
 */
int expand_board(int board[][GAME_COLS], unsigned int rows, unsigned int cols, unsigned int i, unsigned int j) {
    int pos_rivelate = 0;
    if (C0 < board[i][j] && board[i][j] < C8) {
        // Controllo attorno alla casella
        int iter_i = i + 2, iter_j = j + 2, reset_i = i, reset_j = j, copia_i, copia_j, bandiere = 0;
        if (i != 0) i--;
        if (j != 0) j--;
        copia_i = i;
        copia_j = j;
        for (i = copia_i; i < iter_i; i++) {
            if (i >= rows) break;
            for (j = copia_j; j < iter_j; j++) {
                if (j >= cols) continue;
                // Segnala bandiere
                if (board[i][j] == FLAG_FREE || board[i][j] == FLAG_MINE) bandiere++;
            }
        }
        i = reset_i;
        j = reset_j;

        // Controlla se le bandiere sono anche mine
        if (board[i][j] == bandiere) {
            if (i != 0) i--;
            if (j != 0) j--;
            copia_i = i;
            copia_j = j;
            for (i = copia_i; i < iter_i; i++) {
                if (i >= rows) break;
                for (j = copia_j; j < iter_j; j++) {
                    if (j >= cols) continue;
                    // Se mina non segnalata, esplodi
                    if (board[i][j] == UNKN_MINE) return -1;
                    // Se tutto ok, ritorna numero posizioni rivelate
                    if (board[i][j] == UNKN_FREE) pos_rivelate += display_board(board, rows, cols, i, j);
                }
            }
            i = reset_i;
            j = reset_j;
        }
    }
    return pos_rivelate;
}