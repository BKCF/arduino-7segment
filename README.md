# arduino-7segment
7 segment display driver code for arduino. Includes a sample loop iterating over each digit 0-9.

<img src="/gitres/board.jpg" width=300 height=400>

Each LED used has a resistor connection to ground and a jumper from high to
an arduino digital pin.
Beginning at some digital pin <= 7, connect each LED's high (positive) leg to 
the board in order. Ex: connect LED A to pin 7, then B to 8, etc. 

<img src="/gitres/7seg.png" width=190 height=320>

Note: The starting pin can be changed in the #define tag at the top of the file,
default uses pins 7 - 13.
