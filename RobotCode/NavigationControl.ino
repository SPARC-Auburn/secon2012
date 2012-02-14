#include <EEPROM.h>

#define FTA_CYCLE_SIZE  7 // Defines the size (in bytes) of the ftaCycle struct.

// Container for the "follow, terminate, action" cycle values.
struct ftaCycle{
  byte follow;      // "Line-following" vs. "simple encoder travel"
  byte terminate;   // "At right turn", "at left turn", "off the line", etc.
  byte action;      // "turn in place", "turn left wheel then right", "turn right wheel then left"
  int leftAmount;   // Number of encoder clicks to turn left wheel forward (negative is backward)
  int rightAmount;  // Number of encoder clicks to turn right wheel forward (negative is backward)
};

// Executes the three-stage cycle (follow, terminate, action) for a given segment of course.
void executeSegment(int segment)
{
  // Retrieve FTA information from EEPROM:
  ftaCycle current;
  current.follow = EEPROM.read(segment * FTA_CYCLE_SIZE);          // Read the follow type
  current.terminate = EEPROM.read((segment * FTA_CYCLE_SIZE) + 1); // Read the termination type
  current.action = EEPROM.read((segment * FTA_CYCLE_SIZE) + 2);    // Read the action type
  byte tempMSB = EEPROM.read((segment * FTA_CYCLE_SIZE) + 3);      // Read MSB of leftAmount
  byte tempLSB = EEPROM.read((segment * FTA_CYCLE_SIZE) + 4);      // Read LSB of leftAmount
  current.leftAmount = word(tempMSB,tempLSB);            // Combine MSB and LSB
  tempMSB = EEPROM.read((segment * FTA_CYCLE_SIZE) + 5); // Read MSB of righttAmount
  tempLSB = EEPROM.read((segment * FTA_CYCLE_SIZE) + 6); // Read LSB of righttAmount
  current.rightAmount = word(tempMSB,tempLSB);           // Combine MSB and LSB
  
  // TODO:
  // Execute follow-type until termination occurs.
  // Perform appropriate action.
  
}


// Old navigation loop for temporary reference.
// NOTE: DO NOT USE THIS FUNCTION!
void oldLoop()
{
  
  int turnType = isTurn();
  //dynamic_PID();
  switch (mainLoc)
  {
    case 0: // At mainLoc M0
      followLine(); // Follow the line until turn is detected
      if (turnType == AT_RIGHT || turnType == OFF_LINE) 
      {
        turnRight(); // Should only detect a right turn
        mainLoc = 1; // Bot is now at mainLoc M1
        setMove(MOVE_FORWARD); // Begin moving forward again
      }
      break;
    case 1: // At mainLoc M1
      navigateTask();
      break;
    case 2: // At mainLoc M2
      navigateTask();
      break;
    case 3: // At mainLoc M3
      followLine(); // Follow the line unless turn is detected
      if (turnType == AT_RIGHT || turnType == OFF_LINE)
      {
        turnRight(); // Should only detect a right turn
        mainLoc = 4; // Bot is now at mainLoc M4
        setMove(MOVE_FORWARD); // Begin moving forward again
      }
      break;
    case 4: // At mainLoc M4
      followLine(); // Follow the line unless turn is detected
      if (turnType == AT_RIGHT || turnType == OFF_LINE)
      {
        turnRight(); // Should only detect a right turn
        mainLoc = 5; // Bot is now at mainLoc M5
        setMove(MOVE_FORWARD); // Begin moving forward again

      }
      break;
    case 5: // At mainLoc M5
      navigateTask();
      break;
    case 6: // At mainLoc M6
      navigateTask();
      break;
    case 7: // At mainLoc M7
      followLine(); // Follow the line unless turn is detected
      if (turnType == AT_RIGHT || turnType == OFF_LINE) 
      {
        turnRight(); // Should only detect a right turn
        mainLoc = 0; // Bot is now at mainLoc M0
        setMove(MOVE_FORWARD); // Begin moving forward again
      }
      break;
  } 
  
}