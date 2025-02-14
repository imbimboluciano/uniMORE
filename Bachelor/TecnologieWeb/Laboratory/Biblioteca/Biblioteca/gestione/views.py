from django.shortcuts import render,HttpResponse, get_object_or_404
from .models import Libro
from django.utils import timezone

# Create your views here.

MATTONE_THRESHOLD = 300

def show_libri(request):

    templ = "gestione/listalibri.html"

    ctx = {"title": "Lista Libri", "listalibri": Libro.objects.all()}

    return render(request, template_name = templ, context=ctx)


def show_librimattoni(request):

    templ = "gestione/listalibri.html"
    #lista_filtrata = Libro.objects.filter(pagine__gte=MATTONE_THRESHOLD)
    lista_filtrata = Libro.objects.exclude(Pagine__lt=MATTONE_THRESHOLD)

    ctx = {"title": "Lista Libri", "listalibri": lista_filtrata}

    return render(request, template_name = templ, context=ctx)

def show_libriautore(request):
    templ  = "gestione/listalibri.html"

    lista_filtrata = Libro.objects.filter(autore__exact=request.GET["autore"])
    #lista_filtrata = Libro.objects.exclude(pagine__lt=MATTONE_THRESHOLD)
    ctx = {"title": "Lista Libri", "listalibri": lista_filtrata}
    return render(request, template_name = templ, context=ctx)


def show_autore(request,autore):
    templ  = "gestione/listalibri.html"

    lista_filtrata = Libro.objects.filter(autore__exact=autore)
    #lista_filtrata = Libro.objects.exclude(pagine__lt=MATTONE_THRESHOLD)

    ctx = {"title": "Lista Libri", "listalibri": lista_filtrata}

    return render(request, template_name = templ, context=ctx)


def crea_libro(request):
    message = ""

    if "autore" in request.GET and "titolo" in request.GET:
        autore = request.GET["autore"]
        titolo = request.GET["titolo"]
        pag = 100

        try:
            pag = int(request.GET["pagine"])
        except:
            message = "Pagine non valide. Inserite pagine di default"

        l = Libro()
        l.autore = autore
        l.titolo = titolo
        l.Pagine = pag
        l.data_prestito = timezone.now()

        try:
            l.save()
            message = "Creazione libro riuscita!" + message
        except Exception as e:
            message = "Errore nella creazione libro" + str(e)

    return render(request, template_name = "gestione/crealibro.html", context={"title": "Crea Libro", "message": message})


def modifica_libro(request, autore, titolo):

    message = ""
    libro = get_object_or_404(Libro, autore=autore, titolo=titolo)

    if "autore" in request.GET and "titolo" in request.GET:
        autore = str(request.GET["autore"])
        titolo = str(request.GET["titolo"])
        pag = 100

        try:
            pag = int(request.GET["pagine"])
        except:
            message = "Pagine non valide. Inserite pagine di default"

        libro.autore = autore
        libro.titolo = titolo
        libro.Pagine = pag

        try:
            libro.save()
            message = "Modifica libro riuscita!" + message
        except Exception as e:
            message = "Errore nella modifica libro" + str(e)

    return render(request, template_name = "gestione/modificalibro.html", context={"title": "Modifica Libro", "libro": libro, "message": message})

def cancella_libro(request):

    msg = ""
    
    if "libro" in request.GET:
        s = request.GET["libro"]
        s = s[:s.index(':')]
        try:
            l = Libro.objects.get(pk=int(s))
            l.delete()
            msg = "Rimozione completata!"
        except Exception as e:
            msg = "Errore nella cancellazione dell'entry " + str(e)
        

    return render(request, template_name = "gestione/cancellalibro.html", context={"title":"Cancella libro","libri": Libro.objects.all(),"message":msg})