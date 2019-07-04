# VideoOverlay
NOTE: all files within \libraries are made by [nootropic design](https://github.com/nootropicdesign). A small modification was added as described in the forum noted below. Their repo for those files(unmodified) are [here](https://github.com/nootropicdesign/arduino-tvout-ve). The folder is merely placed in this repo for convenience.

## Installation Instructions
1.   Place the folders inside the folder libraries in

        OSX: /Users/<username>/Documents/Arduino/libraries/
        Windows: /C:/Users/<username>/Documents/Arduino/libraries

2.  set up the following circuit:
    any MOSFET should work but the one used by us was the IRF540
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

## Modification made to the TVout library
The TVout library(not the core version, the one built for the video experimenter from [here](https://github.com/nootropicdesign/arduino-tvout-ve)) has a modification made to it. This modification was sourced from the [forum](https://nootropicdesign.com/store/forums/) in this [thread](https://nootropicdesign.com/store/forums/topic/black-letters/)
