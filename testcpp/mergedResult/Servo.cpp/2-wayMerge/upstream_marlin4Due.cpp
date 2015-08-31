#if defined (upstream)
/*
 Servo.cpp - Interrupt driven Servo library for Arduino using 16 bit timers- Version 2
 Copyright (c) 2009 Michael Margolis.  All right reserved.

 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.

 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */
#endif
#if defined (marlin4Due)
    /*
    Copyright (c) 2013 Arduino LLC. All right reserved.

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
    */
#endif
#if defined (upstream)
    /*

    A servo is activated by creating an instance of the Servo class passing the desired pin to the attach() method.
    The servos are pulsed in the background using the value most recently written using the write() method

    Note that analogWrite of PWM on pins associated with the timer are disabled when the first servo is attached.
    Timers are seized as needed in groups of 12 servos - 24 servos use two timers, 48 servos will use four.

    The methods are:

    Servo - Class for manipulating servo motors connected to Arduino pins.

    attach(pin )  - Attaches a servo motor to an i/o pin.
    attach(pin, min, max  ) - Attaches to a pin setting min and max values in microseconds
    default min is 544, max is 2400

    write()     - Sets the servo angle in degrees.  (invalid angle that is valid as pulse in microseconds is treated as microseconds)
    writeMicroseconds() - Sets the servo pulse width in microseconds
    read()      - Gets the last written servo pulse width as an angle between 0 and 180.
    readMicroseconds()   - Gets the last written servo pulse width in microseconds. (was read_us() in first release)
    attached()  - Returns true if there is a servo attached.
    detach()    - Stops an attached servos from pulsing its i/o pin.

    */
#endif
#if defined (marlin4Due)
    /*

    A servo is activated by creating an instance of the Servo class passing the desired pin to the attach() method.
    The servos are pulsed in the background using the value most recently written using the write() method

    Note that analogWrite of PWM on pins associated with the timer are disabled when the first servo is attached.
    Timers are seized as needed in groups of 12 servos - 24 servos use two timers, 48 servos will use four.

    The methods are:

    Servo - Class for manipulating servo motors connected to Arduino pins.

    attach(pin )  - Attaches a servo motor to an i/o pin.
    attach(pin, min, max  ) - Attaches to a pin setting min and max values in microseconds
    default min is 544, max is 2400

    write()     - Sets the servo angle in degrees.  (invalid angle that is valid as pulse in microseconds is treated as microseconds)
    writeMicroseconds() - Sets the servo pulse width in microseconds
    move(pin, angle) - Sequence of attach(pin), write(angle).
    With DEACTIVATE_SERVOS_AFTER_MOVE it waits SERVO_DEACTIVATION_DELAY and detaches.
    read()      - Gets the last written servo pulse width as an angle between 0 and 180.
    readMicroseconds()   - Gets the last written servo pulse width in microseconds. (was read_us() in first release)
    attached()  - Returns true if there is a servo attached.
    detach()    - Stops an attached servos from pulsing its i/o pin.

    */
#endif
#if defined (upstream) || defined (marlin4Due)
    #include "Configuration.h"
#endif
#if defined (upstream) && defined (NUM_SERVOS)
    #include <avr/interrupt.h>
#endif
#if defined (upstream) && defined (NUM_SERVOS) || defined (marlin4Due) && defined (NUM_SERVOS)
    #include <Arduino.h>
#endif
#if defined (upstream) && defined (NUM_SERVOS)
    #include "Servo.h"
#endif
#if defined (marlin4Due) && defined (NUM_SERVOS)
    #include "servo.h"
#endif
#if defined (upstream) && defined (NUM_SERVOS)
    #define usToTicks(_us)    (( clockCyclesPerMicrosecond()* _us) / 8)
#endif
#if defined (marlin4Due) && defined (NUM_SERVOS)
    #define usToTicks(_us)    (( clockCyclesPerMicrosecond() * _us) / 32)
#endif
#if defined (upstream) && defined (NUM_SERVOS)
    // converts microseconds to tick (assumes prescale of 8)  // 12 Aug 2009
#endif
#if defined (marlin4Due) && defined (NUM_SERVOS)
    // converts microseconds to tick
#endif
#if defined (upstream) && defined (NUM_SERVOS)
    #define ticksToUs(_ticks) (( (unsigned)_ticks * 8)/ clockCyclesPerMicrosecond() )
#endif
#if defined (marlin4Due) && defined (NUM_SERVOS)
    #define ticksToUs(_ticks) (( (unsigned)_ticks * 32)/ clockCyclesPerMicrosecond() )
#endif
#if defined (upstream) && defined (NUM_SERVOS) || defined (marlin4Due) && defined (NUM_SERVOS)
    // converts from ticks back to microseconds
    #define TRIM_DURATION       2
#endif
#if defined (upstream) && defined (NUM_SERVOS)
    // compensation ticks to trim adjust for digitalWrite delays // 12 August 2009
#endif
#if defined (marlin4Due) && defined (NUM_SERVOS)
    // compensation ticks to trim adjust for digitalWrite delays
#endif
#if defined (upstream) && defined (NUM_SERVOS)
    //#define NBR_TIMERS        (MAX_SERVOS / SERVOS_PER_TIMER)
#endif
#if defined (marlin4Due) && defined (NUM_SERVOS)
    static ServoInfo_t servo_info[MAX_SERVOS];
#endif
#if defined (upstream) && defined (NUM_SERVOS)
    static servo_t servos[MAX_SERVOS];
#endif
#if defined (marlin4Due) && defined (NUM_SERVOS)
    // static array of servo info structures
#endif
#if defined (upstream) && defined (NUM_SERVOS)
    // static array of servo structures
#endif
#if defined (upstream) && defined (NUM_SERVOS) || defined (marlin4Due) && defined (NUM_SERVOS)
    static volatile int8_t Channel[_Nbr_16timers ];
    // counter for the servo being pulsed for each timer (or -1 if refresh interval)
    uint8_t ServoCount = 0;
    // the total number of attached servos
    // convenience macros
    #define SERVO_INDEX_TO_TIMER(_servo_nbr) ((timer16_Sequence_t)(_servo_nbr / SERVOS_PER_TIMER))
    // returns the timer controlling this servo
    #define SERVO_INDEX_TO_CHANNEL(_servo_nbr) (_servo_nbr % SERVOS_PER_TIMER)
    // returns the index of the servo on this timer
    #define SERVO_INDEX(_timer,_channel)  ((_timer*SERVOS_PER_TIMER) + _channel)
    // macro to access servo index by timer and channel
#endif
#if defined (upstream) && defined (NUM_SERVOS)
    #define SERVO(_timer,_channel)  (servos[SERVO_INDEX(_timer,_channel)])
#endif
#if defined (marlin4Due) && defined (NUM_SERVOS)
    #define SERVO(_timer,_channel)  (servo_info[SERVO_INDEX(_timer,_channel)])
#endif
#if defined (upstream) && defined (NUM_SERVOS) || defined (marlin4Due) && defined (NUM_SERVOS)
    // macro to access servo class by timer and channel
    #define SERVO_MIN() (MIN_PULSE_WIDTH - this->min * 4)
    // minimum value in uS for this servo
    #define SERVO_MAX() (MAX_PULSE_WIDTH - this->max * 4)
    // maximum value in uS for this servo
    /************ static functions common to all instances ***********************/
#endif
#if defined (upstream) && defined (NUM_SERVOS)
static inline void handle_interrupts(timer16_Sequence_t timer, volatile uint16_t *TCNTn, volatile uint16_t* OCRnA) {
    if( Channel[timer] < 0 )
        *TCNTn = 0; // channel set to -1 indicated that refresh interval completed so reset the timer
    else {
        if( SERVO_INDEX(timer,Channel[timer]) < ServoCount && SERVO(timer,Channel[timer]).Pin.isActive == true )
            digitalWrite( SERVO(timer,Channel[timer]).Pin.nbr,LOW); // pulse this channel low if activated
    }
    Channel[timer]++;    // increment to the next channel
    if( SERVO_INDEX(timer,Channel[timer]) < ServoCount && Channel[timer] < SERVOS_PER_TIMER) {
        *OCRnA = *TCNTn + SERVO(timer,Channel[timer]).ticks;
        if(SERVO(timer,Channel[timer]).Pin.isActive == true)     // check if activated
            digitalWrite( SERVO(timer,Channel[timer]).Pin.nbr,HIGH); // its an active channel so pulse it high
    } else {
        // finished all channels so wait for the refresh period to expire before starting over
        if( ((unsigned)*TCNTn) + 4 < usToTicks(REFRESH_INTERVAL) )  // allow a few ticks to ensure the next OCR1A not missed
            *OCRnA = (unsigned int)usToTicks(REFRESH_INTERVAL);
        else
            *OCRnA = *TCNTn + 4;  // at least REFRESH_INTERVAL has elapsed
        Channel[timer] = -1; // this will get incremented at the end of the refresh period to start again at the first channel
    }
}
#endif
#if defined (marlin4Due) && defined (NUM_SERVOS)
    //------------------------------------------------------------------------------
#endif
#if defined (upstream) && (defined (NUM_SERVOS) && !defined (WIRING) )
    // Wiring pre-defines signal handlers so don't define any if compiling for the Wiring platform
#endif
#if defined (marlin4Due) && defined (NUM_SERVOS)
    /// Interrupt handler for the TC0 channel 1.
#endif
#if defined (upstream) && (defined (NUM_SERVOS) && !defined (WIRING) )
    // Interrupt handlers for Arduino
#endif
#if defined (marlin4Due) && defined (NUM_SERVOS)
    //------------------------------------------------------------------------------
#endif
#if defined (upstream) && (defined (NUM_SERVOS) && defined(_useTimer1) && !defined (WIRING) )
    SIGNAL (TIMER1_COMPA_vect)
#endif
#if defined (marlin4Due) && defined (NUM_SERVOS)
    void Servo_Handler(timer16_Sequence_t timer, Tc *pTc, uint8_t channel);
#endif
#if defined (upstream) && (defined (NUM_SERVOS) && defined(_useTimer1) && !defined (WIRING) )

    handle_interrupts(_timer1, &TCNT1, &OCR1A);


#endif
#if defined (marlin4Due) && (defined (NUM_SERVOS) && defined (_useTimer1) )void HANDLER_FOR_TIMER1(void) {
Servo_Handler(_timer1, TC_FOR_TIMER1, CHANNEL_FOR_TIMER1);
}
#endif
#if defined (upstream) && (defined (NUM_SERVOS) && defined(_useTimer3) && !defined (WIRING) )
    SIGNAL (TIMER3_COMPA_vect)
#endif
#if defined (marlin4Due) && (defined (NUM_SERVOS) && defined (_useTimer2) )
void HANDLER_FOR_TIMER2(void) {
    Servo_Handler(_timer2, TC_FOR_TIMER2, CHANNEL_FOR_TIMER2);
}
#endif
#if defined (upstream) && (defined (NUM_SERVOS) && defined(_useTimer3) && !defined (WIRING) )

    handle_interrupts(_timer3, &TCNT3, &OCR3A);


#endif
#if defined (marlin4Due) && (defined (NUM_SERVOS) && defined (_useTimer3) )void HANDLER_FOR_TIMER3(void) {
Servo_Handler(_timer3, TC_FOR_TIMER3, CHANNEL_FOR_TIMER3);
}
#endif
#if defined (upstream) && (defined (NUM_SERVOS) && defined(_useTimer4) && !defined (WIRING) )
    SIGNAL (TIMER4_COMPA_vect)
#endif
#if defined (marlin4Due) && (defined (NUM_SERVOS) && defined (_useTimer4) )
void HANDLER_FOR_TIMER4(void) {
    Servo_Handler(_timer4, TC_FOR_TIMER4, CHANNEL_FOR_TIMER4);
}
#endif
#if defined (upstream) && (defined (NUM_SERVOS) && defined(_useTimer4) && !defined (WIRING) )

    handle_interrupts(_timer4, &TCNT4, &OCR4A);


#endif
#if defined (marlin4Due) && (defined (NUM_SERVOS) && defined (_useTimer5) )void HANDLER_FOR_TIMER5(void) {
Servo_Handler(_timer5, TC_FOR_TIMER5, CHANNEL_FOR_TIMER5);
}
#endif
#if defined (upstream) && (defined (NUM_SERVOS) && defined(_useTimer5) && !defined (WIRING) )
    SIGNAL (TIMER5_COMPA_vect)
#endif
#if defined (marlin4Due) && defined (NUM_SERVOS)
void Servo_Handler(timer16_Sequence_t timer, Tc *tc, uint8_t channel) {
    // clear interrupt
    tc->TC_CHANNEL[channel].TC_SR;
    if (Channel[timer] < 0) {
        tc->TC_CHANNEL[channel].TC_CCR |= TC_CCR_SWTRG; // channel set to -1 indicated that refresh interval completed so reset the timer
    } else {
        if (SERVO_INDEX(timer,Channel[timer]) < ServoCount && SERVO(timer,Channel[timer]).Pin.isActive == true) {
            digitalWrite(SERVO(timer,Channel[timer]).Pin.nbr, LOW); // pulse this channel low if activated
        }
    }
    Channel[timer]++;    // increment to the next channel
    if( SERVO_INDEX(timer,Channel[timer]) < ServoCount && Channel[timer] < SERVOS_PER_TIMER) {
        tc->TC_CHANNEL[channel].TC_RA = tc->TC_CHANNEL[channel].TC_CV + SERVO(timer,Channel[timer]).ticks;
        if(SERVO(timer,Channel[timer]).Pin.isActive) {    // check if activated
            digitalWrite( SERVO(timer,Channel[timer]).Pin.nbr,HIGH); // its an active channel so pulse it high
        }
    } else {
        // finished all channels so wait for the refresh period to expire before starting over
        if( (tc->TC_CHANNEL[channel].TC_CV) + 4 < usToTicks(REFRESH_INTERVAL) ) { // allow a few ticks to ensure the next OCR1A not missed
            tc->TC_CHANNEL[channel].TC_RA = (unsigned int)usToTicks(REFRESH_INTERVAL);
        } else {
            tc->TC_CHANNEL[channel].TC_RA = tc->TC_CHANNEL[channel].TC_CV + 4;  // at least REFRESH_INTERVAL has elapsed
        }
        Channel[timer] = -1; // this will get incremented at the end of the refresh period to start again at the first channel
    }
}
#endif
#if defined (upstream) && (defined (NUM_SERVOS) && defined(_useTimer5) && !defined (WIRING) )

    handle_interrupts(_timer5, &TCNT5, &OCR5A);


#endif
#if defined (marlin4Due) && defined (NUM_SERVOS)static void _initISR(Tc *tc, uint32_t channel, uint32_t id, IRQn_Type irqn)
{
    pmc_enable_periph_clk(id);
    TC_Configure(tc, channel,
                 TC_CMR_TCCLKS_TIMER_CLOCK3 | // MCK/32
                 TC_CMR_WAVE |                // Waveform mode
                 TC_CMR_WAVSEL_UP_RC );       // Counter running up and reset when equals to RC
    /* 84MHz, MCK/32, for 1.5ms: 3937 */
    TC_SetRA(tc, channel, 2625); // 1ms
    /* Configure and enable interrupt */
    NVIC_EnableIRQ(irqn);
    // TC_IER_CPAS: RA Compare
    tc->TC_CHANNEL[channel].TC_IER = TC_IER_CPAS;
    // Enables the timer clock and performs a software reset to start the counting
    TC_Start(tc, channel);
}
#endif
#if defined (upstream) && (defined (NUM_SERVOS) && defined WIRING )
    // Interrupt handlers for Wiring
#endif
#if defined (upstream) && (defined (NUM_SERVOS) && defined(_useTimer1) && defined WIRING )
void Timer1Service() {
    handle_interrupts(_timer1, &TCNT1, &OCR1A);
}
#endif
#if defined (upstream) && (defined (NUM_SERVOS) && defined(_useTimer3) && defined WIRING )
void Timer3Service() {
    handle_interrupts(_timer3, &TCNT3, &OCR3A);
}
#endif
#if defined (upstream) && defined (NUM_SERVOS) || defined (marlin4Due) && defined (NUM_SERVOS)
static void initISR
(timer16_Sequence_t timer) {
#if defined (upstream) && (defined (NUM_SERVOS) && defined (_useTimer1) ) || defined (marlin4Due) && (defined (NUM_SERVOS) && defined (_useTimer1) )
    if
    (timer == _timer1) {
#if defined (upstream) && (defined (NUM_SERVOS) && defined (_useTimer1) )
        TCCR1A = 0;             // normal counting mode
        TCCR1B = _BV(CS11);     // set prescaler of 8
        TCNT1 = 0;              // clear the timer count
#if defined(__AVR_ATmega8__)|| defined(__AVR_ATmega128__)
        TIFR |= _BV(OCF1A);      // clear any pending interrupts;
        TIMSK |=  _BV(OCIE1A) ;  // enable the output compare interrupt
#else
        // here if not ATmega8 or ATmega128
        TIFR1 |= _BV(OCF1A);     // clear any pending interrupts;
        TIMSK1 |=  _BV(OCIE1A) ; // enable the output compare interrupt
#endif
#if defined(WIRING)
        timerAttach(TIMER1OUTCOMPAREA_INT, Timer1Service);
#endif
#endif
#if defined (marlin4Due) && (defined (NUM_SERVOS) && defined (_useTimer1) )_initISR(TC_FOR_TIMER1, CHANNEL_FOR_TIMER1, ID_TC_FOR_TIMER1, IRQn_FOR_TIMER1);
#endif
    }
#endif
#if defined (marlin4Due) && (defined (NUM_SERVOS) && defined (_useTimer2) )
    if (timer == _timer2)
        _initISR(TC_FOR_TIMER2, CHANNEL_FOR_TIMER2, ID_TC_FOR_TIMER2, IRQn_FOR_TIMER2);
#endif
#if defined (upstream) && (defined (NUM_SERVOS) && defined (_useTimer3) ) || defined (marlin4Due) && (defined (NUM_SERVOS) && defined (_useTimer3) )
    if
    (timer == _timer3) {
#if defined (upstream) && (defined (NUM_SERVOS) && defined (_useTimer3) )
        TCCR3A = 0;             // normal counting mode
        TCCR3B = _BV(CS31);     // set prescaler of 8
        TCNT3 = 0;              // clear the timer count
#if defined(__AVR_ATmega128__)
        TIFR |= _BV(OCF3A);     // clear any pending interrupts;
        ETIMSK |= _BV(OCIE3A);  // enable the output compare interrupt
#else
        TIFR3 = _BV(OCF3A);     // clear any pending interrupts;
        TIMSK3 =  _BV(OCIE3A) ; // enable the output compare interrupt
#endif
#if defined(WIRING)
        timerAttach(TIMER3OUTCOMPAREA_INT, Timer3Service);  // for Wiring platform only
#endif
#endif
#if defined (marlin4Due) && (defined (NUM_SERVOS) && defined (_useTimer3) )_initISR(TC_FOR_TIMER3, CHANNEL_FOR_TIMER3, ID_TC_FOR_TIMER3, IRQn_FOR_TIMER3);
#endif
    }
#endif
#if defined (upstream) && (defined (NUM_SERVOS) && defined (_useTimer4) ) || defined (marlin4Due) && (defined (NUM_SERVOS) && defined (_useTimer4) )
    if
    (timer == _timer4) {
#if defined (upstream) && (defined (NUM_SERVOS) && defined (_useTimer4) )
        TCCR4A = 0;             // normal counting mode
        TCCR4B = _BV(CS41);     // set prescaler of 8
        TCNT4 = 0;              // clear the timer count
        TIFR4 = _BV(OCF4A);     // clear any pending interrupts;
        TIMSK4 =  _BV(OCIE4A) ; // enable the output compare interrupt
#endif
#if defined (marlin4Due) && (defined (NUM_SERVOS) && defined (_useTimer4) )_initISR(TC_FOR_TIMER4, CHANNEL_FOR_TIMER4, ID_TC_FOR_TIMER4, IRQn_FOR_TIMER4);
#endif
    }
#endif
#if defined (upstream) && (defined (NUM_SERVOS) && defined (_useTimer5) ) || defined (marlin4Due) && (defined (NUM_SERVOS) && defined (_useTimer5) )
    if
    (timer == _timer5) {
#if defined (upstream) && (defined (NUM_SERVOS) && defined (_useTimer5) )
        TCCR5A = 0;             // normal counting mode
        TCCR5B = _BV(CS51);     // set prescaler of 8
        TCNT5 = 0;              // clear the timer count
        TIFR5 = _BV(OCF5A);     // clear any pending interrupts;
        TIMSK5 =  _BV(OCIE5A) ; // enable the output compare interrupt
#endif
#if defined (marlin4Due) && (defined (NUM_SERVOS) && defined (_useTimer5) )_initISR(TC_FOR_TIMER5, CHANNEL_FOR_TIMER5, ID_TC_FOR_TIMER5, IRQn_FOR_TIMER5);
#endif
    }
#endif
}
static void finISR
(timer16_Sequence_t timer) {
#if defined (upstream) && defined (NUM_SERVOS)
//disable use of the given timer
#endif
#if defined (marlin4Due) && (defined (NUM_SERVOS) && defined (_useTimer1) )
    TC_Stop(TC_FOR_TIMER1, CHANNEL_FOR_TIMER1);
#endif
#if defined (upstream) && (defined (NUM_SERVOS) && defined WIRING )
// Wiring
#endif
#if defined (marlin4Due) && (defined (NUM_SERVOS) && defined (_useTimer2) )
    TC_Stop(TC_FOR_TIMER2, CHANNEL_FOR_TIMER2);
#endif
#if defined (upstream) && (defined (NUM_SERVOS) && defined WIRING )
    if(timer == _timer1) {
#if defined(__AVR_ATmega1281__)||defined(__AVR_ATmega2561__)
        TIMSK1 &=  ~_BV(OCIE1A) ;  // disable timer 1 output compare interrupt
#else
        TIMSK &=  ~_BV(OCIE1A) ;  // disable timer 1 output compare interrupt
#endif
        timerDetach(TIMER1OUTCOMPAREA_INT);
    } else if(timer == _timer3) {
#if defined(__AVR_ATmega1281__)||defined(__AVR_ATmega2561__)
        TIMSK3 &= ~_BV(OCIE3A);    // disable the timer3 output compare A interrupt
#else
        ETIMSK &= ~_BV(OCIE3A);    // disable the timer3 output compare A interrupt
#endif
        timerDetach(TIMER3OUTCOMPAREA_INT);
    }
#endif
#if defined (marlin4Due) && (defined (NUM_SERVOS) && defined (_useTimer3) )
    TC_Stop(TC_FOR_TIMER3, CHANNEL_FOR_TIMER3);
#endif
#if defined (upstream) && (defined (NUM_SERVOS) && !defined WIRING )
//For arduino - in future: call here to a currently undefined function to reset the timer
#endif
#if defined (marlin4Due) && (defined (NUM_SERVOS) && defined (_useTimer4) )
    TC_Stop(TC_FOR_TIMER4, CHANNEL_FOR_TIMER4);
#endif
#if defined (marlin4Due) && (defined (NUM_SERVOS) && defined (_useTimer5) )
    TC_Stop(TC_FOR_TIMER5, CHANNEL_FOR_TIMER5);
#endif
}
static boolean isTimerActive
(timer16_Sequence_t timer) {
// returns true if any servo is active on this timer
    for(uint8_t channel=0; channel < SERVOS_PER_TIMER; channel++) {
        if
#if defined (upstream) && defined (NUM_SERVOS)
        (SERVO(timer,channel).Pin.isActive == true)
#endif
#if defined (marlin4Due) && defined (NUM_SERVOS)
            (SERVO(timer,channel).Pin.isActive)
#endif
            return true;
    }
    return false;
}
/****************** end of static functions ******************************/
#endif
#if defined (upstream) && defined (NUM_SERVOS)
Servo::Servo() {
    if( ServoCount < MAX_SERVOS) {
        this->servoIndex = ServoCount++;                    // assign a servo index to this instance
        servos[this->servoIndex].ticks = usToTicks(DEFAULT_PULSE_WIDTH);   // store default values  - 12 Aug 2009
    } else
        this->servoIndex = INVALID_SERVO ;  // too many servos
}
#endif
#if defined (marlin4Due) && defined (NUM_SERVOS)
Servo::Servo() {
    if (ServoCount < MAX_SERVOS) {
        this->servoIndex = ServoCount++;                    // assign a servo index to this instance
        servo_info[this->servoIndex].ticks = usToTicks(DEFAULT_PULSE_WIDTH);   // store default values  - 12 Aug 2009
    } else
        this->servoIndex = INVALID_SERVO;  // too many servos
}
#endif
#if defined (upstream) && defined (NUM_SERVOS)
uint8_t Servo::attach(int pin) {
    return this->attach(pin, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
}
#endif
#if defined (marlin4Due) && defined (NUM_SERVOS)
int8_t Servo::attach(int pin) {
    return this->attach(pin, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
}
#endif
#if defined (upstream) && defined (NUM_SERVOS)
uint8_t Servo::attach(int pin, int min, int max) {
    if(this->servoIndex < MAX_SERVOS ) {
#if defined (ENABLE_AUTO_BED_LEVELING) && (PROBE_SERVO_DEACTIVATION_DELAY > 0)
        if (pin > 0) this->pin = pin;
        else pin = this->pin;
#endif
        pinMode( pin, OUTPUT) ;                                   // set servo pin to output
        servos[this->servoIndex].Pin.nbr = pin;
        // todo min/max check: abs(min - MIN_PULSE_WIDTH) /4 < 128
        this->min  = (MIN_PULSE_WIDTH - min)/4; //resolution of min/max is 4 uS
        this->max  = (MAX_PULSE_WIDTH - max)/4;
        // initialize the timer if it has not already been initialized
        timer16_Sequence_t timer = SERVO_INDEX_TO_TIMER(servoIndex);
        if(isTimerActive(timer) == false)
            initISR(timer);
        servos[this->servoIndex].Pin.isActive = true;  // this must be set after the check for isTimerActive
    }
    return this->servoIndex ;
}
#endif
#if defined (marlin4Due) && defined (NUM_SERVOS)
int8_t Servo::attach(int pin, int min, int max) {
    if (this->servoIndex >= MAX_SERVOS) return -1;
    if (pin > 0) servo_info[this->servoIndex].Pin.nbr = pin;
    pinMode(servo_info[this->servoIndex].Pin.nbr, OUTPUT); // set servo pin to output
    // todo min/max check: abs(min - MIN_PULSE_WIDTH) /4 < 128
    this->min = (MIN_PULSE_WIDTH - min) / 4; //resolution of min/max is 4 uS
    this->max = (MAX_PULSE_WIDTH - max) / 4;
    // initialize the timer if it has not already been initialized
    timer16_Sequence_t timer = SERVO_INDEX_TO_TIMER(servoIndex);
    if (!isTimerActive(timer)) initISR(timer);
    servo_info[this->servoIndex].Pin.isActive = true;  // this must be set after the check for isTimerActive
    return this->servoIndex;
}
#endif
#if defined (upstream) && defined (NUM_SERVOS) || defined (marlin4Due) && defined (NUM_SERVOS)
void Servo::detach
() {
#if defined (upstream) && defined (NUM_SERVOS)
    servos[this->servoIndex].Pin.isActive = false;
#endif
#if defined (marlin4Due) && defined (NUM_SERVOS)
    servo_info[this->servoIndex].Pin.isActive = false;
#endif
    timer16_Sequence_t timer = SERVO_INDEX_TO_TIMER(servoIndex);
    if
#if defined (upstream) && defined (NUM_SERVOS)
    (isTimerActive(timer) == false)
#endif
#if defined (marlin4Due) && defined (NUM_SERVOS)
        (!isTimerActive(timer))
#endif
    {
        finISR(timer);
    }
}
void Servo::write
(int value) {
#if defined (marlin4Due) && defined (NUM_SERVOS)
// treat values less than 544 as angles in degrees (valid values in microseconds are handled as microseconds)
#endif
    if
    (value < MIN_PULSE_WIDTH) {
#if defined (upstream) && defined (NUM_SERVOS)
// treat values less than 544 as angles in degrees (valid values in microseconds are handled as microseconds)
#endif
        if
        (value < 0)
            value = 0;
        if
        (value > 180)
            value = 180;
        value = map(value, 0, 180, SERVO_MIN(),  SERVO_MAX());
    }
    this->writeMicroseconds(value);
}
void Servo::writeMicroseconds
(int value) {
// calculate and store the values for the given channel
    byte channel = this->servoIndex;
    if
    ( (channel < MAX_SERVOS) )
#if defined (upstream) && defined (NUM_SERVOS)
// ensure channel is valid
#endif
#if defined (marlin4Due) && defined (NUM_SERVOS)
// ensure channel is valid
#endif
        if
        ( value < SERVO_MIN() )
// ensure pulse width is valid
            value = SERVO_MIN();
        else if
        ( value > SERVO_MAX() )
            value = SERVO_MAX();
    value = value - TRIM_DURATION;
    value = usToTicks(value);
#if defined (upstream) && defined (NUM_SERVOS)
// convert to ticks after compensating for interrupt overhead - 12 Aug 2009
#endif
#if defined (marlin4Due) && defined (NUM_SERVOS)
// convert to ticks after compensating for interrupt overhead
    uint8_t oldSREG = SREG;
#endif
#if defined (marlin4Due) && defined (NUM_SERVOS)
    servo_info[channel].ticks = value;
    cli();
    servos[channel].ticks = value;
    SREG = oldSREG;
#endif
}
#endif
#if defined (marlin4Due) && defined (NUM_SERVOS)
    // return the value as degrees
#endif
#if defined (upstream) && defined (NUM_SERVOS) || defined (marlin4Due) && defined (NUM_SERVOS)
int Servo::read
()
#if defined (upstream) && defined (NUM_SERVOS)
    // return the value as degrees
#endif
{
    return  map( this->readMicroseconds()+1, SERVO_MIN(), SERVO_MAX(), 0, 180);
}
int Servo::readMicroseconds
() {
#if defined (upstream) && defined (NUM_SERVOS)
    unsigned int pulsewidth;
#endif
#if defined (marlin4Due) && defined (NUM_SERVOS)
    return (this->servoIndex == INVALID_SERVO) ? 0 : ticksToUs(servo_info[this->servoIndex].ticks) + TRIM_DURATION;
#endif
#if defined (upstream) && defined (NUM_SERVOS)
    if( this->servoIndex != INVALID_SERVO )
        pulsewidth = ticksToUs(servos[this->servoIndex].ticks)  + TRIM_DURATION ;   // 12 aug 2009
    else
        pulsewidth  = 0;
    return pulsewidth;
#endif
}
bool Servo::attached
() {
#if defined (upstream) && defined (NUM_SERVOS)
    return servos[this->servoIndex].Pin.isActive ;
#endif
#if defined (marlin4Due) && defined (NUM_SERVOS)
    return servo_info[this->servoIndex].Pin.isActive;
#endif
}
#endif
#if defined (marlin4Due) && defined (NUM_SERVOS)
void Servo::move(int value) {
    if (this->attach(0) >= 0) {
        this->write(value);
#ifdef DEACTIVATE_SERVOS_AFTER_MOVE
        delay(SERVO_DEACTIVATION_DELAY);
        this->detach();
#endif
    }
}
#endif
