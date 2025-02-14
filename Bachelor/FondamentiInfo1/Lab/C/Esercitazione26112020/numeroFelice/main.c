/* Esercizio 8
Nel file felici.c implementare la definizione della funzione:
extern int felice(unsigned int num);
La funzione prende come input il valore num e ritorna 1 se il numero è felice, 0 se è infelice.
Un numero felice è definito tramite il seguente processo: partendo con un qualsiasi numero intero positivo, si sostituisca il numero con la somma dei quadrati delle sue cifre, 
e si ripeta il processo fino a quando si ottiene 1 (dove ulteriori iterazioni porteranno sempre 1), oppure si entra in un
ciclo che non include mai 1. I numeri per cui tale processo dà 1 sono numeri felici, mentre quelli che non danno mai 1 sono numeri infelici. È possibile dimostrare che se nella sequenza 
si raggiunge il 4, il numero è infelice. Possiamo estendere il concetto allo 0, che ovviamente genera la sequenza composta solo di 0 e quindi possiamo considerarlo infelice. 
Ad esempio, 7 è felice e la sequenza ad esso associata è: 
7→72=49→42+92=97→92+72=130→12+32+02=10→12+02=1 mentre 8 è infelice e la sequenza ad esso associata è: 8→82=64→62+42=52→52+22=29→22+92=85→82+52=89→ 82+92=145→12+42+52=42→42+22=20→22+02=4*/

extern int felice(unsigned int num);

int main(void) {
	int res = felice(7);
	return 0;
}