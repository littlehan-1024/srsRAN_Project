/*
 *
 * Copyright 2013-2022 Software Radio Systems Limited
 *
 * By using this file, you agree to the terms and conditions set
 * forth in the LICENSE file which can be found at the top level of
 * the distribution.
 *
 */

#ifndef SRSGNB_UNITTESTS_PHY_UPPER_CHANNEL_CODING_SHORT_SHORT_BLOCK_ENCODER_TEST_DATA_H
#define SRSGNB_UNITTESTS_PHY_UPPER_CHANNEL_CODING_SHORT_SHORT_BLOCK_ENCODER_TEST_DATA_H

// This file was generated using the following MATLAB class:
//   + "srsShortBlockEncoderUnittest.m"

#include "srsgnb/phy/modulation_scheme.h"
#include "srsgnb/support/file_vector.h"

namespace srsgnb {

struct test_case_t {
  unsigned             nof_messages     = 0;
  unsigned             message_length   = 0;
  unsigned             codeblock_length = 0;
  modulation_scheme    mod              = {};
  file_vector<uint8_t> messages;
  file_vector<uint8_t> codeblocks;
};

static const std::vector<test_case_t> short_block_encoder_test_data = {
    // clang-format off
  {10, 1, 1, modulation_scheme::BPSK, {"test_data/short_block_encoder_test_input0.dat"}, {"test_data/short_block_encoder_test_output0.dat"}},
  {10, 1, 2, modulation_scheme::QPSK, {"test_data/short_block_encoder_test_input1.dat"}, {"test_data/short_block_encoder_test_output1.dat"}},
  {10, 1, 6, modulation_scheme::QAM16, {"test_data/short_block_encoder_test_input2.dat"}, {"test_data/short_block_encoder_test_output2.dat"}},
  {10, 1, 17, modulation_scheme::QAM64, {"test_data/short_block_encoder_test_input3.dat"}, {"test_data/short_block_encoder_test_output3.dat"}},
  {10, 1, 10, modulation_scheme::QAM256, {"test_data/short_block_encoder_test_input4.dat"}, {"test_data/short_block_encoder_test_output4.dat"}},
  {10, 2, 5, modulation_scheme::BPSK, {"test_data/short_block_encoder_test_input5.dat"}, {"test_data/short_block_encoder_test_output5.dat"}},
  {10, 2, 14, modulation_scheme::QPSK, {"test_data/short_block_encoder_test_input6.dat"}, {"test_data/short_block_encoder_test_output6.dat"}},
  {10, 2, 36, modulation_scheme::QAM16, {"test_data/short_block_encoder_test_input7.dat"}, {"test_data/short_block_encoder_test_output7.dat"}},
  {10, 2, 36, modulation_scheme::QAM64, {"test_data/short_block_encoder_test_input8.dat"}, {"test_data/short_block_encoder_test_output8.dat"}},
  {10, 2, 30, modulation_scheme::QAM256, {"test_data/short_block_encoder_test_input9.dat"}, {"test_data/short_block_encoder_test_output9.dat"}},
  {10, 3, 96, modulation_scheme::BPSK, {"test_data/short_block_encoder_test_input10.dat"}, {"test_data/short_block_encoder_test_output10.dat"}},
  {10, 4, 48, modulation_scheme::BPSK, {"test_data/short_block_encoder_test_input11.dat"}, {"test_data/short_block_encoder_test_output11.dat"}},
  {10, 5, 64, modulation_scheme::BPSK, {"test_data/short_block_encoder_test_input12.dat"}, {"test_data/short_block_encoder_test_output12.dat"}},
  {10, 6, 80, modulation_scheme::BPSK, {"test_data/short_block_encoder_test_input13.dat"}, {"test_data/short_block_encoder_test_output13.dat"}},
  {10, 7, 80, modulation_scheme::BPSK, {"test_data/short_block_encoder_test_input14.dat"}, {"test_data/short_block_encoder_test_output14.dat"}},
  {10, 8, 56, modulation_scheme::BPSK, {"test_data/short_block_encoder_test_input15.dat"}, {"test_data/short_block_encoder_test_output15.dat"}},
  {10, 9, 80, modulation_scheme::BPSK, {"test_data/short_block_encoder_test_input16.dat"}, {"test_data/short_block_encoder_test_output16.dat"}},
  {10, 10, 64, modulation_scheme::BPSK, {"test_data/short_block_encoder_test_input17.dat"}, {"test_data/short_block_encoder_test_output17.dat"}},
  {10, 11, 88, modulation_scheme::BPSK, {"test_data/short_block_encoder_test_input18.dat"}, {"test_data/short_block_encoder_test_output18.dat"}},
    // clang-format on
};

} // namespace srsgnb

#endif // SRSGNB_UNITTESTS_PHY_UPPER_CHANNEL_CODING_SHORT_SHORT_BLOCK_ENCODER_TEST_DATA_H
