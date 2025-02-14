
int DivisioneRec(int a, int b) {

    if (a >= b) return 1 + DivisioneRec(a - b, b);
    else return 0;
}


int Divisione(int a, int b) {
    if (a < 0 || b <= 0) {
        return -1;
    }
    return DivisioneRec(a, b);
}



