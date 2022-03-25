#ifndef SRSGNB_UNITTESTS_PHY_UPPER_CHANNEL_PROCESSORS_PDSCH_MODULATOR_TEST_DATA_H
#define SRSGNB_UNITTESTS_PHY_UPPER_CHANNEL_PROCESSORS_PDSCH_MODULATOR_TEST_DATA_H

// This file was generated using the following MATLAB scripts:
//   + "srsPDSCHmodulatorUnittest.m"

#include "../../resource_grid_test_doubles.h"
#include "srsgnb/adt/complex.h"
#include "srsgnb/phy/upper/channel_processors/pdsch_modulator.h"
#include "srsgnb/support/file_vector.h"
#include <array>

namespace srsgnb {

struct test_case_t {
  pdsch_modulator::config_t                               config;
  file_vector<uint8_t>                                    data;
  file_vector<resource_grid_writer_spy::expected_entry_t> symbols;
};

static const std::vector<test_case_t> pdsch_modulator_test_data = {
    // clang-format off
  {{63598, 52, 0, modulation_scheme::QPSK, modulation_scheme::QPSK, rb_allocation({0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51}, vrb_to_prb_mapping_type::NON_INTERLEAVED), 0, 14, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE1, 2, 725, 1, {}, 0, {0}},{"pdsch_modulator_test_input0.dat"},{"pdsch_modulator_test_output0.dat"}},
  {{48847, 52, 0, modulation_scheme::QPSK, modulation_scheme::QPSK, rb_allocation({0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51}, vrb_to_prb_mapping_type::NON_INTERLEAVED), 0, 14, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 2, 698, 1, {}, 0, {0}},{"pdsch_modulator_test_input1.dat"},{"pdsch_modulator_test_output1.dat"}},
  {{39297, 52, 0, modulation_scheme::QPSK, modulation_scheme::QPSK, rb_allocation({0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51}, vrb_to_prb_mapping_type::NON_INTERLEAVED), 0, 14, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 2, 884, 1, {}, 0, {0}},{"pdsch_modulator_test_input2.dat"},{"pdsch_modulator_test_output2.dat"}},
  {{10948, 52, 0, modulation_scheme::QPSK, modulation_scheme::QPSK, rb_allocation({0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51}, vrb_to_prb_mapping_type::NON_INTERLEAVED), 0, 14, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 2, 246, 1, {}, 0, {0}},{"pdsch_modulator_test_input3.dat"},{"pdsch_modulator_test_output3.dat"}},
  {{27965, 52, 0, modulation_scheme::QAM16, modulation_scheme::QAM16, rb_allocation({0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51}, vrb_to_prb_mapping_type::NON_INTERLEAVED), 0, 14, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE1, 2, 353, 1, {}, 0, {0}},{"pdsch_modulator_test_input4.dat"},{"pdsch_modulator_test_output4.dat"}},
  {{43370, 52, 0, modulation_scheme::QAM16, modulation_scheme::QAM16, rb_allocation({0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51}, vrb_to_prb_mapping_type::NON_INTERLEAVED), 0, 14, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 2, 394, 1, {}, 0, {0}},{"pdsch_modulator_test_input5.dat"},{"pdsch_modulator_test_output5.dat"}},
  {{41218, 52, 0, modulation_scheme::QAM16, modulation_scheme::QAM16, rb_allocation({0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51}, vrb_to_prb_mapping_type::NON_INTERLEAVED), 0, 14, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 2, 890, 1, {}, 0, {0}},{"pdsch_modulator_test_input6.dat"},{"pdsch_modulator_test_output6.dat"}},
  {{50598, 52, 0, modulation_scheme::QAM16, modulation_scheme::QAM16, rb_allocation({0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51}, vrb_to_prb_mapping_type::NON_INTERLEAVED), 0, 14, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 2, 364, 1, {}, 0, {0}},{"pdsch_modulator_test_input7.dat"},{"pdsch_modulator_test_output7.dat"}},
  {{27011, 52, 0, modulation_scheme::QAM64, modulation_scheme::QAM64, rb_allocation({0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51}, vrb_to_prb_mapping_type::NON_INTERLEAVED), 0, 14, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE1, 2, 372, 1, {}, 0, {0}},{"pdsch_modulator_test_input8.dat"},{"pdsch_modulator_test_output8.dat"}},
  {{45697, 52, 0, modulation_scheme::QAM64, modulation_scheme::QAM64, rb_allocation({0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51}, vrb_to_prb_mapping_type::NON_INTERLEAVED), 0, 14, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 2, 232, 1, {}, 0, {0}},{"pdsch_modulator_test_input9.dat"},{"pdsch_modulator_test_output9.dat"}},
  {{20286, 52, 0, modulation_scheme::QAM64, modulation_scheme::QAM64, rb_allocation({0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51}, vrb_to_prb_mapping_type::NON_INTERLEAVED), 0, 14, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 2, 202, 1, {}, 0, {0}},{"pdsch_modulator_test_input10.dat"},{"pdsch_modulator_test_output10.dat"}},
  {{55991, 52, 0, modulation_scheme::QAM64, modulation_scheme::QAM64, rb_allocation({0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51}, vrb_to_prb_mapping_type::NON_INTERLEAVED), 0, 14, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 2, 776, 1, {}, 0, {0}},{"pdsch_modulator_test_input11.dat"},{"pdsch_modulator_test_output11.dat"}},
  {{14785, 52, 0, modulation_scheme::QAM256, modulation_scheme::QAM256, rb_allocation({0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51}, vrb_to_prb_mapping_type::NON_INTERLEAVED), 0, 14, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE1, 2, 657, 1, {}, 0, {0}},{"pdsch_modulator_test_input12.dat"},{"pdsch_modulator_test_output12.dat"}},
  {{14294, 52, 0, modulation_scheme::QAM256, modulation_scheme::QAM256, rb_allocation({0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51}, vrb_to_prb_mapping_type::NON_INTERLEAVED), 0, 14, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 2, 192, 1, {}, 0, {0}},{"pdsch_modulator_test_input13.dat"},{"pdsch_modulator_test_output13.dat"}},
  {{31854, 52, 0, modulation_scheme::QAM256, modulation_scheme::QAM256, rb_allocation({0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51}, vrb_to_prb_mapping_type::NON_INTERLEAVED), 0, 14, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 2, 990, 1, {}, 0, {0}},{"pdsch_modulator_test_input14.dat"},{"pdsch_modulator_test_output14.dat"}},
  {{26497, 52, 0, modulation_scheme::QAM256, modulation_scheme::QAM256, rb_allocation({0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51}, vrb_to_prb_mapping_type::NON_INTERLEAVED), 0, 14, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 2, 622, 1, {}, 0, {0}},{"pdsch_modulator_test_input15.dat"},{"pdsch_modulator_test_output15.dat"}},
  {{33938, 52, 0, modulation_scheme::QPSK, modulation_scheme::QPSK, rb_allocation({0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51}, vrb_to_prb_mapping_type::NON_INTERLEAVED), 1, 13, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE1, 2, 553, 1, {}, 0, {0}},{"pdsch_modulator_test_input16.dat"},{"pdsch_modulator_test_output16.dat"}},
  {{36385, 52, 0, modulation_scheme::QPSK, modulation_scheme::QPSK, rb_allocation({0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51}, vrb_to_prb_mapping_type::NON_INTERLEAVED), 1, 13, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 2, 441, 1, {}, 0, {0}},{"pdsch_modulator_test_input17.dat"},{"pdsch_modulator_test_output17.dat"}},
  {{12358, 52, 0, modulation_scheme::QPSK, modulation_scheme::QPSK, rb_allocation({0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51}, vrb_to_prb_mapping_type::NON_INTERLEAVED), 1, 13, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 2, 56, 1, {}, 0, {0}},{"pdsch_modulator_test_input18.dat"},{"pdsch_modulator_test_output18.dat"}},
  {{54386, 52, 0, modulation_scheme::QPSK, modulation_scheme::QPSK, rb_allocation({0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51}, vrb_to_prb_mapping_type::NON_INTERLEAVED), 1, 13, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 2, 341, 1, {}, 0, {0}},{"pdsch_modulator_test_input19.dat"},{"pdsch_modulator_test_output19.dat"}},
  {{54704, 52, 0, modulation_scheme::QAM16, modulation_scheme::QAM16, rb_allocation({0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51}, vrb_to_prb_mapping_type::NON_INTERLEAVED), 1, 13, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE1, 2, 961, 1, {}, 0, {0}},{"pdsch_modulator_test_input20.dat"},{"pdsch_modulator_test_output20.dat"}},
  {{14569, 52, 0, modulation_scheme::QAM16, modulation_scheme::QAM16, rb_allocation({0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51}, vrb_to_prb_mapping_type::NON_INTERLEAVED), 1, 13, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 2, 491, 1, {}, 0, {0}},{"pdsch_modulator_test_input21.dat"},{"pdsch_modulator_test_output21.dat"}},
  {{15951, 52, 0, modulation_scheme::QAM16, modulation_scheme::QAM16, rb_allocation({0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51}, vrb_to_prb_mapping_type::NON_INTERLEAVED), 1, 13, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 2, 153, 1, {}, 0, {0}},{"pdsch_modulator_test_input22.dat"},{"pdsch_modulator_test_output22.dat"}},
  {{31693, 52, 0, modulation_scheme::QAM16, modulation_scheme::QAM16, rb_allocation({0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51}, vrb_to_prb_mapping_type::NON_INTERLEAVED), 1, 13, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 2, 733, 1, {}, 0, {0}},{"pdsch_modulator_test_input23.dat"},{"pdsch_modulator_test_output23.dat"}},
  {{4634, 52, 0, modulation_scheme::QAM64, modulation_scheme::QAM64, rb_allocation({0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51}, vrb_to_prb_mapping_type::NON_INTERLEAVED), 1, 13, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE1, 2, 843, 1, {}, 0, {0}},{"pdsch_modulator_test_input24.dat"},{"pdsch_modulator_test_output24.dat"}},
  {{44761, 52, 0, modulation_scheme::QAM64, modulation_scheme::QAM64, rb_allocation({0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51}, vrb_to_prb_mapping_type::NON_INTERLEAVED), 1, 13, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 2, 349, 1, {}, 0, {0}},{"pdsch_modulator_test_input25.dat"},{"pdsch_modulator_test_output25.dat"}},
  {{21000, 52, 0, modulation_scheme::QAM64, modulation_scheme::QAM64, rb_allocation({0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51}, vrb_to_prb_mapping_type::NON_INTERLEAVED), 1, 13, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 2, 331, 1, {}, 0, {0}},{"pdsch_modulator_test_input26.dat"},{"pdsch_modulator_test_output26.dat"}},
  {{40298, 52, 0, modulation_scheme::QAM64, modulation_scheme::QAM64, rb_allocation({0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51}, vrb_to_prb_mapping_type::NON_INTERLEAVED), 1, 13, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 2, 2, 1, {}, 0, {0}},{"pdsch_modulator_test_input27.dat"},{"pdsch_modulator_test_output27.dat"}},
  {{32479, 52, 0, modulation_scheme::QAM256, modulation_scheme::QAM256, rb_allocation({0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51}, vrb_to_prb_mapping_type::NON_INTERLEAVED), 1, 13, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE1, 2, 793, 1, {}, 0, {0}},{"pdsch_modulator_test_input28.dat"},{"pdsch_modulator_test_output28.dat"}},
  {{46508, 52, 0, modulation_scheme::QAM256, modulation_scheme::QAM256, rb_allocation({0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51}, vrb_to_prb_mapping_type::NON_INTERLEAVED), 1, 13, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 2, 776, 1, {}, 0, {0}},{"pdsch_modulator_test_input29.dat"},{"pdsch_modulator_test_output29.dat"}},
  {{5472, 52, 0, modulation_scheme::QAM256, modulation_scheme::QAM256, rb_allocation({0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51}, vrb_to_prb_mapping_type::NON_INTERLEAVED), 1, 13, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 2, 125, 1, {}, 0, {0}},{"pdsch_modulator_test_input30.dat"},{"pdsch_modulator_test_output30.dat"}},
  {{21344, 52, 0, modulation_scheme::QAM256, modulation_scheme::QAM256, rb_allocation({0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51}, vrb_to_prb_mapping_type::NON_INTERLEAVED), 1, 13, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 2, 154, 1, {}, 0, {0}},{"pdsch_modulator_test_input31.dat"},{"pdsch_modulator_test_output31.dat"}},
  {{8791, 52, 0, modulation_scheme::QPSK, modulation_scheme::QPSK, rb_allocation({0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51}, vrb_to_prb_mapping_type::NON_INTERLEAVED), 2, 12, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE1, 2, 73, 1, {}, 0, {0}},{"pdsch_modulator_test_input32.dat"},{"pdsch_modulator_test_output32.dat"}},
  {{39869, 52, 0, modulation_scheme::QPSK, modulation_scheme::QPSK, rb_allocation({0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51}, vrb_to_prb_mapping_type::NON_INTERLEAVED), 2, 12, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 2, 248, 1, {}, 0, {0}},{"pdsch_modulator_test_input33.dat"},{"pdsch_modulator_test_output33.dat"}},
  {{16424, 52, 0, modulation_scheme::QPSK, modulation_scheme::QPSK, rb_allocation({0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51}, vrb_to_prb_mapping_type::NON_INTERLEAVED), 2, 12, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 2, 499, 1, {}, 0, {0}},{"pdsch_modulator_test_input34.dat"},{"pdsch_modulator_test_output34.dat"}},
  {{51251, 52, 0, modulation_scheme::QPSK, modulation_scheme::QPSK, rb_allocation({0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51}, vrb_to_prb_mapping_type::NON_INTERLEAVED), 2, 12, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 2, 14, 1, {}, 0, {0}},{"pdsch_modulator_test_input35.dat"},{"pdsch_modulator_test_output35.dat"}},
  {{20559, 52, 0, modulation_scheme::QAM16, modulation_scheme::QAM16, rb_allocation({0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51}, vrb_to_prb_mapping_type::NON_INTERLEAVED), 2, 12, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE1, 2, 781, 1, {}, 0, {0}},{"pdsch_modulator_test_input36.dat"},{"pdsch_modulator_test_output36.dat"}},
  {{55719, 52, 0, modulation_scheme::QAM16, modulation_scheme::QAM16, rb_allocation({0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51}, vrb_to_prb_mapping_type::NON_INTERLEAVED), 2, 12, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 2, 875, 1, {}, 0, {0}},{"pdsch_modulator_test_input37.dat"},{"pdsch_modulator_test_output37.dat"}},
  {{3650, 52, 0, modulation_scheme::QAM16, modulation_scheme::QAM16, rb_allocation({0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51}, vrb_to_prb_mapping_type::NON_INTERLEAVED), 2, 12, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 2, 984, 1, {}, 0, {0}},{"pdsch_modulator_test_input38.dat"},{"pdsch_modulator_test_output38.dat"}},
  {{31907, 52, 0, modulation_scheme::QAM16, modulation_scheme::QAM16, rb_allocation({0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51}, vrb_to_prb_mapping_type::NON_INTERLEAVED), 2, 12, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 2, 650, 1, {}, 0, {0}},{"pdsch_modulator_test_input39.dat"},{"pdsch_modulator_test_output39.dat"}},
  {{31165, 52, 0, modulation_scheme::QAM64, modulation_scheme::QAM64, rb_allocation({0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51}, vrb_to_prb_mapping_type::NON_INTERLEAVED), 2, 12, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE1, 2, 237, 1, {}, 0, {0}},{"pdsch_modulator_test_input40.dat"},{"pdsch_modulator_test_output40.dat"}},
  {{16431, 52, 0, modulation_scheme::QAM64, modulation_scheme::QAM64, rb_allocation({0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51}, vrb_to_prb_mapping_type::NON_INTERLEAVED), 2, 12, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 2, 22, 1, {}, 0, {0}},{"pdsch_modulator_test_input41.dat"},{"pdsch_modulator_test_output41.dat"}},
  {{38966, 52, 0, modulation_scheme::QAM64, modulation_scheme::QAM64, rb_allocation({0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51}, vrb_to_prb_mapping_type::NON_INTERLEAVED), 2, 12, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 2, 981, 1, {}, 0, {0}},{"pdsch_modulator_test_input42.dat"},{"pdsch_modulator_test_output42.dat"}},
  {{52230, 52, 0, modulation_scheme::QAM64, modulation_scheme::QAM64, rb_allocation({0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51}, vrb_to_prb_mapping_type::NON_INTERLEAVED), 2, 12, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 2, 657, 1, {}, 0, {0}},{"pdsch_modulator_test_input43.dat"},{"pdsch_modulator_test_output43.dat"}},
  {{56114, 52, 0, modulation_scheme::QAM256, modulation_scheme::QAM256, rb_allocation({0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51}, vrb_to_prb_mapping_type::NON_INTERLEAVED), 2, 12, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE1, 2, 198, 1, {}, 0, {0}},{"pdsch_modulator_test_input44.dat"},{"pdsch_modulator_test_output44.dat"}},
  {{28603, 52, 0, modulation_scheme::QAM256, modulation_scheme::QAM256, rb_allocation({0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51}, vrb_to_prb_mapping_type::NON_INTERLEAVED), 2, 12, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 2, 260, 1, {}, 0, {0}},{"pdsch_modulator_test_input45.dat"},{"pdsch_modulator_test_output45.dat"}},
  {{20136, 52, 0, modulation_scheme::QAM256, modulation_scheme::QAM256, rb_allocation({0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51}, vrb_to_prb_mapping_type::NON_INTERLEAVED), 2, 12, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 2, 455, 1, {}, 0, {0}},{"pdsch_modulator_test_input46.dat"},{"pdsch_modulator_test_output46.dat"}},
  {{14667, 52, 0, modulation_scheme::QAM256, modulation_scheme::QAM256, rb_allocation({0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51}, vrb_to_prb_mapping_type::NON_INTERLEAVED), 2, 12, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 2, 468, 1, {}, 0, {0}},{"pdsch_modulator_test_input47.dat"},{"pdsch_modulator_test_output47.dat"}},
    // clang-format on
};

} // namespace srsgnb

#endif // SRSGNB_UNITTESTS_PHY_UPPER_CHANNEL_PROCESSORS_PDSCH_MODULATOR_TEST_DATA_H