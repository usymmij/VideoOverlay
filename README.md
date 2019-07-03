# VideoOverlay
NOTE: all files within \libraries are made by [nootropic design](https://github.com/nootropicdesign). Their repo for those files are [here](https://github.com/nootropicdesign/arduino-tvout-ve). The folder is merely placed in this repo for convenience.

## Installation Instructions
1.   Place the folders inside the folder libraries in

        OSX: /Users/<username>/Documents/Arduino/libraries/
        Windows: /C:/Users/<username>/Documents/Arduino/libraries

2.  set up the following circuit:  
    g: gate, d: drain, s: source  
    ==: 1k ohm resistor  
  >
    MOSFET  
    g  d  s  
    |  |==|  
    |  |  |__OUPUT on shield  
    |  |  
    |  |__INPUT on shield  
    |  
    pin 10  

    
3.  upload VideoOverlay.ino to the arduino attached