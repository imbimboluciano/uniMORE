#!/usr/bin/python3

import socket
import sys
import time
import os
from itertools import groupby
import re

HOST = '127.0.0.1'
PORT = 8080

def look_and_say(iterations, sequence):
    arr = [sequence]
    def get_sequence(arr,iterations,sequence):
        if iterations == 0:
            return arr
        else:
            current = ''.join(str(len(list(group))) + key for key,group in groupby(sequence))
            arr.append(current)
            get_sequence(arr,iterations-1,current)
        return arr
    
    final_sequence = get_sequence(arr,iterations,sequence)
    return final_sequence


def send_msg(connection,msg):
    msg = msg + '\r\n'
    connection.sendall(msg.encode('utf-8'))


with socket.socket(socket.AF_INET,socket.SOCK_STREAM) as s:
    s.bind((HOST,PORT)) #bind vuole una tupla con indirizzo e porta
    s.listen()
    while True:
        conn, addr = s.accept()
        pid = os.fork()
        if pid == 0:
            with conn:
                data = conn.recv(1024)
                data = data.decode('utf-8')
                if re.findall('^[0-9],[0-9]+\r\n', data) != []:
                    reqline, end = data.split('\r\n', 1)
                    possibleseed, niter = reqline.split(',',1)        
                    seed = int(possibleseed)
                    niterations = int(niter)
                    send_msg(conn,f'+ OK {niterations} iterations on seed {seed}')

                    sequence = look_and_say(niterations, str(seed))
                    for i in sequence:
                         send_msg(conn,str(i))
                    
                else:
                    send_msg(conn,"- ERR")
            sys.exit()
        else:
            conn.close()
