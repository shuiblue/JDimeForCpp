#if defined (upstream) || defined (jcrocholl) || defined (jcrochollUpstream)
//===========================================================================
//=============================private variables=============================
//===========================================================================
static float destination[NUM_AXIS] = {  0.0, 0.0, 0.0, 0.0};
#endif
#if defined (upstream) && defined (DELTA) || defined (jcrocholl)

static float delta[3] = {0.0, 0.0, 0.0};
#endif
#if defined (upstream) || defined (jcrocholl) || defined (jcrochollUpstream)
void process_commands
() {
    if
    (code_seen('G')) {
        switch
        ((int)code_value()) {
        case
                28
                ://G28 Home all Axis one at a time
            enable_endstops(true);
#if defined (upstream) && defined (QUICK_HOME) || defined (jcrocholl) && defined (QUICK_HOME)
            if (home_all_axis) { // Move all carriages up together until the first endstop is hit.
                current_position[X_AXIS] = 0;
                current_position[Y_AXIS] = 0;
                current_position[Z_AXIS] = 0;
                plan_set_position(current_position[X_AXIS], current_position[Y_AXIS], current_position[Z_AXIS], current_position[E_AXIS]);
                destination[X_AXIS] = 1.5 * X_MAX_LENGTH * X_HOME_DIR;
                destination[Y_AXIS] = 1.5 * Y_MAX_LENGTH * Y_HOME_DIR;
                destination[Z_AXIS] = 1.5 * Z_MAX_LENGTH * Z_HOME_DIR;
                feedrate = 1.732 * homing_feedrate[X_AXIS];
                plan_buffer_line(destination[X_AXIS], destination[Y_AXIS], destination[Z_AXIS], destination[E_AXIS], feedrate/60, active_extruder);
                st_synchronize();
                endstops_hit_on_purpose();
                current_position[X_AXIS] = destination[X_AXIS];
                current_position[Y_AXIS] = destination[Y_AXIS];
                current_position[Z_AXIS] = destination[Z_AXIS];
            }
#endif
#if defined (jcrochollUpstream) && Z_HOME_DIR > 0
// If homing away from BED do Z first
#endif
#if defined (upstream) || defined (jcrocholl) || defined (jcrochollUpstream) && Z_HOME_DIR > 0
            if
            ((home_all_axis) || (code_seen(axis_codes[Z_AXIS]))) {
                HOMEAXIS(Z);
            }
#endif
#if defined (upstream) || defined (jcrocholl)
            calculate_delta(current_position);
#endif
#if defined (jcrochollUpstream) && defined (QUICK_HOME)
            if((home_all_axis)||( code_seen(axis_codes[X_AXIS]) && code_seen(axis_codes[Y_AXIS])) ) { //first diagonal move
                current_position[X_AXIS] = 0;
                current_position[Y_AXIS] = 0;
                plan_set_position(current_position[X_AXIS], current_position[Y_AXIS], current_position[Z_AXIS], current_position[E_AXIS]);
                destination[X_AXIS] = 1.5 * X_MAX_LENGTH * X_HOME_DIR;
                destination[Y_AXIS] = 1.5 * Y_MAX_LENGTH * Y_HOME_DIR;
                feedrate = homing_feedrate[X_AXIS];
                if(homing_feedrate[Y_AXIS]<feedrate)
                    feedrate =homing_feedrate[Y_AXIS];
                plan_buffer_line(destination[X_AXIS], destination[Y_AXIS], destination[Z_AXIS], destination[E_AXIS], feedrate/60, active_extruder);
                st_synchronize();
                axis_is_at_home(X_AXIS);
                axis_is_at_home(Y_AXIS);
                plan_set_position(current_position[X_AXIS], current_position[Y_AXIS], current_position[Z_AXIS], current_position[E_AXIS]);
                destination[X_AXIS] = current_position[X_AXIS];
                destination[Y_AXIS] = current_position[Y_AXIS];
                plan_buffer_line(destination[X_AXIS], destination[Y_AXIS], destination[Z_AXIS], destination[E_AXIS], feedrate/60, active_extruder);
                feedrate = 0.0;
                st_synchronize();
                endstops_hit_on_purpose();
            }
            plan_set_position(delta[X_AXIS], delta[Y_AXIS], delta[Z_AXIS], current_position[E_AXIS]);
#endif
#if defined (jcrochollUpstream) && Z_HOME_DIR < 0
// If homing towards BED do Z last
#endif
#if defined (jcrochollUpstream) && Z_HOME_DIR < 0
            if((home_all_axis) || (code_seen(axis_codes[Z_AXIS]))) {
                HOMEAXIS(Z);
            }
#endif
#if defined (jcrochollUpstream)
            plan_set_position(current_position[X_AXIS], current_position[Y_AXIS], current_position[Z_AXIS], current_position[E_AXIS]);
#endif
#if defined (upstream) && defined (ENDSTOPS_ONLY_FOR_HOMING) || defined (jcrocholl) && defined (ENDSTOPS_ONLY_FOR_HOMING) || defined (jcrochollUpstream) && defined (ENDSTOPS_ONLY_FOR_HOMING)
            enable_endstops(false);
#endif
        }
    }
}
#endif
#if defined (upstream) && defined (DELTA) || defined (jcrocholl)

void calculate_delta(float cartesian[3]) {
    delta[X_AXIS] = sqrt(sq(DELTA_DIAGONAL_ROD)
                         - sq(DELTA_TOWER1_X-cartesian[X_AXIS])
                         - sq(DELTA_TOWER1_Y-cartesian[Y_AXIS])
                        ) + cartesian[Z_AXIS];
    delta[Y_AXIS] = sqrt(sq(DELTA_DIAGONAL_ROD)
                         - sq(DELTA_TOWER2_X-cartesian[X_AXIS])
                         - sq(DELTA_TOWER2_Y-cartesian[Y_AXIS])
                        ) + cartesian[Z_AXIS];
    delta[Z_AXIS] = sqrt(sq(DELTA_DIAGONAL_ROD)
                         - sq(DELTA_TOWER3_X-cartesian[X_AXIS])
                         - sq(DELTA_TOWER3_Y-cartesian[Y_AXIS])
                        ) + cartesian[Z_AXIS];
    /*
    SERIAL_ECHOPGM("cartesian x="); SERIAL_ECHO(cartesian[X_AXIS]);
    SERIAL_ECHOPGM(" y="); SERIAL_ECHO(cartesian[Y_AXIS]);
    SERIAL_ECHOPGM(" z="); SERIAL_ECHOLN(cartesian[Z_AXIS]);
    SERIAL_ECHOPGM("delta x="); SERIAL_ECHO(delta[X_AXIS]);
    SERIAL_ECHOPGM(" y="); SERIAL_ECHO(delta[Y_AXIS]);
    SERIAL_ECHOPGM(" z="); SERIAL_ECHOLN(delta[Z_AXIS]);
    */
}
#endif
#if defined (upstream) || defined (jcrocholl) || defined (jcrochollUpstream)
void prepare_move
() {
    clamp_to_software_endstops(destination);
    previous_millis_cmd = millis();
#if defined (upstream) && defined (DELTA) || defined (jcrocholl)
    float difference[NUM_AXIS];
#endif
#if defined (jcrochollUpstream)
// Do not use feedmultiply for E or Z only moves
#endif
#if defined (upstream) && defined (DELTA) || defined (jcrocholl)
    for (int8_t i=0; i < NUM_AXIS; i++) {
        difference[i] = destination[i] - current_position[i];
    }
#endif
#if defined (jcrochollUpstream)
    if( (current_position[X_AXIS] == destination [X_AXIS]) && (current_position[Y_AXIS] == destination [Y_AXIS])) {
        plan_buffer_line(destination[X_AXIS], destination[Y_AXIS], destination[Z_AXIS], destination[E_AXIS], feedrate/60, active_extruder);
    } else {
        plan_buffer_line(destination[X_AXIS], destination[Y_AXIS], destination[Z_AXIS], destination[E_AXIS], feedrate*feedmultiply/60/100.0, active_extruder);
    }
#endif
#if defined (upstream) && defined (DELTA) || defined (jcrocholl)
    float cartesian_mm = sqrt(sq(difference[X_AXIS]) +
                              sq(difference[Y_AXIS]) +
                              sq(difference[Z_AXIS]));
    if (cartesian_mm < 0.000001) {
        cartesian_mm = abs(difference[E_AXIS]);
    }
    if (cartesian_mm < 0.000001) {
        return;
    }
    float seconds = 6000 * cartesian_mm / feedrate / feedmultiply;
    int steps = max(1, int(DELTA_SEGMENTS_PER_SECOND * seconds));
// SERIAL_ECHOPGM("mm="); SERIAL_ECHO(cartesian_mm);
// SERIAL_ECHOPGM(" seconds="); SERIAL_ECHO(seconds);
// SERIAL_ECHOPGM(" steps="); SERIAL_ECHOLN(steps);
    for (int s = 1; s <= steps; s++) {
        float fraction = float(s) / float(steps);
        for(int8_t i=0; i < NUM_AXIS; i++) {
            destination[i] = current_position[i] + difference[i] * fraction;
        }
        calculate_delta(destination);
        plan_buffer_line(delta[X_AXIS], delta[Y_AXIS], delta[Z_AXIS],
                         destination[E_AXIS], feedrate*feedmultiply/60/100.0,
                         active_extruder);
    }
#endif
    for(int8_t i=0; i < NUM_AXIS; i++) {
        current_position[i] = destination[i];
    }
}
#endif
