/*********
  Rui Santos
  Complete project details at http://randomnerdtutorials.com  
*********/

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

MDNSResponder mdns;

// Replace with your network credentials
const char* ssid = "REPLACE_WITH_YOUR_SSID";
const char* password = "REPLACE_WITH_YOUR_PASSWORD";

ESP8266WebServer server(80);

String webPage = "";

// LED GPIOs
int led1 = 5;
int led2 = 4;

void setup(void){
  // Creates a web page, so that you can control the ESP8266 
  // using your web browser
  webPage += "<h1>ESP8266 Web Server</h1><p>LED #1 <a href=\"ON1\"><button>ON</button></a>&nbsp;<a href=\"OFF1\"><button>OFF</button></a></p>";
  webPage += "<p>LED #2 <a href=\"ON2\"><button>ON</button></a>&nbsp;<a href=\"OFF2\"><button>OFF</button></a></p>";
  
  // Preparing GPIOs
  pinMode(led1, OUTPUT);
  digitalWrite(led1, LOW);
  pinMode(led2, OUTPUT);
  digitalWrite(led2, LOW);

  // Connects to your router via WiFi
  delay(1000);
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  
  if (mdns.begin("esp8266", WiFi.localIP())) {
    Serial.println("MDNS responder started");
  }
  
  server.on("/", [](){
    server.send(200, "text/html", webPage);
  });
  // Turns the led1 ON
  server.on("/ON1", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(led1, HIGH);
    delay(1000);
  });
  // Turns the led1 OFF
  server.on("/OFF1", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(led1, LOW);
    delay(1000); 
  });
  // Turns the led2 ON
  server.on("/ON2", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(led2, HIGH);
    delay(1000);
  });
  // Turns the led2 OFF
  server.on("/OFF2", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(led2, LOW);
    delay(1000); 
  });
  server.begin();
  Serial.println("HTTP server started");
}
 
void loop(void){
  // Handles all the client connections
  server.handleClient();
} 
