#include <SPI.h>
#include <MFRC522.h>

constexpr uint8_t RST_PIN = 9;     // Configurable, see typical pin layout above
constexpr uint8_t SS_PIN = 10;     // Configurable, see typical pin layout above
//Define pins for Data OUTPUT-Change as Required
#define MOSI_PIN    D3      // hardware SPI: A5
#define MISO_PIN    D4      //     "     " : A4
#define SCK_PIN     D5      //     "     " : A3

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

 MFRC522::MIFARE_Key key;

char* allowedTags[] = {
"[INSERT IDENTIFIER HERE]", // Tag 1
"2900940E95", // Tag 2
"ABC123DE45", // Tag 3
};

// List of names to associate with the matching tag IDs
char* tagName[] = {
"[ADD YOUR NAME HERE]", // Tag 1
"Mark Trussell", // Tag 2
"NAME 3", // Tag 3
};

// Check the number of tags defined
int numberOfTags = sizeof(allowedTags)/sizeof(allowedTags[0]);

int incomingByte = 0; // To store incoming serial data

void setup() {
Serial.begin(9600); // Initialize serial communications with the PC
    while (!Serial);    // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
    SPI.begin();        // Init SPI bus
    mfrc522.PCD_Init(); // Init MFRC522 card
    // Prepare the key (used both as key A and as key B)
    for (byte i = 0; i < 6; i++) {
        key.keyByte[i] = 0xFF;
    }

    Serial.println(F("Scan a MIFARE Classic PICC to demonstrate read and write."));
    Serial.print(F("Using key (for A and B):"));
    dump_byte_array(key.keyByte, MFRC522::MF_KEY_SIZE);
    Serial.println();
    Serial.println(F("BEWARE: Data will be written to the PICC, in sector #1"));
}



void loop() {
  if ( ! mfrc522.PICC_IsNewCardPresent()){
    RC522.readCardSerial();
    Serial.println("Card detected:");
    /* Output the serial number to the UART */
    for(i = 0; i <= 4; i++)
    {
      Serial.print(RC522.serNum[i],HEX);
      Serial.print(" ");
    }
    Serial.println();
  }
  else
      Serial.println("Card NOT detected:");
      
  delay(1000);
  }
        return;

    // Select one of the cards
    if ( ! mfrc522.PICC_ReadCardSerial())
        return;
}
 // Dump debug info about the card; PICC_HaltA() is automatically called
  mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
}
