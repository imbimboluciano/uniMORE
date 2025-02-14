from flask import Flask


appname = "IOT - Sample2"
app = Flask(appname)

@app.route('/') #manage the paths
def testoHTML():
    return '<h1>I love IoT</h1>'

if __name__ == "__main__":
    port = 10000
    interface = "0.0.0.0" #all running addresses
    app.run(host=interface, port=port)