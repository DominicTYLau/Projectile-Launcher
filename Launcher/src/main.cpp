// nrf24_client

#include <SPI.h>
#include <RH_NRF24.h>

// Singleton instance of the radio driver
RH_NRF24 nrf24;

const int relay = 2;
// RH_NRF24 nrf24(8, 7); // use this to be electrically compatible with Mirf
// RH_NRF24 nrf24(8, 10);// For Leonardo, need explicit SS pin
// RH_NRF24 nrf24(8, 7); // For RFM73 on Anarduino Mini

void setup() 
{
  Serial.begin(9600);
  pinMode(relay, OUTPUT);
  while (!Serial) 
    ; // wait for serial port to connect. Needed for Leonardo only
  if (!nrf24.init())
    Serial.println("init failed");
  // Defaults after init are 2.402 GHz (channel 2), 2Mbps, 0dBm
  if (!nrf24.setChannel(1))
    Serial.println("setChannel failed");
  if (!nrf24.setRF(RH_NRF24::DataRate2Mbps, RH_NRF24::TransmitPower0dBm))
    Serial.println("setRF failed");    
}

void fire(){
  for(int i = 5; i > 0; i--){
    Serial.println(i);
    delay(1000);
  }
  Serial.println("fire");
  uint8_t data[] = "fire";
  nrf24.send(data, sizeof(data));
  
  digitalWrite(relay, HIGH);
  delay(5000);
  digitalWrite(relay, LOW);
}

void loop()
{
 while (true) {
    // Wait for user input
    while (Serial.available() == 0) {
      Serial.println("Deactivated");
      delay(3000);
    }

    // Read the input string until a newline character
    String input = Serial.readString();

    // Remove the newline character from the input string
    input.trim();

    if (input == "activate") {
      break; // Exit the loop if the condition is met
    }
  }
  while(true){
  while (Serial.available() == 0) {
      Serial.println("Activated");
      delay(3000);
  }  
    String input = Serial.readString();
    input.trim();

    if(input == "fire"){
      fire();
      break;
    }
    else{
      break;
    }
  }
}

