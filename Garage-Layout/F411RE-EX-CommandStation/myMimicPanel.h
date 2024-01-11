// Sequences for my mimic panel
// Point LEDs are set/reset via macro in myPoints.h
// Decoupler LEDs are set/reset via macro in myDecouplers.h

AUTOSTART SEQUENCE(DECOUPLER_SEQUENCE)
  IF(DECOUPLER1_BUTTON)
    START(WAREHOUSE_DECOUPLER)
  ENDIF
  IF(DECOUPLER2_BUTTON)
    START(CAR_DECOUPLER)
  ENDIF
  IF(DECOUPLER3_BUTTON)
    START(CONTAINER_DECOUPLER)
  ENDIF
  IF(DECOUPLER4_BUTTON)
    START(STORAGE3_DECOUPLER)
  ENDIF
  IF(DECOUPLER5_BUTTON)
    START(STORAGE2_DECOUPLER)
  ENDIF
  IF(DECOUPLER6_BUTTON)
    START(STORAGE1_DECOUPLER)
  ENDIF
  IF(DECOUPLER7_BUTTON)
    START(MAINTENANCE_DECOUPLER)
  ENDIF
FOLLOW(100)

// Event handler for the rotary encoder/turntable controller
// Blackpill at 0x70, Vpin 700

ONCHANGE(RE_VPIN)
  IFRE(RE_VPIN, 0)
    START(TTROUTE_9)
  ENDIF
  IFRE(RE_VPIN, 1)
    START(TTROUTE_1)
  ENDIF
  IFRE(RE_VPIN, 2)
    START(TTROUTE_2)
  ENDIF
  IFRE(RE_VPIN, 3)
    START(TTROUTE_3)
  ENDIF
  IFRE(RE_VPIN, 4)
    START(TTROUTE_4)
  ENDIF
  IFRE(RE_VPIN, 5)
    START(TTROUTE_5)
  ENDIF
  IFRE(RE_VPIN, 6)
    START(TTROUTE_6)
  ENDIF
  IFRE(RE_VPIN, 7)
    START(TTROUTE_7)
  ENDIF
  IFRE(RE_VPIN, 8)
    START(TTROUTE_8)
  ENDIF
DONE
