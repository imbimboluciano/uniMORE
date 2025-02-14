#!/usr/bin/python3

import socket
import json
import time
import os

HOST = '155.185.124.56' #'127.0.0.1'
PORT = 8080

with socket.socket(socket.AF_INET,socket.SOCK_STREAM) as s:
    s.bind((HOST,PORT))
    s.listen()

    conn, addr = s.accept()
    with conn:
        data = conn.recv(1024)
        dict_from_client = json.loads(data)
        file_path = "uploads/" + dict_from_client["filename"]
        
        status_code = {"statuscode" : 200}
        
        data = conn.recv(1024)
        with open(file_path,'w') as f:
            f.write(data.decode('utf-8'))

        serialized_message = str.encode(json.dumps(status_code)) 
        conn.sendall(serialized_message)

        time.sleep(2)