"""
URL configuration for Biblioteca project.

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/4.2/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
from django.contrib import admin
from django.urls import path
from .views import show_libri,show_librimattoni, show_libriautore, show_autore,crea_libro, modifica_libro, cancella_libro

app_name = "gestione"


urlpatterns = [
    path('listalibri/', show_libri, name = "listalibri"),
    path('listalibrimattoni/', show_librimattoni, name = "listalibrimattoni"),
    path('listalibriautore/', show_libriautore, name = "listalibriautore"),
    path('autore/<str:autore>/',show_autore, name = "autore"),
    path('crealibro/', crea_libro, name = "crealibro"),
    path('modificalibro/<str:autore>/<str:titolo>', modifica_libro, name = "modificalibro"),
    path('cancellalibro/', cancella_libro, name = "cancellalibro")

]
