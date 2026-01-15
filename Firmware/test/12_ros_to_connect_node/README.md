## 12_ros_to_connect_node

This project demonstrates a basic ROS2 serial communication pipeline involving capacitive touch sensing and two microcontrollers (ESP32 and Arduino Uno):

1. **ESP32 Node:**
	- Reads the capacitive touch value.
	- Sends the value via serial communication to a computer running ROS2.

2. **ROS2 Serial Reader Node:**
	- Receives the serial data from the ESP32.
	- Publishes the received value as a ROS2 topic.

3. **ROS2 Subscriber Node:**
	- Subscribes to the published topic.
	- Forwards the value via serial communication to an Arduino Uno.

4. **Arduino Uno Node:**
	- Receives the value from the ROS2 subscriber node via serial.
	- it is used to control led which was connected to arduino uno

This setup enables seamless data transfer from a capacitive touch sensor (on ESP32) through ROS2, and finally to another microcontroller (Arduino Uno), allowing for distributed robotic control and feedback.

### System Workflow

1. Touch is detected on the ESP32.
2. ESP32 sends the touch value over serial to the ROS2 machine.
3. ROS2 node reads and publishes the value.
4. Another ROS2 node subscribes and relays the value to Arduino Uno.
5. Arduino Uno receives and can act on the value.

### Demo Animation

Below is an animation showing the working setup:

![System Output Animation](output.gif)

---
