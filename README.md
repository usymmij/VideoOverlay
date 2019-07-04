# VideoOverlay
**NOTE**: all files within \libraries are made by [nootropic design](https://github.com/nootropicdesign). A small modification was added as described in the forum noted below. Their repo for those files(unmodified) are [here](https://github.com/nootropicdesign/arduino-tvout-ve). The folder with the modified libraries is placed in this repo for convenience.

## Installation Instructions
1.  ### Place the folders inside the folder libraries in here

        OSX: /Users/<username>/Documents/Arduino/libraries/
        Windows: /C:/Users/<username>/Documents/Arduino/libraries

2.  ### set up the following circuit:  
    Video experimenter settings should be SYNC ONLY and sync select jumper should short V AND INPUT  
    any MOSFET should work but the one used by us was the IRF540  
    g: gate, d: drain, s: source  
    ==: 240 ohm resistor  
    
    >  
    > IRF540  
    > g&nbsp;&nbsp;&nbsp;d&nbsp;&nbsp;&nbsp;s  
    > |&nbsp;&nbsp;&nbsp;&nbsp;|==|  
    > |&nbsp;&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp; |__OUPUT on shield  
    > |&nbsp;&nbsp;&nbsp;&nbsp;|  
    > |&nbsp;&nbsp;&nbsp;&nbsp;|__INPUT on shield  
    > |  
    > pin 10     

    
3.  ### upload VideoOverlay.ino to the arduino attached

## Modifications made to the TVout library
The TVout library(not the core version, the one built for the video experimenter from [here](https://github.com/nootropicdesign/arduino-tvout-ve)) has a modification made to it. This modification was sourced from the [forum](https://nootropicdesign.com/store/forums/) in this [thread](https://nootropicdesign.com/store/forums/topic/black-letters/)

### VideoGen.cpp
        - add the macros
        ```C
        #define MIN_BAR 30 //minimum top of the bar is 30
        #define MAX_BAR 60 //maximum bottom of the bar is 240
        ```
        - add this to the **very top** of the function `render_line5c()`
        ```C
        if ((display.scanLine > MIN_BAR) && (display.scanLine < MAX_BAR)) {
                PORTB &= ~(_BV(2));  // video off for lower lines
        }
        ```
        - add this to the **very bottom** of the function `render_line5c()`
        ```C
        PORTB |= _BV(2);
        ```  
