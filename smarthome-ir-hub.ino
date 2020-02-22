#include <WiFi.h>
#include "wificonfig.h"

WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  pinMode(5, OUTPUT);
  
  delay(10);
  
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  
  server.begin();
}

String readLineFrom(WiFiClient client) {
  String res = ""; 
  while (true) {
    if (!client.connected()) break;
    if (!client.available()) continue; // TODO consider delay instead of continue
    
    char c = client.read();
    if (c == '\n') break;
    if (c != '\r') res += c;
  }
  return res;
}

void sendResponse(WiFiClient client) {
  client.println("HTTP/1.1 200 OK");
  client.println("Content-type:text/html");
  client.println();

  client.print("Click <a href=\"/H\">here</a><br>ok");

  client.println();
}

void loop() {
  WiFiClient client = server.available();
  if (!client) return;

  Serial.println("New Client.");
  while (client.connected()) {
    String line = readLineFrom(client);
    Serial.println(line);
    
    if (line.endsWith("GET /H")) {
      digitalWrite(5, HIGH);
    }

    // if the current line is blank, you got two newline characters in a row.
    // that's the end of the client HTTP request, so send a response:
    if (line.length() == 0) {
      sendResponse(client);
      break;
    }
  }
  
  client.stop();
  Serial.println("Client Disconnected.");
}
