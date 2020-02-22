#include <WiFi.h>
#include "wificonfig.h"

#include "rc5.cpp"

WiFiServer server(80);
static const int OUTPUT_PIN = 5;
IRrc5 rc5 = IRrc5(OUTPUT_PIN);

void setup() {
  Serial.begin(115200);
  pinMode(OUTPUT_PIN, OUTPUT);
  
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

void sendIndex(WiFiClient client) {
  client.println("HTTP/1.1 200 OK");
  client.println("Content-type:text/html");
  client.println();

  client.print("Click <a href=\"/rc5/1/16\">V+</a><br>ok");

  client.println();
}

void send404(WiFiClient client) {
  client.println("HTTP/1.1 404 Not Found");
  client.println();
  client.println();
}


void loop() {
  WiFiClient client = server.available();
  if (!client) return;

  Serial.println("New Client.");
  while (client.connected()) {
    String line = readLineFrom(client);
    Serial.println(line);

    if (line.startsWith("GET / ")) {
      sendIndex(client);
      break;
    }
    
    if (line.startsWith("GET /rc5/")) {
      line.replace("GET /rc5/", "");
      rc5.write(line.toInt());
      break;
    }

    // if the current line is blank, you got two newline characters in a row.
    // that's the end of the client HTTP request
    if (line.length() == 0) {
      send404(client);
      break;
    }
  }
  
  client.stop();
  Serial.println("Client Disconnected.");
}
