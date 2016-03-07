	#include "Environment.h"
	/*
	 * Waterlevels:
	 * 0: below the low sensor
	 * 1: between low and high sensors
	 * 2: above high sensor
	 */
	 int waterLevel = 1;

	 int methaneLevelCritical = 0;

	void lowerWaterLevel() {
		if (waterLevel > 0) {
			waterLevel = waterLevel-1;
		}
	}

	void waterRise() {
		if (waterLevel < 2) {
			waterLevel = waterLevel+1;
		}
	}

	void changeMethaneLevel() {
		if (methaneLevelCritical) {
			methaneLevelCritical = 0;
		} else {
			methaneLevelCritical = 1;
		}
	}

	int isMethaneLevelCritical() {
		return methaneLevelCritical;
	}


	void printEnvironment() {
		printf("Env(Water:%i", waterLevel);
		printf(",Meth:");
		if (methaneLevelCritical)
			printf("CRIT");
		else
			printf("OK");
		printf(")");
	}

	int getWaterLevel() {
		return waterLevel;
	}

	//-------highWaterSensor-------
	int isHighWaterSensorDry() {
		// cpachecker bug
		//return waterLevel < 2;
		if (waterLevel < 2) {
			return 1;
		} else {
			return 0;
		}
	}
	//-------LowWaterSensor-------
	int isLowWaterSensorDry() {
		return waterLevel == 0;
	}
