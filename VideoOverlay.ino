#include <TVout.h>
#include <fontALL.h>

#define W 136
#define H 96
#define MAX_LENGTH 33 //maximum message length since scrolling was disabled

TVout tv;
char message[33] = "Test Test Test Test Test";

void setup()  {
  tv.begin(NTSC, W, H);
  initOverlay();
  tv.select_font(font4x6);
  tv.fill(0);
  pinMode(10, OUTPUT);
}

// Initialize ATMega registers for video overlay capability.
// Must be called after tv.begin().
void initOverlay() {
  TCCR1A = 0;
  // Enable timer1.  ICES0 is set to 0 for falling edge detection on input capture pin.
  TCCR1B = _BV(CS10);

  // Enable input capture interrupt
  TIMSK1 |= _BV(ICIE1);

  // Enable external interrupt INT0 on pin 2 with falling edge.
  EIMSK = _BV(INT0);
  EICRA = _BV(ISC01);
}

// Required to reset the scan line when the vertical sync occurs
ISR(INT0_vect) {
  display.scanLine = 0;
}

void loop() {
  //tv.draw_line(0, 0, 0, 50, 1);
    tv.print(10, 2, message); //y should be top of black bar - 28~29
}
