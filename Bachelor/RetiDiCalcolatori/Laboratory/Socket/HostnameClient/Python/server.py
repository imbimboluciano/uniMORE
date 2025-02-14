#!/usr/bin/python3

import socket
import sys
import time

HOST = '127.0.0.1'
PORT = 2525

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST,PORT))

    s.listen()
    conn, addr = s.accept()
    with conn:
        data = conn.recv(1024)
        print(data.decode('utf-8'))

        time.sleep(1)
