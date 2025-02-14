#!/usr/bin/env python3
import socket
import os
import sys
import time
import re

HOST = '127.0.0.1' # (localhost)
PORT = 2525 # Port to connect to

def expect_response(s: str, exp_code: str): #specified type of variable
    data = s.splitlines()
    for l in data:
        print(l)
    # data[last_line] -> response
    rv = data[-1][0:3]
    if rv != exp_code:
        print(f'recv: "{rv}" instead of "{exp_code}"')
        sys.exit()

# main
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))
    # Receive welcome message
    expect_response(s.recv(1024).decode('ascii'), '220')
    # send HELO message
    s.sendall('HELO localhost\r\n'.encode('ascii'))
    expect_response(s.recv(1024).decode('ascii'), '250')
    # send MAIL envelope
    s.sendall('MAIL FROM: <riccardo@localhost>\r\n'.encode('ascii'))
    expect_response(s.recv(1024).decode('ascii'), '250')
    s.sendall('RCPT TO: <riccardo@localhost>\r\n'.encode('ascii'))
    expect_response(s.recv(1024).decode('ascii'), '250')

    # send MAIL message (RFC822)
    s.sendall('DATA\r\n'.encode('ascii'))
    expect_response(s.recv(1024).decode('ascii'), '354')
    s.sendall('From: riccardo <riccardo@localhost>\r\n'\
    'To: riccardo <riccardo@localhost>\r\n'\
    'Subject: prova\r\n\r\n'\
    'Messaggio di prova\r\n.\r\n'.encode('ascii')) # . + black line indicates end of header SMTP
    expect_response(s.recv(1024).decode('ascii'), '250')
    # Submit message
    s.sendall('QUIT\r\n'.encode('ascii'))
    expect_response(s.recv(1024).decode('ascii'), '221')