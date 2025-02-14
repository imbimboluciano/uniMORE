#!/usr/bin/python3

import socket
import sys
import time
import re

HOST = '127.0.0.1'
PORT = 1025


def netID(netid,Iparts):

    if netid == 1:
        return Iparts[0] + ".0.0.0"
    elif netid == 2:
        return Iparts[0] + "." + Iparts[1] + ".0.0"
    
    return Iparts[0] + "." + Iparts[1] + "." + Iparts[2] + ".0" 


def broadcast(netid,Iparts):
    if netid == 1:
        return Iparts[0] + ".255.255.255"
    elif netid == 2:
        return Iparts[0] + "." + Iparts[1] + ".255.255"
    
    return Iparts[0] + "." + Iparts[1] + "." + Iparts[2] + ".255" 



with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST,PORT))

    s.listen()
    conn, addr = s.accept()
    with conn:
        classe = ""
        netid = ""
        broad = ""
        output = ""
        data = conn.recv(1024).decode('utf-8')
        if re.findall('[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}', data) != []:
            IpParts = data.split('.')
            firstByte = int(IpParts[0])
            if firstByte < 128:
                classe = "A"
                netid = netID(1,IpParts)
                broad = broadcast(1,IpParts)
            elif firstByte >= 128 and firstByte < 192:
                classe = "B"
                netid = netID(2,IpParts)
                broad = broadcast(2,IpParts)
            elif firstByte >= 192 and firstByte < 224:
                classe = "C"
                netid = netID(3,IpParts)
                broad = broadcast(3,IpParts)
            elif firstByte >= 224 and firstByte < 240:
                classe = "D"
            else:
                classe = "E"

            output = classe + " " + netid + " " + broad
        else:    
            output = "ERROR"
            
        conn.sendall(output.encode('utf-8'))
        
        time.sleep(1)


