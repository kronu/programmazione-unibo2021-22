#include "game.h"

// Variabili fornite da main.c o da inizializzare
static int h, w, racc_lung, racc1_punti, racc2_punti, orig_x, orig_y;
// Strutture fornite da main.c da aggiornare
static struct s {
	int y;
	int x;
} palla_pos, palla_dir, racc1_pos, racc2_pos;

// Setup (valori forniti da main.c)
void setup_game(int height, int width, struct position ball_pos, struct position ball_dir, struct position pad1_pos,
	struct position pad2_pos, int pad_len) {
	w = width;
	h = height;
	orig_x = ball_pos.x;
	orig_y = ball_pos.y;
	palla_pos.x = ball_pos.x;
	palla_pos.y = ball_pos.y;
	palla_dir.x = ball_dir.x;
	palla_dir.y = ball_dir.y;
	racc1_pos.x = pad1_pos.x;
	racc1_pos.y = pad1_pos.y;
	racc2_pos.x = pad2_pos.x;
	racc2_pos.y = pad2_pos.y;
	racc_lung = pad_len;
	racc1_punti = 0;
	racc2_punti = 0;
	return;
}

void move_ball(void) {
	// Se palla tocca il lato sinistro, racc2 segna un punto e si riparte
	if (palla_pos.x == 0) {
		racc2_punti++;
		palla_pos.x = orig_x;
		palla_pos.y = orig_y;
		return;
	}
	// Se palla tocca lato destro, racc1 segna un punto e si riparte
	if (palla_pos.x == w - 1) {
		racc1_punti++;
		palla_pos.x = orig_x;
		palla_pos.y = orig_y;
		return;
	}
	// Se palla tocca il soffitto, si abbassa
	if (palla_pos.y == 0) palla_dir.y = 1;
	// Se palla tocca il pavimento, si alza
	if (palla_pos.y == h) palla_dir.y = -1;
	// Se palla tocca racchetta 1, cambia direzione a destra
	if ((((palla_pos.x == racc1_pos.x) || (palla_pos.x == racc1_pos.x - 1) || (palla_pos.x == racc1_pos.x + 1)) && (palla_pos.y == racc1_pos.y - 1)) ||
		(((palla_pos.x == racc1_pos.x) || (palla_pos.x == racc1_pos.x - 1) || (palla_pos.x == racc1_pos.x + 1)) && (palla_pos.y == racc1_pos.y + racc_lung)) ||
		((palla_pos.y >= racc1_pos.y) && (palla_pos.x == racc1_pos.x + 1) && (palla_pos.y <= racc1_pos.y + racc_lung - 1))) {
		palla_dir.x = 1;
	}
	// Se palla tocca racchetta 2, cambia direzione a sinistra
	if ((((palla_pos.x == racc2_pos.x) || (palla_pos.x == racc2_pos.x - 1) || (palla_pos.x == racc2_pos.x - 2)) && (palla_pos.y == racc2_pos.y - 1)) ||
		(((palla_pos.x == racc2_pos.x) || (palla_pos.x == racc2_pos.x - 1) || (palla_pos.x == racc2_pos.x - 2)) && (palla_pos.y == racc2_pos.y + racc_lung)) ||
		((palla_pos.y >= racc2_pos.y) && (palla_pos.x == racc2_pos.x - 2) && (palla_pos.y <= racc2_pos.y + racc_lung - 1))) {
		palla_dir.x = -1;
	}
	// Se palla tocca un bordo superiore, palla "rimbalza" verso l'alto
	if ((((palla_pos.x == racc1_pos.x) || (palla_pos.x == racc1_pos.x - 1) || (palla_pos.x == racc1_pos.x + 1)) && (palla_pos.y == racc1_pos.y - 1)) ||
		(((palla_pos.x == racc2_pos.x) || (palla_pos.x == racc2_pos.x - 1) || (palla_pos.x == racc2_pos.x - 2)) && (palla_pos.y == racc2_pos.y - 1))) {
		palla_dir.y = -1;
	}
	// Se palla tocca un bordo inferiore, palla "rimbalza" verso il basso
	if ((((palla_pos.x == racc1_pos.x) || (palla_pos.x == racc1_pos.x - 1) || (palla_pos.x == racc1_pos.x + 1)) && (palla_pos.y == racc1_pos.y + racc_lung)) ||
		(((palla_pos.x == racc2_pos.x) || (palla_pos.x == racc2_pos.x - 1) || (palla_pos.x == racc2_pos.x - 2)) && (palla_pos.y == racc2_pos.y + racc_lung))) {
		palla_dir.y = 1;
	}
	// Aggiorna posizione della palla
	palla_pos.x = palla_pos.x + palla_dir.x;
	palla_pos.y = palla_pos.y + palla_dir.y;
	return;
}

void move_pad1_up(void) {
	// Se la prima racchetta non tocca né il soffitto né la palla superiormente, alza la racchetta di un'unità
	if (racc1_pos.y > 0) {
		if ((palla_pos.x != racc1_pos.x - 1) && (palla_pos.x != racc1_pos.x) && (palla_pos.x != racc1_pos.x + 1)) {
			racc1_pos.y--;
		}
		else {
			if ((palla_pos.y != racc1_pos.y - 1) && (palla_pos.y != racc1_pos.y + 1)) {
				racc1_pos.y--;
			}
		}
		return;

	}
	return;
}

void move_pad2_up(void) {
	// Se la seconda racchetta non tocca né il soffitto né la palla superiormente, alza la racchetta di un'unità
	if (racc2_pos.y > 0) {
		if ((palla_pos.x != racc2_pos.x - 1) && (palla_pos.x != racc2_pos.x) && (palla_pos.x != racc2_pos.x - 2)) {
			racc2_pos.y--;
		}
		else {
			if ((palla_pos.y != racc2_pos.y - 1) && (palla_pos.y != racc2_pos.y + 1)) {
				racc2_pos.y--;
			}
		}
		return;

	}
	return;
}

void move_pad1_down(void) {
	// Se la prima racchetta non tocca né il pavimento né la palla inferiormente, abbassa la racchetta di un'unità
	if (h > racc1_pos.y + racc_lung - 1) {
		if ((palla_pos.x != racc1_pos.x) && (palla_pos.x != racc1_pos.x - 1) && (palla_pos.x != racc1_pos.x + 1)) {
			racc1_pos.y++;
		}
		else {
			if (palla_pos.y != racc1_pos.y + racc_lung) {
				racc1_pos.y++;
			}
		}
		return;
	}
	return;
}

void move_pad2_down(void) {
	// Se la seconda racchetta non tocca né il pavimento né la palla inferiormente, abbassa la racchetta di un'unità
	if (h > racc2_pos.y + racc_lung - 1) {
		if ((palla_pos.x != racc2_pos.x) && (palla_pos.x != racc2_pos.x - 1) && (palla_pos.x != racc2_pos.x - 2)) {
			racc2_pos.y++;
		}
		else {
			if (palla_pos.y != racc2_pos.y + racc_lung) {
				racc2_pos.y++;
			}
		}
		return;
	}
	return;
}

// Ritorna la posizione della palla
struct position get_ball_pos(void) {
	struct position p;
	p.x = palla_pos.x;
	p.y = palla_pos.y;
	return p;
}

// Ritorna la posizione della prima racchetta
struct position get_pad1_pos(void) {
	struct position p;
	p.x = racc1_pos.x;
	p.y = racc1_pos.y;
	return p;
}

// Ritorna la posizione della seconda racchetta
struct position get_pad2_pos(void) {
	struct position p;
	p.x = racc2_pos.x;
	p.y = racc2_pos.y;
	return p;
}

// Ritorna il punteggio della prima racchetta
unsigned int get_pad1_score(void) {
	return racc1_punti;
}

// Ritorna il punteggio della seconda racchetta
unsigned int get_pad2_score(void) {
	return racc2_punti;
}

// Ritorna la lunghezza della racchetta
unsigned int get_pad_len(void) {
	return racc_lung;
}