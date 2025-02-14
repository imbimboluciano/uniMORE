### author: Roberto Vezzani

import serial
import serial.tools.list_ports

import configparser

import paho.mqtt.client as mqtt

class Bridge():

	def __init__(self):
		self.config = configparser.ConfigParser()
		self.config.read('config.ini')

		self.setupSerial()
		self.setupMQTT()

	def setupSerial(self):
		# open serial port
		self.ser = None
		if self.config.get("Serial","UseDescription", fallback=False):
			self.portname = self.config.get("Serial","PortName", fallback="/dev/ttyS1")

		try:
			if self.portname is not None:
				self.ser = serial.Serial(self.portname,9600, timeout=0)
		except:
			self.ser = None
		
		
		# self.ser.open()

		# internal input buffer from serial
		self.inbuffer = []

	def setupMQTT(self):
		self.clientMQTT = mqtt.Client()
		self.clientMQTT.on_connect = self.on_connect
		self.clientMQTT.connect(self.config.get("MQTT", "Server", fallback="localhost"), 
						  		self.config.getint("MQTT", "Port", fallback=1883),
								60)
		print("Connecting to MQTT broker...")

		self.clientMQTT.loop_start()

	def on_connect(self, client, userdata, flags, rc):
		print("Connected with result code " + str(rc))
	
	def loop(self):
		# infinite loop for serial managing
		#
		while (True):
			#look for a byte from serial
			if not self.ser is None:

				if self.ser.in_waiting>0:
					# data available from the serial port
					lastchar = self.ser.read(1)

					if lastchar==b'\xfe': #EOL
						print("\nValue received")
						self.useData()
						self.inbuffer =[]
					else:
						# append
						self.inbuffer.append (lastchar)

	def useData(self):
		# I have received a packet from the serial port. I can use it
		if len(self.inbuffer)<3:   # at least header, size, footer
			return False
		# split parts
		if self.inbuffer[0] != b'\xff':
			return False

		numval = int.from_bytes(self.inbuffer[1], byteorder='little')

		for i in range (numval):
			val = int.from_bytes(self.inbuffer[i+2], byteorder='little')
			strval = "Sensor %d: %d " % (i, val)
			print(strval)
			topic = "LDR/Sensor%d" % (i)
			self.clientMQTT.publish(topic, payload=val, qos=0, retain=False)


if __name__ == '__main__':
	br=Bridge()
	br.loop()

