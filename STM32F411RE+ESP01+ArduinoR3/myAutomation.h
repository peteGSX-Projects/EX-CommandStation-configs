CLOSE(101)
CLOSE(102)

DONE

// Turnouts
#define PULSE 50

#define ROKUHANTURNOUT(t, p1, p2, desc, ali) \
PIN_TURNOUT(t, 0, desc) \
ALIAS(ali, t) \
DONE \
ONCLOSE(t) \
SET(p1) \
SET(p2)DELAY(PULSE)RESET(p2) \
DONE \
ONTHROW(t1) \
RESET(p1) \
SET(p2)DELAY(PULSE)RESET(p2) \
DONE \

ROKUHANTURNOUT(101, 50, 51, "Turnout 1", TRN_1)
ROKUHANTURNOUT(102, 2, 4, "Turnout 2", TRN_2)

// EX-Turntable routes
#define EX_TURNTABLE(route_id, reserve_id, vpin, steps, activity, desc) \
  ROUTE(route_id, desc) \
    RESERVE(reserve_id) \
    MOVETT(vpin, steps, activity) \
    WAITFOR(vpin) \
    FREE(reserve_id) \
    DONE

// Turntable
EX_TURNTABLE(TTROUTE1, TURNTABLE, 600, 500, Turn, "Position 1")

// Traverser
EX_TURNTABLE(TRROUTE1, TRAVERSER, 601, 500, Turn, "Position 1")

// Rotary encoder routes
ONCHANGE(700)
  IFRE(700, 5)
    START(TTROUTE1)
  ENDIF
  DONE


// Loco roster entries
ROSTER(2004, "QR 2004", "Lights")
ROSTER(2006, "QR 2006", "Lights")
ROSTER(2010, "QR 2010", "Lights")

// Aliases
ALIAS(TURNTABLE, 255)
ALIAS(TRAVERSER, 254)
ALIAS(TTROUTE1)
ALIAS(TTROUTE2)
ALIAS(TTROUTE3)
ALIAS(TTROUTE4)
ALIAS(TTROUTE5)
ALIAS(TTROUTE6)
ALIAS(TTROUTE7)
ALIAS(TTROUTE8)
ALIAS(TRROUTE1)
ALIAS(TRROUTE2)
ALIAS(TRROUTE3)
ALIAS(TRROUTE4)
ALIAS(TRROUTE5)
ALIAS(TRROUTE6)
ALIAS(TRROUTE7)
ALIAS(TRROUTE8)