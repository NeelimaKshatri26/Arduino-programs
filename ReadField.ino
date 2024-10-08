/*
  ReadField
  
  Description: Demonstates reading from a public channel which requires no API key and reading from a private channel which requires a read API key.
               The value read from the public channel is the current outside temperature at MathWorks headquaters in Natick, MA.  The value from the
               private channel is an example counter that increments every 10 seconds.
  
  Hardware: ESP8266 based boards
  
  !!! IMPORTANT - Modify the secrets.h file for this project with your network connection and ThingSpeak channel details. !!!
  
  Note:
  - Requires ESP8266WiFi library and ESP8622 board add-on. See https://github.com/esp8266/Arduino for details.
  - Select the target hardware from the Tools->Board menu
  - This example is written for a network using WPA encryption. For WEP or WPA, change the WiFi.begin() call accordingly.
  
  ThingSpeak ( https://www.thingspeak.com ) is an analytic IoT platform service that allows you to aggregate, visualize, and 
  analyze live data streams in the cloud. Visit https://www.thingspeak.com to sign up for a free account and create a channel.  
  
  Documentation for the ThingSpeak Communication Library for Arduino is in the README.md folder where the library was installed.
  See https://www.mathworks.com/help/thingspeak/index.html for the full ThingSpeak documentation.
  
  For licensing information, see the accompanying license file.
  
  Copyright 2020, The MathWorks, Inc.
*/

#include <ESP8266WiFi.h>
#include "secrets.h"
#include "ThingSpeak.h" // always include thingspeak header file after other header files and custom macros

char ssid[] = "iQOO Z3 5G";   // your network SSID (name) 
char pass[] = "NEELIMA26";   // your network password
int keyIndex = 0;            // your network key Index number (needed only for WEP)
WiFiClient  client;


const char * myChannelReadAPIKey ="FT6GB8YM7874Z2TF";


// Weather station channel details
// unsigned long weatherStationChannelNumber = SECRET_CH_ID_WEATHER_STATION;
// unsigned int temperatureFieldNumber = 4;

// // Counting channel details
// unsigned long counterChannelNumber = 2220442;
// const char * myCounterReadAPIKey ="FT6GB8YM7874Z2TF";
// unsigned int counterFieldNumber = 1; 

void setup() {
  Serial.begin(115200);  // Initialize serial
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo native USB port only
  }
  
  WiFi.mode(WIFI_STA); 
  ThingSpeak.begin(client);  // Initialize ThingSpeak
}

void loop() {

  int statusCode = 0;
  
  // Connect or reconnect to WiFi
  if(WiFi.status() != WL_CONNECTED){
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(SECRET_SSID);
    while(WiFi.status() != WL_CONNECTED){
      WiFi.begin(ssid, pass); // Connect to WPA/WPA2 network. Change this line if using open or WEP network
      Serial.print(".");
      delay(5000);     
    } 
    Serial.println("\nConnected");
  }

  // Read in field 4 of the public channel recording the temperature
  // float temperatureInF = ThingSpeak.readFloatField(weatherStationChannelNumber, temperatureFieldNumber);  

  // // Check the status of the read operation to see if it was successful
  // statusCode = ThingSpeak.getLastReadStatus();
  // if(statusCode == 200){
  //   Serial.println("Temperature at MathWorks HQ: " + String(temperatureInF) + " deg F");
  // }
  // else{
  //   Serial.println("Problem reading channel. HTTP error code " + String(statusCode)); 
  // }
  
  // delay(15000); // No need to read the temperature too often.

  // Read in field 1 of the private channel which is a counter  
  long x = ThingSpeak.readLongField( 2220442, 1, myChannelReadAPIKey);  

   // Check the status of the read operation to see if it was successful
  statusCode = ThingSpeak.getLastReadStatus();
  if(statusCode == 200){
    Serial.println("Water Level is: " + String(x));
  }
  else{
    Serial.println("Problem reading channel. HTTP error code " + String(statusCode)); 
  }
  
  delay(1000); // No need to read the counter too often.
  
}
