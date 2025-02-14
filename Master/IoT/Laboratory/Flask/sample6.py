from flask import Flask
from flask.config import Config
from flask import render_template


appname = "IOT - Sample6"
app = Flask(appname)
myconfig = Config
app.config.from_object(myconfig)

elenco = []

@app.route('/') 
def testoHTML():
    return '<h1>I love IoT</h1>'


#use templates instead of simple text
@app.route('/lista', methods = ['GET'])
def stampalista():
    return render_template("lista.html", lista = elenco)

@app.route('/addinlista/<name>', methods = ['POST'])
def add_to_list(name):
    elenco.append(name)
    return str(len(elenco))