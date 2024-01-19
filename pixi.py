import serial
from pynput import keyboard
car = serial.Serial("COM3", 9600)

def on_press(key):
    try:
        if key.char == 'w':
            car.write(b'w')
            print("Going Forward...")
        elif key.char == 'a':
            car.write(b'a')
            print("Going Backward...")
        elif key.char == 'd':
            car.write(b'd')
            print("Turning Left...")
        elif key.char == 's':
            car.write(b's')
            print("Turning Right...")
        elif key.char == '1':
            car.write(b'1')
            print("Down")
        elif key.char == '2':
            car.write(b'2')
            print("UP")

        elif key.char == '3':
            car.write(b'3')
            print("Turning Right...")

        elif key.char == '4':
            car.write(b'4')
            print("Turning Right...")
    except:
        pass

def on_release(key):
    car.write(b'x')
    print("STOP!")


# Collect events until released
with keyboard.Listener(
        on_press=on_press,
        on_release=on_release) as listener:
    listener.join()
