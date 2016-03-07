	#include "Environment.h"
	#include "MinePump.h"


int pumpRunning = 0;
int systemActive = 1;

	void timeShift() {
		if (pumpRunning)
			lowerWaterLevel();
		if (systemActive)
			processEnvironment();
	}
	void processEnvironment() {
		//-------highWaterSensor-------
		if (!pumpRunning && isHighWaterLevel()) {
			activatePump();
		} 
		//-------LowWaterSensor-------
		if (pumpRunning && isLowWaterLevel()) {
			deactivatePump();
		} 
		//-------methaneAlarm-------
		if (pumpRunning && isMethaneAlarm()) {
			deactivatePump();
		}
	}

	void activatePump() {
        //-------methaneQuery-------
		if (!isMethaneAlarm()) {
			//---origin---
			pumpRunning = 1;
			//---origin---
		} else {
			//System.out.println("Pump not activated due to methane alarm");
		}
		
	}

	void deactivatePump() {
		pumpRunning = 0;
	}
	
	int isMethaneAlarm() {
		return isMethaneLevelCritical();
	}

	int isPumpRunning() {
		return pumpRunning;
	}

	void printPump() {
		printf("Pump(System:");
		if (systemActive)
			printf("On");
		else
			printf("Off");
		printf(",Pump:");
		if (pumpRunning)
			printf("On");
		else
			printf("Off");
		printf(") ");
		printEnvironment();
		printf("\n");
	}

	//-------highWaterSensor-------
	int isHighWaterLevel() {
		return ! isHighWaterSensorDry();
	}
	
	//-------LowWaterSensor-------
	int isLowWaterLevel() {
		return ! isLowWaterSensorDry();
	}

	//-------startCommand-------
	void startSystem() {
		// assert !pumpRunning;
		systemActive = 1;
	}
	//-------stopCommand-------
	void stopSystem() {
		if (pumpRunning) {
			deactivatePump();
		}
		// assert !pumpRunning;
		systemActive = 0;
	}


