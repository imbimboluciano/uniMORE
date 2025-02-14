#!/usr/bin/python3

import socket
import sys


HOST = sys.argv[1]
PORT = int(sys.argv[2])

with socket.socket(socket.AF_INET,socket.SOCK_STREAM) as s:
    s.connect((HOST,PORT))
    msg = input('Please enter your message: ')
    s.sendall(msg.encode('utf-8'))
    data = s.recv(1024)
    print(data.decode('utf-8'))
    s.close()