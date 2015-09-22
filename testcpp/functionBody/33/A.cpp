<<<<<<< origin/develop
<<<<<<< origin/develop
<<<<<<< origin/develop
<<<<<<< origin/develop
/* -*- c++ -*- */
=======
>>>>>>> HEAD~18
=======
/* -*- c++ -*- */
>>>>>>> HEAD~16
=======
>>>>>>> HEAD~15

static void lcd_control_motion_menu()
{
    START_MENU();
    MENU_ITEM(back, MSG_CONTROL, lcd_control_menu);
#ifdef ENABLE_AUTO_BED_LEVELING
    MENU_ITEM_EDIT(float32, MSG_ZPROBE_ZOFFSET, &zprobe_zoffset, 0.5, 50);
#endif
    MENU_ITEM_EDIT(float5, MSG_ACC, &acceleration, 500, 99000);
    MENU_ITEM_EDIT(float3, MSG_VXY_JERK, &max_xy_jerk, 1, 990);
    MENU_ITEM_EDIT(float52, MSG_VZ_JERK, &max_z_jerk, 0.1, 990);
    MENU_ITEM_EDIT(float3, MSG_VE_JERK, &max_e_jerk, 1, 990);
    MENU_ITEM_EDIT(float3, MSG_VMAX MSG_X, &max_feedrate[X_AXIS], 1, 999);
    MENU_ITEM_EDIT(float3, MSG_VMAX MSG_Y, &max_feedrate[Y_AXIS], 1, 999);
    MENU_ITEM_EDIT(float3, MSG_VMAX MSG_Z, &max_feedrate[Z_AXIS], 1, 999);
    MENU_ITEM_EDIT(float3, MSG_VMAX MSG_E, &max_feedrate[E_AXIS], 1, 999);
    MENU_ITEM_EDIT(float3, MSG_VMIN, &minimumfeedrate, 0, 999);
    MENU_ITEM_EDIT(float3, MSG_VTRAV_MIN, &mintravelfeedrate, 0, 999);
    MENU_ITEM_EDIT_CALLBACK(long5, MSG_AMAX MSG_X, &max_acceleration_units_per_sq_second[X_AXIS], 100, 99000, reset_acceleration_rates);
    MENU_ITEM_EDIT_CALLBACK(long5, MSG_AMAX MSG_Y, &max_acceleration_units_per_sq_second[Y_AXIS], 100, 99000, reset_acceleration_rates);
    MENU_ITEM_EDIT_CALLBACK(long5, MSG_AMAX MSG_Z, &max_acceleration_units_per_sq_second[Z_AXIS], 100, 99000, reset_acceleration_rates);
    MENU_ITEM_EDIT_CALLBACK(long5, MSG_AMAX MSG_E, &max_acceleration_units_per_sq_second[E_AXIS], 100, 99000, reset_acceleration_rates);
    MENU_ITEM_EDIT(float5, MSG_A_RETRACT, &retract_acceleration, 100, 99000);
    MENU_ITEM_EDIT(float52, MSG_XSTEPS, &axis_steps_per_unit[X_AXIS], 5, 9999);
    MENU_ITEM_EDIT(float52, MSG_YSTEPS, &axis_steps_per_unit[Y_AXIS], 5, 9999);
    MENU_ITEM_EDIT(float51, MSG_ZSTEPS, &axis_steps_per_unit[Z_AXIS], 5, 9999);
    MENU_ITEM_EDIT(float51, MSG_ESTEPS, &axis_steps_per_unit[E_AXIS], 5, 9999);
#ifdef ABORT_ON_ENDSTOP_HIT_FEATURE_ENABLED
    MENU_ITEM_EDIT(bool, MSG_ENDSTOP_ABORT, &abort_on_endstop_hit);
#endif
#ifdef SCARA
    MENU_ITEM_EDIT(float74, MSG_XSCALE, &axis_scaling[X_AXIS],0.5,2);
    MENU_ITEM_EDIT(float74, MSG_YSCALE, &axis_scaling[Y_AXIS],0.5,2);
#endif
    END_MENU();
}






=======
void CardReader::initsd()
{
  cardOK = false;
  if(root.isOpen())
    root.close();
  if (!card.init(SPI_FULL_SPEED,SDSS))
  {
    //if (!card.init(SPI_HALF_SPEED,SDSS))
    SERIAL_ECHO_START;
    SERIAL_ECHOLNPGM(MSG_SD_INIT_FAIL);
  }
  else if (!volume.init(&card))
  {
    SERIAL_ERROR_START;
    SERIAL_ERRORLNPGM(MSG_SD_VOL_INIT_FAIL);
  }
  else if (!root.openRoot(&volume)) 
  {
    SERIAL_ERROR_START;
    SERIAL_ERRORLNPGM(MSG_SD_OPENROOT_FAIL);
  }
  else 
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
>>>>>>> HEAD~19

}
