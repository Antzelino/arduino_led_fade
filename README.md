# arduino_led_fade
Code for Arduino IDE to fade in and out for anything that works with the analog pin

Can work with 2 ways, depending on preference. set `mode = 1` for first mode and `mode = 2` for second mode.

**First mode** iterates every value of analog output, from 0 to 255 and changes the delay between them.

**Second mode** changes the value of analog output exponentially, and keeps the delay time constant between each value (so analog output might not end up having every possible value)
