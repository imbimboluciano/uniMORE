#!/usr/bin/python3

import socket
import sys
import json
import os

HOST = '127.0.0.1'
PORT = 8080

with socket.socket(socket.AF_INET,socket.SOCK_STREAM) as s:
    s.connect((HOST,PORT))

    dict_message = {"filename" : "file.txt"}
    dict_message['filesize'] = os.path.getsize(dict_message['filename'])

    serialized_message = str.encode(json.dumps(dict_message)) 
    s.sendall(serialized_message)

    with open(dict_message['filename'],'r') as f:
        filecontent = f.read()

    s.sendall(filecontent.encode('utf-8'))


    data = s.recv(1024)
    status = json.loads(data)
    print(status)

    
    s.close()
    