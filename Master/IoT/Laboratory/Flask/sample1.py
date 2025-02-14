from flask import Flask


appname = "IOT - Sample1"
app = Flask(appname)

@app.route('/') #manage the paths
def testoHTML():
    return '<h1>I love IoT</h1>'