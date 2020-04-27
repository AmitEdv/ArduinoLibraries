/*
  PIR_HCSR501.h - library for PIR_HCSR501, movement detection
  Copyright (c) 2020 Amit Edvy.  All right reserved.
*/

// ensure this library description is only included once
#ifndef PIR_HCSR501_h
#define PIR_HCSR501_h

#include <Arduino.h>

typedef void (*onMotionDetection_f)(void);

// library interface description
class Pir
{
  // user-accessible "public" interface
  public:
    Pir(int);
	
	void setMotionStartCB(onMotionDetection_f detectedCB);
	void setMotionEndCB(onMotionDetection_f notDetectedCB);
	void detectMotion(void);

  // library-accessible "private" interface
  private:
	int m_inputPin;
    int m_pirState;
	onMotionDetection_f m_motionDetectedCB;
	onMotionDetection_f m_noMotionDetectedCB;
	
	//void doSomethingSecret(void);
};

#endif //PIR_HCSR501_h

