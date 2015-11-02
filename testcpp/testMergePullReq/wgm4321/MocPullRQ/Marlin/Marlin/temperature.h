#if defined (upstreamBeforeMerge) || defined (forkBeforeMerge)
/*
  temperature.h - temperature controller
  Part of Marlin

  Copyright (c) 2011 Erik van der Zalm

  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/
#endif
#if defined (upstreamBeforeMerge) && !defined (temperature_h) || defined (forkBeforeMerge) && !defined (temperature_h)
    #define temperature_h
    #include "Marlin.h"
    #include "planner.h"
#endif
#if defined (upstreamBeforeMerge) && (defined (PID_ADD_EXTRUSION_RATE) && !defined (temperature_h) ) || defined (forkBeforeMerge) && (defined (PID_ADD_EXTRUSION_RATE) && !defined (temperature_h) )
    #include "stepper.h"
#endif
#if defined (upstreamBeforeMerge) && !defined (temperature_h) || defined (forkBeforeMerge) && !defined (temperature_h)
    // public functions
    void tp_init();
    //initialize the heating
    void manage_heater();
    //it is critical that this is called periodically.
#endif
#if defined (upstreamBeforeMerge) && (defined (FILAMENT_SENSOR) && !defined (temperature_h) ) || defined (forkBeforeMerge) && (defined (FILAMENT_SENSOR) && !defined (temperature_h) )
    // For converting raw Filament Width to milimeters
    float analog2widthFil();
    // For converting raw Filament Width to an extrusion ratio
    int widthFil_to_size_ratio();
#endif
#if defined (upstreamBeforeMerge) && !defined (temperature_h) || defined (forkBeforeMerge) && !defined (temperature_h)
    // low level conversion routines
    // do not use these routines and variables outside of temperature.cpp
    extern int target_temperature[EXTRUDERS];
    extern float current_temperature[EXTRUDERS];
#endif
#if defined (upstreamBeforeMerge) && (defined (SHOW_TEMP_ADC_VALUES) && !defined (temperature_h) ) || defined (forkBeforeMerge) && (defined (SHOW_TEMP_ADC_VALUES) && !defined (temperature_h) )
    extern int current_temperature_raw[EXTRUDERS];
    extern int current_temperature_bed_raw;
#endif
#if defined (upstreamBeforeMerge) && !defined (temperature_h) || defined (forkBeforeMerge) && !defined (temperature_h)
    extern int target_temperature_bed;
    extern float current_temperature_bed;
#endif
#if defined (upstreamBeforeMerge) && (defined (TEMP_SENSOR_1_AS_REDUNDANT) && !defined (temperature_h) ) || defined (forkBeforeMerge) && (defined (TEMP_SENSOR_1_AS_REDUNDANT) && !defined (temperature_h) )
    extern float redundant_temperature;
#endif
#if defined (upstreamBeforeMerge) && ((defined(CONTROLLERFAN_PIN) && CONTROLLERFAN_PIN > -1 && )!defined (temperature_h) ) || defined (forkBeforeMerge) && ((defined(CONTROLLERFAN_PIN) && CONTROLLERFAN_PIN > -1 && )!defined (temperature_h) )
    extern unsigned char soft_pwm_bed;
#endif
#if defined (upstreamBeforeMerge) && (defined (PIDTEMP) && !defined (temperature_h) ) || defined (forkBeforeMerge) && (defined (PIDTEMP) && !defined (temperature_h) )
    extern float Kp,Ki,Kd,Kc;
    float scalePID_i(float i);
    float scalePID_d(float d);
    float unscalePID_i(float i);
    float unscalePID_d(float d);
#endif
#if defined (upstreamBeforeMerge) && (defined (PIDTEMPBED) && !defined (temperature_h) ) || defined (forkBeforeMerge) && (defined (PIDTEMPBED) && !defined (temperature_h) )
    extern float bedKp,bedKi,bedKd;
#endif
#if defined (upstreamBeforeMerge) && (defined (BABYSTEPPING) && !defined (temperature_h) ) || defined (forkBeforeMerge) && (defined (BABYSTEPPING) && !defined (temperature_h) )
    extern volatile int babystepsTodo[3];
#endif
#if defined (upstreamBeforeMerge) && !defined (temperature_h) || defined (forkBeforeMerge) && !defined (temperature_h)
//high level conversion routines, for use outside of temperature.cpp
//inline so that there is no performance decrease.
//deg=degreeCelsius
FORCE_INLINE float degHotend
(uint8_t extruder) {
    return current_temperature[extruder];
}
;
#endif
#if defined (upstreamBeforeMerge) && (defined (SHOW_TEMP_ADC_VALUES) && !defined (temperature_h) ) || defined (forkBeforeMerge) && (defined (SHOW_TEMP_ADC_VALUES) && !defined (temperature_h) )
FORCE_INLINE float rawHotendTemp
(uint8_t extruder) {
    return current_temperature_raw[extruder];
}
;
FORCE_INLINE float rawBedTemp
() {
    return current_temperature_bed_raw;
}
;
#endif
#if defined (upstreamBeforeMerge) && !defined (temperature_h) || defined (forkBeforeMerge) && !defined (temperature_h)
FORCE_INLINE float degBed
() {
    return current_temperature_bed;
}
;
FORCE_INLINE float degTargetHotend
(uint8_t extruder) {
    return target_temperature[extruder];
}
;
FORCE_INLINE float degTargetBed
() {
    return target_temperature_bed;
}
;
FORCE_INLINE void setTargetHotend
(const float &celsius, uint8_t extruder) {
    target_temperature[extruder] = celsius;
}
;
FORCE_INLINE void setTargetBed
(const float &celsius) {
    target_temperature_bed = celsius;
}
;
FORCE_INLINE bool isHeatingHotend
(uint8_t extruder) {
    return target_temperature[extruder] > current_temperature[extruder];
}
;
FORCE_INLINE bool isHeatingBed
() {
    return target_temperature_bed > current_temperature_bed;
}
;
FORCE_INLINE bool isCoolingHotend
(uint8_t extruder) {
    return target_temperature[extruder] < current_temperature[extruder];
}
;
FORCE_INLINE bool isCoolingBed
() {
    return target_temperature_bed < current_temperature_bed;
}
;
#define degHotend0() degHotend(0)
#define degTargetHotend0() degTargetHotend(0)
#define setTargetHotend0(_celsius) setTargetHotend((_celsius), 0)
#define isHeatingHotend0() isHeatingHotend(0)
#define isCoolingHotend0() isCoolingHotend(0)
#endif
#if defined (upstreamBeforeMerge) && (EXTRUDERS > 1 && !defined (temperature_h) ) || defined (forkBeforeMerge) && (EXTRUDERS > 1 && !defined (temperature_h) )
    #define degHotend1() degHotend(1)
    #define degTargetHotend1() degTargetHotend(1)
    #define setTargetHotend1(_celsius) setTargetHotend((_celsius), 1)
    #define isHeatingHotend1() isHeatingHotend(1)
    #define isCoolingHotend1() isCoolingHotend(1)
#endif
#if defined (upstreamBeforeMerge) && (!EXTRUDERS > 1 && !defined (temperature_h) ) || defined (forkBeforeMerge) && (!EXTRUDERS > 1 && !defined (temperature_h) )
    #define setTargetHotend1(_celsius) do{}while(0)
#endif
#if defined (upstreamBeforeMerge) && (EXTRUDERS > 2 && !defined (temperature_h) ) || defined (forkBeforeMerge) && (EXTRUDERS > 2 && !defined (temperature_h) )
    #define degHotend2() degHotend(2)
    #define degTargetHotend2() degTargetHotend(2)
    #define setTargetHotend2(_celsius) setTargetHotend((_celsius), 2)
    #define isHeatingHotend2() isHeatingHotend(2)
    #define isCoolingHotend2() isCoolingHotend(2)
#endif
#if defined (upstreamBeforeMerge) && (!EXTRUDERS > 2 && !defined (temperature_h) ) || defined (forkBeforeMerge) && (!EXTRUDERS > 2 && !defined (temperature_h) )
    #define setTargetHotend2(_celsius) do{}while(0)
#endif
#if defined (upstreamBeforeMerge) && (EXTRUDERS > 3 && !defined (temperature_h) ) || defined (forkBeforeMerge) && (EXTRUDERS > 3 && !defined (temperature_h) )
    #error Invalid number of extruders
#endif
#if defined (upstreamBeforeMerge) && !defined (temperature_h) || defined (forkBeforeMerge) && !defined (temperature_h)
    int getHeaterPower(int heater);
    void disable_heater();
    void setWatch();
    void updatePID();
#endif
#if defined (upstreamBeforeMerge) && ((defined (THERMAL_RUNAWAY_PROTECTION_PERIOD) && THERMAL_RUNAWAY_PROTECTION_PERIOD > 0 && )!defined (temperature_h) ) || defined (forkBeforeMerge) && ((defined (THERMAL_RUNAWAY_PROTECTION_PERIOD) && THERMAL_RUNAWAY_PROTECTION_PERIOD > 0 && )!defined (temperature_h) )
    void thermal_runaway_protection(int *state, unsigned long *timer, float temperature, float target_temperature, int heater_id, int period_seconds, int hysteresis_degc);
    static int thermal_runaway_state_machine[3];
    // = {0,0,0};
    static unsigned long thermal_runaway_timer[3];
    // = {0,0,0};
    static bool thermal_runaway = false;
#endif
#if defined (upstreamBeforeMerge) && (TEMP_SENSOR_BED != 0 && (defined (THERMAL_RUNAWAY_PROTECTION_PERIOD) && THERMAL_RUNAWAY_PROTECTION_PERIOD > 0 && )!defined (temperature_h) ) || defined (forkBeforeMerge) && (TEMP_SENSOR_BED != 0 && (defined (THERMAL_RUNAWAY_PROTECTION_PERIOD) && THERMAL_RUNAWAY_PROTECTION_PERIOD > 0 && )!defined (temperature_h) )
    static int thermal_runaway_bed_state_machine;
    static unsigned long thermal_runaway_bed_timer;
#endif
#if defined (upstreamBeforeMerge) && !defined (temperature_h) || defined (forkBeforeMerge) && !defined (temperature_h)
FORCE_INLINE void autotempShutdown
() {
#if defined (upstreamBeforeMerge) && (defined (AUTOTEMP) && !defined (temperature_h) ) || defined (forkBeforeMerge) && (defined (AUTOTEMP) && !defined (temperature_h) )
    if
    (autotemp_enabled) {
        autotemp_enabled=false;
        if
        (degTargetHotend(active_extruder)>autotemp_min)
            setTargetHotend(0,active_extruder);
    }
#endif
}
void PID_autotune(float temp, int extruder, int ncycles);
void setExtruderAutoFanState(int pin, bool state);
void checkExtruderAutoFans();
#endif
