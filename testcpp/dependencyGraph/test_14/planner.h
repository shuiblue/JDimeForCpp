 ISR(TIMER0_COMPA_vect)
  {
    old_OCR0A += 52; // ~10kHz interrupt (250000 / 26 = 9615kHz)
    OCR0A = old_OCR0A;
    // Set E direction (Depends on E direction + advance)
    for(unsigned char i=0; i<4;i++) {
      if (e_steps[0] != 0) {
        WRITE(E0_STEP_PIN, INVERT_E_STEP_PIN);
        if (e_steps[0] < 0) {
          WRITE(E0_DIR_PIN, INVERT_E0_DIR);
          e_steps[0]++;
          WRITE(E0_STEP_PIN, !INVERT_E_STEP_PIN);
        }
        else if (e_steps[0] > 0) {
          WRITE(E0_DIR_PIN, !INVERT_E0_DIR);
          e_steps[0]--;
          WRITE(E0_STEP_PIN, !INVERT_E_STEP_PIN);
        }
      }
 #if EXTRUDERS > 1
      if (e_steps[1] != 0) {
        WRITE(E1_STEP_PIN, INVERT_E_STEP_PIN);
        if (e_steps[1] < 0) {
          WRITE(E1_DIR_PIN, INVERT_E1_DIR);
          e_steps[1]++;
          WRITE(E1_STEP_PIN, !INVERT_E_STEP_PIN);
        }
        else if (e_steps[1] > 0) {
          WRITE(E1_DIR_PIN, !INVERT_E1_DIR);
          e_steps[1]--;
          WRITE(E1_STEP_PIN, !INVERT_E_STEP_PIN);
        }
      }
 #endif
 #if EXTRUDERS > 2
      if (e_steps[2] != 0) {
        WRITE(E2_STEP_PIN, INVERT_E_STEP_PIN);
        if (e_steps[2] < 0) {
          WRITE(E2_DIR_PIN, INVERT_E2_DIR);
          e_steps[2]++;
          WRITE(E2_STEP_PIN, !INVERT_E_STEP_PIN);
        }
        else if (e_steps[2] > 0) {
          WRITE(E2_DIR_PIN, !INVERT_E2_DIR);
          e_steps[2]--;
          WRITE(E2_STEP_PIN, !INVERT_E_STEP_PIN);
        }
      }
 #endif
    }
  }