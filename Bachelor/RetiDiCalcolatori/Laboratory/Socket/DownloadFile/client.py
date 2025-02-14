#!/usr/bin/python3

import socket
import sys
import json

HOST = '127.0.0.1'
PORT = 8080

with socket.socket(socket.AF_INET,socket.SOCK_STREAM) as s:
    s.connect((HOST,PORT))

    dict_message = {"filename" : "file.txt"}
    serialized_message = str.encode(json.dumps(dict_message)) 
    s.sendall(serialized_message)

    data = s.recv(1024)
    dict_message = json.loads(data)

    data = s.recv(1024)
    with open("downloads/file.txt", "w") as f:
        f.write(data.decode('utf-8'))

    s.close()
    