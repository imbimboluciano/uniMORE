#!/usr/bin/env python3
import socket
import os
import sys
import time

HOST = '127.0.0.1' # Standard loopback interface address (localhost)
PORT = 8080 # Port to listen on
HTDOCS = 'htdocs/'
MIMETYPES=[
    ('.gif', 'image/gif'),
    ('.png', 'image/png'),
    ('.jpg', 'image/jpeg'),
    ('.html', 'text/html'),
]


def get_mime(fname):
    mime = 'text/plain' # default
    for ext, mimetype in MIMETYPES:
        if fname.endswith(ext):
            mime = mimetype
            break
    return mime

def send_200(conn, fname):
    header = 'HTTP/1.0 200 OK\r\n' + \
        'Connection: close\r\n' + \
        'Content-Length: %d\r\n' % os.path.getsize(fname) + \
        'Content-Type: %s\r\n\r\n' % get_mime(fname)
    conn.sendall(header.encode('ascii'))
    with open(fname, 'rb') as f:
        l = f.read(1024)
        while (l):
            conn.send(l)
            l = f.read(1024)
    time.sleep(1)


def send_404(conn, url):
    body='<html><body><h1>%s Not Found!</h1></body></html>' % url
    resp='HTTP/1.0 404 Not Found\r\n' + \
        'Connection: close\r\n' + \
        'Content-Type: text/html\r\n' + \
        'Content-Length: %d\r\n\r\n' % len(body) + body
    conn.sendall(resp.encode('ascii'))
    time.sleep(1)

def send_response(conn, url):
    doc_root = HTDOCS
    fname = doc_root + url
    if not os.path.exists(fname):
        print('file %s not found' % fname)
        send_404(conn, url)
    else:
        print('sending file %s' % fname)
        send_200(conn, fname)

def parse_request(conn):
    request = ''
    while True:
        request += conn.recv(1024).decode('utf-8')
        if request.find('\r\n\r\n') > 0: #blank line indicates end of HTTP Header
            break
    reqline, headers = request.split('\r\n', 1) #2th parameter is number of split
    method, url, version = reqline.split(' ', 3)
    return url


def serve_request(conn):
    url=parse_request(conn)
    send_response(conn, url)
    conn.close()

# main
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST, PORT))
    s.listen()
    # non-parallel version:
    while True:
        conn, addr = s.accept()
        with conn:
            serve_request(conn)