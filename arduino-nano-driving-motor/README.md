# Summary

The goal of this project was to get a 28BYJ-48 stepper motor turning using a Arduino Nano Chinese knockoff.

First step was programming the Arduino Nano, with the main obstacle being finding the drivers.  The first link below has a good summary of this, but I have also downloaded and included the .zip file for Win 8/10 and OSX in this repo.

Second major issue I encountered was, you really should solder the header pins onto the Arduino to get consistent results.  I wasted a lot of time debugging pinout, moving wires around etc b/c I thought the Nano "just did work" as advertised.  Turns out, trying to use the Nano in a breadboard without soldering the headers in can give you spotty connections and the appearance that certain digital I/O don't work.


# Links

* [How to use cheap Chinese Arduinos that come with with CH340G / CH341G Serial/USB chip (Windows & Mac OS-X) · Personal blog by Konstantin Gredeskoul](http://kiguino.moos.io/2014/12/31/how-to-use-arduino-nano-mini-pro-with-CH340G-on-mac-osx-yosemite.html)

* [Stepper motor wiring tutorial | 42 Bots](http://42bots.com/tutorials/stepper-motor-wiring-how-to/)
