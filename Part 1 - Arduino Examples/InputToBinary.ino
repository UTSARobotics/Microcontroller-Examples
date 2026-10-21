// Authored by:     Justin Joslin
// Created:         10-20-2026
// Last modified:   10-20-2026

// Runs ONLY ONE TIME when the board initializes.
void setup() {
  // Starts the communication between our computer and the arduino board
  Serial.begin(9600);

  // Establishes the LED as an output for our program
  pinMode(LED_BUILTIN, OUTPUT);

  // Prints the text into the Serial Monitor with a new line (enter) afterwards
  Serial.println("Type some text:");
}

// Runs continuously after the board has been ititialized
void loop() {

  // If the user has sent a message through the Serial Monitor
  if (Serial.available() > 0) {

    // Turns that message into a string we can manipulate later
    String user_input = Serial.readString();

    // Prints the text to the Serial Monitor without a new line so we can add more onto the same line
    Serial.print("Recieved: ");

    // Prints the text with a new line to the Serial Monitor (will print on the same line as the last print)
    Serial.println(user_input);
    
    // For every character (input_ch) in the user_input String
    for (char input_ch : user_input) {

      // Cast that character into an int, and save that to the variable ascii_value
      int ascii_value = static_cast<int>(input_ch);

      // Run the binary_value function (defined outside of the loop) to give us the binary value as a String
      String binary = binary_value(ascii_value);

      // Print out the charcater and its binary value to the Serial Monitor
      Serial.println(String(input_ch) + ": " + binary);

      // Runs the function that will flash the LED according to its binary value (defined outside of the loop)
      flash_binary(binary);
    }
  }
}

// Custom defined function that takes in a number and turns it into a binary string
String binary_value(int num) {

  // Will start at the last bit in the string (counts from 0 to 7)
  int pos = 7;

  // Define the binary string with 8 bits
  String binary_result = "00000000";

  // Loop until we have either wrote to all 8 bits or if the num variable (passed in through the function) is 0
  while(num != 0 && pos >= 0) {

    // Edit the string at 'pos' (starts at pos 7, the last number in the string)
    // Does bitwise & operation to get the value then converts it to a character
    binary_result[pos] = (num & 1) + '0';

    // Bitshift the number to the right
    num >>= 1;

    // Subtract one from 'pos' so we edit the next number in the string during the next loop
    pos--;
  }

  // Returns the result as a string
  return binary_result;
}

// Custom defined function that will make the LED flash based on the binary string passed into it
void flash_binary(String binary){

  // For every character (ch) in the binary string sequence
  for (char ch : binary) {

    // If it is 0, we want to do a short flash
    if(ch == '0'){
      // Turn on LED
      digitalWrite(LED_BUILTIN, HIGH);
      // Very short delay (200ms or 0.2 seconds)
      delay(200);
      // Turn off LED
      digitalWrite(LED_BUILTIN, LOW);
    
    // If it is anything else other than a zero (presumably a 1) we want to do a long flash
    } else {
      // Turn the LED on
      digitalWrite(LED_BUILTIN, HIGH);
      // Longer delay this time (600ms or 0.6 seconds)
      delay(600);
      //Turn the LED off
      digitalWrite(LED_BUILTIN, LOW);
    }
    // a 200ms or 0.2 second delay between every short OR long flash
    delay(200);
  }
}
