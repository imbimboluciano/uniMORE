from django.db import models


class Libro(models.Model):
    titolo = models.CharField(max_length=200)
    autore = models.CharField(max_length=200)
    Pagine = models.IntegerField(default=100)
    data_prestito = models.DateField(default=None)

    def __str__(self):
        out = self.titolo + " " + self.autore + " " + str(self.Pagine)
        if self.data_prestito == None:
            out += " disponibile"
        else:
            out += " in prestito dal " + str(self.data_prestito)
        return out

    
