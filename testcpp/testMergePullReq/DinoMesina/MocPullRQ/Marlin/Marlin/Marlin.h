#if defined (upstreamBeforeMerge) || defined (forkBeforeMerge)
// Tonokip RepRap firmware rewrite based off of Hydra-mmm firmware.
// License: GPL
#endif
#if defined (upstreamBeforeMerge) && !defined (MARLIN_H) || defined (forkBeforeMerge) && !defined (MARLIN_H)
    #define MARLIN_H
    #define  FORCE_INLINE __attribute__((always_inline)) inline
    #include <math.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <inttypes.h>
    #include <util/delay.h>
    #include <avr/pgmspace.h>
    #include <avr/eeprom.h>
    #include <avr/interrupt.h>
    #include "fastio.h"
    #include "Configuration.h"
    #include "pins.h"
#endif
#if defined (upstreamBeforeMerge) && (!defined (AT90USB) && !defined (MARLIN_H) ) || defined (forkBeforeMerge) && (!defined (AT90USB) && !defined (MARLIN_H) )
    #define  HardwareSerial_h
    // trick to disable the standard HWserial
#endif
#if defined (upstreamBeforeMerge) && (!defined (MARLIN_H) && (ARDUINO >= 100) ) || defined (forkBeforeMerge) && (!defined (MARLIN_H) && (ARDUINO >= 100) )
    #include "Arduino.h"
#endif
#if defined (upstreamBeforeMerge) && (!(ARDUINO >= 100) && !defined (MARLIN_H) ) || defined (forkBeforeMerge) && (!(ARDUINO >= 100) && !defined (MARLIN_H) )
    #include "WProgram.h"
#endif
#if defined (upstreamBeforeMerge) && !defined (MARLIN_H) || defined (forkBeforeMerge) && !defined (MARLIN_H)
    // Arduino < 1.0.0 does not define this, so we need to do it ourselves
#endif
#if defined (upstreamBeforeMerge) && (!defined (analogInputToDigitalPin) && !defined (MARLIN_H) ) || defined (forkBeforeMerge) && (!defined (analogInputToDigitalPin) && !defined (MARLIN_H) )
    #define analogInputToDigitalPin(p) ((p) + A0)
#endif
#if defined (upstreamBeforeMerge) && (defined (AT90USB) && !defined (MARLIN_H) ) || defined (forkBeforeMerge) && (defined (AT90USB) && !defined (MARLIN_H) )
    #include "HardwareSerial.h"
#endif
#if defined (upstreamBeforeMerge) && !defined (MARLIN_H) || defined (forkBeforeMerge) && !defined (MARLIN_H)
    #include "MarlinSerial.h"
#endif
#if defined (upstreamBeforeMerge) && (!defined (cbi) && !defined (MARLIN_H) ) || defined (forkBeforeMerge) && (!defined (cbi) && !defined (MARLIN_H) )
    #define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif
#if defined (upstreamBeforeMerge) && (!defined (sbi) && !defined (MARLIN_H) ) || defined (forkBeforeMerge) && (!defined (sbi) && !defined (MARLIN_H) )
    #define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif
#if defined (upstreamBeforeMerge) && !defined (MARLIN_H) || defined (forkBeforeMerge) && !defined (MARLIN_H)
    #include "WString.h"
#endif
#if defined (upstreamBeforeMerge) && (defined (BTENABLED) && defined (AT90USB) && !defined (MARLIN_H) ) || defined (forkBeforeMerge) && (defined (BTENABLED) && defined (AT90USB) && !defined (MARLIN_H) )
    #define MYSERIAL bt
#endif
#if defined (upstreamBeforeMerge) && (!defined (BTENABLED) && defined (AT90USB) && !defined (MARLIN_H) ) || defined (forkBeforeMerge) && (!defined (BTENABLED) && defined (AT90USB) && !defined (MARLIN_H) )
    #define MYSERIAL Serial
#endif
#if defined (upstreamBeforeMerge) && (defined (AT90USB) && !defined (MARLIN_H) ) || defined (forkBeforeMerge) && (defined (AT90USB) && !defined (MARLIN_H) )
    // BTENABLED
#endif
#if defined (upstreamBeforeMerge) && (!defined (AT90USB) && !defined (MARLIN_H) ) || defined (forkBeforeMerge) && (!defined (AT90USB) && !defined (MARLIN_H) )
    #define MYSERIAL MSerial
#endif
#if defined (upstreamBeforeMerge) && !defined (MARLIN_H) || defined (forkBeforeMerge) && !defined (MARLIN_H)
#define SERIAL_PROTOCOL(x) (MYSERIAL.print(x))
#define SERIAL_PROTOCOL_F(x,y) (MYSERIAL.print(x,y))
#define SERIAL_PROTOCOLPGM(x) (serialprintPGM(PSTR(x)))
#define SERIAL_PROTOCOLLN(x) (MYSERIAL.print(x),MYSERIAL.write('\n'))
#define SERIAL_PROTOCOLLNPGM(x) (serialprintPGM(PSTR(x)),MYSERIAL.write('\n'))
extern const char errormagic[] PROGMEM;
extern const char echomagic[] PROGMEM;
#define SERIAL_ERROR_START (serialprintPGM(errormagic))
#define SERIAL_ERROR(x) SERIAL_PROTOCOL(x)
#define SERIAL_ERRORPGM(x) SERIAL_PROTOCOLPGM(x)
#define SERIAL_ERRORLN(x) SERIAL_PROTOCOLLN(x)
#define SERIAL_ERRORLNPGM(x) SERIAL_PROTOCOLLNPGM(x)
#define SERIAL_ECHO_START (serialprintPGM(echomagic))
#define SERIAL_ECHO(x) SERIAL_PROTOCOL(x)
#define SERIAL_ECHOPGM(x) SERIAL_PROTOCOLPGM(x)
#define SERIAL_ECHOLN(x) SERIAL_PROTOCOLLN(x)
#define SERIAL_ECHOLNPGM(x) SERIAL_PROTOCOLLNPGM(x)
#define SERIAL_ECHOPAIR(name,value) (serial_echopair_P(PSTR(name),(value)))
void serial_echopair_P(const char *s_P, float v);
void serial_echopair_P(const char *s_P, double v);
void serial_echopair_P(const char *s_P, unsigned long v);
//Things to write to serial from Program memory. Saves 400 to 2k of RAM.
FORCE_INLINE void serialprintPGM
(const char *str) {
    char ch=pgm_read_byte(str);
    while
    (ch) {
        MYSERIAL.write(ch);
        ch=pgm_read_byte(++str);
    }
}
void get_command();
void process_commands();
void manage_inactivity(bool ignore_stepper_queue=false);
#endif
#if defined (upstreamBeforeMerge) && ((defined(DUAL_X_CARRIAGE) && defined(X_ENABLE_PIN) && X_ENABLE_PIN > -1 \
    && defined(X2_ENABLE_PIN) && X2_ENABLE_PIN > -1 && )!defined (MARLIN_H) ) || defined (forkBeforeMerge) && ((defined(DUAL_X_CARRIAGE) && defined(X_ENABLE_PIN) && X_ENABLE_PIN > -1 \
    && defined(X2_ENABLE_PIN) && X2_ENABLE_PIN > -1 && )!defined (MARLIN_H) )
#define  enable_x() do { WRITE(X_ENABLE_PIN, X_ENABLE_ON); WRITE(X2_ENABLE_PIN, X_ENABLE_ON); } while (0)
&& defined(X2_ENABLE_PIN) && X2_ENABLE_PIN > -1 && )!defined (MARLIN_H) ) || defined (forkBeforeMerge) && ((defined(DUAL_X_CARRIAGE) && defined(X_ENABLE_PIN) && X_ENABLE_PIN > -1 \
        && defined(X2_ENABLE_PIN) && X2_ENABLE_PIN > -1 && )!defined (MARLIN_H) )
#define disable_x() do { WRITE(X_ENABLE_PIN,!X_ENABLE_ON); WRITE(X2_ENABLE_PIN,!X_ENABLE_ON); axis_known_position[X_AXIS] = false; } while (0)
#endif
#if defined (upstreamBeforeMerge) && ((defined(X_ENABLE_PIN) && X_ENABLE_PIN > -1 && )!defined (MARLIN_H) ) || defined (forkBeforeMerge) && ((defined(X_ENABLE_PIN) && X_ENABLE_PIN > -1 && )!defined (MARLIN_H) )
    #define  enable_x() WRITE(X_ENABLE_PIN, X_ENABLE_ON)
    #define disable_x() { WRITE(X_ENABLE_PIN,!X_ENABLE_ON); axis_known_position[X_AXIS] = false; }
#endif
#if defined (upstreamBeforeMerge) && ((!defined(X_ENABLE_PIN) && X_ENABLE_PIN > -1 && )!defined (MARLIN_H) ) || defined (forkBeforeMerge) && ((!defined(X_ENABLE_PIN) && X_ENABLE_PIN > -1 && )!defined (MARLIN_H) )
    #define enable_x() ;
    #define disable_x() ;
#endif
#if defined (upstreamBeforeMerge) && (!defined (MARLIN_H) && (defined(Y_ENABLE_PIN) && Y_ENABLE_PIN > -1 && )defined (Y_DUAL_STEPPER_DRIVERS) ) || defined (forkBeforeMerge) && (!defined (MARLIN_H) && (defined(Y_ENABLE_PIN) && Y_ENABLE_PIN > -1 && )defined (Y_DUAL_STEPPER_DRIVERS) )
    #define  enable_y() { WRITE(Y_ENABLE_PIN, Y_ENABLE_ON); WRITE(Y2_ENABLE_PIN,  Y_ENABLE_ON); }
    #define disable_y() { WRITE(Y_ENABLE_PIN,!Y_ENABLE_ON); WRITE(Y2_ENABLE_PIN, !Y_ENABLE_ON); axis_known_position[Y_AXIS] = false; }
#endif
#if defined (upstreamBeforeMerge) && (!defined (MARLIN_H) && (defined(Y_ENABLE_PIN) && Y_ENABLE_PIN > -1 && )!defined (Y_DUAL_STEPPER_DRIVERS) ) || defined (forkBeforeMerge) && (!defined (MARLIN_H) && (defined(Y_ENABLE_PIN) && Y_ENABLE_PIN > -1 && )!defined (Y_DUAL_STEPPER_DRIVERS) )
    #define  enable_y() WRITE(Y_ENABLE_PIN, Y_ENABLE_ON)
    #define disable_y() { WRITE(Y_ENABLE_PIN,!Y_ENABLE_ON); axis_known_position[Y_AXIS] = false; }
#endif
#if defined (upstreamBeforeMerge) && (!defined (MARLIN_H) && (!defined(Y_ENABLE_PIN) && Y_ENABLE_PIN > -1 &) || defined (forkBeforeMerge) && (!defined (MARLIN_H) && (!defined(Y_ENABLE_PIN) && Y_ENABLE_PIN > -1 &)
    #define enable_y() ;
    #define disable_y() ;
#endif
#if defined (upstreamBeforeMerge) && ((defined(Z_ENABLE_PIN) && Z_ENABLE_PIN > -1 && )!defined (MARLIN_H) && defined (Z_DUAL_STEPPER_DRIVERS) ) || defined (forkBeforeMerge) && ((defined(Z_ENABLE_PIN) && Z_ENABLE_PIN > -1 && )!defined (MARLIN_H) && defined (Z_DUAL_STEPPER_DRIVERS) )
    #define  enable_z() { WRITE(Z_ENABLE_PIN, Z_ENABLE_ON); WRITE(Z2_ENABLE_PIN, Z_ENABLE_ON); }
    #define disable_z() { WRITE(Z_ENABLE_PIN,!Z_ENABLE_ON); WRITE(Z2_ENABLE_PIN,!Z_ENABLE_ON); axis_known_position[Z_AXIS] = false; }
#endif
#if defined (upstreamBeforeMerge) && ((defined(Z_ENABLE_PIN) && Z_ENABLE_PIN > -1 && )!defined (MARLIN_H) && !defined (Z_DUAL_STEPPER_DRIVERS) ) || defined (forkBeforeMerge) && ((defined(Z_ENABLE_PIN) && Z_ENABLE_PIN > -1 && )!defined (MARLIN_H) && !defined (Z_DUAL_STEPPER_DRIVERS) )
    #define  enable_z() WRITE(Z_ENABLE_PIN, Z_ENABLE_ON)
    #define disable_z() { WRITE(Z_ENABLE_PIN,!Z_ENABLE_ON); axis_known_position[Z_AXIS] = false; }
#endif
#if defined (upstreamBeforeMerge) && ((!defined(Z_ENABLE_PIN) && Z_ENABLE_PIN > -1 && )!defined (MARLIN_H) ) || defined (forkBeforeMerge) && ((!defined(Z_ENABLE_PIN) && Z_ENABLE_PIN > -1 && )!defined (MARLIN_H) )
    #define enable_z() ;
    #define disable_z() ;
#endif
#if defined (upstreamBeforeMerge) && ((defined(E0_ENABLE_PIN) && (E0_ENABLE_PIN > -1) && )!defined (MARLIN_H) ) || defined (forkBeforeMerge) && ((defined(E0_ENABLE_PIN) && (E0_ENABLE_PIN > -1) && )!defined (MARLIN_H) )
    #define enable_e0() WRITE(E0_ENABLE_PIN, E_ENABLE_ON)
    #define disable_e0() WRITE(E0_ENABLE_PIN,!E_ENABLE_ON)
#endif
#if defined (upstreamBeforeMerge) && (!defined (MARLIN_H) && (!defined(E0_ENABLE_PIN) && (E0_ENABLE_PIN > -1) &) || defined (forkBeforeMerge) && (!defined (MARLIN_H) && (!defined(E0_ENABLE_PIN) && (E0_ENABLE_PIN > -1) &)
    #define enable_e0()
    /* nothing */
    #define disable_e0()
    /* nothing */
#endif
#if defined (upstreamBeforeMerge) && (!defined (MARLIN_H) && ((EXTRUDERS > 1) && defined(E1_ENABLE_PIN) && (E1_ENABLE_PIN > -1) &) || defined (forkBeforeMerge) && (!defined (MARLIN_H) && ((EXTRUDERS > 1) && defined(E1_ENABLE_PIN) && (E1_ENABLE_PIN > -1) &)
    #define enable_e1() WRITE(E1_ENABLE_PIN, E_ENABLE_ON)
    #define disable_e1() WRITE(E1_ENABLE_PIN,!E_ENABLE_ON)
#endif
#if defined (upstreamBeforeMerge) && (!defined (MARLIN_H) && (!(EXTRUDERS > 1) && defined(E1_ENABLE_PIN) && (E1_ENABLE_PIN > -1) &) || defined (forkBeforeMerge) && (!defined (MARLIN_H) && (!(EXTRUDERS > 1) && defined(E1_ENABLE_PIN) && (E1_ENABLE_PIN > -1) &)
    #define enable_e1()
    /* nothing */
    #define disable_e1()
    /* nothing */
#endif
#if defined (upstreamBeforeMerge) && (!defined (MARLIN_H) && ((EXTRUDERS > 2) && defined(E2_ENABLE_PIN) && (E2_ENABLE_PIN > -1) &) || defined (forkBeforeMerge) && (!defined (MARLIN_H) && ((EXTRUDERS > 2) && defined(E2_ENABLE_PIN) && (E2_ENABLE_PIN > -1) &)
    #define enable_e2() WRITE(E2_ENABLE_PIN, E_ENABLE_ON)
    #define disable_e2() WRITE(E2_ENABLE_PIN,!E_ENABLE_ON)
#endif
#if defined (upstreamBeforeMerge) && (!defined (MARLIN_H) && (!(EXTRUDERS > 2) && defined(E2_ENABLE_PIN) && (E2_ENABLE_PIN > -1) &) || defined (forkBeforeMerge) && (!defined (MARLIN_H) && (!(EXTRUDERS > 2) && defined(E2_ENABLE_PIN) && (E2_ENABLE_PIN > -1) &)
    #define enable_e2()
    /* nothing */
    #define disable_e2()
    /* nothing */
#endif
#if defined (upstreamBeforeMerge) && !defined (MARLIN_H) || defined (forkBeforeMerge) && !defined (MARLIN_H)
enum AxisEnum {X_AXIS=0, Y_AXIS=1, Z_AXIS=2, E_AXIS=3};
void FlushSerialRequestResend();
void ClearToSend();
void get_coordinates();
#endif
#if defined (upstreamBeforeMerge) && (defined (DELTA) && !defined (MARLIN_H) ) || defined (forkBeforeMerge) && (defined (DELTA) && !defined (MARLIN_H) )
    void calculate_delta(float cartesian[3]);
    extern float delta[3];
#endif
#if defined (upstreamBeforeMerge) && (defined (SCARA) && !defined (MARLIN_H) ) || defined (forkBeforeMerge) && (defined (SCARA) && !defined (MARLIN_H) )
    void calculate_delta(float cartesian[3]);
    void calculate_SCARA_forward_Transform(float f_scara[3]);
#endif
#if defined (upstreamBeforeMerge) && !defined (MARLIN_H) || defined (forkBeforeMerge) && !defined (MARLIN_H)
    void prepare_move();
    void kill();
    void Stop();
    bool IsStopped();
    void enquecommand(const char *cmd);
    //put an ASCII command at the end of the current buffer.
    void enquecommand_P(const char *cmd);
    //put an ASCII command at the end of the current buffer, read from flash
    void prepare_arc_move(char isclockwise);
    void clamp_to_software_endstops(float target[3]);
    void refresh_cmd_timeout(void);
#endif
#if defined (upstreamBeforeMerge) && (defined (FAST_PWM_FAN) && !defined (MARLIN_H) ) || defined (forkBeforeMerge) && (defined (FAST_PWM_FAN) && !defined (MARLIN_H) )
    void setPwmFrequency(uint8_t pin, int val);
#endif
#if defined (upstreamBeforeMerge) && (!defined (CRITICAL_SECTION_START) && !defined (MARLIN_H) ) || defined (forkBeforeMerge) && (!defined (CRITICAL_SECTION_START) && !defined (MARLIN_H) )
    #define CRITICAL_SECTION_START  unsigned char _sreg = SREG; cli();
    #define CRITICAL_SECTION_END    SREG = _sreg;
#endif
#if defined (upstreamBeforeMerge) && !defined (MARLIN_H) || defined (forkBeforeMerge) && !defined (MARLIN_H)
    //CRITICAL_SECTION_START
    extern float homing_feedrate[];
    extern bool axis_relative_modes[];
    extern int feedmultiply;
    extern int extrudemultiply;
    // Sets extrude multiply factor (in percent) for all extruders
    extern bool volumetric_enabled;
    extern int extruder_multiply[EXTRUDERS];
    // sets extrude multiply factor (in percent) for each extruder individually
    extern float filament_size[EXTRUDERS];
    // cross-sectional area of filament (in millimeters), typically around 1.75 or 2.85, 0 disables the volumetric calculations for the extruder.
    extern float volumetric_multiplier[EXTRUDERS];
    // reciprocal of cross-sectional area of filament (in square millimeters), stored this way to reduce computational burden in planner
    extern float current_position[NUM_AXIS] ;
    extern float add_homing[3];
#endif
#if defined (upstreamBeforeMerge) && (defined (DELTA) && !defined (MARLIN_H) ) || defined (forkBeforeMerge) && (defined (DELTA) && !defined (MARLIN_H) )
    extern float endstop_adj[3];
    extern float delta_radius;
    extern float delta_diagonal_rod;
    extern float delta_segments_per_second;
    void recalc_delta_settings(float radius, float diagonal_rod);
#endif
#if defined (upstreamBeforeMerge) && (defined (SCARA) && !defined (MARLIN_H) ) || defined (forkBeforeMerge) && (defined (SCARA) && !defined (MARLIN_H) )
    extern float axis_scaling[3];
    // Build size scaling
#endif
#if defined (upstreamBeforeMerge) && !defined (MARLIN_H) || defined (forkBeforeMerge) && !defined (MARLIN_H)
    extern float min_pos[3];
    extern float max_pos[3];
    extern bool axis_known_position[3];
    extern float zprobe_zoffset;
    extern int fanSpeed;
#endif
#if defined (upstreamBeforeMerge) && (defined (BARICUDA) && !defined (MARLIN_H) ) || defined (forkBeforeMerge) && (defined (BARICUDA) && !defined (MARLIN_H) )
    extern int ValvePressure;
    extern int EtoPPressure;
#endif
#if defined (upstreamBeforeMerge) && (defined (FAN_SOFT_PWM) && !defined (MARLIN_H) ) || defined (forkBeforeMerge) && (defined (FAN_SOFT_PWM) && !defined (MARLIN_H) )
    extern unsigned char fanSpeedSoftPwm;
#endif
#if defined (upstreamBeforeMerge) && (defined (FILAMENT_SENSOR) && !defined (MARLIN_H) ) || defined (forkBeforeMerge) && (defined (FILAMENT_SENSOR) && !defined (MARLIN_H) )
    extern float filament_width_nominal;
    //holds the theoretical filament diameter ie., 3.00 or 1.75
    extern bool filament_sensor;
    //indicates that filament sensor readings should control extrusion
    extern float filament_width_meas;
    //holds the filament diameter as accurately measured
    extern signed char measurement_delay[];
    //ring buffer to delay measurement
    extern int delay_index1, delay_index2;
    //index into ring buffer
    extern float delay_dist;
    //delay distance counter
    extern int meas_delay_cm;
    //delay distance
#endif
#if defined (upstreamBeforeMerge) && (!defined (MARLIN_H) && defined (FWRETRACT) ) || defined (forkBeforeMerge) && (!defined (MARLIN_H) && defined (FWRETRACT) )
    extern bool autoretract_enabled;
    extern bool retracted[EXTRUDERS];
    extern float retract_length, retract_length_swap, retract_feedrate, retract_zlift;
    extern float retract_recover_length, retract_recover_length_swap, retract_recover_feedrate;
#endif
#if defined (upstreamBeforeMerge) && !defined (MARLIN_H) || defined (forkBeforeMerge) && !defined (MARLIN_H)
    extern unsigned long starttime;
    extern unsigned long stoptime;
    // Handling multiple extruders pins
    extern uint8_t active_extruder;
#endif
#if defined (upstreamBeforeMerge) && (defined (DIGIPOT_I2C) && !defined (MARLIN_H) ) || defined (forkBeforeMerge) && (defined (DIGIPOT_I2C) && !defined (MARLIN_H) )
    extern void digipot_i2c_set_current( int channel, float current );
    extern void digipot_i2c_init();
#endif
#if defined (upstreamBeforeMerge) || defined (forkBeforeMerge)
    extern void calculate_volumetric_multipliers();
#endif
