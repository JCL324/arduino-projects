
// Include the ESP8266 WiFi library. (Works a lot like the
// Arduino WiFi library.)
#include <ESP8266WiFi.h>
// Include the SparkFun Phant library.
//#include <Phant.h>

WiFiServer server(80); //Initialize the server on Port 80

//////////////////////
// WiFi Definitions //
//////////////////////
const char WiFiSSID[] = "ADD_WIFI_SSID_NAME_HERE";
const char WiFiPSK[] = "ADD_WIFI_PASSWORD_HERE";

/////////////////////
// Pin Definitions //
/////////////////////
const int LED_PIN = 5; // Thing's onboard, green LED
const int ANALOG_PIN = A0; // The only analog pin on the Thing
const int DIGITAL_PIN = 12; // Digital pin to be read

// Time to sleep (in seconds):
const int sleepTimeS = 30;

void setup() 
{
  initHardware();
  connectWiFi();
  server.begin();
  digitalWrite(LED_PIN, HIGH);
  pinMode(BUILTIN_LED, OUTPUT);  // initialize onboard LED as output
}

void connectWiFi()
{
  byte ledStatus = LOW;

  // Set WiFi mode to station (as opposed to AP or AP_STA)
  WiFi.mode(WIFI_STA);
  // WiFI.begin([ssid], [passkey]) initiates a WiFI connection
  // to the stated [ssid], using the [passkey] as a WPA, WPA2,
  // or WEP passphrase.
  WiFi.begin(WiFiSSID, WiFiPSK);

  // Use the WiFi.status() function to check if the ESP8266
  // is connected to a WiFi network.
  while (WiFi.status() != WL_CONNECTED)
  {
    // Blink the LED
    digitalWrite(LED_PIN, ledStatus); // Write LED high/low
    ledStatus = (ledStatus == HIGH) ? LOW : HIGH;

    // Delays allow the ESP8266 to perform critical tasks
    // defined outside of the sketch. These tasks include
    // setting up, and maintaining, a WiFi connection.
    delay(100);
    // Potentially infinite loops are generally dangerous.
    // Add delays -- allowing the processor to perform other
    // tasks -- wherever possible.
  }
}

void initHardware()
{
  Serial.begin(9600);
  pinMode(DIGITAL_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  // Don't need to set ANALOG_PIN as input, 
  // that's all it can be.
}

void loop() {
    
  WiFiClient client = server.available();
  if (!client) { 
    return; 
  } 
  //Looking under the hood 
  Serial.println("Somebody has connected :)");
  
  //Read what the browser has sent into a String class and print the request to the monitor
  String request = client.readStringUntil('\r');
  //Looking under the hood 
  Serial.println(request);    

  // Handle the Request

  if (request.indexOf("/OFF") != -1){ 
    Serial.println("Turn Light Off");
    digitalWrite(BUILTIN_LED, HIGH); }
  else if (request.indexOf("/ON") != -1){ 
    Serial.println("Turn Light On");
    digitalWrite(BUILTIN_LED, LOW); 
  }


  String s = "HTTP/1.1 200 OK\r\n";
  s += "Content-Type: text/html\r\n\r\n";
  s += "<DOCTYPE HTML>\r\n";
  s += "<html>\r\n";
  s += "<body>\r\n";
  s += "<br><input type=\"button\" name=\"b1\" value=\"Turn LED ON\" onclick=\"location.href='/ON'\">\r\n";
  s += "<br><br>\r\n";
  s += "<br><input type=\"button\" name=\"b2\" value=\"Turn LED OFF\" onclick=\"location.href='/OFF'\">\r\n";
  s += "</body>\r\n";
  s += "</html>\r\n";  
  
  client.flush(); //clear previous info in the stream 
  client.print(s); // Send the response to the client 
  delay(1); 
  Serial.println("Client disonnected"); //Looking under the hood
}
