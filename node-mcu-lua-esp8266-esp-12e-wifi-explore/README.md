# Summary

Just some notes to get  up and running with this chip

## Installing the board in Arduino IDE

In the Arduino IDE open the Preferences window and enter the URL below into the Additional Boards Manager URLs field, and select OK.

http://arduino.esp8266.com/stable/package_esp8266com_index.json

Select the menu option Tools → Board → Boards Manager... and scroll down and to locate the option esp8266 by ESP8266 Community which should be the last item on the list, and click Install.

After restarting the Arduino IDE we can now select the board we're using from the menu option Tools → Board → NodeMCU 1.0 (ESP-12E Module). Then, we specify the correct CPU Frequency (Tools → CPU Frequency: "" → 80MHz) and Upload Speed (Tools → Upload Speed: "" → 115200). Finally, the last step is to select the correct option for the Port (Tools → Port → /dev/cu.SLAB_USBtoUART).

At this point we can write our own firmware and upload it. To get started we can try one of the examples File → Examples → ESP8266WiFi → WiFiScan. After uploading it, we can open the Serial Monitor window and observe the results. Note that we need to match the baud rate, so check that 115200 is selected from the drop down menu

## Links

* [NodeMcu Lua ESP8266 ESP-12E WIFI Development Board Sale-Banggood.com](http://www.banggood.com/NodeMcu-Lua-ESP-12E-WIFI-Development-Board-p-985891.html)

* [Get Started with ESP8266 Using AT Commands, NodeMCU, or Arduino (ESP-12E) - All](http://www.instructables.com/id/Get-Started-with-ESP8266-Using-AT-Commands-NodeMCU/)

* [ESP8266 Quick Start Guide](http://benlo.com/esp8266/esp8266QuickStart.html)
