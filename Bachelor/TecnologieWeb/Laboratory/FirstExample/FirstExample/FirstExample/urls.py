"""First URL Configuration

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/4.1/topics/http/urls/
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
from django.urls import path,re_path
from .views import *

urlpatterns = [
    path('admin/', admin.site.urls), #pannello di amministrazione
    re_path(r'^$|^/$|^home/$',home_page,name = "homepage"),  #associo home ad una view (ad una business logic)
    path("elencoparametri/",elenca_params,name = "params"),
    path("parametronumero/",param_pari_dispari,name = "pari"),
    path("ciaoutente/",ciao_utente,name = "utente"),
    re_path(r'welcome_+[A-Za-z0-9]+$',welcome,name = "welcome"),
    path('welcome/<str:nome>/<int:eta>/',welcome_type2,name="welcome2")
    #con questa riga sostituiamo le seguenti righe
    #path("home/",home_page, name = "homepage")
    #path("/",home_page, name = "homepage")
    #path("",home_page, name = "homepage")


]