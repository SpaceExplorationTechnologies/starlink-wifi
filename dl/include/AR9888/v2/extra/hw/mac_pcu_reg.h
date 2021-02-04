#ifdef AR9887
#include "../../hw/mac_pcu_reg_swift.h"
#else
#include "../../hw/mac_pcu_reg_peregrine.h"
#endif

/* TBDXXX - REMOVE */

#define MISSING_MAC_PCU 0x0


/* NOTE: The key cache has been entirely removed for AR9888 arch and
 * replaced with the AST (address search table). All WHAL fns need to be
 * migrated to AST and this can be removed
 */
#define MAC_PCU_KEY_CACHE_ADDRESS MISSING_MAC_PCU

