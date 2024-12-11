import RPi.GPIO as GPIO
import time
from flask import Flask, render_template

# This is making it so I can use pin numbers instead of broadcom numbers
GPIO.setmode(GPIO.BOARD)

# This is where the pins are being set up
resistorPinTopLeft = 7
resistorPinMiddleLeft = 11
resistorPinBottomLeft = 13
resistorPinTopCenter = 15
resistorPinMiddleCenter = 36
resistorPinBottomCenter = 33
resistorPinTopRight = 35
resistorPinMiddleRight = 37
resistorPinBottomRight = 38


# This is where the variable "__name__" is being passed as first argument.
app = Flask(__name__)

# ------------------- LDR Sensors -------------------
# This is the function where the LDR sensors are getting used
def LDR():

    # This will tell the user which LDR sensors are getting covered, but for now they are set to False (uncovered)
    TopLeftSensor = False
    MiddleLeftSensor = False
    BottomLeftSensor = False
    TopCenterSensor = False
    MiddleCenterSensor = False
    BottomCenterSensor = False
    TopRightSensor = False
    MiddleRightSensor = False
    BottomRightSensor = False

    # This is where the top left LDR sensor is put as an output
    GPIO.setup(resistorPinTopLeft, GPIO.OUT)
    GPIO.setup(resistorPinTopLeft, GPIO.LOW)
    time.sleep(0.05)

    # This is where the top left LDR sensor is put as an input
    GPIO.setup(resistorPinTopLeft, GPIO.IN)

    # This is where the values are being set that are used to measure the results of the top left LDR sensor
    currentTimeTopLeft = time.time()
    diffTopLeft = 0

    # This is where the results of the top left LDR sensor are being measured
    while (GPIO.input(resistorPinTopLeft) == GPIO.LOW):
        diffTopLeft = time.time() - currentTimeTopLeft

    # This is where the middle left LDR sensor is put as an output
    GPIO.setup(resistorPinMiddleLeft, GPIO.OUT)
    GPIO.setup(resistorPinMiddleLeft, GPIO.LOW)
    time.sleep(0.05)

    # This is where the middle left LDR sensor is put as an input
    GPIO.setup(resistorPinMiddleLeft, GPIO.IN)

    # This is where the values are being set that are used to measure the results of the middle left LDR sensor
    currentTimeMiddleLeft = time.time()
    diffMiddleLeft = 0

    # This is where the results of the middle left LDR sensor are being measured
    while (GPIO.input(resistorPinMiddleLeft) == GPIO.LOW):
        diffMiddleLeft = time.time() - currentTimeMiddleLeft

    # This is where the bottom left LDR sensor is put as an output
    GPIO.setup(resistorPinBottomLeft, GPIO.OUT)
    GPIO.setup(resistorPinBottomLeft, GPIO.LOW)
    time.sleep(0.05)

    # This is where the bottom left LDR sensor is put as an input
    GPIO.setup(resistorPinBottomLeft, GPIO.IN)

    # This is where the values are being set that are used to measure the results of the bottom left LDR sensor
    currentTimeBottomLeft = time.time()
    diffBottomLeft = 0

    # This is where the results of the bottom left LDR sensor are being measured
    while (GPIO.input(resistorPinBottomLeft) == GPIO.LOW):
        diffBottomLeft = time.time() - currentTimeBottomLeft

    # This is where the top center LDR sensor is put as an output
    GPIO.setup(resistorPinTopCenter, GPIO.OUT)
    GPIO.setup(resistorPinTopCenter, GPIO.LOW)
    time.sleep(0.05)

    # This is where the top center LDR sensor is put as an input
    GPIO.setup(resistorPinTopCenter, GPIO.IN)

    # This is where the values are being set that are used to measure the results of the top center LDR sensor
    currentTimeTopCenter = time.time()
    diffTopCenter = 0

    # This is where the results of the top center LDR sensor are being measured
    while (GPIO.input(resistorPinTopCenter) == GPIO.LOW):
        diffTopCenter = time.time() - currentTimeTopCenter

    # This is where the middle center LDR sensor is put as an output
    GPIO.setup(resistorPinMiddleCenter, GPIO.OUT)
    GPIO.setup(resistorPinMiddleCenter, GPIO.LOW)
    time.sleep(0.05)

    # This is where the middle center LDR sensor is put as an input
    GPIO.setup(resistorPinMiddleCenter, GPIO.IN)

    # This is where the values are being set that are used to measure the results of the middle center LDR sensor
    currentTimeMiddleCenter = time.time()
    diffMiddleCenter = 0

    # This is where the results of the middle center LDR sensor are being measured
    while (GPIO.input(resistorPinMiddleCenter) == GPIO.LOW):
        diffMiddleCenter = time.time() - currentTimeMiddleCenter

    # This is where the bottom center LDR sensor is put as an output
    GPIO.setup(resistorPinBottomCenter, GPIO.OUT)
    GPIO.setup(resistorPinBottomCenter, GPIO.LOW)
    time.sleep(0.05)

    # This is where the bottom center LDR sensor is put as an input
    GPIO.setup(resistorPinBottomCenter, GPIO.IN)

    # This is where the values are being set that are used to measure the results of the bottom center LDR sensor
    currentTimeBottomCenter = time.time()
    diffBottomCenter = 0

    # This is where the results of the bottom center LDR sensor are being measured
    while (GPIO.input(resistorPinBottomCenter) == GPIO.LOW):
        diffBottomCenter = time.time() - currentTimeBottomCenter

    # This is where the top right LDR sensor is put as an output
    GPIO.setup(resistorPinTopRight, GPIO.OUT)
    GPIO.setup(resistorPinTopRight, GPIO.LOW)
    time.sleep(0.05)

    # This is where the top right LDR sensor is put as an input
    GPIO.setup(resistorPinTopRight, GPIO.IN)

    # This is where the values are being set that are used to measure the results of the top right LDR sensor
    currentTimeTopRight = time.time()
    diffTopRight = 0

    # This is where the results of the top right LDR sensor are being measured
    while (GPIO.input(resistorPinTopRight) == GPIO.LOW):
        diffTopRight = time.time() - currentTimeTopRight

    # This is where the middle right LDR sensor is put as an output
    GPIO.setup(resistorPinMiddleRight, GPIO.OUT)
    GPIO.setup(resistorPinMiddleRight, GPIO.LOW)
    time.sleep(0.05)

    # This is where the middle right LDR sensor is put as an input
    GPIO.setup(resistorPinMiddleRight, GPIO.IN)

    # This is where the values are being set that are used to measure the results of the middle right LDR sensor
    currentTimeMiddleRight = time.time()
    diffMiddleRight = 0

    # This is where the results of the middle right LDR sensor are being measured
    while (GPIO.input(resistorPinMiddleRight) == GPIO.LOW):
        diffMiddleRight = time.time() - currentTimeMiddleRight

    # This is where the bottom right LDR sensor is put as an output
    GPIO.setup(resistorPinBottomRight, GPIO.OUT)
    GPIO.setup(resistorPinBottomRight, GPIO.LOW)
    time.sleep(0.05)

    # This is where the bottom right LDR sensor is put as an input
    GPIO.setup(resistorPinBottomRight, GPIO.IN)

    # This is where the values are being set that are used to measure the results of the bottom right LDR sensor
    currentTimeBottomRight = time.time()
    diffBottomRight = 0

    # This is where the results of the bottom right LDR sensor are being measured
    while (GPIO.input(resistorPinBottomRight) == GPIO.LOW):
        diffBottomRight = time.time() - currentTimeBottomRight

    # This is where the results are being calculated
    TopLeftResult = diffTopLeft * 1000
    MiddleLeftResult = diffMiddleLeft * 1000
    BottomLeftResult = diffBottomLeft * 1000
    TopCenterResult = diffTopCenter * 1000
    MiddleCenterResult = diffMiddleCenter * 1000
    BottomCenterResult = diffBottomCenter * 1000
    TopRightResult = diffTopRight * 1000
    MiddleRightResult = diffMiddleRight * 1000
    BottomRightResult = diffBottomRight * 1000

    # This is where the results are being shown to the user
    print(TopLeftResult)
    print(MiddleLeftResult)
    print(BottomLeftResult)
    print(TopCenterResult)
    print(MiddleCenterResult)
    print(BottomCenterResult)
    print(TopRightResult)
    print(MiddleRightResult)
    print(BottomRightResult)
    print("----------")

    # This is where the top left LDR result gets checked to see if it's covered (True) or not
    if TopLeftResult >= 2.5:
        print("Top Left")
        TopLeftSensor = True

    # This is where the top center LDR result gets checked to see if it's covered (True) or not
    if TopCenterResult >= 15:
        print("Top Center")
        TopCenterSensor = True

    # This is where the top right LDR result gets checked to see if it's covered (True) or not
    if TopRightResult >= 4:
        print("Top Right")
        TopRightSensor = True

    # This is where the middle left LDR result gets checked to see if it's covered (True) or not
    if MiddleLeftResult >= 4:
        print("Middle Left")
        MiddleLeftSensor = True

    # This is where the middle center LDR result gets checked to see if it's covered (True) or not
    if MiddleCenterResult >= 20:
        print("Middle Center")
        MiddleCenterSensor = True

    # This is where the middle right LDR result gets checked to see if it's covered (True) or not
    if MiddleRightResult >= 3:
        print("Middle Right")
        MiddleRightSensor = True

    # This is where the bottom left LDR result gets checked to see if it's covered (True) or not
    if BottomLeftResult >= 5:
        print("Bottom Left")
        BottomLeftSensor = True

    # This is where the bottom center LDR result gets checked to see if it's covered (True) or not
    if BottomCenterResult >= 2:
        print("Bottom Center")
        BottomCenterSensor = True

    # This is where the bottom right LDR result gets checked to see if it's covered (True) or not
    if BottomRightResult >= 5:
        print("Bottom Right")
        BottomRightSensor = True

    print("----------")

    # This is where the results of whether the LDR sensors are covered or not get returned to the Flask server
    return TopLeftSensor, TopCenterSensor, TopRightSensor, MiddleLeftSensor, MiddleCenterSensor, MiddleRightSensor, BottomLeftSensor, BottomCenterSensor, BottomRightSensor


# ------------------- Flask Server -------------------
# This is where the route of the website link is set (in this case 'IP-address RPi'/)
@app.route("/")
# This is the method where the website is called from
def index():
    # This is where the results of whether the LDR sensors are covered or not get retrieved
    TopLeftSensor,TopCenterSensor,TopRightSensor,MiddleLeftSensor,MiddleCenterSensor,MiddleRightSensor,BottomLeftSensor,BottomCenterSensor,BottomRightSensor = LDR()
    # This is where the results of the sensors are getting entered into the website
    templateData = {
        'TopLeft': TopLeftSensor,
        'TopCenter': TopCenterSensor,
        'TopRight': TopRightSensor,
        'MiddleLeft': MiddleLeftSensor,
        'MiddleCenter': MiddleCenterSensor,
        'MiddleRight': MiddleRightSensor,
        'BottomLeft': BottomLeftSensor,
        'BottomCenter': BottomCenterSensor,
        'BottomRight': BottomRightSensor
    }

    # This is where the website 'template' is being rendered with the given sensor data
    return render_template("index.html", **templateData)


# This is the method where the Flask server will be started
def startApp():
    app.run(debug=True, port=80, host='0.0.0.0', use_reloader=False)


# This is what happens when the main.py file gets started
if __name__ == "__main__":
    startApp()
