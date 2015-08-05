#if defined (A) && !defined (DISABLE_M503) || defined (B) && !defined (DISABLE_M503)
void Config_PrintSettings() {
#if defined (B) && !defined (DISABLE_M503)
// Always have this function, even with EEPROM_SETTINGS disabled, the current values will be shown
    SERIAL_ECHO_START;
    SERIAL_ECHOLNPGM("Steps per unit:");
#endif
#if defined (A) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (B) && !defined (DISABLE_M503)
    SERIAL_ECHO_START;
#endif
#if defined (A)
    SERIAL_ECHOPAIR("  M666 X",endstop_adj[X_AXIS] );
#endif
#if defined (B)
    SERIAL_ECHOPAIR("  M92 X",axis_steps_per_unit[0]);
#endif
#if defined (A)
    SERIAL_ECHOPAIR(" Y" ,endstop_adj[Y_AXIS] );
#endif
#if defined (B)
    SERIAL_ECHOPAIR(" Y",axis_steps_per_unit[1]);
#endif
#if defined (A)
    SERIAL_ECHOPAIR(" Z" ,endstop_adj[Z_AXIS] );
#endif
#if defined (B)
    SERIAL_ECHOPAIR(" Z",axis_steps_per_unit[2]);
#endif
#if defined (B) && !defined (DISABLE_M503)
    SERIAL_ECHOPAIR(" E",axis_steps_per_unit[3]);
#endif
#if defined (A) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (B) && !defined (DISABLE_M503)
    SERIAL_ECHOLN("");
    SERIAL_ECHO_START;
#endif
#if defined (A)
    SERIAL_ECHOLNPGM("Delta settings: L=delta_diagonal_rod, R=delta_radius, S=delta_segments_per_second");
#endif
#if defined (B)
    SERIAL_ECHOLNPGM("Scaling factors:");
#endif
#if defined (A) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (B) && (defined (SCARA) && !defined (DISABLE_M503) )
    SERIAL_ECHO_START;
#endif
#if defined (A)
    SERIAL_ECHOPAIR("  M665 L",delta_diagonal_rod );
#endif
#if defined (B)
    SERIAL_ECHOPAIR("  M365 X",axis_scaling[0]);
#endif
#if defined (A)
    SERIAL_ECHOPAIR(" R" ,delta_radius );
#endif
#if defined (B)
    SERIAL_ECHOPAIR(" Y",axis_scaling[1]);
#endif
#if defined (A)
    SERIAL_ECHOPAIR(" S" ,delta_segments_per_second );
#endif
#if defined (B)
    SERIAL_ECHOPAIR(" Z",axis_scaling[2]);
#endif
#if defined (A) && (defined (DELTA) && !defined (DISABLE_M503) ) || defined (B) && (defined (SCARA) && !defined (DISABLE_M503) )
    SERIAL_ECHOLN("");
#endif
#if defined (A) && (defined (PIDTEMP) && !defined (DISABLE_M503) ) || defined (B) && (defined (SCARA) && !defined (DISABLE_M503) )
    SERIAL_ECHO_START;
#endif
#if defined (A)
    SERIAL_ECHOLNPGM("PID settings:");
#endif
#if defined (B)
    SERIAL_ECHOLNPGM("Maximum feedrates (mm/s):");
#endif
#if defined (A) && (defined (PIDTEMP) && !defined (DISABLE_M503) ) || defined (B) && !defined (DISABLE_M503)
    SERIAL_ECHO_START;
#endif
#if defined (A)
    SERIAL_ECHOPAIR("   M301 P",Kp);
#endif
#if defined (B)
    SERIAL_ECHOPAIR("  M203 X",max_feedrate[0]);
#endif
#if defined (A)
    SERIAL_ECHOPAIR(" I" ,unscalePID_i(Ki));
#endif
#if defined (B)
    SERIAL_ECHOPAIR(" Y",max_feedrate[1] );
#endif
#if defined (A)
    SERIAL_ECHOPAIR(" D" ,unscalePID_d(Kd));
#endif
#if defined (B)
    SERIAL_ECHOPAIR(" Z", max_feedrate[2] );
#endif
#if defined (B) && !defined (DISABLE_M503)
    SERIAL_ECHOPAIR(" E", max_feedrate[3]);
#endif
#if defined (A) && (defined (PIDTEMP) && !defined (DISABLE_M503) ) || defined (B) && !defined (DISABLE_M503)
    SERIAL_ECHOLN("");
#endif
#if defined (B) && !defined (DISABLE_M503)
    SERIAL_ECHO_START;
    SERIAL_ECHOLNPGM("Maximum Acceleration (mm/s2):");
#endif
#if defined (A) && (!defined (DISABLE_M503) && defined (FWRETRACT) ) || defined (B) && !defined (DISABLE_M503)
    SERIAL_ECHO_START;
#endif
#if defined (A)
    SERIAL_ECHOLNPGM("Retract: S=Length (mm) F:Speed (mm/m) Z: ZLift (mm)");
#endif
#if defined (B)
    SERIAL_ECHOPAIR("  M201 X" ,max_acceleration_units_per_sq_second[0] );
#endif
#if defined (B) && !defined (DISABLE_M503)
    SERIAL_ECHOPAIR(" Y" , max_acceleration_units_per_sq_second[1] );
    SERIAL_ECHOPAIR(" Z" ,max_acceleration_units_per_sq_second[2] );
    SERIAL_ECHOPAIR(" E" ,max_acceleration_units_per_sq_second[3]);
    SERIAL_ECHOLN("");
#endif
#if defined (A) && (!defined (DISABLE_M503) && defined (FWRETRACT) ) || defined (B) && !defined (DISABLE_M503)
    SERIAL_ECHO_START;
#endif
#if defined (A)
    SERIAL_ECHOPAIR("   M207 S",retract_length);
#endif
#if defined (B)
    SERIAL_ECHOLNPGM("Acceleration: S=acceleration, T=retract acceleration");
#endif
#if defined (A)
    SERIAL_ECHOPAIR(" F" ,retract_feedrate*60);
#endif
#if defined (B)
    SERIAL_ECHO_START;
#endif
#if defined (A)
    SERIAL_ECHOPAIR(" Z" ,retract_zlift);
#endif
#if defined (B)
    SERIAL_ECHOPAIR("  M204 S",acceleration );
#endif
#if defined (B) && !defined (DISABLE_M503)
    SERIAL_ECHOPAIR(" T" ,retract_acceleration);
#endif
#if defined (A) && (!defined (DISABLE_M503) && defined (FWRETRACT) ) || defined (B) && !defined (DISABLE_M503)
    SERIAL_ECHOLN("");
    SERIAL_ECHO_START;
#endif
#if defined (A)
    SERIAL_ECHOLNPGM("Recover: S=Extra length (mm) F:Speed (mm/m)");
#endif
#if defined (B)
    SERIAL_ECHOLNPGM("Advanced variables: S=Min feedrate (mm/s), T=Min travel feedrate (mm/s), B=minimum segment time (ms), X=maximum XY jerk (mm/s),  Z=maximum Z jerk (mm/s),  E=maximum E jerk (mm/s)");
#endif
#if defined (A) && (!defined (DISABLE_M503) && defined (FWRETRACT) ) || defined (B) && !defined (DISABLE_M503)
    SERIAL_ECHO_START;
#endif
#if defined (A)
    SERIAL_ECHOPAIR("   M208 S",retract_recover_length);
#endif
#if defined (B)
    SERIAL_ECHOPAIR("  M205 S",minimumfeedrate );
#endif
#if defined (A)
    SERIAL_ECHOPAIR(" F", retract_recover_feedrate*60);
#endif
#if defined (B)
    SERIAL_ECHOPAIR(" T" ,mintravelfeedrate );
#endif
#if defined (B) && !defined (DISABLE_M503)
    SERIAL_ECHOPAIR(" B" ,minsegmenttime );
    SERIAL_ECHOPAIR(" X" ,max_xy_jerk );
    SERIAL_ECHOPAIR(" Z" ,max_z_jerk);
    SERIAL_ECHOPAIR(" E" ,max_e_jerk);
#endif
#if defined (A) && (!defined (DISABLE_M503) && defined (FWRETRACT) ) || defined (B) && !defined (DISABLE_M503)
    SERIAL_ECHOLN("");
    SERIAL_ECHO_START;
#endif
#if defined (A)
    SERIAL_ECHOLNPGM("Auto-Retract: S=0 to disable, 1 to interpret extrude-only moves as retracts or recoveries");
#endif
#if defined (B)
    SERIAL_ECHOLNPGM("Home offset (mm):");
#endif
#if defined (A) && (!defined (DISABLE_M503) && defined (FWRETRACT) ) || defined (B) && !defined (DISABLE_M503)
    SERIAL_ECHO_START;
#endif
#if defined (A)
    SERIAL_ECHOPAIR("   M209 S", (unsigned long)(autoretract_enabled ? 1 : 0));
#endif
#if defined (B)
    SERIAL_ECHOPAIR("  M206 X",add_homing[0] );
#endif
#if defined (B) && !defined (DISABLE_M503)
    SERIAL_ECHOPAIR(" Y" ,add_homing[1] );
    SERIAL_ECHOPAIR(" Z" ,add_homing[2] );
#endif
#if defined (A) && (!defined (DISABLE_M503) && defined (FWRETRACT) ) || defined (B) && !defined (DISABLE_M503)
    SERIAL_ECHOLN("");
#endif
#if defined (A) && (EXTRUDERS > 1 && !defined (DISABLE_M503) && defined (FWRETRACT) ) || defined (B) && (defined (DELTA) && !defined (DISABLE_M503) )
    SERIAL_ECHO_START;
#endif
#if defined (A)
    SERIAL_ECHOLNPGM("Multi-extruder settings:");
#endif
#if defined (B)
    SERIAL_ECHOLNPGM("Endstop adjustement (mm):");
#endif
#if defined (A) && (EXTRUDERS > 1 && !defined (DISABLE_M503) && defined (FWRETRACT) ) || defined (B) && (defined (DELTA) && !defined (DISABLE_M503) )
    SERIAL_ECHO_START;
#endif
#if defined (A)
    SERIAL_ECHOPAIR("   Swap retract length (mm):    ", retract_length_swap);
#endif
#if defined (B)
    SERIAL_ECHOPAIR("  M666 X",endstop_adj[0] );
#endif
#if defined (B) && (defined (DELTA) && !defined (DISABLE_M503) )
    SERIAL_ECHOPAIR(" Y" ,endstop_adj[1] );
    SERIAL_ECHOPAIR(" Z" ,endstop_adj[2] );
#endif
#if defined (A) && (EXTRUDERS > 1 && !defined (DISABLE_M503) && defined (FWRETRACT) ) || defined (B) && (defined (DELTA) && !defined (DISABLE_M503) )
    SERIAL_ECHOLN("");
#endif
#if defined (B) && (defined (DELTA) && !defined (DISABLE_M503) )
    SERIAL_ECHO_START;
    SERIAL_ECHOLNPGM("Delta settings: L=delta_diagonal_rod, R=delta_radius, S=delta_segments_per_second");
#endif
#if defined (A) && (EXTRUDERS > 1 && !defined (DISABLE_M503) && defined (FWRETRACT) ) || defined (B) && (defined (DELTA) && !defined (DISABLE_M503) )
    SERIAL_ECHO_START;
#endif
#if defined (A)
    SERIAL_ECHOPAIR("   Swap rec. addl. length (mm): ", retract_recover_length_swap);
#endif
#if defined (B)
    SERIAL_ECHOPAIR("  M665 L",delta_diagonal_rod );
#endif
#if defined (B) && (defined (DELTA) && !defined (DISABLE_M503) )
    SERIAL_ECHOPAIR(" R" ,delta_radius );
    SERIAL_ECHOPAIR(" S" ,delta_segments_per_second );
#endif
#if defined (A) && (EXTRUDERS > 1 && !defined (DISABLE_M503) && defined (FWRETRACT) ) || defined (B) && (defined (DELTA) && !defined (DISABLE_M503) )
    SERIAL_ECHOLN("");
#endif
#if defined (B) && (defined (PIDTEMP) && !defined (DISABLE_M503) )
    SERIAL_ECHO_START;
    SERIAL_ECHOLNPGM("PID settings:");
#endif
#if defined (A) && (!defined (DISABLE_M503) && defined (FWRETRACT) ) || defined (B) && (defined (PIDTEMP) && !defined (DISABLE_M503) )
    SERIAL_ECHO_START;
#endif
#if defined (A)
    if (volumetric_enabled) {
        SERIAL_ECHOLNPGM("Filament settings:");
        SERIAL_ECHO_START;
        SERIAL_ECHOPAIR("   M200 D", filament_size[0]);
        SERIAL_ECHOLN("");
#if EXTRUDERS > 1
        SERIAL_ECHO_START;
        SERIAL_ECHOPAIR("   M200 T1 D", filament_size[1]);
        SERIAL_ECHOLN("");
#if EXTRUDERS > 2
        SERIAL_ECHO_START;
        SERIAL_ECHOPAIR("   M200 T2 D", filament_size[2]);
        SERIAL_ECHOLN("");
#endif
#endif
    } else {
        SERIAL_ECHOLNPGM("Filament settings: Disabled");
    }
#endif
#if defined (B)
    SERIAL_ECHOPAIR("   M301 P",Kp);
#endif
#endif
#if defined (B) && (defined (PIDTEMP) && !defined (DISABLE_M503) )
    SERIAL_ECHOPAIR(" I" ,unscalePID_i(Ki));
    SERIAL_ECHOPAIR(" D" ,unscalePID_d(Kd));
    SERIAL_ECHOLN("");
#endif
}
#endif