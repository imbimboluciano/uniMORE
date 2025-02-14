from gestione.models import Libro
from django.utils import timezone
from datetime import datetime

def erase_DB():
    Libro.objects.all().delete()


def init_DB():

    if len(Libro.objects.all()) != 0:
        return
    
    def func_time(off_year=None, off_month=None, off_day=None):
        tz = timezone.now()
        out = datetime(tz.year-off_year, tz.month-off_month, tz.day-off_day,tz.hour, tz.minute,tz.second)
        return out

    libridict = {
        "autori" : ["Alessandro Manzoni", "George Orwell", "Omero"],
        "titoli" : ["Promessi Sposi", "1984", "Odissea"],
        "pagine" : [832,159,760],
        "date" : [func_time(y,m,d) for y in range(2) for m in range(2) for d in range(2)]
    }

    for i in range(3):
        l = Libro()
        for k in libridict:
            if k == "autori":
                l.autore = libridict[k][i]
            if k == "titoli":
                l.titolo = libridict[k][i]
            if k == "pagine":
                l.Pagine = libridict[k][i]
            if k == "date":
                l.data_prestito = libridict[k][i]

        l.save()