!#############!##############!Marlin_main.cpp
+-+-+-

+-+-+-
#if defined (upstream) && defined (DELTA) || defined (jcrocholl)

static float delta[3] = {0.0, 0.0, 0.0};
#endif
+-+-+-
++++additional ifdef+++
+++parent:#if defined (upstream) || defined (jcrocholl) || defined (jcrochollUpstream)

+++child:defined(upstream)&&defined(DELTA)||defined(jcrocholl)
+-+-+-

+-+-+-
#if defined (jcrocholl) && defined (QUICK_HOME)
if (home_all_axis)  // Move all carriages up together until the first endstop is hit.
      {
        current_position[X_AXIS] = 0;
        current_position[Y_AXIS] = 0;
        current_position[Z_AXIS] = 0;
        plan_set_position(current_position[X_AXIS], current_position[Y_AXIS], current_position[Z_AXIS], current_position[E_AXIS]); 

        destination[X_AXIS] = 3 * Z_MAX_LENGTH;
        destination[Y_AXIS] = 3 * Z_MAX_LENGTH;
        destination[Z_AXIS] = 3 * Z_MAX_LENGTH;
        feedrate = 1.732 * homing_feedrate[X_AXIS];
        plan_buffer_line(destination[X_AXIS], destination[Y_AXIS], destination[Z_AXIS], destination[E_AXIS], feedrate/60, active_extruder);
        st_synchronize();
        endstops_hit_on_purpose();

        current_position[X_AXIS] = destination[X_AXIS];
        current_position[Y_AXIS] = destination[Y_AXIS];
        current_position[Z_AXIS] = destination[Z_AXIS];
      }
#endif
+-+-+-
++++additional ifdef+++
+++parent:#if defined (upstream) || defined (jcrocholl) || defined (jcrochollUpstream)

+++child:defined(jcrocholl)&&defined(QUICK_HOME)
+-+-+-

+-+-+-
#if defined (upstream) && defined (DELTA) || defined (jcrocholl)

calculate_delta(current_position);
#endif
+-+-+-
++++additional ifdef+++
+++parent:#if defined (upstream) || defined (jcrocholl) || defined (jcrochollUpstream)

+++child:defined(upstream)&&defined(DELTA)||defined(jcrocholl)
+-+-+-

+-+-+-
#if defined (upstream) && defined (DELTA) || defined (jcrocholl)

plan_set_position(delta[X_AXIS], delta[Y_AXIS], delta[Z_AXIS], current_position[E_AXIS]);
#endif
+-+-+-
++++additional ifdef+++
+++parent:#if defined (upstream) || defined (jcrocholl) || defined (jcrochollUpstream)

+++child:defined(upstream)&&defined(DELTA)||defined(jcrocholl)
+-+-+-

+-+-+-
#if defined (upstream) && defined (DELTA) || defined (jcrocholl)

void calculate_delta(float cartesian[3])
{
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
+-+-+-
++++additional ifdef+++
+++parent:#if defined (upstream) || defined (jcrocholl) || defined (jcrochollUpstream)

+++child:defined(upstream)&&defined(DELTA)||defined(jcrocholl)
+-+-+-

+-+-+-
#if defined (upstream) && defined (DELTA) || defined (jcrocholl)

float difference[NUM_AXIS];
#endif
+-+-+-
++++additional ifdef+++
+++parent:#if defined (upstream) || defined (jcrocholl) || defined (jcrochollUpstream)

+++child:defined(upstream)&&defined(DELTA)||defined(jcrocholl)
+-+-+-

+-+-+-
#if defined (upstream) && defined (DELTA) || defined (jcrocholl)

for (int8_t i=0; i < NUM_AXIS; i++) {
    difference[i] = destination[i] - current_position[i];
  }
#endif
+-+-+-
++++additional ifdef+++
+++parent:#if defined (upstream) || defined (jcrocholl) || defined (jcrochollUpstream)

+++child:defined(upstream)&&defined(DELTA)||defined(jcrocholl)
+-+-+-

+-+-+-
#if defined (upstream) && defined (DELTA) || defined (jcrocholl)

float cartesian_mm = sqrt(sq(difference[X_AXIS]) +
                            sq(difference[Y_AXIS]) +
                            sq(difference[Z_AXIS]));
#endif
+-+-+-
++++additional ifdef+++
+++parent:#if defined (upstream) || defined (jcrocholl) || defined (jcrochollUpstream)

+++child:defined(upstream)&&defined(DELTA)||defined(jcrocholl)
+-+-+-

+-+-+-
#if defined (upstream) && defined (DELTA) || defined (jcrocholl)

if (cartesian_mm < 0.000001) { cartesian_mm = abs(difference[E_AXIS]); }
#endif
+-+-+-
++++additional ifdef+++
+++parent:#if defined (upstream) || defined (jcrocholl) || defined (jcrochollUpstream)

+++child:defined(upstream)&&defined(DELTA)||defined(jcrocholl)
+-+-+-

+-+-+-
#if defined (upstream) && defined (DELTA) || defined (jcrocholl)

if (cartesian_mm < 0.000001) { return; }
#endif
+-+-+-
++++additional ifdef+++
+++parent:#if defined (upstream) || defined (jcrocholl) || defined (jcrochollUpstream)

+++child:defined(upstream)&&defined(DELTA)||defined(jcrocholl)
+-+-+-

+-+-+-
#if defined (upstream) && defined (DELTA) || defined (jcrocholl)

float seconds = 6000 * cartesian_mm / feedrate / feedmultiply;
#endif
+-+-+-
++++additional ifdef+++
+++parent:#if defined (upstream) || defined (jcrocholl) || defined (jcrochollUpstream)

+++child:defined(upstream)&&defined(DELTA)||defined(jcrocholl)
+-+-+-

+-+-+-
#if defined (upstream) && defined (DELTA) || defined (jcrocholl)

int steps = max(1, int(DELTA_SEGMENTS_PER_SECOND * seconds));
#endif
+-+-+-
++++additional ifdef+++
+++parent:#if defined (upstream) || defined (jcrocholl) || defined (jcrochollUpstream)

+++child:defined(upstream)&&defined(DELTA)||defined(jcrocholl)
+-+-+-

+-+-+-
#if defined (upstream) && defined (DELTA) || defined (jcrocholl)

// SERIAL_ECHOPGM("mm="); SERIAL_ECHO(cartesian_mm);
#endif
+-+-+-
++++additional ifdef+++
+++parent:#if defined (upstream) || defined (jcrocholl) || defined (jcrochollUpstream)

+++child:defined(upstream)&&defined(DELTA)||defined(jcrocholl)
+-+-+-

+-+-+-
#if defined (upstream) && defined (DELTA) || defined (jcrocholl)

// SERIAL_ECHOPGM(" seconds="); SERIAL_ECHO(seconds);
#endif
+-+-+-
++++additional ifdef+++
+++parent:#if defined (upstream) || defined (jcrocholl) || defined (jcrochollUpstream)

+++child:defined(upstream)&&defined(DELTA)||defined(jcrocholl)
+-+-+-

+-+-+-
#if defined (upstream) && defined (DELTA) || defined (jcrocholl)

// SERIAL_ECHOPGM(" steps="); SERIAL_ECHOLN(steps);
#endif
+-+-+-
++++additional ifdef+++
+++parent:#if defined (upstream) || defined (jcrocholl) || defined (jcrochollUpstream)

+++child:defined(upstream)&&defined(DELTA)||defined(jcrocholl)
+-+-+-

+-+-+-
#if defined (upstream) && defined (DELTA) || defined (jcrocholl)

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
+-+-+-
++++additional ifdef+++
+++parent:#if defined (upstream) || defined (jcrocholl) || defined (jcrochollUpstream)

+++child:defined(upstream)&&defined(DELTA)||defined(jcrocholl)