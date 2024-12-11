#! /usr/bin/env python

# Set up libraries and overall settings
import RPi.GPIO as GPIO  # Imports the standard Raspberry Pi GPIO library
from time import sleep   # Imports sleep (aka wait or pause) into the program

# Set up the pin for outputpin
def pinOut(pin):
    GPIO.setup(pin, GPIO.OUT)

# Calculates the degrees
# @param degree = the degree that you want
# Since there is a 10% window (from 2% to 12%), we need to change the degree to get the right value between 2 - 12
# We do this by dividing the amount of degrees by 18 (since 180 (max degrees) / 18 = 10 (the 10% window)) 
# and adding 2 (since the minimum value is 2(%))
def calcDegrees(degree):
    calcedDegree = (degree / 18) + 2
    return calcedDegree

# Rotates the servo
# @param servoPin = the gpio pin used, degree = the (converted) degree used
def servoRotation(servoPin, degree):
    GPIO.output(servoPin, True)         # Turns on the pin for output
    
    servoCtrl.ChangeDutyCycle(degree)   # Rotates the servo with the given degrees
    print(str(servoPin) + ", " + str(degree))
    sleep(2)                            # Standby for 2 seconds to prevent spamming the servo

    GPIO.output(servoPin, False)        # Turns off the pin for output

    servoCtrl.ChangeDutyCycle(0)        # Changes the duty to 0 to prevent continuously spamming inputs to the servo

# Cleans the GPIO setup and stops the PWM
def clean():
    servoCtrl.stop()
    GPIO.cleanup()

servoPin = 11                           # The pin that is used to control the servo

# Setup of the desired degrees per position
left = calcDegrees(5)                   
middleLeft = calcDegrees(47.5)
middle = calcDegrees(90) 
middleRight = calcDegrees(132.5)
right = calcDegrees(175)

# Sets up the GPIO pins to match the pin numbers on the pi
GPIO.setmode(GPIO.BOARD)
pinOut(servoPin)

# Sets up a PWM on the servoPin
servoCtrl = GPIO.PWM(servoPin, 50)
servoCtrl.start(float(middle))

# Rotates the servo
servoRotation(servoPin, left)
servoRotation(servoPin, middleLeft)
servoRotation(servoPin, middle)
servoRotation(servoPin, middleRight)
servoRotation(servoPin, right)
servoRotation(servoPin, middle)

clean()