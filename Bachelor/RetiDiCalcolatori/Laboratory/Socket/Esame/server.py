#!/usr/bin/python3

import socket
import sys
import time
import re
import json
import ipaddress

HOST = '127.0.0.1'
PORT = 1029


with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST,PORT))

    s.listen()
    conn, addr = s.accept()
    with conn:
        status = ""
        ipmin = ""
        ipmax = ""
        response = {}
        data = conn.recv(1024)
        dict_from_client = json.loads(data)
        netid = dict_from_client['netid']
        netmask = int(dict_from_client['netmaskCIDR'])
        if re.findall('[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}', netid) != [] and  0 < netmask < 33:

            
            try:
                mask = ipaddress.IPv4Network(netid + "/" + str(netmask))

                netlen = mask.num_addresses
                ipmin = mask[1]
                ipmax = mask[-2]
            
                print(ipmax)
                print(ipmin)
                status = "OK"

                response["status"] =  status
                response["IPmin"] =  str(ipmin)
                response["IPmax"] =  str(ipmax)

            except ValueError:
                status = "ERROR"
                response["status"] =  status
        else:
            status = "ERROR"
            response["status"] =  status
            

        
        print(response)
        data = str.encode(json.dumps(response))
        conn.sendall(data)
        
        time.sleep(1)


