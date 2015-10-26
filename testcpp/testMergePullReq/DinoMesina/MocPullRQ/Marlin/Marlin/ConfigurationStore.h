#if defined (upstreamBeforeMerge) && !defined (CONFIG_STORE_H) || defined (forkBeforeMerge) && !defined (CONFIG_STORE_H)
    #define CONFIG_STORE_H
    #include "Configuration.h"
    void Config_ResetDefault();
#endif
#if defined (upstreamBeforeMerge) && (!defined (CONFIG_STORE_H) && !defined (DISABLE_M503) ) || defined (forkBeforeMerge) && (!defined (CONFIG_STORE_H) && !defined (DISABLE_M503) )
    void Config_PrintSettings();
#endif
#if defined (upstreamBeforeMerge) && (defined (DISABLE_M503) && !defined (CONFIG_STORE_H) ) || defined (forkBeforeMerge) && (defined (DISABLE_M503) && !defined (CONFIG_STORE_H) )
FORCE_INLINE void Config_PrintSettings
() {
}
#endif
#if defined (upstreamBeforeMerge) && (!defined (CONFIG_STORE_H) && defined (EEPROM_SETTINGS) ) || defined (forkBeforeMerge) && (!defined (CONFIG_STORE_H) && defined (EEPROM_SETTINGS) )
    void Config_StoreSettings();
    void Config_RetrieveSettings();
#endif
#if defined (upstreamBeforeMerge) && (!defined (CONFIG_STORE_H) && !defined (EEPROM_SETTINGS) ) || defined (forkBeforeMerge) && (!defined (CONFIG_STORE_H) && !defined (EEPROM_SETTINGS) )
FORCE_INLINE void Config_StoreSettings
() {
}
FORCE_INLINE void Config_RetrieveSettings
() {
    Config_ResetDefault();
    Config_PrintSettings();
}
#endif
#if defined (upstreamBeforeMerge) || defined (forkBeforeMerge)
    //CONFIG_STORE_H
#endif
