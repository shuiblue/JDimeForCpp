
extern CardReader card;
#define IS_SD_PRINTING (card.sdprinting)

#if (SDCARDDETECT > -1)
# ifdef SDCARDDETECTINVERTED 
#  define IS_SD_INSERTED (READ(SDCARDDETECT)!=0)
# else
#  define IS_SD_INSERTED (READ(SDCARDDETECT)==0)
# endif //SDCARDTETECTINVERTED
#else
//If we don't have a card detect line, aways asume the card is inserted
# define IS_SD_INSERTED true
#endif

#else

#define IS_SD_PRINTING (false)

#endif //SDSUPPORT
#endif
