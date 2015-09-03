#if defined (upstream) || defined (marlin4Due)
    #include "Marlin.h"
#endif
#if defined (upstream) && defined (USE_WATCHDOG)
    #include <avr/wdt.h>
#endif
#if defined (upstream) && defined (USE_WATCHDOG) || defined (marlin4Due) && defined (USE_WATCHDOG)
    #include "watchdog.h"
    #include "ultralcd.h"
    //===========================================================================
#endif
#if defined (upstream) && defined (USE_WATCHDOG)
    //=============================private variables  ============================
#endif
#if defined (marlin4Due) && defined (USE_WATCHDOG)
    //============================ private variables ============================
#endif
#if defined (upstream) && defined (USE_WATCHDOG) || defined (marlin4Due) && defined (USE_WATCHDOG)
    //===========================================================================
    //===========================================================================
#endif
#if defined (upstream) && defined (USE_WATCHDOG)
    //=============================functinos         ============================
#endif
#if defined (marlin4Due) && defined (USE_WATCHDOG)
    //================================ functions ================================
#endif
#if defined (upstream) && defined (USE_WATCHDOG) || defined (marlin4Due) && defined (USE_WATCHDOG)
//===========================================================================
/// intialise watch dog with a 4 sec interrupt time
void watchdog_init
() {
#if defined (upstream) && (defined (WATCHDOG_RESET_MANUAL) && defined (USE_WATCHDOG) )
//We enable the watchdog timer, but only for the interrupt.
#endif
#if defined (marlin4Due) && defined (USE_WATCHDOG)
    const uint32_t wdtTicks = 256;
#endif
#if defined (upstream) && (defined (WATCHDOG_RESET_MANUAL) && defined (USE_WATCHDOG) )
//Take care, as this requires the correct order of operation, with interrupts disabled. See the datasheet of any AVR chip for details.
#endif
#if defined (marlin4Due) && defined (USE_WATCHDOG)
// number of watchdog ticks @ 32768Hz/128 before the watchdog times out (max 4095)
#endif
#if defined (upstream) && (defined (WATCHDOG_RESET_MANUAL) && defined (USE_WATCHDOG) )
    wdt_reset();
#endif
#if defined (marlin4Due) && defined (USE_WATCHDOG)
    WDT_Enable(WDT, (wdtTicks << WDT_MR_WDV_Pos) | (wdtTicks << WDT_MR_WDD_Pos) | WDT_MR_WDRSTEN);
#endif
#if defined (upstream) && (defined (WATCHDOG_RESET_MANUAL) && defined (USE_WATCHDOG) )
    _WD_CONTROL_REG = _BV(_WD_CHANGE_BIT) | _BV(WDE);
#endif
#if defined (marlin4Due) && defined (USE_WATCHDOG)
// enable watchdog, reset the mcu if it times out
#endif
#if defined (upstream) && (defined (WATCHDOG_RESET_MANUAL) && defined (USE_WATCHDOG) )
    _WD_CONTROL_REG = _BV(WDIE) | WDTO_4S;
#endif
#if defined (upstream) && (!defined (WATCHDOG_RESET_MANUAL) && defined (USE_WATCHDOG) )
    wdt_enable(WDTO_4S);
#endif
}
/// reset watchdog. MUST be called every 1s after init or avr will reset.
void watchdog_reset
() {
#if defined (upstream) && defined (USE_WATCHDOG)
    wdt_reset();
#endif
#if defined (marlin4Due) && defined (USE_WATCHDOG)
    WDT_Restart(WDT);
#endif
}
#endif
#if defined (upstream) && defined (USE_WATCHDOG)
    //===========================================================================
    //=============================ISR               ============================
    //===========================================================================
    //Watchdog timer interrupt, called if main program blocks >1sec and manual reset is enabled.
#endif
#if defined (upstream) && (defined (USE_WATCHDOG) && defined (WATCHDOG_RESET_MANUAL) )
    ISR(WDT_vect)

    //TODO: This message gets overwritten by the kill() call
    LCD_ALERTMESSAGEPGM("ERR:Please Reset");//16 characters so it fits on a 16x2 display
    lcd_update();
    SERIAL_ERROR_START;
    SERIAL_ERRORLNPGM("Something is wrong, please turn off the printer.");
    kill(); //kill blocks
    while(1); //wait for user or serial reset


#endif
#if defined (upstream) && defined (USE_WATCHDOG)
    //RESET_MANUAL
#endif
#if defined (upstream)
    //USE_WATCHDOG
#endif