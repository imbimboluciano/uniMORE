#include "cerchio.h"

bool nel_cerchio(const struct punto* p, const struct cerchio* c) {
	if (p == NULL || c == NULL)	return false;

	int distanza = pow(p->x - c->x, 2) + pow(p->y - c->y, 2);
	distanza = sqrt(distanza);

	if (distanza <= c->r)	return true;
	else   return false;

}