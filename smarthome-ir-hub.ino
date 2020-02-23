#include <M5Stack.h>
#include <WiFi.h>
#include "wificonfig.h"

#include "rc5.cpp"
#include "fujitsu-rah2e.cpp"

WiFiServer server(80);
static const int OUTPUT_PIN = 5;
IRrc5 rc5 = IRrc5(OUTPUT_PIN);
IRFujitsuRah2e rah2e = IRFujitsuRah2e(OUTPUT_PIN);

void setup() {
  M5.begin();

  M5.Lcd.setBrightness(200);    // BRIGHTNESS MAX 255
  M5.Lcd.fillScreen(BLACK);

  Serial.begin(115200);

  pinMode(OUTPUT_PIN, OUTPUT);

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

  M5.Lcd.setTextSize(3);
  M5.Lcd.print(WiFi.localIP());

  server.begin();
}

String readLineFrom(WiFiClient client) {
  String res = "";
  while (true) {
    if (!client.connected()) break;
    for(int i=0; !client.available(); i++) {
      delay(2);
      if (i==500*2) {
        Serial.println("Timed out");
        return res;
      }
    }

    char c = client.read();
    if (c == '\n' || !c) break;
    if (c != '\r') res += c;
  }
  return res;
}

void sendIndex(WiFiClient client) {
  client.println("HTTP/1.1 200 OK");
  client.println("Content-type:text/html");
  client.println();

  client.print("<!doctype html><html lang=\"en\"><head><meta charset=\"utf-8\"/><title>IR Hub</title><link href=\"https://jorenca.github.io/smarthome-ir-hub/static/css/main.26ba6ad6.chunk.css\" rel=\"stylesheet\"></head><body><noscript>You need to enable JavaScript to run this app.</noscript><div id=\"root\"></div><script>!function(e){function r(r){for(var n,i,l=r[0],f=r[1],a=r[2],c=0,s=[];c<l.length;c++)i=l[c],Object.prototype.hasOwnProperty.call(o,i)&&o[i]&&s.push(o[i][0]),o[i]=0;for(n in f)Object.prototype.hasOwnProperty.call(f,n)&&(e[n]=f[n]);for(p&&p(r);s.length;)s.shift()();return u.push.apply(u,a||[]),t()}function t(){for(var e,r=0;r<u.length;r++){for(var t=u[r],n=!0,l=1;l<t.length;l++){var f=t[l];0!==o[f]&&(n=!1)}n&&(u.splice(r--,1),e=i(i.s=t[0]))}return e}var n={},o={1:0},u=[];function i(r){if(n[r])return n[r].exports;var t=n[r]={i:r,l:!1,exports:{}};return e[r].call(t.exports,t,t.exports,i),t.l=!0,t.exports}i.m=e,i.c=n,i.d=function(e,r,t){i.o(e,r)||Object.defineProperty(e,r,{enumerable:!0,get:t})},i.r=function(e){\"undefined\"!=typeof Symbol&&Symbol.toStringTag&&Object.defineProperty(e,Symbol.toStringTag,{value:\"Module\"}),Object.defineProperty(e,\"__esModule\",{value:!0})},i.t=function(e,r){if(1&r&&(e=i(e)),8&r)return e;if(4&r&&\"object\"==typeof e&&e&&e.__esModule)return e;var t=Object.create(null);if(i.r(t),Object.defineProperty(t,\"default\",{enumerable:!0,value:e}),2&r&&\"string\"!=typeof e)for(var n in e)i.d(t,n,function(r){return e[r]}.bind(null,n));return t},i.n=function(e){var r=e&&e.__esModule?function(){return e.default}:function(){return e};return i.d(r,\"a\",r),r},i.o=function(e,r){return Object.prototype.hasOwnProperty.call(e,r)},i.p=\"/\";var l=this[\"webpackJsonpir-hub-web-ui\"]=this[\"webpackJsonpir-hub-web-ui\"]||[],f=l.push.bind(l);l.push=r,l=l.slice();for(var a=0;a<l.length;a++)r(l[a]);var p=f;t()}([])</script><script src=\"https://jorenca.github.io/smarthome-ir-hub/static/js/2.97472629.chunk.js\"></script><script src=\"https://jorenca.github.io/smarthome-ir-hub/static/js/main.b3e8f2b0.chunk.js\"></script></body></html>");

  client.println();
}

void send404(WiFiClient client) {
  client.println("HTTP/1.1 404 Not Found");
  client.println();
  client.println();
}

void send200(WiFiClient client) {
  client.println("HTTP/1.1 200 OK");
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
      send200(client);
      break;
    }

    if (line.startsWith("GET /rah2e/")) {
      line.replace("GET /rah2e/", "");
      line.replace(" HTTP/1.1", "");
      
      char data[20];
      int len = 0;
      while(len < 20 && line.length() > 0) {
        int nextDelimiter = line.indexOf('/');
        if (nextDelimiter == -1) nextDelimiter = line.length();
        data[len++] = line.substring(0, nextDelimiter).toInt();
        line.remove(0, nextDelimiter+1);
      }

      rah2e.send(data, len);
      send200(client);
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
