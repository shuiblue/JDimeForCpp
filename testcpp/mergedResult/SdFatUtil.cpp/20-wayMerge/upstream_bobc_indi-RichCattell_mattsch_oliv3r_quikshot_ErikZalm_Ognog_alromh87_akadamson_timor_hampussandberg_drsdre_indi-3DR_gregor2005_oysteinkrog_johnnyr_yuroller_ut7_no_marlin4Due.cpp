#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (Ognog) || defined (alromh87) || defined (akadamson) || defined (timor) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
/* Arduino SdFat Library
 * Copyright (C) 2008 by William Greiman
 *
 * This file is part of the Arduino SdFat Library
 *
 * This Library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This Library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with the Arduino SdFat Library.  If not, see
 * <http://www.gnu.org/licenses/>.
 */
#include "Marlin.h"
#endif
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (indi-3DR) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT)
    #include "SdFatUtil.h"
    //------------------------------------------------------------------------------
#endif
#if defined (upstream) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT)
    /** Amount of free RAM
    * \return The number of free bytes.
    */
#endif
#if defined (oliv3r) && defined (SDSUPPORT)
    extern int  __bss_end;
#endif
#if defined (upstream) && (defined (SDSUPPORT) && defined (__arm__) ) || defined (ErikZalm) && (defined (SDSUPPORT) && defined (__arm__) ) || defined (oysteinkrog) && (defined (SDSUPPORT) && defined (__arm__) ) || defined (yuroller) && (defined (SDSUPPORT) && defined (__arm__) )

    extern "C" char* sbrk(int incr);
#endif
#if defined (oliv3r) && defined (SDSUPPORT)
    extern int* __brkval;
#endif
#if defined (upstream) && (defined (SDSUPPORT) && defined (__arm__) ) || defined (ErikZalm) && (defined (SDSUPPORT) && defined (__arm__) ) || defined (oysteinkrog) && (defined (SDSUPPORT) && defined (__arm__) ) || defined (yuroller) && (defined (SDSUPPORT) && defined (__arm__) )

int SdFatUtil::FreeRam() {
    char top;
    return &top - reinterpret_cast<char*>(sbrk(0));
}
#endif
#if defined (upstream) && (defined (SDSUPPORT) && !defined (__arm__) ) || defined (ErikZalm) && (defined (SDSUPPORT) && !defined (__arm__) ) || defined (oysteinkrog) && (defined (SDSUPPORT) && !defined (__arm__) ) || defined (yuroller) && (defined (SDSUPPORT) && !defined (__arm__) )
    // __arm__
    extern char *__brkval;
    extern char __bss_end;
#endif
#if defined (upstream) && (defined (SDSUPPORT) && !defined (__arm__) ) || defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT)
    /** Amount of free RAM
    * \return The number of free bytes.
    */
#endif
#if defined (upstream) && (defined (SDSUPPORT) && !defined (__arm__) ) || defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && (defined (SDSUPPORT) && !defined (__arm__) ) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (indi-3DR) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (oysteinkrog) && (defined (SDSUPPORT) && !defined (__arm__) ) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && (defined (SDSUPPORT) && !defined (__arm__) ) || defined (ut7) && defined (SDSUPPORT)
int SdFatUtil::FreeRam
() {
#if defined (upstream) && (defined (SDSUPPORT) && !defined (__arm__) ) || defined (ErikZalm) && (defined (SDSUPPORT) && !defined (__arm__) ) || defined (oysteinkrog) && (defined (SDSUPPORT) && !defined (__arm__) ) || defined (yuroller) && (defined (SDSUPPORT) && !defined (__arm__) )
    char top;
#endif
#if defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (indi-3DR) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT)
    extern int  __bss_end;
#endif
#if defined (upstream) && (defined (SDSUPPORT) && !defined (__arm__) ) || defined (ErikZalm) && (defined (SDSUPPORT) && !defined (__arm__) ) || defined (oysteinkrog) && (defined (SDSUPPORT) && !defined (__arm__) ) || defined (yuroller) && (defined (SDSUPPORT) && !defined (__arm__) )
    return __brkval ? &top - __brkval : &top - &__bss_end;
#endif
#if defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (indi-3DR) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT)
    extern int* __brkval;
#endif
#if defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (indi-3DR) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT)
    int free_memory;
    if (reinterpret_cast<int>(__brkval) == 0) {
        // if no heap use from end of bss section
        free_memory = reinterpret_cast<int>(&free_memory)
                      - reinterpret_cast<int>(&__bss_end);
    } else {
        // use from top of stack to heap
        free_memory = reinterpret_cast<int>(&free_memory)
                      - reinterpret_cast<int>(__brkval);
    }
    return free_memory;
#endif
}
#endif
#if defined (upstream) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT)
    // __arm
#endif
#if defined (upstream) && defined (SDSUPPORT) || defined (bobc) && defined (SDSUPPORT) || defined (indi-RichCattell) && defined (SDSUPPORT) || defined (mattsch) && defined (SDSUPPORT) || defined (oliv3r) && defined (SDSUPPORT) || defined (quikshot) && defined (SDSUPPORT) || defined (ErikZalm) && defined (SDSUPPORT) || defined (Ognog) && defined (SDSUPPORT) || defined (alromh87) && defined (SDSUPPORT) || defined (akadamson) && defined (SDSUPPORT) || defined (timor) && defined (SDSUPPORT) || defined (hampussandberg) && defined (SDSUPPORT) || defined (drsdre) && defined (SDSUPPORT) || defined (indi-3DR) && defined (SDSUPPORT) || defined (gregor2005) && defined (SDSUPPORT) || defined (oysteinkrog) && defined (SDSUPPORT) || defined (johnnyr) && defined (SDSUPPORT) || defined (yuroller) && defined (SDSUPPORT) || defined (ut7) && defined (SDSUPPORT)
//------------------------------------------------------------------------------
/** %Print a string in flash memory.
 *
 * \param[in] pr Print object for output.
 * \param[in] str Pointer to string stored in flash memory.
 */
void SdFatUtil::print_P
( PGM_P str) {
    for(uint8_t c; (c = pgm_read_byte(str)); str++)
    }
//------------------------------------------------------------------------------
/** %Print a string in flash memory followed by a CR/LF.
 *
 * \param[in] pr Print object for output.
 * \param[in] str Pointer to string stored in flash memory.
 */
void SdFatUtil::println_P
( PGM_P str) {
    print_P( str);
    MYSERIAL.println();
}
//------------------------------------------------------------------------------
/** %Print a string in flash memory to Serial.
 *
 * \param[in] str Pointer to string stored in flash memory.
 */
void SdFatUtil::SerialPrint_P
(PGM_P str) {
    print_P(str);
}
//------------------------------------------------------------------------------
/** %Print a string in flash memory to Serial followed by a CR/LF.
 *
 * \param[in] str Pointer to string stored in flash memory.
 */
void SdFatUtil::SerialPrintln_P
(PGM_P str) {
    println_P( str);
}
#endif
