#!/usr/bin/python3

import socket
import sys
import time

HOST = sys.argv[1]
PORT = 2525

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST,PORT))

    s.sendall('Connection from '.encode('utf-8') + socket.gethostname().encode('utf-8'))
    s.close()