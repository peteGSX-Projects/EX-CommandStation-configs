/* myAutomation.h
*  All layout setup and automation items are defined here.
*/

/* Rokuhan turnout macro
*  This macro defines Rokuhan turnouts as well as ensuring that these
*  turnouts are driven only by a short pulse to prevent coil burn out.
*
*  Call this macro with:
*  ROKUHANTURNOUT(t, p1, p2, desc)
*
*  Where:
*  t = turnout ID
*  p1 = direction pin
*  p2 = enable pin
*  desc = description of the turnout
*
*  Adjust the PULSE time (in ms) below as required, 25 seems reliable.
*
*  When a turnout command is sent to one of the defined turnouts, the macro
*  will close or throw the turnout using the defined PULSE time.
*
*  This also ensures all turnouts are defined as part of the compilation.
*/
#define PULSE 25

#define ROKUHANTURNOUT(t, p1, p2, desc) \
PIN_TURNOUT(t, p1, desc) \
DONE \
ONCLOSE(t) \
SET(p1) \
SET(p2)DELAY(PULSE)RESET(p2) \
DONE \
ONTHROW(t) \
RESET(p1) \
SET(p2)DELAY(PULSE)RESET(p2) \
DONE

/* Startup sequence
*  This section defines startup actions:
*  - Set L293D enable pins low
*  - Turn the turnout power relay on
*  - Close all turnouts
*/

// Ensure all L293D enable pins are RESET before providing turnout power
// This is to prevent turnout coil burnout
RESET(172)
RESET(173)
RESET(174)
RESET(175)
RESET(176)
RESET(177)
RESET(178)
RESET(179)
RESET(188)
RESET(189)
RESET(190)
RESET(191)
RESET(192)
RESET(193)
RESET(194)
RESET(195)
RESET(204)
RESET(205)
RESET(206)
RESET(207)
RESET(208)
RESET(209)

// Turn the turnout power relay on
// Relay control sits on the last pin of the last MCP23017
SET(211)

// Close all turnouts on start up
CLOSE(101)
CLOSE(102)
CLOSE(103)
CLOSE(104)
CLOSE(105)
CLOSE(106)
CLOSE(107)
CLOSE(108)
CLOSE(109)
CLOSE(110)
CLOSE(111)
CLOSE(112)
CLOSE(113)
CLOSE(114)
CLOSE(115)
CLOSE(116)
CLOSE(117)
CLOSE(118)
CLOSE(119)
CLOSE(120)
CLOSE(121)
CLOSE(122)

// Define the turntable DCC turnouts
TURNOUT(201, 0, 51, "Main track connection")
TURNOUT(202, 0, 51, "Main track connection")
TURNOUT(203, 0, 51, "Main track connection")
TURNOUT(204, 0, 51, "Main track connection")
TURNOUT(205, 0, 51, "Main track connection")
TURNOUT(206, 0, 51, "Main track connection")
TURNOUT(207, 0, 51, "Main track connection")
TURNOUT(208, 0, 51, "Main track connection")
TURNOUT(209, 0, 51, "Main track connection")
TURNOUT(210, 0, 51, "Main track connection")
TURNOUT(211, 0, 51, "Main track connection")
TURNOUT(212, 0, 51, "Main track connection")

// This is the end of the startup sequence
DONE

// Turnout definitions using the ROKUHANTURNOUT macro

// Main to industry loop turnout definitions
ROKUHANTURNOUT(101, 164, 172, "Main to industry loop 1") // Pair of left turnouts
ROKUHANTURNOUT(102, 165, 173, "Industry loop to main 1")
ROKUHANTURNOUT(103, 166, 174, "Main to industry loop 2") // Pair of right turnouts)
ROKUHANTURNOUT(104, 165, 175, "Industry loop to main 2")

// Industry loop turnouts
ROKUHANTURNOUT(105, 168, 176, "Yard entrance")
ROKUHANTURNOUT(106, 169, 177, "Inner industry loop entrance 1") // Behind roundhouse
ROKUHANTURNOUT(107, 170, 178, "Inner industry loop entrance 2") // To right of main turnouts
ROKUHANTURNOUT(108, 171, 179, "Car loading entrance")
ROKUHANTURNOUT(109, 180, 188, "Container loading entrance")
ROKUHANTURNOUT(110, 181, 189, "Warehouse siding entrance")
ROKUHANTURNOUT(111, 182, 190, "Distribution centre entrance")
ROKUHANTURNOUT(112, 183, 191, "Distribution centre split")
ROKUHANTURNOUT(113, 184, 192, "TBA industry siding")

// Yard turnouts
ROKUHANTURNOUT(114, 185, 193, "Yard 1") // First left turnout after entrance)
ROKUHANTURNOUT(115, 186, 194, "Runaround siding") // Entry to siding with runaround
ROKUHANTURNOUT(116, 187, 195, "Rolling road entry")
ROKUHANTURNOUT(117, 196, 204, "Turntable entry")
ROKUHANTURNOUT(118, 197, 205, "Runaround 1") // Pair of right turnouts for runaround
ROKUHANTURNOUT(119, 198, 206, "Runaround 2")
ROKUHANTURNOUT(120, 199, 207, "Yard 2") // Right turnout
ROKUHANTURNOUT(121, 200, 208, "Yard 3") // Left turnout
ROKUHANTURNOUT(122, 201, 209, "Yard 4") // Left turnout
DONE

// Ensure main to industry loops turnouts operate together
ONCLOSE(101) CLOSE(102) DONE
ONTHROW(101) THROW(102) DONE
ONCLOSE(102) CLOSE(101) DONE
ONTHROW(102) THROW(101) DONE
ONCLOSE(103) CLOSE(104) DONE
ONTHROW(103) THROW(104) DONE
ONCLOSE(104) CLOSE(103) DONE
ONTHROW(104) THROW(103) DONE

// Ensure the runaround turnouts operate together
ONCLOSE(118) CLOSE(119) DONE
ONTHROW(118) THROW(119) DONE
ONCLOSE(119) CLOSE(118) DONE
ONTHROW(119) THROW(118) DONE
