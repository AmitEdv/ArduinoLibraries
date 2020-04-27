/*
  Test.h - Test library for Wiring - implementation
  Copyright (c) 2006 John Doe.  All right reserved.
*/

#include "PIR_HCSR501.h"
// include this library's description file

// include description files for other libraries used (if any)
#include "HardwareSerial.h"

// Constructor /////////////////////////////////////////////////////////////////
// Function that handles the creation and setup of instances

Pir::Pir(int inputPinNumber)
{
  // initialize this instance's variables
  m_inputPin = inputPinNumber;
  m_pirState = LOW; // we start, assuming no motion detected

  // do whatever is required to initialize the library
  pinMode(m_inputPin, INPUT); // declare sensor as input
}

// Public Methods //////////////////////////////////////////////////////////////
// Functions available in Wiring sketches, this library, and other libraries

void Pir::setMotionStartCB(onMotionDetection_f detectedCB)
{
	m_motionDetectedCB = detectedCB;
}

void Pir::setMotionEndCB(onMotionDetection_f notDetectedCB)
{
	m_noMotionDetectedCB = notDetectedCB;
}


void Pir::detectMotion(void)
{  
  int val = 0;                    // variable for reading the pin status
  val = digitalRead(m_inputPin);  // read input value
  Serial.print("value is ");
  Serial.println(val);
  
  // check if the input is HIGH
  if (val == HIGH) 
  {
	  if (m_motionDetectedCB != 0)
	  {
		  m_motionDetectedCB();
	  }
  }
  else
  {
	  if (m_noMotionDetectedCB != 0)
	  {
		  m_noMotionDetectedCB();
	  }
  }
}

// Private Methods /////////////////////////////////////////////////////////////
// Functions only available to other functions in this library

//void Test::doSomethingSecret(void)
//{
//  digitalWrite(13, HIGH);
//  delay(200);
//  digitalWrite(13, LOW);
//  delay(200);
//}

