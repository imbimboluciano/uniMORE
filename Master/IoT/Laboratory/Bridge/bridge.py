import serial

PORTNAME = "/dev/ttyS1"


class Bridge():

    def setup(self):

        self.ser = serial.Serial(PORTNAME,9600, timeout=0)
        #self.ser.open()
        self.inbuffer = []

    def loop(self):

        while(True):
            if self.ser.in_waiting > 0:
                lastchar = self.ser.read(1)


                if lastchar == b'\xfe':
                    print("\nValue received")
                    self.useData()
                    self.inbuffer = []
                else:
                    self.inbuffer.append(lastchar)


    def useData(self):
        #check the syntax of packet received
        if len(self.inbuffer) < 3:
            return False
        
        if self.inbuffer[0] != b'\xff':
            return False
        
        numval = int.from_bytes(self.inbuffer[1], byteorder='little')
        for i in range(numval):
            val = int.from_bytes(self.inbuffer[i+2], byteorder='little')
            strval = "Sensor %d: %d " % (i,val)
            print(strval)



if __name__ == '__main__':
    br = Bridge()
    br.setup()
    br.loop()