from flask import Flask


appname = "IOT - Sample4"
app = Flask(appname)

elenco = []

@app.route('/') #manage the paths
def testoHTML():
    return '<h1>I love IoT</h1>'

@app.route('/lista')
def stampalista():
    txt = ";".join(elenco)
    return txt

@app.route('/addinlista/<name>')
def add_to_list(name):
    elenco.append(name)
    return str(len(elenco))