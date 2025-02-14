# use of DB
#pip install flask-sqlalchemy


from flask import Flask
from config import Config
from flask import render_template, request, jsonify
from flask_sqlalchemy import SQLAlchemy
from datetime import datetime

appname = "IOT - sample11"
app = Flask(appname)
myconfig = Config
app.config.from_object(myconfig)

db = SQLAlchemy(app)

class Sensorfeed(db.Model):
    id = db.Column('value_id', db.Integer, primary_key = True)
    value = db.Column(db.String(100))
    timestamp = db.Column(db.DateTime(timezone=True), nullable=False,  default=datetime.utcnow)

    def __init__(self, value):
        self.value = value


myset=[]


@app.errorhandler(404)
def page_not_found(error):
    return 'Error', 404

@app.route('/')
def testoHTML():
    if request.accept_mimetypes['application/json']:
        return jsonify( {'text':'I Love IoT'}), '200 OK'
    else:
        return '<h1>I love IoT</h1>'


@app.route('/list', methods=['GET'])
def printList():
    myset = Sensorfeed.query.all()
    """
    myres=db.select(Sensorfeed).order_by(Sensorfeed.id.desc()).limit(2)
    filteredSet=db.session.execute(myres).scalars()
    """
    return render_template('lista3.html', lista=myset)


@app.route('/addToList/<val>', methods=['POST'])
def addToList(val):
    sf = Sensorfeed(val)
    db.session.add(sf)
    db.session.commit()
    return str(sf.id)


if True:  # first time (?)
        with app.app_context():
            db.create_all()

if __name__ == '__main__':

    app.run(host=app.config.get('FLASK_RUN_HOST','0.0.0.0'),
            port=app.config.get('FLASK_RUN_PORT',80))