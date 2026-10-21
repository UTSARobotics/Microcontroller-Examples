void setup() {
  // Starts the communication between our computer and the arduino board
  Serial.begin(9600);

  // Establishes the LED as an output for our program
  pinMode(LED_BUILTIN, OUTPUT);

  // Prints the text into the Serial Monitor with a new line (enter) afterwards
  Serial.println("Type on or off:");
}

void loop() {
  // If a user has sent a message to the Arduino using the Serial Monitor
  if(Serial.available() > 0) {
    
    // Read in that string into a variable called user_input
    String user_input = Serial.readString();

    // Make it lowercase to normalize input
    user_input = user_input.toLowerCase();

    // If user input is "on"
    if(user_input == "on") {
      // Turns the LED on
      digitalWrite(LED_BUILTIN, HIGH);

    // otherwise if it is "off"
    } else if (user_input == "off") {
      // Turns the LED off
      digitalWrite(LED_BUILTIN, LOW);
    
    // If it wasn't one of those two
    } else {
      // Print out that the command was not recognized.
      Serial.println("Unrecognized command. Please type on or off");
    }
  }
}
