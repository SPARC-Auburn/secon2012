// --- Pin Overwrites ---
// Comment out if you plan on using the file-default pin values.
#define OVERWRITE_MOTOR_PINS // Use these motor pin values
#define OVERWRITE_RELAY_PINS // Use these relay pin values
#define OVERWRITE_TASK_PINS  // Use these task sensor pin values
#define OVERWRITE_QTR_PINS   // Use these QTR sensor pin values

// --- Motor Pin Definitions ---
#ifdef OVERWRITE_MOTOR_PINS
  #define LEFT_PWM_PIN   5  // (PWM) DPin 5  - Left motor PWM speed control
  #define LEFT_DIR_PIN   38 // (DIG) DPin 38 - Left motor direction control
  #define LEFT_EN_PIN    36 // (DIG) DPin 36 - Left motor enable control
  #define RIGHT_PWM_PIN  2  // (PWM) DPin 2  - Right motor PWM speed control 
  #define RIGHT_DIR_PIN  3  // (DIG) DPin 3  - Right motor direction control
  #define RIGHT_EN_PIN   4  // (DIG) DPin 4  - Right motor enable control
#endif

// --- Relay Pin Definitions ---
#ifdef OVERWRITE_RELAY_PINS
  #define RELAY_K1_PIN   52 // (DIG) DPin 52 - Control Relay 1
  #define RELAY_K2_PIN   53 // (DIG) DPin 53 - Control Relay 2
#endif

// --- Task Sensor Pin Definitions ---
#ifdef OVERWRITE_TASK_PINS  
  // Hit switch pins:
    #define HIT_SWITCH_PIN 40 // (DIG) DPin 40 - Physical switch pin
  // Capcitance sensor pins:
    #define PIN_CR1        A1 // (ANA) APin 1  - Samples the cap voltage (analog)
    #define PIN_CR2        A2 // (DIG) APin 2  - Discharges the capacitor (digital)
    #define PIN_CR3        A3 // (DIG) APin 3  - Charges the capacitor (digital)
  // Voltage sensor pins:
    #define PIN_VOLT       A0 // (ANA) APin0   - Measure voltage
  // Temperature sensor pins:
    #define PIN_TEMP       11 // (DIG) DPin11  - For measuring temperature
  // Waveform sensor pins (D0-D7 also used, PORTB):
    #define PIN_RD         8  // (DIG) DPin 8  - Connected to RD of the MAX153
    #define PIN_INT        9  // (DIG) DPin 9  - Connected to INT of the MAX 153
    #define PIN_CS         10 // (DIG) DPin 10 - Connected to CS of MAX 153
#endif

// --- QTR Sensor Pin Definitions ---
#ifdef OVERWRITE_QTR_PINS
  unsigned char fSensorPins[] = {12,11,10,9,8,7,6,33,35,37,39,41,43,45}; // Main line sensor
  unsigned char lEncoderPins[] = {46}; // Left encoder sensor
  unsigned char rEncoderPins[] = {48}; // Right encoder sensor
#endif
