/**
 *
 * \section COPYRIGHT
 *
 * Copyright 2013-2022 Software Radio Systems Limited
 *
 * By using this file, you agree to the terms and conditions set
 * forth in the LICENSE file which can be found at the top level of
 * the distribution.
 *
 */

#ifndef SRSGNB_MAC_CELL_ASN1_HELPERS_H
#define SRSGNB_MAC_CELL_ASN1_HELPERS_H

#include "srsgnb/mac/cell_configuration.h"

// ASN.1 forward declarations
namespace asn1 {
namespace rrc_nr {

struct serving_cell_cfg_common_sib_s;
struct mib_s;

} // namespace rrc_nr
} // namespace asn1

namespace srsgnb {

/// Fills mac cell configuration with parameters in ASN.1 ServingCellConfigCommonSIB
void fill_mac_cell_cfg_from_asn1(mac_cell_creation_request&                         out,
                                 const asn1::rrc_nr::serving_cell_cfg_common_sib_s& serv_cell_sib_in,
                                 const asn1::rrc_nr::mib_s&                         mib_in,
                                 subcarrier_spacing                                 ssb_scs);

} // namespace srsgnb

#endif // SRSGNB_MAC_CELL_ASN1_HELPERS_H
