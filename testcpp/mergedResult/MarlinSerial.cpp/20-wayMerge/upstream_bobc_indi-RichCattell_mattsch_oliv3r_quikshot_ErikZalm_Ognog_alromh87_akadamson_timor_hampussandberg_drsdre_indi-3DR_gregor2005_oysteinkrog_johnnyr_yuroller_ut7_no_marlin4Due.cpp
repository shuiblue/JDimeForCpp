#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (Ognog) || defined (alromh87) || defined (akadamson) || defined (timor) || defined (hampussandberg) || defined (drsdre) || defined (indi-3DR) || defined (gregor2005) || defined (oysteinkrog) || defined (johnnyr) || defined (yuroller) || defined (ut7)
/*
  HardwareSerial.cpp - Hardware serial library for Wiring
  Copyright (c) 2006 Nicholas Zambetti.  All right reserved.

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

  Modified 23 November 2006 by David A. Mellis
  Modified 28 September 2010 by Mark Sproul
*/
#include "Marlin.h"
#include "MarlinSerial.h"
#endif
#if defined (akadamson) && MOTHERBOARD != 8 || defined (timor) && MOTHERBOARD != 8
    // !teensylu
#endif
#if defined (upstream) && !defined (AT90USB) || defined (bobc) && !defined (AT90USB) || defined (indi-RichCattell) && !defined (AT90USB) || defined (mattsch) && !defined (AT90USB) || defined (oliv3r) && !defined (AT90USB) || defined (quikshot) && !defined (AT90USB) || defined (ErikZalm) && !defined (AT90USB) || defined (Ognog) && !defined (AT90USB) || defined (alromh87) && !defined (AT90USB) || defined (akadamson) && MOTHERBOARD != 8 || defined (timor) && MOTHERBOARD != 8 || defined (hampussandberg) && !defined (AT90USB) || defined (drsdre) && !defined (AT90USB) || defined (indi-3DR) && !defined (AT90USB) || defined (gregor2005) && !defined (AT90USB) || defined (oysteinkrog) && !defined (AT90USB) || defined (johnnyr) && !defined (AT90USB) || defined (yuroller) && !defined (AT90USB) || defined (ut7) && !defined (AT90USB)
    // this next line disables the entire HardwareSerial.cpp,
#endif
#if defined (indi-RichCattell) && !defined (AT90USB) || defined (oliv3r) && !defined (AT90USB) || defined (akadamson) && MOTHERBOARD != 8 || defined (timor) && MOTHERBOARD != 8 || defined (drsdre) && !defined (AT90USB) || defined (indi-3DR) && !defined (AT90USB) || defined (gregor2005) && !defined (AT90USB)
    // this is so I can support Attiny series and any other chip without a uart
#endif
#if defined (upstream) && !defined (AT90USB) || defined (bobc) && !defined (AT90USB)
    // this is so I can support Attiny series and any other chip without a UART
#endif
#if defined (upstream) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) && UART_PRESENT(SERIAL_PORT) ) || defined (bobc) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) && UART_PRESENT(SERIAL_PORT) ) || defined (indi-RichCattell) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) && UART_PRESENT(SERIAL_PORT) ) || defined (mattsch) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) && UART_PRESENT(SERIAL_PORT) ) || defined (oliv3r) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) && UART_PRESENT(SERIAL_PORT) ) || defined (quikshot) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) && UART_PRESENT(SERIAL_PORT) ) || defined (ErikZalm) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) && UART_PRESENT(SERIAL_PORT) ) || defined (Ognog) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) && UART_PRESENT(SERIAL_PORT) ) || defined (alromh87) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) && UART_PRESENT(SERIAL_PORT) ) || defined (akadamson) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )UART_PRESENT(SERIAL_PORT) && MOTHERBOARD != 8 ) || defined (timor) && ((defined(UBRRH) || defined(UBRR0H) && )(defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )MOTHERBOARD != 8 ) || defined (hampussandberg) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) && UART_PRESENT(SERIAL_PORT) ) || defined (drsdre) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) && UART_PRESENT(SERIAL_PORT) ) || defined (indi-3DR) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) && UART_PRESENT(SERIAL_PORT) ) || defined (gregor2005) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) && UART_PRESENT(SERIAL_PORT) ) || defined (oysteinkrog) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) && UART_PRESENT(SERIAL_PORT) ) || defined (johnnyr) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) && UART_PRESENT(SERIAL_PORT) ) || defined (yuroller) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) && UART_PRESENT(SERIAL_PORT) ) || defined (ut7) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) && UART_PRESENT(SERIAL_PORT) )
ring_buffer rx_buffer  =  { { 0 }, 0, 0 };
#endif
#if defined (upstream) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (bobc) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (indi-RichCattell) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (mattsch) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (oliv3r) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (quikshot) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (ErikZalm) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (Ognog) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (alromh87) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (akadamson) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )MOTHERBOARD != 8 ) || defined (timor) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )MOTHERBOARD != 8 ) || defined (hampussandberg) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (drsdre) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (indi-3DR) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (gregor2005) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (oysteinkrog) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (johnnyr) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (yuroller) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (ut7) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) )
FORCE_INLINE void store_char
(unsigned char c) {
    int i = (unsigned int)(rx_buffer.head + 1) % RX_BUFFER_SIZE;
// if we should be storing the received character into the location
// just before the tail (meaning that the head would advance to the
// current location of the tail), we're about to overflow the buffer
// and so we don't write the character or advance the head.
    if
    (i != rx_buffer.tail) {
        rx_buffer.buffer[rx_buffer.head] = c;
        rx_buffer.head = i;
    }
}
//#elif defined(SIG_USART_RECV)
#endif
#if defined (upstream) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (bobc) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (indi-RichCattell) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (mattsch) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (oliv3r) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (quikshot) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (ErikZalm) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (Ognog) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (alromh87) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (akadamson) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )MOTHERBOARD != 8 ) || defined (timor) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )defined(USART0_RX_vect) && MOTHERBOARD != 8 ) || defined (hampussandberg) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (drsdre) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (indi-3DR) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (gregor2005) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (oysteinkrog) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (johnnyr) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (yuroller) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (ut7) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) )
    // fixed by Mark Sproul this is on the 644/644p
    //SIGNAL(SIG_USART_RECV)
#endif
#if defined (timor) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )defined(USART0_RX_vect) && MOTHERBOARD != 8 )
    SIGNAL(USART0_RX_vect)
#endif
#if defined (upstream) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (bobc) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (indi-RichCattell) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (mattsch) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (oliv3r) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (quikshot) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (ErikZalm) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (Ognog) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (alromh87) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (akadamson) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )MOTHERBOARD != 8 ) || defined (hampussandberg) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (drsdre) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (indi-3DR) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (gregor2005) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (oysteinkrog) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (johnnyr) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (yuroller) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (ut7) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) )

    SIGNAL(M_USARTx_RX_vect)
#endif
#if defined (upstream) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (bobc) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (indi-RichCattell) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (mattsch) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (oliv3r) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (quikshot) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (ErikZalm) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (Ognog) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (alromh87) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (akadamson) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )MOTHERBOARD != 8 ) || defined (timor) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )defined(USART0_RX_vect) && MOTHERBOARD != 8 ) || defined (hampussandberg) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (drsdre) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (indi-3DR) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (gregor2005) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (oysteinkrog) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (johnnyr) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (yuroller) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (ut7) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) )
    #if defined (timor) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )defined(USART0_RX_vect) && MOTHERBOARD != 8 && defined(UDR0) )
        unsigned char c  =  UDR0;
    #endif
    #if defined (upstream) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (bobc) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (indi-RichCattell) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (mattsch) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (oliv3r) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (quikshot) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (ErikZalm) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (Ognog) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (alromh87) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (akadamson) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )MOTHERBOARD != 8 ) || defined (hampussandberg) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (drsdre) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (indi-3DR) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (gregor2005) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (oysteinkrog) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (johnnyr) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (yuroller) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (ut7) && (defined(M_USARTx_RX_vect) && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) )

        unsigned char c  =  M_UDRx;
    #endif
    #if defined (timor) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )defined(USART0_RX_vect) && MOTHERBOARD != 8 && defined(UDR) )
        unsigned char c  =  UDR;
        //  atmega8, atmega32
    #endif
    #if defined (timor) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )defined(USART0_RX_vect) && !defined(UDR) && MOTHERBOARD != 8 )
        #error UDR not defined
    #endif
    store_char(c);
#endif
#if defined (upstream) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (bobc) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (indi-RichCattell) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (mattsch) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (oliv3r) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (quikshot) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (ErikZalm) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (Ognog) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (alromh87) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (akadamson) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )MOTHERBOARD != 8 ) || defined (timor) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )MOTHERBOARD != 8 ) || defined (hampussandberg) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (drsdre) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (indi-3DR) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (gregor2005) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (oysteinkrog) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (johnnyr) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (yuroller) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (ut7) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) )
// Constructors ////////////////////////////////////////////////////////////////
MarlinSerial::MarlinSerial
() {
}
// Public Methods //////////////////////////////////////////////////////////////
void MarlinSerial::begin
(long baud) {
    uint16_t baud_setting;
#if defined (timor) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )MOTHERBOARD != 8 )
    bool useU2X0 = true;
#endif
#if defined (upstream) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (bobc) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (indi-RichCattell) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (mattsch) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (oliv3r) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (quikshot) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (ErikZalm) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (Ognog) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (alromh87) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (akadamson) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )MOTHERBOARD != 8 ) || defined (hampussandberg) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (drsdre) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (indi-3DR) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (gregor2005) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (oysteinkrog) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (johnnyr) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (yuroller) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (ut7) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) )
    bool useU2X = true;
#endif
#if defined (bobc) && ((F_CPU == 16000000UL && SERIAL_PORT == 0 && )(defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (indi-RichCattell) && ((F_CPU == 16000000UL && SERIAL_PORT == 0 && )(defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (oliv3r) && ((F_CPU == 16000000UL && SERIAL_PORT == 0 && )(defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (quikshot) && ((F_CPU == 16000000UL && SERIAL_PORT == 0 && )(defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (Ognog) && ((F_CPU == 16000000UL && SERIAL_PORT == 0 && )(defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (alromh87) && ((F_CPU == 16000000UL && SERIAL_PORT == 0 && )(defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (akadamson) && ((F_CPU == 16000000UL && SERIAL_PORT == 0 && )(defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )MOTHERBOARD != 8 ) || defined (timor) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )F_CPU == 16000000UL && MOTHERBOARD != 8 ) || defined (hampussandberg) && ((F_CPU == 16000000UL && SERIAL_PORT == 0 && )(defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (drsdre) && ((F_CPU == 16000000UL && SERIAL_PORT == 0 && )(defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (indi-3DR) && ((F_CPU == 16000000UL && SERIAL_PORT == 0 && )(defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (gregor2005) && ((F_CPU == 16000000UL && SERIAL_PORT == 0 && )(defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (johnnyr) && ((F_CPU == 16000000UL && SERIAL_PORT == 0 && )(defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) )
// hard coded exception for compatibility with the bootloader shipped
#endif
#if defined (upstream) && ((F_CPU == 16000000UL && SERIAL_PORT == 0 && )(defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (mattsch) && ((F_CPU == 16000000UL && SERIAL_PORT == 0 && )(defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (ErikZalm) && ((F_CPU == 16000000UL && SERIAL_PORT == 0 && )(defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (oysteinkrog) && ((F_CPU == 16000000UL && SERIAL_PORT == 0 && )(defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (yuroller) && ((F_CPU == 16000000UL && SERIAL_PORT == 0 && )(defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (ut7) && ((F_CPU == 16000000UL && SERIAL_PORT == 0 && )(defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) )
// hard-coded exception for compatibility with the bootloader shipped
#endif
#if defined (upstream) && ((F_CPU == 16000000UL && SERIAL_PORT == 0 && )(defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (bobc) && ((F_CPU == 16000000UL && SERIAL_PORT == 0 && )(defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (indi-RichCattell) && ((F_CPU == 16000000UL && SERIAL_PORT == 0 && )(defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (mattsch) && ((F_CPU == 16000000UL && SERIAL_PORT == 0 && )(defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (oliv3r) && ((F_CPU == 16000000UL && SERIAL_PORT == 0 && )(defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (quikshot) && ((F_CPU == 16000000UL && SERIAL_PORT == 0 && )(defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (ErikZalm) && ((F_CPU == 16000000UL && SERIAL_PORT == 0 && )(defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (Ognog) && ((F_CPU == 16000000UL && SERIAL_PORT == 0 && )(defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (alromh87) && ((F_CPU == 16000000UL && SERIAL_PORT == 0 && )(defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (akadamson) && ((F_CPU == 16000000UL && SERIAL_PORT == 0 && )(defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )MOTHERBOARD != 8 ) || defined (timor) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )F_CPU == 16000000UL && MOTHERBOARD != 8 ) || defined (hampussandberg) && ((F_CPU == 16000000UL && SERIAL_PORT == 0 && )(defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (drsdre) && ((F_CPU == 16000000UL && SERIAL_PORT == 0 && )(defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (indi-3DR) && ((F_CPU == 16000000UL && SERIAL_PORT == 0 && )(defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (gregor2005) && ((F_CPU == 16000000UL && SERIAL_PORT == 0 && )(defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (oysteinkrog) && ((F_CPU == 16000000UL && SERIAL_PORT == 0 && )(defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (johnnyr) && ((F_CPU == 16000000UL && SERIAL_PORT == 0 && )(defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (yuroller) && ((F_CPU == 16000000UL && SERIAL_PORT == 0 && )(defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (ut7) && ((F_CPU == 16000000UL && SERIAL_PORT == 0 && )(defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) )
// with the Duemilanove and previous boards and the firmware on the 8U2
// on the Uno and Mega 2560.
    if
    (baud == 57600) {
#if defined (timor) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )F_CPU == 16000000UL && MOTHERBOARD != 8 )
        useU2X0 = false;
#endif
#if defined (upstream) && ((F_CPU == 16000000UL && SERIAL_PORT == 0 && )(defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (bobc) && ((F_CPU == 16000000UL && SERIAL_PORT == 0 && )(defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (indi-RichCattell) && ((F_CPU == 16000000UL && SERIAL_PORT == 0 && )(defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (mattsch) && ((F_CPU == 16000000UL && SERIAL_PORT == 0 && )(defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (oliv3r) && ((F_CPU == 16000000UL && SERIAL_PORT == 0 && )(defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (quikshot) && ((F_CPU == 16000000UL && SERIAL_PORT == 0 && )(defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (ErikZalm) && ((F_CPU == 16000000UL && SERIAL_PORT == 0 && )(defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (Ognog) && ((F_CPU == 16000000UL && SERIAL_PORT == 0 && )(defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (alromh87) && ((F_CPU == 16000000UL && SERIAL_PORT == 0 && )(defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (akadamson) && ((F_CPU == 16000000UL && SERIAL_PORT == 0 && )(defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )MOTHERBOARD != 8 ) || defined (hampussandberg) && ((F_CPU == 16000000UL && SERIAL_PORT == 0 && )(defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (drsdre) && ((F_CPU == 16000000UL && SERIAL_PORT == 0 && )(defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (indi-3DR) && ((F_CPU == 16000000UL && SERIAL_PORT == 0 && )(defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (gregor2005) && ((F_CPU == 16000000UL && SERIAL_PORT == 0 && )(defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (oysteinkrog) && ((F_CPU == 16000000UL && SERIAL_PORT == 0 && )(defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (johnnyr) && ((F_CPU == 16000000UL && SERIAL_PORT == 0 && )(defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (yuroller) && ((F_CPU == 16000000UL && SERIAL_PORT == 0 && )(defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (ut7) && ((F_CPU == 16000000UL && SERIAL_PORT == 0 && )(defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) )
        useU2X = false;
#endif
    }
#endif
#if defined (timor) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )MOTHERBOARD != 8 )
    if (useU2X0) {
        UCSR0A = 1 << U2X0;
        baud_setting = (F_CPU / 4 / baud - 1) / 2;
    } else {
        UCSR0A = 0;
        baud_setting = (F_CPU / 8 / baud - 1) / 2;
    }
#endif
#if defined (upstream) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (bobc) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (indi-RichCattell) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (mattsch) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (oliv3r) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (quikshot) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (ErikZalm) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (Ognog) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (alromh87) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (akadamson) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )MOTHERBOARD != 8 ) || defined (hampussandberg) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (drsdre) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (indi-3DR) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (gregor2005) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (oysteinkrog) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (johnnyr) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (yuroller) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (ut7) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) )
    if (useU2X) {
        M_UCSRxA = 1 << M_U2Xx;
        baud_setting = (F_CPU / 4 / baud - 1) / 2;
    } else {
        M_UCSRxA = 0;
        baud_setting = (F_CPU / 8 / baud - 1) / 2;
    }
#endif
// assign the baud_setting, a.k.a. ubbr (USART Baud Rate Register)
#if defined (timor) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )MOTHERBOARD != 8 )
    UBRR0H = baud_setting >> 8;
#endif
#if defined (upstream) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (bobc) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (indi-RichCattell) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (mattsch) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (oliv3r) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (quikshot) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (ErikZalm) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (Ognog) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (alromh87) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (akadamson) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )MOTHERBOARD != 8 ) || defined (hampussandberg) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (drsdre) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (indi-3DR) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (gregor2005) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (oysteinkrog) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (johnnyr) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (yuroller) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (ut7) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) )
    M_UBRRxH = baud_setting >> 8;
#endif
#if defined (timor) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )MOTHERBOARD != 8 )
    UBRR0L = baud_setting;
#endif
#if defined (upstream) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (bobc) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (indi-RichCattell) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (mattsch) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (oliv3r) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (quikshot) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (ErikZalm) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (Ognog) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (alromh87) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (akadamson) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )MOTHERBOARD != 8 ) || defined (hampussandberg) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (drsdre) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (indi-3DR) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (gregor2005) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (oysteinkrog) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (johnnyr) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (yuroller) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (ut7) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) )
    M_UBRRxL = baud_setting;
#endif
#if defined (timor) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )MOTHERBOARD != 8 )
    sbi(UCSR0B, RXEN0);
#endif
#if defined (upstream) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (bobc) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (indi-RichCattell) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (mattsch) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (oliv3r) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (quikshot) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (ErikZalm) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (Ognog) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (alromh87) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (akadamson) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )MOTHERBOARD != 8 ) || defined (hampussandberg) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (drsdre) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (indi-3DR) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (gregor2005) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (oysteinkrog) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (johnnyr) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (yuroller) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (ut7) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) )
    sbi(M_UCSRxB, M_RXENx);
#endif
#if defined (timor) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )MOTHERBOARD != 8 )
    sbi(UCSR0B, TXEN0);
#endif
#if defined (upstream) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (bobc) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (indi-RichCattell) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (mattsch) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (oliv3r) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (quikshot) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (ErikZalm) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (Ognog) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (alromh87) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (akadamson) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )MOTHERBOARD != 8 ) || defined (hampussandberg) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (drsdre) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (indi-3DR) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (gregor2005) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (oysteinkrog) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (johnnyr) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (yuroller) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (ut7) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) )
    sbi(M_UCSRxB, M_TXENx);
#endif
#if defined (timor) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )MOTHERBOARD != 8 )
    sbi(UCSR0B, RXCIE0);
#endif
#if defined (upstream) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (bobc) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (indi-RichCattell) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (mattsch) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (oliv3r) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (quikshot) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (ErikZalm) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (Ognog) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (alromh87) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (akadamson) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )MOTHERBOARD != 8 ) || defined (hampussandberg) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (drsdre) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (indi-3DR) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (gregor2005) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (oysteinkrog) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (johnnyr) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (yuroller) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (ut7) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) )
    sbi(M_UCSRxB, M_RXCIEx);
#endif
}
void MarlinSerial::end
() {
#if defined (timor) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )MOTHERBOARD != 8 )
    cbi(UCSR0B, RXEN0);
#endif
#if defined (upstream) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (bobc) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (indi-RichCattell) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (mattsch) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (oliv3r) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (quikshot) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (ErikZalm) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (Ognog) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (alromh87) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (akadamson) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )MOTHERBOARD != 8 ) || defined (hampussandberg) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (drsdre) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (indi-3DR) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (gregor2005) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (oysteinkrog) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (johnnyr) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (yuroller) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (ut7) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) )
    cbi(M_UCSRxB, M_RXENx);
#endif
#if defined (timor) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )MOTHERBOARD != 8 )
    cbi(UCSR0B, TXEN0);
#endif
#if defined (upstream) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (bobc) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (indi-RichCattell) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (mattsch) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (oliv3r) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (quikshot) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (ErikZalm) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (Ognog) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (alromh87) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (akadamson) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )MOTHERBOARD != 8 ) || defined (hampussandberg) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (drsdre) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (indi-3DR) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (gregor2005) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (oysteinkrog) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (johnnyr) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (yuroller) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (ut7) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) )
    cbi(M_UCSRxB, M_TXENx);
#endif
#if defined (timor) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )MOTHERBOARD != 8 )
    cbi(UCSR0B, RXCIE0);
#endif
#if defined (upstream) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (bobc) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (indi-RichCattell) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (mattsch) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (oliv3r) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (quikshot) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (ErikZalm) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (Ognog) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (alromh87) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (akadamson) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )MOTHERBOARD != 8 ) || defined (hampussandberg) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (drsdre) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (indi-3DR) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (gregor2005) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (oysteinkrog) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (johnnyr) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (yuroller) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) ) || defined (ut7) && ((defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H) && )!defined (AT90USB) )
    cbi(M_UCSRxB, M_RXCIEx);
#endif
}
int MarlinSerial::peek
(void) {
    if
    (rx_buffer.head == rx_buffer.tail) {
        return -1;
    } else {
        return rx_buffer.buffer[rx_buffer.tail];
    }
}
int MarlinSerial::read
(void) {
// if the head isn't ahead of the tail, we don't have any characters
    if
    (rx_buffer.head == rx_buffer.tail) {
        return -1;
    } else {
        unsigned char c = rx_buffer.buffer[rx_buffer.tail];
        rx_buffer.tail = (unsigned int)(rx_buffer.tail + 1) % RX_BUFFER_SIZE;
        return c;
    }
}
void MarlinSerial::flush
() {
// don't reverse this or there may be problems if the RX interrupt
// occurs after reading the value of rx_buffer_head but before writing
// the value to rx_buffer_tail; the previous value of rx_buffer_head
// may be written to rx_buffer_tail, making it appear as if the buffer
// don't reverse this or there may be problems if the RX interrupt
// occurs after reading the value of rx_buffer_head but before writing
// the value to rx_buffer_tail; the previous value of rx_buffer_head
// may be written to rx_buffer_tail, making it appear as if the buffer
// were full, not empty.
    rx_buffer.head = rx_buffer.tail;
}
/// imports from print.h
void MarlinSerial::print
(char c, int base) {
    print((long) c, base);
}
void MarlinSerial::print
(unsigned char b, int base) {
    print((unsigned long) b, base);
}
void MarlinSerial::print
(int n, int base) {
    print((long) n, base);
}
void MarlinSerial::print
(unsigned int n, int base) {
    print((unsigned long) n, base);
}
void MarlinSerial::print
(long n, int base) {
    if
    (base == 0) {
        write(n);
    } else if
    (base == 10) {
        if
        (n < 0) {
            print('-');
            n = -n;
        }
        printNumber(n, 10);
    } else {
        printNumber(n, base);
    }
}
void MarlinSerial::print
(unsigned long n, int base) {
    if
    (base == 0)
        write(n);
    else
        printNumber(n, base);
}
void MarlinSerial::print
(double n, int digits) {
    printFloat(n, digits);
}
void MarlinSerial::println
(void) {
    print('\r');
    print('\n');
}
void MarlinSerial::println
(const String &s) {
    print(s);
    println();
}
void MarlinSerial::println
(const char c[]) {
    print(c);
    println();
}
void MarlinSerial::println
(char c, int base) {
    print(c, base);
    println();
}
void MarlinSerial::println
(unsigned char b, int base) {
    print(b, base);
    println();
}
void MarlinSerial::println
(int n, int base) {
    print(n, base);
    println();
}
void MarlinSerial::println
(unsigned int n, int base) {
    print(n, base);
    println();
}
void MarlinSerial::println
(long n, int base) {
    print(n, base);
    println();
}
void MarlinSerial::println
(unsigned long n, int base) {
    print(n, base);
    println();
}
void MarlinSerial::println
(double n, int digits) {
    print(n, digits);
    println();
}
// Private Methods /////////////////////////////////////////////////////////////
void MarlinSerial::printNumber
(unsigned long n, uint8_t base) {
    unsigned char buf[8 * sizeof(long)];
// Assumes 8-bit chars.
    unsigned long i = 0;
    if
    (n == 0) {
        print('0');
        return;
    }
    while
    (n > 0) {
        buf[i++] = n % base;
        n /= base;
    }
    for(; i > 0; i--)
    }
void MarlinSerial::printFloat
(double number, uint8_t digits) {
// Handle negative numbers
    if
    (number < 0.0) {
        print('-');
        number = -number;
    }
// Round correctly so that print(1.999, 2) prints as "2.00"
    double rounding = 0.5;
    for(uint8_t i=0; i<digits; ++i)
        number += rounding;
// Extract the integer part of the number and print it
    unsigned long int_part = (unsigned long)number;
    double remainder = number - (double)int_part;
    print(int_part);
// Print the decimal point, but only if there are digits beyond
    if
    (digits > 0)
        print(".");
// Extract digits from the remainder one at a time
    while
    (digits-- > 0) {
        remainder *= 10.0;
        int toPrint = int(remainder);
        print(toPrint);
        remainder -= toPrint;
    }
}
// Preinstantiate Objects //////////////////////////////////////////////////////
MarlinSerial MSerial;
#endif
#if defined (upstream) && !defined (AT90USB) || defined (bobc) && !defined (AT90USB) || defined (indi-RichCattell) && !defined (AT90USB) || defined (mattsch) && !defined (AT90USB) || defined (oliv3r) && !defined (AT90USB) || defined (quikshot) && !defined (AT90USB) || defined (ErikZalm) && !defined (AT90USB) || defined (Ognog) && !defined (AT90USB) || defined (alromh87) && !defined (AT90USB) || defined (akadamson) && MOTHERBOARD != 8 || defined (timor) && MOTHERBOARD != 8 || defined (hampussandberg) && !defined (AT90USB) || defined (drsdre) && !defined (AT90USB) || defined (indi-3DR) && !defined (AT90USB) || defined (gregor2005) && !defined (AT90USB) || defined (oysteinkrog) && !defined (AT90USB) || defined (johnnyr) && !defined (AT90USB) || defined (yuroller) && !defined (AT90USB) || defined (ut7) && !defined (AT90USB)
    // whole file
#endif
#if defined (akadamson) || defined (timor)
    //teensylu
#endif
#if defined (upstream) || defined (bobc) || defined (indi-RichCattell) || defined (mattsch) || defined (oliv3r) || defined (quikshot) || defined (ErikZalm) || defined (Ognog) || defined (alromh87)
    // !AT90USB
#endif
#if defined (upstream) || defined (bobc)
    // For AT90USB targets use the UART for BT interfacing
#endif
#if defined (upstream) && (defined(AT90USB) && defined (BTENABLED)) || defined (bobc) && (defined(AT90USB) && defined (BTENABLED))
    HardwareSerial bt;
#endif
