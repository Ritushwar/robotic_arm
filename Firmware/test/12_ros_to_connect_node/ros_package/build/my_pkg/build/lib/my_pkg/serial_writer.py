import serial
import rclpy
from rclpy.node import Node
from std_msgs.msg import String

class SerialWriter(Node):
    def __init__(self):
        super().__init__('serial_writer')

        self.declare_parameter("port", "/dev/ttyACM0")
        self.declare_parameter("baudrate", 115200)

        port = self.get_parameter("port").value
        baudrate = self.get_parameter("baudrate").value

        # Serial connection
        self.esp32 = serial.Serial(port=port, baudrate=baudrate, timeout=0.1)
        self.get_logger().info(f"Connected to {port}")

        #subscriber
        self.sub = self.create_subscription(String,           # data type
                                            'esp32/data',     # topic
                                            self.send_to_esp, # call back function
                                            10                # buffer size
                                            )
        
    def send_to_esp(self, msg):
        data = msg.data + '\n'
        self.esp32.write(data.encode('utf-8'))
        self.get_logger().info(f"Send to esp: {msg.data}")

def main():
    rclpy.init()
    interface_node2 = SerialWriter()
    try:
        rclpy.spin(interface_node2)
    except KeyboardInterrupt:
        pass
    interface_node2.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()
    