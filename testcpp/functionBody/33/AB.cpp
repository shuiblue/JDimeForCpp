#if defined (C) || defined (B) || defined (A)
void CardReader::initsd
() {
#if defined (C)
    {
        cardOK = false;
        if(root.isOpen())
            root.close();
#ifdef SDSLOW
        if (!card.init(SPI_HALF_SPEED,SDSS)
#if defined(LCD_SDSS) && (LCD_SDSS != SDSS)
        && !card.init(SPI_HALF_SPEED,LCD_SDSS)
#endif
           )
#else
        if (!card.init(SPI_FULL_SPEED,SDSS)
#if defined(LCD_SDSS) && (LCD_SDSS != SDSS)
        && !card.init(SPI_FULL_SPEED,LCD_SDSS)
#endif
           )
#endif
        {
            //if (!card.init(SPI_HALF_SPEED,SDSS))
            SERIAL_ECHO_START;
            SERIAL_ECHOLNPGM(MSG_SD_INIT_FAIL);
        } else if (!volume.init(&card)) {
            SERIAL_ERROR_START;
            SERIAL_ERRORLNPGM(MSG_SD_VOL_INIT_FAIL);
        } else if (!root.openRoot(&volume)) {
            SERIAL_ERROR_START;
            SERIAL_ERRORLNPGM(MSG_SD_OPENROOT_FAIL);
        } else
        {
            cardOK = true;
            SERIAL_ECHO_START;
            SERIAL_ECHOLNPGM(MSG_SD_CARD_OK);
        }
        workDir=root;
        curDir=&root;
        /*
        if(!workDir.openRoot(&volume))
        {
          SERIAL_ECHOLNPGM(MSG_SD_WORKDIR_FAIL);
        }
        */

    }
#endif
#if defined (B) || defined (A)
    {
        cardOK = false;
        if(root.isOpen())
            root.close();
        if (!card.init(SPI_FULL_SPEED,SDSS)) {
            //if (!card.init(SPI_HALF_SPEED,SDSS))
            SERIAL_ECHO_START;
            SERIAL_ECHOLNPGM(MSG_SD_INIT_FAIL);
        } else if (!volume.init(&card)) {
            SERIAL_ERROR_START;
            SERIAL_ERRORLNPGM(MSG_SD_VOL_INIT_FAIL);
        } else if (!root.openRoot(&volume)) {
            SERIAL_ERROR_START;
            SERIAL_ERRORLNPGM(MSG_SD_OPENROOT_FAIL);
        } else
        {
            cardOK = true;
            SERIAL_ECHO_START;
            SERIAL_ECHOLNPGM(MSG_SD_CARD_OK);
        }
        workDir=root;
        curDir=&root;
        /*
        if(!workDir.openRoot(&volume))
        {
          SERIAL_ECHOLNPGM(MSG_SD_WORKDIR_FAIL);
        }
        */

    }
#endif
}
#endif
