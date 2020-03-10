#include QMK_KEYBOARD_H


// Common Definitions
#define _MAIN 0

#define VSCBCK LCTL(KC_MINS)
#define VSCFWD LCTL(LSFT(KC_MINS))


// Iris Definitions
#define _BRACKETS 1
#define _NAV 2
#define _ADJUST 3

#define CTL_ESC CTL_T(KC_ESC)
#define LBRK_J LT(_BRACKETS, KC_J)
#define LNAV_F LT(_NAV, KC_F)
#define LADJ TG(_ADJUST)
#define CMDSPC LCMD(KC_SPC)


// BDN9 Definitions
#define _DEBUG 1
#define _SEARCH 2

#define STRT KC_F5
#define CMDP LCMD(KC_P)
#define FSCRN LCMD(LCTRL(KC_F))
#define LDBG TG(_DEBUG)
#define LSRCH TG(_SEARCH)
#define GDEFN KC_F12
#define SREFN LSHFT(KC_F12)
#define PDEFN LALT(KC_F12)
#define TGBRK KC_F9
#define STOP LSFT(KC_F5)
#define SHDBG LSFT(LCMD(KC_D))
#define STIN KC_F11
#define STOUT LSFT(KC_F11)
#define STOVR KC_F10
#define FIND LCMD(KC_F)
#define RPLC LALT(LCMD(KC_F))
#define FNFL LSFT(LCMD(KC_F))
#define RPFL LSFT(LCMD(KC_H))
#define FD_NEXT LCMD(KC_G)
#define FD_PREV LSFT(LCMD(KC_G))
#define EG_PREV SEND_STRING(SS_LCMD("K") SS_LCMD(SS_TAP(X_LEFT)))
#define EG_NEXT SEND_STRING(SS_LCMD("K") SS_LCMD(SS_TAP(X_RGHT)))
