#include <Arduino.h>
#include <ESP8266WiFi.h> 
#include "arduino_secrets.h"

int TCPPORT = 9006;
int baudRate = 115200;

// const char* ssid = "SSID"; 
// const char* password = "Password"; 

WiFiServer server(TCPPORT); 
WiFiClient client;

// Setting up capability of watchdog time if polling is enabled we are able to add a watchdog timer to reset the 8266 if it should hang.
int watchdogTimeout = 2000; 
bool watchdogEnabled = false;
int startupDelay = 30;
int JMRIConnectedPin = 0;
bool jmriConnected = false;

unsigned long startTime;
bool switchedToShortWDT = false;

void setup() { 

  Serial.begin(baudRate);    // Connected to Mega Serial3 on KS5014 
  pinMode(JMRIConnectedPin, OUTPUT);
  digitalWrite(JMRIConnectedPin, LOW);

  delay(2000);

  Serial.println("-------------------------------");
  Serial.println("ESP8266 startup and initialization.");
  Serial.println("-------------------------------");


  WiFi.mode(WIFI_STA); 
  WiFi.begin(SECRET_SSID, SECRET_PASSWORD); 

  while (WiFi.status() != WL_CONNECTED) { 
    delay(500); 
    Serial.print("ESP8266 connecting to ");
    Serial.print(SECRET_SSID);
    Serial.println("......");
  } 

  Serial.print("ESP8266 connected to ");
  Serial.println(SECRET_SSID);

  printWifiStatus();

  server.begin(); 
  server.setNoDelay(true); 

  delay(500);

  Serial.print("ESP8266 started Server on TCP");
  Serial.println(String(TCPPORT));
  Serial.println("ESP8266 waiting for JMRI to connect.");

} 

void loop() { 
  // Accept new client if none connected 

  if (!client || !client.connected()) { 
    client = server.available();
    if(jmriConnected) {
      Serial.println("ESP8266 JMRI system disconnected."); 
      digitalWrite(JMRIConnectedPin, LOW);
    }
    jmriConnected = false;
    return; 
  } 

  if(!jmriConnected) {
    Serial.println("ESP8266 JMRI system connected."); 
    jmriConnected = true;
    digitalWrite(JMRIConnectedPin, HIGH);
  }

    // Forward data from client → Mega 
  if (client.available()) { 
    while (client.available()) { 
      Serial.write(client.read()); 
      // String req = client.readStringUntil((char)0x03); 
      // Serial.println(req);   
    } 
  } 

  // Forward data from Mega → client 
  if (Serial.available()) { 
    while (Serial.available()) { 
      client.write(Serial.read()); 
      // When data is received from the Mega, it's in response to a CMRI poll request, we can enable the watchdog timer.
    } 
  } 
} 

void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.println("-------------------------------");
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your board's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
  Serial.println("-------------------------------");
}