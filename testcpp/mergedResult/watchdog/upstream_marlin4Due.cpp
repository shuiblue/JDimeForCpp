#if defined (A) || defined (B)
    #include "Marlin.h"
#endif
#if defined (A) && defined (USE_WATCHDOG)
    #include <avr/wdt.h>
#endif
#if defined (A) && defined (USE_WATCHDOG) || defined (B) && defined (USE_WATCHDOG)
    #include "watchdog.h"
    #include "ultralcd.h"
    //===========================================================================
#endif
#if defined (A) && defined (USE_WATCHDOG)
    //=============================private variables  ============================
#endif
#if defined (B) && defined (USE_WATCHDOG)
    //============================ private variables ============================
#endif
#if defined (A) && defined (USE_WATCHDOG) || defined (B) && defined (USE_WATCHDOG)
    //===========================================================================
    //===========================================================================
#endif
#if defined (A) && defined (USE_WATCHDOG)
    //=============================functinos         ============================
#endif
#if defined (B) && defined (USE_WATCHDOG)
    //================================ functions ================================
#endif
#if defined (A) && defined (USE_WATCHDOG) || defined (B) && defined (USE_WATCHDOG)
//===========================================================================
/// intialise watch dog with a 4 sec interrupt time
void watchdog_init
() {
#if defined (A) && defined (USE_WATCHDOG)
#ifdef WATCHDOG_RESET_MANUAL
    //We enable the watchdog timer, but only for the interrupt.
    //Take care, as this requires the correct order of operation, with interrupts disabled. See the datasheet of any AVR chip for details.
    wdt_reset();
    _WD_CONTROL_REG = _BV(_WD_CHANGE_BIT) | _BV(WDE);
    _WD_CONTROL_REG = _BV(WDIE) | WDTO_4S;
#else
    wdt_enable(WDTO_4S);
#endif
#endif
#if defined (B) && defined (USE_WATCHDOG)
    const uint32_t wdtTicks = 256;	// number of watchdog ticks @ 32768Hz/128 before the watchdog times out (max 4095)
    WDT_Enable(WDT, (wdtTicks << WDT_MR_WDV_Pos) | (wdtTicks << WDT_MR_WDD_Pos) | WDT_MR_WDRSTEN);	// enable watchdog, reset the mcu if it times out
#endif
}
/// reset watchdog. MUST be called every 1s after init or avr will reset.
void watchdog_reset
() {
#if defined (A) && defined (USE_WATCHDOG)
    wdt_reset();
#endif
#if defined (B) && defined (USE_WATCHDOG)
    WDT_Restart(WDT);
#endif
}
#endif
#if defined (A) && defined (USE_WATCHDOG)
    //===========================================================================
    //=============================ISR               ============================
    //===========================================================================
    //Watchdog timer interrupt, called if main program blocks >1sec and manual reset is enabled.
#endif
#if defined (A) && (defined (USE_WATCHDOG) && defined (WATCHDOG_RESET_MANUAL) )
    ISR(WDT_vect)


    //TODO: This message gets overwritten by the kill() call
    LCD_ALERTMESSAGEPGM("ERR:Please Reset");//16 characters so it fits on a 16x2 display
    lcd_update();
    SERIAL_ERROR_START;
    SERIAL_ERRORLNPGM("Something is wrong, please turn off the printer.");
    kill(); //kill blocks
    while(1); //wait for user or serial reset


#endif
#if defined (A) && defined (USE_WATCHDOG)
    //RESET_MANUAL
#endif
#if defined (A)
    //USE_WATCHDOG
#endif