/* @author: Atilla Ören | 500849757
   This part of the program is used for the 4-Digit Display V1.2.
   It will show the time, the day of the week and it can also function as a stopwatch.
   Copyright 2023 <Atilla Ören> - Creative Commons Attribution Non Commercial
*/

#include <Arduino.h>
#include <TM1637Display.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <ArduinoJson.h>
#include "pitches.h"
#include <Stepper.h>
#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>         // https://github.com/tzapu/WiFiManager

// Module connection pins (Digital Pins)
#define IN1_STEP D0
#define IN2_STEP D1
#define CLK D2  //D2 for WeMOS, 2 for Arduino Uno
#define DIO D3  //D3 for WeMOS, 3 for Arduino Uno
#define LDR D4
#define BUTTON_STOPWATCH D5
#define BUZZER D6
#define IN3_STEP D7
#define IN4_STEP D8

// The amount of time (in milliseconds) for delays
#define TIME_LOOP_DELAY 100
#define SECOND_DELAY 1000
#define FIVE_DELAY 5000
#define TEN_DELAY 10000

// Serial baud amount
#define MAC_BAUD 9600
#define SERIAL_BAUD 115200

// The insert needed to display a colon (:) on the 4-Digit Display
#define COLON 0b01000000

// The maximum amount of seconds, minutes and hours
#define SM_AMOUNT 59
#define MAX_HOURS 999

// Length for Display
#define FOUR_LENGTH 4
#define THREE_LENGTH 3
#define TWO_LENGTH 2
#define ONE_LENGTH 1
#define ZERO_LENGTH 0

// Calculation values
#define NINETY_PER 0.9

// Stepper speed
#define TEN_RPM 10

// Defining the size of the JsonBuffer
#define JSONBUFFER 1024

// Step constant
#define MOTORINTERFACETYPE 4

// Value for getting the datetime or day of the week from the getData() function
#define DT_VAL "datetime"
#define DOTW_VAL "day"

// Value for getting the tune or darkvalue from the getApptInfo() function
#define TUNE_VAL "tune"
#define DARK_VAL "dark"

// The link to the realtime api
#define REALTIME_API "http://worldtimeapi.org/api/timezone/Europe/Amsterdam"
#define APPT_API "http://orenda.loca.lt/database/api.php"

/* Creating the words/letters I want displayed. 
   I do this by calling every seperate position as displayed below.
        A
       ---
    F |   | B
      | G |
       ---
    E |   | C
      |   |
       ---
        D  
*/
const uint8_t SEG_DAY[] = {
  SEG_B | SEG_C | SEG_D | SEG_E | SEG_G,          // d
  SEG_A | SEG_B | SEG_C | SEG_E | SEG_F | SEG_G,  // A
  SEG_B | SEG_C | SEG_D | SEG_F | SEG_G           // y
};

const uint8_t SEG_CELSIUS[] = {
  SEG_A | SEG_B | SEG_F | SEG_G,  // °
  SEG_A | SEG_D | SEG_E | SEG_F   // C
};

const uint8_t SEG_HOURS[] = {
  SEG_B | SEG_C | SEG_E | SEG_F | SEG_G  // H
};

/* These are the tunes you can choose as an alarm tune
   Notes in the melody are imported from 'pitches.h'
*/
int standardMelody[] = {
  NOTE_C4, 4, NOTE_G3, 8, NOTE_G3, 8, NOTE_A3, 4, 
  NOTE_G3, 4, REST, 4, NOTE_B3, 4, NOTE_C4, 4,
};

int nokiaMelody[] = { 
  NOTE_E5, 8, NOTE_D5, 8, NOTE_FS4, 4, NOTE_GS4, 4, 
  NOTE_CS5, 8, NOTE_B4, 8, NOTE_D4, 4, NOTE_E4, 4, 
  NOTE_B4, 8, NOTE_A4, 8, NOTE_CS4, 4, NOTE_E4, 4,
  NOTE_A4, 2, 
};

int harryPotterMelody[] = {
  REST, 2, NOTE_D4, 4, NOTE_G4, -4, NOTE_AS4, 8, 
  NOTE_A4, 4, NOTE_G4, 2, NOTE_D5, 4, NOTE_C5, -2, 
  NOTE_A4, -2, NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4,
  NOTE_F4, 2, NOTE_GS4, 4, NOTE_D4, -1, 
}

int doomMelody[] {
  NOTE_E2, 8, NOTE_E2, 8, NOTE_E3, 8, NOTE_E2, 8,
  NOTE_E2, 8, NOTE_D3, 8, NOTE_E2, 8, NOTE_E2, 8, 
  NOTE_C3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_AS2, 8,
  NOTE_E2, 8, NOTE_E2, 8, NOTE_B2, 8, NOTE_C3, 8,
  NOTE_E2, 8, NOTE_E2, 8, NOTE_E3, 8, NOTE_E2, 8, 
  NOTE_E2, 8, NOTE_D3, 8, NOTE_E2, 8, NOTE_E2, 8,
  NOTE_C3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_AS2, -2,  
}

int vaderMelody[] {
  NOTE_A4, 4, NOTE_A4, 4, NOTE_A4, 4, NOTE_F4, -8, 
  NOTE_C5, 16, NOTE_A4, 4, NOTE_F4, -8, NOTE_C5, 16,
  NOTE_A4, 2, NOTE_E5, 4, NOTE_E5, 4, NOTE_E5, 4, 
  NOTE_F5, -8, NOTE_C5, 16, NOTE_A4 ,4, NOTE_F4, -8,
  NOTE_C5, 16, NOTE_A4, 2,
}

int furEliseMelody[] {
  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_DS5, 16, 
  NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,
  NOTE_A4, -8, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16,
  NOTE_B4, -8, NOTE_E4, 16, NOTE_GS4, 16, NOTE_B4, 16,
  NOTE_C5, 8,  REST, 16, NOTE_E4, 16, NOTE_E5, 16, 
  NOTE_DS5, 16, NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, 
  NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16, NOTE_A4, -8, 
  NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16, NOTE_B4, -8, 
  NOTE_E4, 16, NOTE_C5, 16, NOTE_B4, 16, NOTE_A4 , 4, 
}

int melodyTempo[] {80, 120, 144, 180, 225}

int divider = 0, noteDuration = 0;

// Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence
AccelStepper myStepper(MOTORINTERFACETYPE, IN1_STEP, IN2_STEP, IN3_STEP, IN4_STEP);

TM1637Display display(CLK, DIO);

// Set web server port number to 80
WiFiServer server(80);

// Variable to store the HTTP request
String header;

String outputState = "off";

void setup() {
  pinMode(LDR, INPUT);
  //Define baud rate for serial communication
  Serial.begin(SERIAL_BAUD);
  // Serial.begin(MAC_BAUD);   //bauld for finding a new macaddress
  // WiFi.begin("***", "***");  //WiFi at school
  // WiFi.begin("***", "***");  //WiFi at home

  pinMode(BUTTON_STOPWATCH, INPUT);

  display.setBrightness(0x0f);

  // WiFiManager
  // Local intialization. Once its business is done, there is no need to keep it around
  WiFiManager wifiManager;
  
  // Uncomment and run it once, if you want to erase all the stored information
  //wifiManager.resetSettings();
  
  // set custom ip for portal
  //wifiManager.setAPConfig(IPAddress(10,0,1,1), IPAddress(10,0,1,1), IPAddress(255,255,255,0));

  // fetches ssid and pass from eeprom and tries to connect
  // if it does not connect it starts an access point with the specified name
  // here  "AutoConnectAP"
  // and goes into a blocking loop awaiting configuration
  wifiManager.autoConnect("AutoConnectAP");
  // or use this for auto generated name ESP + ChipID
  //wifiManager.autoConnect();
  
  // if you get here you have connected to the WiFi
  Serial.println("Connected.");
  
  server.begin();
  // Keep in while-loop while the device is not connected to your accesspoint.
  while (WiFi.status() != WL_CONNECTED) {
    delay(SECOND_DELAY);  // Waiting on connection...
  }
}

// This loops the time method
void loop() {
  wifiManager();
  setBrightness();
  time();
  delay(TIME_LOOP_DELAY);
}

/* This method is used for a stopwatch display.
   For every 60 seconds (60x1000 milisecond delay) a minute gets added and for every 60 minutes an hour gets added.
   When the user stops the stopwatch by pressing the assigned button, the 4-Digit Display displays the amount of hours (xxxh) 
   and the amount of minutes and seconds (mm:ss).
   After the display of time passed has ended, the 4-Digit Display will go back to display the current time again.    
*/
void stopwatch() {
  int minutesDisplay;
  int secondsDisplay;
  for (int hours = 0; hours <= MAX_HOURS; hours++) {
    for (int minutes = 0; minutes <= SM_AMOUNT; minutes++) {
      display.showNumberDecEx(minutes, COLON, true, 2, 0);
      for (int seconds = 0; seconds <= SM_AMOUNT; seconds++) {
        display.showNumberDecEx(seconds, COLON, true, 2, 2);
        delay(1000);

        // If the stopwatch button gets pressed, the stopwatch will stop
        if (digitalRead(BUTTON_STOPWATCH) == HIGH) {
          secondsDisplay = seconds;
          break;
        }
      }

      if (digitalRead(BUTTON_STOPWATCH) == HIGH) {
        minutesDisplay = minutes;
        break;
      }
    }

    // The results of the stopwatch will be displayed after the end.
    if (digitalRead(BUTTON_STOPWATCH) == HIGH) {
      display.showNumberDec(hours, true, THREE_LENGTH, ZERO_LENGTH);
      display.setSegments(SEG_HOURS, ONE_LENGTH, THREE_LENGTH);
      delay(FIVE_DELAY);
      display.showNumberDecEx(minutesDisplay, COLON, true, TWO_LENGTH, ZERO_LENGTH);
      display.showNumberDecEx(secondsDisplay, COLON, true, TWO_LENGTH, TWO_LENGTH);
      delay(FIVE_DELAY);
      break;
    }
  }
}

/* This method is used to display the current day of the week.
   Monday = dAy1
   Tuesday = dAy2
   Wednesday = dAy3
   Thursday = dAy4
   Friday = dAy5   
   Saturday = dAy6
   Sunday = dAy7
   @param day is a variable received from the 'void time()' method where day = day of the week.
*/
void dayOfTheWeek(int day) {
  display.setSegments(SEG_DAY);
  display.showNumberDecEx(day, ZERO_LENGTH, false, ONE_LENGTH, THREE_LENGTH);
  delay(TEN_DELAY);
}

/* This method receives the time, seconds and the day of the week from the 'int getTime()', 'int getSeconds()' and 'int getDayOfTheWeek()'.
   It displays the time via the 'displayTime()' method.
*/
void time() {
  int time = getTime();
  int seconds = getSeconds();
  int dayOTW = getData(DOTW_VAL).toInt();

  // When it is the start of the minute (when the seconds are 00, for example 16:10:00), it checks for appointments.
  if (seconds == 00) {
    displayTime(time);
    String tune = getApptInfo(TUNE_VAL);
    int darkValue = getApptInfo(DARK_VAL).toInt();
    apptCheck(tune, darkValue);
  }

  // If 25 seconds had passed since the beginning of the minute, it will show which day of the week it is.
  if (seconds == 45) {
    Serial.println("Start dayOTW");
    dayOfTheWeek(dayOTW);
    displayTime(time);
  }

  // If the button gets pressed the stopwatch starts.
  if (digitalRead(BUTTON_STOPWATCH) == HIGH) {
    stopwatch();
  }
}

/* With this function I check wether or not the buzzer should buzz in the dark or not
   darkValue == 0 means that the user does not want the buzzer tot turn on in the dark
   darkValue == 1 means that the user does want the buzzer to turn on in the dark
   ldrValue == 0 means that there is light detected
   ldrValue == 1 means that there is no light detected
   @param String tune = the melody of the buzzer and int darkValue = 0 or 1 value (see above)
*/
void apptCheck (String tune, int darkValue) { 
  if (tune == NULL && darkValue == NULL) {
    Serial.println("No appointment");
  } else {
    if (darkValue == 0) {
      ldrValue = ldr();
      if (ldrValue == 1) {
        Serial.println("No alarm while it's dark");
      } else if (ldrValue == 0) {
        buzzer(tune);
      }
    } else if (darkValue == 1) {
      buzzer(tune);
    }
  }  
}

/* Through this method I am receiving the either the datetime or day of the week value through an api.
   @param datetimeOrDay is a string value to see if you want the datetime or day_of_week value.
*/
String getData(String datetimeOrDay) {
  WiFiClient client;
  HTTPClient httpClient;
  DynamicJsonDocument jsonBuffer(JSONBUFFER);
  String dateTime;
  String payload;
  String dayOfTheWeek;

  // The connection to the api
  httpClient.begin(client, REALTIME_API);
  int httpCode = httpClient.GET();

  // If there is a connection
  if (httpCode == HTTP_CODE_OK) {  // HTTP_CODE_OK == 200
    payload = httpClient.getString();
    deserializeJson(jsonBuffer, payload);
    String saveTime = jsonBuffer["datetime"];
    String saveDay = jsonBuffer["day_of_week"];
    dateTime = saveTime;
    dayOfTheWeek = saveDay;
    Serial.println(dateTime);

    // If there isn't a connection
  } else {
    Serial.println("Unable to connect :(");
  }

  // If you want to receive the datetime
  if (datetimeOrDay == "datetime") {
    return dateTime;

    // If you want to receive the day_of_week
  } else if (datetimeOrDay == "day") {
    return dayOfTheWeek;

    // If you forgot to send a String through or if you didn't put in the right String
  } else {
    Serial.println("NO RETURN");
  }
}

// This method is used to trim the time out of the datetime.
int getTime() {
  String editTime = getData(DT_VAL);  // editTime will be similar to "2023-02-21T11:22:07.256685+01:00"
  editTime.remove(0, 11);             // Removing the first eleven characters to become "11:22:07.256685+01:00"
  editTime.remove(5);                 // Removing everything after the fifth character to become "11:22"
  editTime.remove(2, 1);              // Removing a single character after the second character to become "1122"
  Serial.println(editTime);
  int time = editTime.toInt();  // The remaining "1122" will be converted to an int
  return time;
}

// This method is used to trim the seconds out of the datetime
int getSeconds() {
  String editSeconds = getData(DT_VAL);  // editSeconds will be similar to "2023-02-21T11:22:07.256685+01:00"
  editSeconds.remove(0, 17);             // Removing the first seventeen characters to become "07.256685+01:00"
  editSeconds.remove(2);                 // Removing everything after the seconds character to become "07"
  Serial.println(editSeconds);
  int seconds = editSeconds.toInt();  // The remaining "07" will be converted to an int
  return seconds;
}

// This method is used to get the date out of the datetime
String getDate() {
  String date = getData(DT_VAL);  // date will be similar to "2023-02-21T11:22:07.256685+01:00"
  date.remove(10);                // Removing everything after the tenth character to become "2023-02-21"
  Serial.println(date);
  return date;
}

/* This method is so I don't have to repeat formulating the way I want the time to be displayed.
   
   @param time is a 1-4 character long int to display the time 
*/
void displayTime(int time) {
  display.showNumberDecEx(time, COLON, true, FOUR_LENGTH, ZERO_LENGTH);  
}

// I am using this method to change the brightness of the display depending on wether it is dark or not where 0 = Light and 1 = No light.
void setBrightness() {
  int maxBrightness = 7;
  int minBrightness = 4;
  int ldrValue = ldr();
  if (ldrValue == 0) {
    display.setBrightness(maxBrightness);
  } else {
    display.setBrightness(minBrightness);
  }
}

/* This gets the data from a LDR (Light-Dependent Resistor)
   0 = Detects Light
   1 = No light
*/
int ldr() {
  int sensorData = digitalRead(LDR);
  Serial.print("Sensor value:");
  Serial.println(sensorData);
  return sensorData;
}

/* The buzzer method is used to let the user know that they have an appointment planned at that time
   @param String melodyName = a specific String value that has been passed through the website -> database
*/
void buzzer(String melodyName) {
  int notes;
  int tempo;

  // this checks which melody is chosen by the user and creates the correct amount of notes and tempo
  if (melodyName == "Nokia") {
    notes = sizeof(nokiaMelody) / sizeof(nokiaMelody[0]) / 2;
    tempo = melodyTempo[3];
  } else if (melodyName == "Standard") {
    notes = sizeof(standardMelody) / sizeof(standardMelody[0]) / 2;
    tempo = melodyTempo[3];
  } else if (melodyName == "Harry Potter") {
    notes = sizeof(harryPotterMelody) / sizeof(harryPotterMelody[0]) / 2;
    tempo = melodyTempo[2];
  } else if (melodyName == "Doom") {
    notes = sizeof(doomMelody) / sizeof(doomMelody[0]) / 2;
    tempo = melodyTempo[4];
  } else if (melodyName == "Darth Vader") {
    notes = sizeof(vaderMelody) / sizeof(vaderMelody[0]) / 2;
    tempo = melodyTempo[1];
  } else if (melodyName == "Fur Elise") {
    notes = sizeof(furEliseMelody) / sizeof(furEliseMelody[0]) / 2;
    tempo = melodyTempo[0];
  }

  // this calculates the duration of a whole note in ms
  int wholenote = (60000 * 4) / tempo;
  
  // this is to loop throught the melody until the melody is finished
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
    
    // this checks the duration of each note from the chosen melody
    if (melodyName == "Nokia") {
    // calculates the duration of each note
      divider = nokiaMelody[thisNote + 1];
    } else if (melodyName == "Standard") {
      divider = standardMelody[thisNote + 1];
    } else if (melodyName == "Harry Potter") {
      divider = harryPotterMelody[thisNote + 1];
    } else if (melodyName == "Doom") {
      divider = doomMelody[thisNote + 1];
    } else if (melodyName == "Darth Vader") {
      divider = vaderMelody[thisNote + 1];
    } else if (melodyName == "Fur Elise") {
      divider = furEliseMelody[thisNote + 1];
    }

    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }

    // checks for which melody is chosen and plays the selected melody  
    if (melodyName == "Nokia") {
      // we only play the note for 90% of the duration, leaving 10% as a pause
      tone(BUZZER, nokiaMelody[thisNote], noteDuration * NINETY_PER);
    } else if (melodyName == "Standard") {
      tone(BUZZER, standardMelody[thisNote], noteDuration * NINETY_PER);
    } else if (melodyName == "Harry Potter") {
      tone(BUZZER, harryPotterMelody[thisNote], noteDuration * NINETY_PER);      
    } else if (melodyName == "Doom") {
      tone(BUZZER, doomMelody[thisNote], noteDuration * NINETY_PER);  
    } else if (melodyName == "Darth Vader") {
      tone(BUZZER, vaderMelody[thisNote], noteDuration * NINETY_PER);
    } else if (melodyName == "Fur Elise") {
      tone(BUZZER, furEliseMelody[thisNote], noteDuration * NINETY_PER);
    }
    // Wait for the specief duration before playing the next note.
    delay(noteDuration);

    // stop the waveform generation before the next note.
    noTone(BUZZER);
  }
}

// This method activates the Stepper Motor
void stepMotor(double maxSpeed, double acceleration, int speed, int destination) {
  myStepper.setMaxSpeed(maxSpeed);
	myStepper.setAcceleration(acceleration);
	myStepper.setSpeed(speed);
	myStepper.moveTo(destination);
  if (myStepper.distanceToGo() == 0) {
		myStepper.moveTo(-myStepper.currentPosition());
  }
	myStepper.run();
}

/* This method is used to get the MAC-address of my WeMos.
   I need the MAC-address to connect to the iotroam network and this method is just in case I accidentally fry my WeMos (again)
*/
void macAddress() {
  Serial.print("MAC-address of your WeMoS: ");
  Serial.println(WiFi.macAddress());
  delay(FIVE_DELAY);
}

void wifiManager(){
  WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            
            // turns the GPIOs on and off
            if (header.indexOf("GET /5/on") >= 0) {
              Serial.println("GPIO on");
              outputState = "on";
              
              
            } else if (header.indexOf("GET /5/off") >= 0) {
              Serial.println("GPIO off");
              outputState = "off";
              
            }
            
            // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons 
            // Feel free to change the background-color and font-size attributes to fit your preferences
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #195B6A; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            
            // Web Page Heading
            client.println("<body><h1>ESP8266 Web Server</h1>");
            
            // Display current state, and ON/OFF buttons for GPIO 5  
            client.println("<p>GPIO - State " + outputState + "</p>");
            // If the output5State is off, it displays the ON button       
            if (output5State=="off") {
              client.println("<p><a href=\"/5/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/5/off\"><button class=\"button button2\">OFF</button></a></p>");
            } 
            
            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}

/* This function checks to see if the user has an appointment by checking if there is data posted on the api.php site.
   The api prints the information based on the current date and the current time.
   If there is no appointment at this date and time, there is no information printed and if there is an appointment at
   this date and time, there will be information printed in the following way.
   Example: 
   [{"idappointments":31,"appt_name":"test123","appt_date":"2023-03-21","appt_time":"12:15:00","appt_context":"testing","appt_tune":"Nokia"}]
*/
String getApptInfo(String tuneOrDark) {
  WiFiClient client;
  HTTPClient httpClient;
  DynamicJsonDocument jsonBuffer(JSONBUFFER);
  
  // The connection to the api
  httpClient.begin(client, APPT_API);
  int httpCode = httpClient.GET();

  // If there is a connection
  if (httpCode == HTTP_CODE_OK) {  // HTTP_CODE_OK == 200
    payload = httpClient.getString();
    deserializeJson(jsonBuffer, payload);
    String apptTune = jsonBuffer[0]["appt_tune"];
    String apptDark = jsonBuffer[0]["appt_dark"];
    Serial.println(apptTune);
    Serial.println(apptDark);

    // If there isn't a connection
  } else {
    Serial.println("Unable to connect :(");
  }
  if (apptTune != null && apptdark !=null) {
    if (tuneOrDark == TUNE_VAL) {
      return apptTune;    
    } else if (tuneOrDark == DARK_VAL) {
      return apptDark;
    }
  } else {
    return NULL;
  }
}
