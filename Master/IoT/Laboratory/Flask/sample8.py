from flask import Flask
from flask.config import Config
from flask import render_template,request, jsonify


appname = "IOT - Sample8"
app = Flask(appname)
myconfig = Config
app.config.from_object(myconfig)

elenco = []

@app.errorhandler(404)
def page_not_found(error):
    return "Errore pagina non trovata", 404

@app.route('/') 
def testoHTML():
    if request.accept_mimetypes['application/json']:
        return jsonify({'text' : 'I love IoT'})
    else:
        return '<h1>I love IoT</h1>'

@app.route('/lista', methods = ['GET'])
def stampalista():
    return render_template("lista2.html", lista = elenco)

@app.route('/addinlista/<name>', methods = ['POST'])
def add_to_list(name):
    elenco.append(name)
    return str(len(elenco))