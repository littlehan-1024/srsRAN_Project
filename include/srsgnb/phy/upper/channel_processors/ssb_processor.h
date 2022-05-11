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

#ifndef SRSGNB_SRSGNB_PHY_UPPER_CHANNEL_PROCESSORS_SSB_PROCESSOR_H_
#define SRSGNB_SRSGNB_PHY_UPPER_CHANNEL_PROCESSORS_SSB_PROCESSOR_H_

#include "srsgnb/adt/static_vector.h"
#include "srsgnb/phy/resource_grid.h"
#include "srsgnb/ran/slot_point.h"
#include "srsgnb/ran/ssb_mapping.h"

namespace srsgnb {

/// Describes the SSB processor interface.
class ssb_processor
{
public:
  /// Defines the BCH payload size.
  static constexpr unsigned BCH_PAYLOAD_SIZE = 32;

  /// Describes the SS/PBCH Block PDU.
  struct pdu_t {
    /// Current slot context.
    slot_point slot;
    /// Physical Cell identifier.
    unsigned phys_cell_id;
    /// PSS power level allocation in dB, relative to SSS.
    float beta_pss;
    /// SSB opportunity index in a burst.
    unsigned ssb_idx;
    /// Maximum number of SS/PBCH block candidates in a 5ms burst, described in TS 38.213 section 4.1.
    unsigned L_max;
    /// SSB offset between the common resource grid and the beginning of the SSB as a number of 15kHz subcarriers.
    unsigned ssb_subcarrier_offset;
    /// SSB offset between the point A and the beginning if the common resource grid in RB.
    unsigned ssb_offset_pointA;
    /// SS/PBCH pattern case (A,B,C,D,E).
    ssb_pattern_case pattern_case;
    /// \brief PBCH payload.
    /// The first 24 bits correspond to the packed MIB, while the last 8 bits are:
    /// - SFN (4 bit),
    /// - half-radio frame (1 bit), and
    /// - SS/PBCH block index (3 bit) for L_max=64, otherwise
    /// - SS/PBCH subcarrier offset (1 bit) and 2 padding bits.
    /// \remark Bit order is specified in 3GPP TS 38.212 section 7.1.1.
    std::array<uint8_t, BCH_PAYLOAD_SIZE> bch_payload;
    /// Port indexes to map the SS/PBCH transmission.
    static_vector<uint8_t, MAX_PORTS> ports;
  };

  /// Default destructor.
  virtual ~ssb_processor() = default;

  /// \brief Processes the SS/PBCH Block PDU and writes the resultant signal in the given grid.
  /// \param [in] pdu Provides the necessary data to generate the SSB message.
  /// \param [out] grid Provides the destination resource grid.
  virtual void process(const pdu_t& pdu, resource_grid_writer& grid) = 0;
};

} // namespace srsgnb

#endif // SRSGNB_SRSGNB_PHY_UPPER_CHANNEL_PROCESSORS_SSB_PROCESSOR_H_
