/* gen164/5/ed_sign.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

#include <ed25519.h>

/* functions
*/
  u2_weak                                                         //  transfer
  j2_mc(Pt5, ed, sign)(u2_wire wir_r,
                        u2_noun a,                                 //  retain
                        u2_noun b,                                 //  retain
                        u2_noun c)                                 //  retain
  {
    c3_y sig_y[64];
    c3_y sec_y[64];
    c3_y pub_y[32];

    c3_w secm_w = u2_met(3, b);
    c3_w pubm_w = u2_met(3, c);

    c3_w mesm_w = u2_met(3, a);

    c3_y* mes_y = 0;

    if ( 64 < secm_w ) {
      return u2_bl_bail(wir_r, c3__exit);
    }
    if ( 32 < pubm_w ) {
      return u2_bl_bail(wir_r, c3__exit);
    }

    mes_y = c3_malloc(mesm_w);
    u2_cr_bytes(0, mesm_w, mes_y, a);
    u2_cr_bytes(0, 64, sec_y, b);
    u2_cr_bytes(0, 32, pub_y, c);

    ed25519_sign(sig_y, mes_y, mesm_w, pub_y, sec_y);
    free(mes_y);
    return u2_ci_bytes(64, sig_y);
  }
/* structures
*/
  u2_ho_jet
  j2_mcj(Pt5, ed, sign)[] = {
    { ".2", c3__lite, j2_mc(Pt5, ed, sign), u2_jet_test|u2_jet_live, u2_none, u2_none },
    { }
  };