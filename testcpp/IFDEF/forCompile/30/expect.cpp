 #if defined(A) || (defined(SUICIDE_PIN) && SUICIDE_PIN > -1)
        st_synchronize();
        suicide();
        #endif

      #if defined(A) || (defined(PS_ON_PIN) && PS_ON_PIN > -1)
        SET_OUTPUT(PS_ON_PIN);
        WRITE(PS_ON_PIN, PS_ON_ASLEEP);
      #endif