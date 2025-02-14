#!/usr/bin/python3

import socket
import sys
import time

HOST = sys.argv[1]
PORT = 1025
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST,PORT))


    data = sys.argv[2]

    s.sendall(data.encode('utf-8'))
    data = s.recv(1024)
    
    print(data.decode('utf-8'))
   
    s.close()