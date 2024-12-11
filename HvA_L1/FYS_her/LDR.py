import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BOARD)

resistorPinTopLeft = 7
resistorPinMiddleLeft = 11
resistorPinBottomLeft = 13
resistorPinTopCenter = 15
resistorPinMiddleCenter = 36
resistorPinBottomCenter = 33
resistorPinTopRight = 35
resistorPinMiddleRight = 37
resistorPinBottomRight = 38

TopLeftSensor = False
MiddleLeftSensor = False
BottomLeftSensor = False
TopCenterSensor = False
MiddleCenterSensor = False
BottomCenterSensor = False
TopRightSensor = False
MiddleRightSensor = False
BottomRightSensor = False

while True:
    GPIO.setup(resistorPinTopLeft, GPIO.OUT)
    GPIO.setup(resistorPinTopLeft, GPIO.LOW)
    time.sleep(0.05)

    GPIO.setup(resistorPinTopLeft, GPIO.IN)

    currentTimeTopLeft = time.time()
    diffTopLeft = 0

    while (GPIO.input(resistorPinTopLeft) == GPIO.LOW):
        diffTopLeft = time.time() - currentTimeTopLeft

    GPIO.setup(resistorPinMiddleLeft, GPIO.OUT)
    GPIO.setup(resistorPinMiddleLeft, GPIO.LOW)
    time.sleep(0.05)

    GPIO.setup(resistorPinMiddleLeft, GPIO.IN)

    currentTimeMiddleLeft = time.time()
    diffMiddleLeft = 0

    while (GPIO.input(resistorPinMiddleLeft) == GPIO.LOW):
        diffMiddleLeft = time.time() - currentTimeMiddleLeft

    GPIO.setup(resistorPinBottomLeft, GPIO.OUT)
    GPIO.setup(resistorPinBottomLeft, GPIO.LOW)
    time.sleep(0.05)

    GPIO.setup(resistorPinBottomLeft, GPIO.IN)

    currentTimeBottomLeft = time.time()
    diffBottomLeft = 0

    while (GPIO.input(resistorPinBottomLeft) == GPIO.LOW):
        diffBottomLeft = time.time() - currentTimeBottomLeft

    GPIO.setup(resistorPinTopCenter, GPIO.OUT)
    GPIO.setup(resistorPinTopCenter, GPIO.LOW)
    time.sleep(0.05)

    GPIO.setup(resistorPinTopCenter, GPIO.IN)

    currentTimeTopCenter = time.time()
    diffTopCenter = 0

    while (GPIO.input(resistorPinTopCenter) == GPIO.LOW):
        diffTopCenter = time.time() - currentTimeTopCenter

    GPIO.setup(resistorPinMiddleCenter, GPIO.OUT)
    GPIO.setup(resistorPinMiddleCenter, GPIO.LOW)
    time.sleep(0.05)

    GPIO.setup(resistorPinMiddleCenter, GPIO.IN)

    currentTimeMiddleCenter = time.time()
    diffMiddleCenter = 0

    while (GPIO.input(resistorPinMiddleCenter) == GPIO.LOW):
        diffMiddleCenter = time.time() - currentTimeMiddleCenter

    GPIO.setup(resistorPinBottomCenter, GPIO.OUT)
    GPIO.setup(resistorPinBottomCenter, GPIO.LOW)
    time.sleep(0.05)

    GPIO.setup(resistorPinBottomCenter, GPIO.IN)

    currentTimeBottomCenter = time.time()
    diffBottomCenter = 0

    while (GPIO.input(resistorPinBottomCenter) == GPIO.LOW):
        diffBottomCenter = time.time() - currentTimeBottomCenter

    GPIO.setup(resistorPinTopRight, GPIO.OUT)
    GPIO.setup(resistorPinTopRight, GPIO.LOW)
    time.sleep(0.05)

    GPIO.setup(resistorPinTopRight, GPIO.IN)

    currentTimeTopRight = time.time()
    diffTopRight = 0

    while (GPIO.input(resistorPinTopRight) == GPIO.LOW):
        diffTopRight = time.time() - currentTimeTopRight

    GPIO.setup(resistorPinMiddleRight, GPIO.OUT)
    GPIO.setup(resistorPinMiddleRight, GPIO.LOW)
    time.sleep(0.05)

    GPIO.setup(resistorPinMiddleRight, GPIO.IN)

    currentTimeMiddleRight = time.time()
    diffMiddleRight = 0

    while (GPIO.input(resistorPinMiddleRight) == GPIO.LOW):
        diffMiddleRight = time.time() - currentTimeMiddleRight

    GPIO.setup(resistorPinBottomRight, GPIO.OUT)
    GPIO.setup(resistorPinBottomRight, GPIO.LOW)
    time.sleep(0.05)

    GPIO.setup(resistorPinBottomRight, GPIO.IN)

    currentTimeBottomRight = time.time()
    diffBottomRight = 0

    while (GPIO.input(resistorPinBottomRight) == GPIO.LOW):
        diffBottomRight = time.time() - currentTimeBottomRight

    TopLeftResult = diffTopLeft * 1000
    MiddleLeftResult = diffMiddleLeft * 1000
    BottomLeftResult = diffBottomLeft * 1000
    TopCenterResult = diffTopCenter * 1000
    MiddleCenterResult = diffMiddleCenter * 1000
    BottomCenterResult = diffBottomCenter * 1000
    TopRightResult = diffTopRight * 1000
    MiddleRightResult = diffMiddleRight * 1000
    BottomRightResult = diffBottomRight * 1000

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

    if TopLeftResult >= 2.5:
        print("Top Left")
        TopLeftSensor = True

    if TopCenterResult >= 15:
        print("Top Center")
        TopCenterSensor = True

    if TopRightResult >= 4:
        print("Top Right")
        TopRightSensor = True

    if MiddleLeftResult >= 4:
        print("Middle Left")
        MiddleLeftSensor = True

    if MiddleCenterResult >= 20:
        print("Middle Center")
        MiddleCenterSensor = True

    if MiddleRightResult >= 3:
        print("Middle Right")
        MiddleRightSensor = True

    if BottomLeftResult >= 5:
        print("Bottom Left")
        BottomLeftSensor = True

    if BottomCenterResult >= 2:
        print("Bottom Center")
        BottomCenterSensor = True

    if BottomRightResult >= 5:
        print("Bottom Right")
        BottomRightSensor = True

    print("----------")
    time.sleep(0.05)
