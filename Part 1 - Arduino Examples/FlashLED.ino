void setup() {
  // Establishes the LED as an output for our program
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // Turns the LED on
  digitalWrite(LED_BUILTIN, HIGH);

  // Adds a delay, in milleseconds
  delay(500);

  // Turns the LED off
  digitalWrite(LED_BUILTIN, LOW);

  // Another delay (so it stays off for the same amount of time)
  delay(500);
  
  // Now that we are at the end, this code will automatically loop
}
