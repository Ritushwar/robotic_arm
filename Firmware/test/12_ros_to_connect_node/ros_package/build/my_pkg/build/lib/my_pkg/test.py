import serial
while(True):
    ser = serial.Serial('/dev/ttyUSB0', 115200)
    print(ser.readline())
