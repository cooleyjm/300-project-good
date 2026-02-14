// Based on Adafruit's pixels_test.ino

#include <Wire.h>
#include <Adafruit_AMG88xx.h>

Adafruit_AMG88xx amg;

float pixels[AMG88xx_PIXEL_ARRAY_SIZE];

void setup() {
    Serial.begin(115200); // JC: Changed to 115200 (from 9600)
    Serial.println(F("AMG88xx pixels"));

    bool status;
    
    // default settings
    status = amg.begin();
    if (!status) {
        Serial.println("Could not find a valid AMG88xx sensor, check wiring!");
        while (1);
    }

    // Intialize to Moving Average Mode -- Uneditable
    amg.setMovingAverageMode(true); // JC
    
    //Serial.println("-- Pixels Test --");

    Serial.println();

    delay(100); // let sensor boot up
}


void loop() { 

    // Boot-Up (JC)
    amg.readPixels(pixels);
    static int avg[64] = {0}; // 8x8

    // Basic Editable Moving Average Filter (JC)
    /*
    const int N = 4;
    for(int i = 0; i < 64; i++){
      avg[i] = (avg[i] + ((pixels[i] - avg[i]) / N) );
    }
    */

    // High Pass Filter (JC) -- Evaluate to True if Pass
    const int pass_val = 30;
    for(int i = 0; i < 64; i++){
      if(pixels[i] >= pass_val){
        avg[i] = 1;
      }
      else{
        avg[i] = 0;
      }
    }

    int col = 0; // JC
    volatile int vl_num = 0; // 0
    volatile int left_num = 0; // 1-2
    volatile int mid_num = 0; // 3-4
    volatile int right_num = 0; // 5-6
    volatile int vr_num; // 7

    Serial.print("[");
    Serial.println();
    for(int i=1; i < 65;  i++){ // New Loop for 8x8
      // Prints row by row

      // Add to Col Zones
      if(avg[i] == 1){
        if(col == 0){
          // Void Left
          vl_num++;
        }
        else if((col == 1) || (col == 2)){
          // Left Num
          left_num++;
        }
        else if((col == 3) || (col == 4)){
          // Middle 
          mid_num++;
        }
        else if((col == 5) || (col == 6)){
          // Right Num
          right_num++;
        }
        else{
          // Right Void
          vr_num++;
        }
      } // End Add to Col Zones

      // Keep track of Col (JC)
      col++;
      if(col == 8){
        col = 0;
      }

      Serial.print(avg[i-1]); // Modified from pixels to avg (JC)
      Serial.print(", ");
      
      if( i%8 == 0 ){
        Serial.println();
      } // End of Row If

    } // End For 8x8 Loop
    Serial.println("]");
    Serial.println();

    // Print Col Data
    /*
    Serial.print("Col Data");
    Serial.println();
    Serial.print("VL: ");
    Serial.print(vl_num);
    Serial.print(" L: ");
    Serial.print(left_num);
    Serial.print(" M: ");
    Serial.print(mid_num);
    Serial.print(" R: ");
    Serial.print(right_num);
    Serial.print(" VR: ");
    Serial.print(vl_num);
    Serial.println();
    Serial.println();
    */

    //delay a second
    //delay(1000);

    // Making delay smaller to improve MAF response
    delay(500);
} // End of Void Loop
