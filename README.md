import serial
import keyboard

car = serial.Serial("COM3", 9600)

def on_press(e):
    try:
        if e.name == 'w':
            car.write(b'w')
            print("Going Forward...")
        elif e.name == 'a':
            car.write(b'a')
            print("Going Backward...")
        elif e.name == 'd':
            car.write(b'd')
            print("Turning Left...")
        elif e.name == 's':
            car.write(b's')
            print("Turning Right...")
        elif e.name == '1':
            car.write(b'1')
            print("Down")
        elif e.name == '2':
            car.write(b'2')
            print("UP")
        elif e.name == '3':
            car.write(b'3')
            print("Turning Right...")
        elif e.name == '4':
            car.write(b'4')
            print("Turning Right...")
    except:
        pass

def on_release(e):
    car.write(b'x')
    print("STOP!")

# Collect events until released
keyboard.hook(on_press)
keyboard.hook(on_release)
keyboard.wait('esc')  # Wait for the 'esc' key to exit the program
