// Define the pins being used from the LEDs
//                    green/red

#define RED 9
#define GREEN 8

char LED_Pins_array[] = { RED, GREEN};
 
// Array to hold the LED sequence. green, yellow, red, yellow, green.
// position 0 is not used (considered not good practice but keeps the code easy to understand)
char LED_Sequence_array[] = { RED, GREEN};
byte squenceLength = 2;
 
int pin_switch = 2;
 
// variables to hold the new and old switch states
boolean oldSwitchState = LOW;
boolean newSwitchState1 = LOW;
boolean newSwitchState2 = LOW;
boolean newSwitchState3 = LOW;
 
byte state = -1;
 
void setup() 
{
    /*Serial.begin(9600);
    Serial.print("Sketch:   ");   Serial.println(__FILE__);
    Serial.print("Uploaded: ");   Serial.println(__DATE__);
    Serial.println(" ");*/
 
    for (byte i=0; i< 3; i++)
    {    
         pinMode(LED_Pins_array[i], OUTPUT);    digitalWrite(LED_Pins_array[i],LOW); 
    }
    pinMode(pin_switch, INPUT); 
}
 
void loop()
{
    newSwitchState1 = digitalRead(pin_switch);
    delay(1);
    newSwitchState2 = digitalRead(pin_switch);
    delay(1);
    newSwitchState3 = digitalRead(pin_switch);
 
    // if all 3 values are the same we can continue
    if (  (newSwitchState1==newSwitchState2) && (newSwitchState1==newSwitchState3) )
    {
        if ( newSwitchState1 != oldSwitchState ) 
        {
 
           // has the button switch been closed?
           if ( newSwitchState1 == HIGH )
           {
 
                state++;
                if (state > (squenceLength) ) { state = 0; }
 
                // turn all LEDs off. Doing it this way means we do not need to care about the individual LEDs
                // simply turn them all off and then turn on the correct one. 
                for (byte i=0; i< 3; i++)
                {
                     digitalWrite(LED_Pins_array[i],LOW); 
                }
 
                // Turn on the next LED
                digitalWrite(LED_Sequence_array[state],HIGH); 
           }
           oldSwitchState = newSwitchState1;
        }  
    }
}
