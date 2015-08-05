#if defined (A) || defined (B)
static void axis_is_at_home(int axis) {
#if defined (A) && defined (DUAL_X_CARRIAGE) || defined (B) && defined (DUAL_X_CARRIAGE)
    if (axis == X_AXIS) {
        if (active_extruder != 0) {
            current_position[X_AXIS] = x_home_pos(active_extruder);
            min_pos[X_AXIS] =          X2_MIN_POS;
            max_pos[X_AXIS] =          max(extruder_offset[X_AXIS][1], X2_MAX_POS);
            return;
        } else if (dual_x_carriage_mode == DXC_DUPLICATION_MODE && active_extruder == 0) {
            current_position[X_AXIS] = base_home_pos(X_AXIS) + add_homing[X_AXIS];
            min_pos[X_AXIS] =          base_min_pos(X_AXIS) + add_homing[X_AXIS];
            max_pos[X_AXIS] =          min(base_max_pos(X_AXIS) + add_homing[X_AXIS],
                                           max(extruder_offset[X_AXIS][1], X2_MAX_POS) - duplicate_extruder_x_offset);
            return;
        }
    }
#endif
#if defined (A) && defined (SCARA) || defined (B) && defined (SCARA)
    float homeposition[3];
    char i;
#if defined (A) && defined (SCARA) || defined (B) && defined (SCARA)
    if (axis < 2) {
        {
            for (i=0; i<3; i++) {
                homeposition[i] = base_home_pos(i);
            }
            // SERIAL_ECHOPGM("homeposition[x]= "); SERIAL_ECHO(homeposition[0]);
            //  SERIAL_ECHOPGM("homeposition[y]= "); SERIAL_ECHOLN(homeposition[1]);
            // Works out real Homeposition angles using inverse kinematics,
            // and calculates homing offset using forward kinematics
            calculate_delta(homeposition);
            // SERIAL_ECHOPGM("base Theta= "); SERIAL_ECHO(delta[X_AXIS]);
            // SERIAL_ECHOPGM(" base Psi+Theta="); SERIAL_ECHOLN(delta[Y_AXIS]);
            for (i=0; i<2; i++) {
                delta[i] -= add_homing[i];
            }
            // SERIAL_ECHOPGM("addhome X="); SERIAL_ECHO(add_homing[X_AXIS]);
            // SERIAL_ECHOPGM(" addhome Y="); SERIAL_ECHO(add_homing[Y_AXIS]);
            // SERIAL_ECHOPGM(" addhome Theta="); SERIAL_ECHO(delta[X_AXIS]);
            // SERIAL_ECHOPGM(" addhome Psi+Theta="); SERIAL_ECHOLN(delta[Y_AXIS]);
            calculate_SCARA_forward_Transform(delta);
            // SERIAL_ECHOPGM("Delta X="); SERIAL_ECHO(delta[X_AXIS]);
            // SERIAL_ECHOPGM(" Delta Y="); SERIAL_ECHOLN(delta[Y_AXIS]);
            current_position[axis] = delta[axis];
            // SCARA home positions are based on configuration since the actual limits are determined by the
            // inverse kinematic transform.
            min_pos[axis] =          base_min_pos(axis); // + (delta[axis] - base_home_pos(axis));
            max_pos[axis] =          base_max_pos(axis); // + (delta[axis] - base_home_pos(axis));
        }
#endif
    } else {
        current_position[axis] = base_home_pos(axis) + add_homing[axis];
        min_pos[axis] =          base_min_pos(axis) + add_homing[axis];
        max_pos[axis] =          base_max_pos(axis) + add_homing[axis];
    }
#endif
#if defined (A) && !defined (SCARA) || defined (B) && !defined (SCARA)
    current_position[axis] = base_home_pos(axis) + add_homing[axis];
    min_pos[axis] =          base_min_pos(axis) + add_homing[axis];
    max_pos[axis] =          base_max_pos(axis) + add_homing[axis];
#endif
}
#endif
