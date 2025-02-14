from flask import Flask
from markupsafe import escape


appname = "IOT - Sample3"
app = Flask(appname)

@app.route('/') #manage the paths
def testoHTML():
    return '<h1>I love IoT</h1>'

@app.route('/<name>')
def welcome_user(name):
    return f'Welcome {name}'

@app.route('/welcome')
def welcome():
    return 'Welcome user'