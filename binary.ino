/**
 * Binary Counter for Arduino
 *
 * Designed as a project for students to introduce them to Arduinos and
 * programming.
 *
 * Written by Dave Hall - http://davehall.com.au
 */

// Define our LED pins.
int ledPin[] = {4, 5, 6, 7,};

// The number of LEDS configured.
int numLeds = 4;

// Define our input button pin.
int buttonPin = 3;

// Always start the counter at 0.
byte counter = 0;

// Calculate the maximum value to be displayed.
int maxValue = 7;

/**
 * Perform the initial setup of our device.
 */
void setup()
{
  // Tell the arduino to listen for input from the button.
  pinMode(buttonPin, INPUT);

  // Tell the arduino to expect output
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPin[i], OUTPUT);
  }

  // Blink each of the LEDs to confirm the circuit is correct.
  fastBlink();
}

/**
 * What to do continuously until stopped.
 */
void loop()
{
  // Check if our button is being pressed
  if (digitalRead(buttonPin) == HIGH) {
    // Increment the counter.
    counter++;
    // Wait half a second so we don't double count presses.
    delay(500);
    // Update our display.
    displayBinary(counter);
  }

  // Make sure we don't go past our maximum allowed value.
  if (counter >= maxValue) {
    // Make sure the user sees all the LEDs lit up.
    delay(1000);
    // Reset our counter.
    counter = 0;
	displayBinary(counter);
  }
}

/**
 * Displays the value as a binary number using an array of LEDs.
 *
 * Derived from work by M Atkinson.
 * http://www.multiwingspan.co.uk/arduino.php?page=led5
 */
void displayBinary(byte numToShow)
{
  // Check each of the bits in our number.
  for (int i = 0; i < numLeds; i++)
  {
    // Is the bit "on"?
    if (bitRead(numToShow, i) == 1)
    {
      // Turn the LED on.
      digitalWrite(ledPin[i], HIGH);
    }
    else
    {
      // Turn the LED off.
      digitalWrite(ledPin[i], LOW);
    }
  }
}
