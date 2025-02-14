import serial
import serial.tools.list_ports

import configparser

import paho.mqtt.client as mqtt

class Bridge():

	def __init__(self):
		self.setupSerial()
		self.setupMQTT()

	def setupSerial(self):
		# open serial port
		self.ser = None
		self.portname = "/dev/ttyS2"

		self.ser = serial.Serial(self.portname, 9600, timeout=0)
		# self.ser.open()

		# internal input buffer from serial
		self.inbuffer = []
		self.value_from_sensor0 = []
		self.value_from_sensor1 = []


	def setupMQTT(self):
		self.clientMQTT = mqtt.Client()
		self.clientMQTT.on_connect = self.on_connect
		self.clientMQTT.on_message = self.on_message
		print("Connecting to MQTT broker...")
		self.clientMQTT.connect("localhost", 1883, 60)
		self.clientMQTT.loop_forever()

	def on_connect(self, client, userdata, flags, rc):
		print("Connected with result code " + str(rc))
		
		# Subscribing in on_connect() means that if we lose the connection and
		# reconnect then subscriptions will be renewed.
		t = "LDR/#"
		client.subscribe(t)
		print("Subscribed to " + t)

	# The callback for when a PUBLISH message is received from the server.
	def on_message(self, client, userdata, msg):
		print(msg.topic + " " + str(msg.payload))
		
		if("Sensor0" in msg.topic):
			self.value_from_sensor0.append(int(msg.payload))
		elif("Sensor1" in msg.topic):
			self.value_from_sensor1.append(int(msg.payload))

		if self.value_from_sensor0 and self.value_from_sensor1:
			if (self.value_from_sensor1[-1] + self.value_from_sensor0[-1]) / 2 >= 240:
				self.command_to_led("ON")
			else:
				self.command_to_led("OFF")


	def command_to_led(self, command):
		if not self.ser is None:
			self.ser.write(bytes(command, 'utf-8'))


	def loop(self):
		pass

if __name__ == '__main__':
	br=Bridge()
	br.loop()

