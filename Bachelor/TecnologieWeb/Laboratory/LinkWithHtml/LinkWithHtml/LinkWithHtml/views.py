from datetime import datetime
from django.shortcuts import render
    

def hello_template(request,nome,eta):
    
    ctx = {"title": "Hello Template",
    "lista" : [datetime.now(), datetime.today().strftime('%A'), datetime.today().strftime('%B')]}

    return render(request, template_name = "baseext.html",context=ctx)


def risorse_statiche(request):
    return render(request, template_name = "provastatic.html", context = {"title": "Elementi Statici"})