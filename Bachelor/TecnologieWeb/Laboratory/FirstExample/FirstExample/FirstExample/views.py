from django.http import HttpResponse

def home_page(request):

    response = "Benvenuto nella Homepage\n"
    response += "di Luciano Imbimbo\n"

    return HttpResponse(response)



def elenca_params(request):
    response = ""
    for k in request.GET:
        response += request.GET[k] + " "
    
    return HttpResponse(response)


def param_pari_dispari(request):
    

    if not "num" in request.GET: 
        response = "Non mi hai dato il parametro giusto"

    a = request.GET['num']

    if not a.isdigit():
        response = "non è un numero"
    else:
        a = int(a)
        if a % 2 == 0:
            response = "pari"
        else:
            response = "dispari"

    return HttpResponse(response)

def ciao_utente(request):

    return HttpResponse("Ciao " + request.GET['nome'])


def welcome(request):

    return HttpResponse("Ciao " + request.path[len("welcome_") + 1:])


def welcome_type2(request,nome,eta):
    
    return HttpResponse("Ciao sono " + nome + " ed ho " + str(eta) + " anni")