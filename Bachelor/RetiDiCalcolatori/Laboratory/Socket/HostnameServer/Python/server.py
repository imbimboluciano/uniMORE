#!/usr/bin/python3

import socket
import sys
import time
import os

HOST = '127.0.0.1'
PORT = 2525

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST,PORT))
    s.listen()

    while True:
        conn, addr = s.accept()
        pid = os.fork()
        if pid == 0:
            with conn:
                time.sleep(3)
                conn.sendall('Welcome from '.encode('utf-8') + socket.gethostname().encode('utf-8'))
                print('Ho dato il benvenuto al client con il processo pid ' + os.getpid())
                time.sleep(2)
                
            os._exit(0)
            
        