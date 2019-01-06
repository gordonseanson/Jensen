#include <Servo.h>
#include <enhancedServo.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Array for saving each position
// 6 servo motors and 100 possible arm positions
int frames = 100;
int positionArray[100][6] = {
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0}
};
// Number of frames with non-zero data
float actualFrames;

int delayFrames[100] = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

// Constructor from enhancedServo library

// enhancedServo::enhancedServo(
//  Adafruit_PWMServoDriver _pwm, 
//  0  String _name, 
//  1  uint8_t _feed_pin, // middle pin of potentiometer
//  2  uint8_t _pot_pin,  // top pin of potentiometer
//  3  uint8_t _pot_reference_pin,  // bottom pin of potentiometer
//  4  uint8_t _write_pin,  // write pin of servo
//  5  double _write_min, 
//  6  double _write_max, 
//  7  int _feed_min,
//  8  int _feed_max,
//  9  double _Ki,  // constant for tuning integral control loop
//  10 double _alpha, // constant for tuning control loop EWMA
//  11 double _errorMargin
//  12 boolean gripper
// ) {

// Error margin for each move
int errorMargin = 4;

// Initalizing each servo motor
//                           0          1    2    3    4  5    6    7    8    9      10    11           12
enhancedServo base(pwm,     "Base",     A0,  A1,  A2,  0, 135, 500, 127, 860, 0.005, 0.02, 3,           false);
enhancedServo shoulder(pwm, "Shoulder", A3,  A4,  A5,  1, 170, 500, 158, 807, 0.005, 0.02, errorMargin, false);
enhancedServo elbow(pwm,    "Elbow",    A6,  A7,  A8,  2, 150, 470, 140, 770, 0.005, 0.02, errorMargin, false);
enhancedServo wrist(pwm,    "Wrist",    A9,  A10, A11, 3, 135, 500, 118, 844, 0.005, 0.02, errorMargin, false);
enhancedServo rotation(pwm, "Rotation", A12, A13, A14, 4, 150, 450, 117, 965, 0.005, 0.02, errorMargin, false);
enhancedServo gripper(pwm,  "Gripper",  A15, A13, A14, 5, 290, 390, 248, 332, 0.01,  0.02, 13,          true);

// Delay between each while() loop
float delay_us = 1;


// Debugging flags
bool programming_DEBUG = false;
bool playback_DEBUG = false;

// Helpful bools
bool isDefault = false;
bool isProgrammed = false;

// Pin numbers
int SAVE = 37;
int PROGRAM = 35;
int PLAYPAUSE = 33;
int HOME = 31;

void setup() {
  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
  Serial.begin(250000);
  pinMode(SAVE, INPUT);
  pinMode(PROGRAM, INPUT);
  pinMode(PLAYPAUSE, INPUT);
  // Initialize feedback running averages and move to default position
  setupInitializer();
  defaultPos();
}

// Main loop; can select various methods with the physical buttons
void loop() {
  // Debouncing
  while (digitalRead(PROGRAM) == HIGH) {}
  while (digitalRead(SAVE) == HIGH) {}
  while (digitalRead(PLAYPAUSE) == HIGH) {}
  while (digitalRead(HOME) == HIGH) {}

  // Main menu
  Serial.println("\nMain menu:");
  
  Serial.println(" Program - Give the arm a set of positions to cycle through.");
  
  if (isProgrammed) Serial.println(" Play - Begin movement.");
  else Serial.println(" Play - Must program first!");
  
  if (!isDefault) Serial.println(" Home - Move the arm to its default position.");
  else Serial.println(" Home - The arm is already in its default position.");
  
  // Branching logic depending on button pressed
  char button = 'x';
  bool standby = true;
  while (standby) {
    feedbackRefresh();
    if (digitalRead(PROGRAM) == HIGH) {
      button = 'c';
      standby = false;
    }
    if (digitalRead(PLAYPAUSE) == HIGH) {
      button = 'p';
      standby = false;
    }
    if (digitalRead(HOME) == HIGH) {
      button = 'h';
      standby = false;
    }
  }

  // Switch case for selected button
  switch (button) {
    case 'c':
      Serial.println("\nProgramming Mode");
      Serial.println("Use the save button to save a sequence of positions.");
      Serial.println("Use the play/pause button to insert a 1 second delay.");
      program();
      break;
    case 'p':
      Serial.println("\nPlayback Mode");
      // Debouncing
      while (digitalRead(PLAYPAUSE) == HIGH) {}
      
      while (digitalRead(PLAYPAUSE) == LOW && digitalRead(HOME) == LOW) {
        playback();
      }
      
      if (digitalRead(HOME) == HIGH) defaultPos();
      break;
    case 'h':
      defaultPos();
      break;
    default:
      break;
  }
}

// Playback mode: cycles through saved arm positions
void playback() {
  // Debouncing
  while (digitalRead(PLAYPAUSE) == HIGH) {}
  
  // Count number of arm positions
  actualFrames = 0;
  for (int i = 0; i < frames; i++) {
    if (positionArray[i][0] != 0) {
      actualFrames++;
    }
  }

  preInitializer(); // Initializes the integral control loop
  boolean playing = true;
  // Each for() loop represents one "move" to a arm position
  for (int i = 0; i < actualFrames; i++) {
    // Initializes the arrival conditions as false before each move
    loopInitializer();
    // While the arrival conditions are false, calculates error correction output for each servo
    while(!isArrived()) {
      // Checks if pause button has been pressed
      if (digitalRead(PLAYPAUSE) == HIGH || digitalRead(HOME) == HIGH) {
        playing = false;
        break;
      }

      if (delayFrames[i] == 1) {
        delay(1000);
        break;
      }
      
      // Continually looping computePath() moves the arm (see enhancedServo library)
      computePath(i);
      isDefault = false;
      delayMicroseconds(delay_us);
    }
    if (!playing) break;
    if (delayFrames[i] == 0) Serial.print("Move "); 
    else Serial.print("Delay: ");
    Serial.print(i+1); Serial.print(" completed"); Serial.print("\n");
  }
}

// "Programs" the robot arm by saving an array of positions. Each position is a "frame."
void program() {
  // Debouncing
  while (digitalRead(PROGRAM) == HIGH) {}
  
  // Set all frames to 0
  for (int i = 0; i < frames; i++) {
    for (int j = 0; j < 2; j++) {
      positionArray[i][j] = 0;
    }
    delayFrames[i] = 0;
  }
  
  // Assigns values to the array in sequential order
  boolean programming_mode = true;
  detach(); // Allows you to move the servos freely with your hand

  // In each iteration of the for() loop, one position of the arm is saved to the position array
  for (int i = 0; i < frames; i++) {
    //  Exits programming mode when the "Program" button is pressed again
    if (programming_mode == false) {
      break;
    }

    // Debouncing
    while (programming_mode && (digitalRead(SAVE) == HIGH || digitalRead(PLAYPAUSE) == HIGH)) {};

    //  Waits until "Save" or "Program" is pressed
    bool waiting = true;
    while (waiting) {
      feedbackRefresh();  // Keeps running averages for feedback going

      // Debug print statements
      if (programming_DEBUG) {
        Serial.print(base.getFeedback()); Serial.print(" ");
        Serial.print(shoulder.getFeedback()); Serial.print(" ");
        Serial.print(elbow.getFeedback()); Serial.print(" ");
        Serial.print(wrist.getFeedback()); Serial.print(" ");
        Serial.print(rotation.getFeedback()); Serial.print(" ");
        Serial.print(gripper.getFeedback()); Serial.println(" ");
      }

      // If "Program" is pressed while in programming mode, the positions are saved and programming mode is exited
      if (digitalRead(PROGRAM) == HIGH) {
        programming_mode = false;
        waiting = false;
      }

      // If "Save" is pressed, each angle between the links of the arm are saved to one row of the position array
      if (digitalRead(SAVE) == HIGH) {
        savePositions(i);
        Serial.print("Position saved ["); Serial.print(i+1); Serial.println("/100]");
        waiting = false;
      }

      // If "Stop" is pressed, a delay will be inserted into the sequence of motion
      if (digitalRead(PLAYPAUSE) == HIGH) {
        savePositions(i); // Just saving the positions so that they aren't zero (data will not be used)
        delayFrames[i] = 1;
        Serial.print("Delay saved ["); Serial.print(i+1); Serial.println("/100]");
        waiting = false;
      }

      delay(200);
    }
  }

  isProgrammed = true;
  Serial.print("Program Saved\n");
  
  hold(); // holds arm position after programming is done
  
  // Count number of frames
  float actualFrames = 0;
  for (int i = 0; i < frames; i++) {
    if (positionArray[i][0] != 0) {
      actualFrames++;
    }
  }

  // Prints saved positions
  if (programming_DEBUG) {
    for (int i = 0; i < actualFrames; i++) {
      Serial.print("Position "); Serial.print(i + 1); 
      Serial.print(" feedback: "); 
      Serial.print(positionArray[i][0]); Serial.print(" "); 
      Serial.print(positionArray[i][1]); Serial.print(" "); 
      Serial.print(positionArray[i][2]); Serial.print(" "); 
      Serial.print(positionArray[i][3]); Serial.print(" ");
      Serial.print(positionArray[i][4]); Serial.print(" ");
      Serial.println(positionArray[i][5]);
    }
  }
}

// All functions below group servo actions

// Puts arm in default position
void defaultPos() {
  Serial.println("\nMoving to default position");
  preInitializer();
  loopInitializer();
  while(!isArrived()) {
      base.computePath(480);
      shoulder.computePath(740);
      elbow.computePath(490);
      wrist.computePath(140);
      rotation.computePath(585);
      gripper.computePath(322);
      delayMicroseconds(delay_us);
  }
  isDefault = true;
}

// Holds arm position
void hold() {
  int baseF = base.getFeedback();
  int shoulderF = shoulder.getFeedback();
  int elbowF = elbow.getFeedback();
  int wristF = wrist.getFeedback();
  int rotationF = rotation.getFeedback();
  int gripperF = gripper.getFeedback();
  preInitializer();
  loopInitializer();
  while(!isArrived()) {
      base.computePath(baseF);
      shoulder.computePath(shoulderF);
      elbow.computePath(elbowF);
      wrist.computePath(wristF);
      rotation.computePath(rotationF);
      gripper.computePath(gripperF);
      delayMicroseconds(delay_us);
  }
}

// Call this function before doing any arm movement to correctly initialize running averages for feedback
void setupInitializer() {
  base.setupInitializer();
  shoulder.setupInitializer();
  elbow.setupInitializer();
  wrist.setupInitializer();
  rotation.setupInitializer();
  gripper.setupInitializer();
}

// Delegates all servo detachments
void detach() {
  base.detach();
  shoulder.detach();
  elbow.detach();
  wrist.detach();
  rotation.detach();
  gripper.detach();
}

// Delegates all pre-initializers
void preInitializer() {
  base.preInitializer();
  shoulder.preInitializer();
  elbow.preInitializer();
  wrist.preInitializer();
  rotation.preInitializer();
  gripper.preInitializer();
}

// Delegates all loop initializers
void loopInitializer() {
  base.loopInitializer();
  shoulder.loopInitializer();
  elbow.loopInitializer();
  wrist.loopInitializer();
  rotation.loopInitializer();
  gripper.loopInitializer();
}

// Delegates all path compute methods
void computePath(int i) {
  base.computePath(positionArray[i][0]);
  shoulder.computePath(positionArray[i][1]);
  elbow.computePath(positionArray[i][2]);
  wrist.computePath(positionArray[i][3]);
  rotation.computePath(positionArray[i][4]);
  gripper.computePath(positionArray[i][5]);
}

// Delegates saving each servo's position
void savePositions(int i) {
  positionArray[i][0] = base.getFeedback();
  positionArray[i][1] = shoulder.getFeedback();
  positionArray[i][2] = elbow.getFeedback();
  positionArray[i][3] = wrist.getFeedback();
  positionArray[i][4] = rotation.getFeedback();
  positionArray[i][5] = gripper.getFeedback();
}

// Once the arm starts, all feedback is kept in running averages
// This function is called in programming mode to keep the averages going
void feedbackRefresh() {
  base.getFeedback();
  shoulder.getFeedback();
  elbow.getFeedback();
  wrist.getFeedback();
  rotation.getFeedback();
  gripper.getFeedback();
}

// Returns true if all servos have arrived at their respective positions
boolean isArrived() {
  // Debug print statements
  if (playback_DEBUG) {
    Serial.print(base.getArrived()); Serial.print(" ");
    Serial.print(shoulder.getArrived()); Serial.print(" ");
    Serial.print(elbow.getArrived()); Serial.print(" ");
    Serial.print(wrist.getArrived()); Serial.print(" ");
    Serial.print(rotation.getArrived()); Serial.print(" ");
    Serial.print(gripper.getArrived()); Serial.println(" ");
  }
  if (
    base.getArrived() && 
    shoulder.getArrived() && 
    elbow.getArrived() && 
    wrist.getArrived() && 
    rotation.getArrived() && 
    gripper.getArrived()
    ) {
    return true;
  } else {
    return false;
  }
}
