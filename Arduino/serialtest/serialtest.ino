void setup() {
  Serial.begin(115200); // initialize serial communication at 9600 bits per second
}

void loop() {
  if (Serial.available() > 0) { // check if there is data available on the serial port
    String incomingByte = Serial.readString(); // read the incoming byte
    Serial.println(incomingByte); // send the incoming byte back to the computer
  }
}
