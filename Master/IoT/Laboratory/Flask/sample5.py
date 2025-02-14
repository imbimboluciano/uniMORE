from flask import Flask
from flask.config import Config


appname = "IOT - Sample5"
app = Flask(appname)
myconfig = Config
app.config.from_object(myconfig)

elenco = []

@app.route('/') 
def testoHTML():
    return '<h1>I love IoT</h1>'

#we use http verbs in the right way

@app.route('/lista', methods = ['GET'])
def stampalista():
    txt = ";".join(elenco)
    return txt

@app.route('/addinlista/<name>', methods = ['POST'])
def add_to_list(name):
    elenco.append(name)
    return str(len(elenco))