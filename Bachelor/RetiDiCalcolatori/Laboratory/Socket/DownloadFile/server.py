#!/usr/bin/python3

import socket
import json
import time
import os

HOST = '127.0.0.1'
PORT = 8080

with socket.socket(socket.AF_INET,socket.SOCK_STREAM) as s:
    s.bind((HOST,PORT))
    s.listen()

    conn, addr = s.accept()
    with conn:
        data = conn.recv(1024)
        dict_from_client = json.loads(data)
        dict_from_client['filesize'] = os.path.getsize(dict_from_client['filename'])

        data = str.encode(json.dumps(dict_from_client))
        conn.sendall(data)


        with open(dict_from_client['filename'],'r') as f:
            filecontent = f.read()

        print(filecontent)
        conn.sendall(filecontent.encode('utf-8'))

        time.sleep(2)