#!/usr/bin/python3

import socket
import sys
import time


HOST = '127.0.0.1'
PORT = int(sys.argv[1])

with socket.socket(socket.AF_INET,socket.SOCK_STREAM) as s:
    s.bind((HOST,PORT)) #bind vuole una tupla con indirizzo e porta
    s.listen()
    conn, addr = s.accept() #conn è la connection socket
    with conn:
        print('connection from', addr)
        data = conn.recv(1024)
        # python utilizza solo UNICODE, quindi dobbiamo convertire la sequenza di byte in stringa
        print('I got your message: %s' % data.decode('utf-8'))
        conn.sendall('I got your message'.encode('utf-8'))
        time.sleep(1)

#uscendo dallo scope la connessione viene chiusa automaticamente