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

#ifndef SRSGNB_PHY_UPPER_CHANNEL_CODING_POLAR_POLAR_DECODER_H
#define SRSGNB_PHY_UPPER_CHANNEL_CODING_POLAR_POLAR_DECODER_H

#include "srsgnb/adt/span.h"
#include "srsgnb/phy/upper/channel_coding/polar/polar_code.h"
#include "srsgnb/phy/upper/channel_coding/polar/polar_encoder.h"
#include <cstdint>
#include <memory>

namespace srsgnb {

class polar_decoder
{
public:
  virtual ~polar_decoder() = default;

  /*!
   * \brief Decodes the input (int8_t) codeword with the specified polar decoder.
   * \param[in] input_llr The decoder LLR input vector.
   * \param[out] data_decoded The decoder output vector.
   * \param[in] code Polar code
   * \return An integer: 0 if the function executes correctly, -1 otherwise.
   */
  virtual void decode(span<const int8_t> input_llr, span<uint8_t> data_decoded, const polar_code& code) = 0;
};

/*!
 * \brief Initializes all the polar decoder variables according to fixed-point (8 bit) Simplified Successive
 * Cancellation (SSC) decoder algorithm and the maximum given code size. \param[in] enc The polar encoder implementation
 * \param[in] code_size_log The \f$ log_2\f$ of the number of bits of the decoder input/output vector.
 * \return An integer: 0 if the function executes correctly, -1 otherwise.
 */
std::unique_ptr<polar_decoder> create_polar_decoder_ssc(std::unique_ptr<polar_encoder> enc, unsigned code_size_log);

} // namespace srsgnb

#endif // SRSGNB_PHY_UPPER_CHANNEL_CODING_POLAR_POLAR_DECODER_H
