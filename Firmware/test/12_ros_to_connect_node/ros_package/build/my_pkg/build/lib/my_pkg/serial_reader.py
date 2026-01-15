import serial
import rclpy
from rclpy.node import Node
from std_msgs.msg import String

class SerialReader(Node):
    def __init__(self):
        super().__init__('serial_reader')

        # Parameters for serial communication
        self.declare_parameter("port", "/dev/ttyUSB0")
        self.declare_parameter("baudrate", 115200)

        port = self.get_parameter("port").value
        baudrate = self.get_parameter("baudrate").value

        # Serial connection
        self.esp32 = serial.Serial(port=port, baudrate=baudrate, timeout=0.1)
        self.get_logger().info(f"Connected to {port}")
        
        # publisher
        self.pub = self.create_publisher(String, 'esp32/data', 10)


        # Timer for reading (10Hz)
        self.timer = self.create_timer(0.01, self.read_serial)

    def read_serial(self):
        if not self.esp32.is_open:
            return

        try:
            data = self.esp32.readline().decode("utf-8").strip()
            if not data:
                return
            msg = String()
            msg.data = data
            self.get_logger().info(f"Received: {data}")
            self.pub.publish(msg)

        except Exception as e:
            self.get_logger().warn(f"Serial read error: {e}")
            
def main():
    rclpy.init()
    interface_node = SerialReader()
    try:
        rclpy.spin(interface_node)
    except KeyboardInterrupt:
        pass
    interface_node.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()