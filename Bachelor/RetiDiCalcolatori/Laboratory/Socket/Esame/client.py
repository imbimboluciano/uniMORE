#!/usr/bin/python3

import socket
import sys
import time
import json

HOST = '127.0.0.1'
PORT = 1029

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST,PORT))

    data = sys.argv[1]
    if data.find('/') == -1:
        print("ERRORE non riesco ad interpretare l'input")
    else:

        part = data.split('/')
        dict_message = {"netid" : part[0], "netmaskCIDR" : part[1]}


        serialized_message = str.encode(json.dumps(dict_message)) 
        s.sendall(serialized_message)

        data_response = s.recv(1024)
        response = json.loads(data_response)

        print(response)


   
    s.close()