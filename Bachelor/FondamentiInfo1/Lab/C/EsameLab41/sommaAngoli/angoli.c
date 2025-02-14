#include "angoli.h"

struct angolo somma_angoli(struct angolo a, struct angolo b) {
	struct angolo s = { 0,0,0 };
	if (a.secondi + b.secondi >= 60) {
		s.secondi = a.secondi + b.secondi - 60;
		s.primi += 1;
	}
	else {
		s.secondi = a.secondi + b.secondi;
	}

	if (a.primi + b.primi >= 60) {
		s.primi += a.primi + b.primi - 60;
		s.gradi += 1;
	}
	else {
		s.primi += a.primi + b.primi;
	}

	if (a.gradi + b.gradi >= 360) {
		s.gradi += a.gradi + b.gradi - 360;
	}
	else {
		s.gradi += a.gradi + b.gradi;
	}
	return s;
}
