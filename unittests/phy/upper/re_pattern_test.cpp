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

#include "srsgnb/phy/cyclic_prefix.h"
#include "srsgnb/phy/upper/re_pattern.h"
#include "srsgnb/support/srsgnb_test.h"

using namespace srsgnb;

// Tests that two patterns with subcarrier mask in common are merged into one.
void test_merge_1()
{
  unsigned rb_begin  = 1;
  unsigned rb_end    = 50;
  unsigned rb_stride = 50;

  re_pattern_list list;

  // Reset list.
  list.clear();

  // Create first pattern containing:
  // - even subcarrier indexes, and
  // - even symbol indexes.
  re_pattern pattern_1 = {};
  pattern_1.rb_begin   = rb_begin;
  pattern_1.rb_end     = rb_end;
  pattern_1.rb_stride  = rb_stride;
  for (unsigned k = 0; k != NRE; ++k) {
    pattern_1.re_mask[k] = (k % 2 == 0);
  }
  for (unsigned l = 0; l != MAX_NSYMB_PER_SLOT; ++l) {
    pattern_1.symbols[l] = (l % 2 == 0);
  }
  list.merge(pattern_1);
  TESTASSERT_EQ(list.get_nof_entries(), 1);

  // Create second pattern:
  // - Even subcarrier indexes, and
  // - odd symbol indexes.
  re_pattern pattern_2 = pattern_1;
  for (unsigned l = 0; l != MAX_NSYMB_PER_SLOT; ++l) {
    pattern_2.symbols[l] = (l % 2 == 1); // Only odd symbols
  }
  list.merge(pattern_2);
  TESTASSERT_EQ(list.get_nof_entries(), 1);

  // The pattern should be repeated for each symbol.
  for (unsigned l = 0; l != MAX_NSYMB_PER_SLOT; ++l) {
    // Create mask with all entries to false
    std::array<bool, MAX_RB* NRE> mask = {};

    // Set include mask.
    list.get_inclusion_mask(mask, l);

    // For each subcarrier it checks the mask.
    for (unsigned k = 0; k != MAX_RB * NRE; ++k) {
      bool gold = false;

      // if it is in the RB range, then check the subcarrier index.
      if (k >= rb_begin * NRE && k < rb_end * NRE && (k / NRE - rb_begin) % rb_stride == 0) {
        // Even subcarrier
        gold = (k % 2 == 0);
      }
      TESTASSERT_EQ(mask[k], gold);
    }

    // Set exclude.
    list.get_exclusion_mask(mask, l);

    // All the subcarriers shall be false.
    for (unsigned k = 0; k != MAX_RB * NRE; ++k) {
      TESTASSERT(!mask[k]);
    }
  }
}

// Tests that two patterns with symbol mask in common are merged into one.
void test_merge_2()
{
  unsigned rb_begin  = 1;
  unsigned rb_end    = 50;
  unsigned rb_stride = 50;

  re_pattern_list list;

  // Reset list.
  list.clear();

  // Create first pattern containing:
  // - even subcarrier indexes, and
  // - even symbol indexes.
  re_pattern pattern_1 = {};
  pattern_1.rb_begin   = rb_begin;
  pattern_1.rb_end     = rb_end;
  pattern_1.rb_stride  = rb_stride;
  for (unsigned k = 0; k != NRE; ++k) {
    pattern_1.re_mask[k] = (k % 2 == 0);
  }
  for (unsigned l = 0; l != MAX_NSYMB_PER_SLOT; ++l) {
    pattern_1.symbols[l] = (l % 2 == 0);
  }
  list.merge(pattern_1);
  TESTASSERT(list.get_nof_entries() == 1);

  // Create second pattern:
  // - odd subcarrier indexes, and
  // - even symbol indexes.
  re_pattern pattern_2 = pattern_1;
  for (unsigned k = 0; k != NRE; ++k) {
    pattern_2.re_mask[k] = (k % 2 == 1);
  }
  list.merge(pattern_2);
  TESTASSERT(list.get_nof_entries() == 1);

  // The pattern should be repeated for each symbol.
  for (unsigned l = 0; l != MAX_NSYMB_PER_SLOT; ++l) {
    // Create mask with all entries to false
    std::array<bool, MAX_RB* NRE> mask = {};

    // Set include mask.
    list.get_inclusion_mask(mask, l);

    // For each subcarrier it checks the mask.
    for (unsigned k = 0; k != MAX_RB * NRE; ++k) {
      bool gold = false;

      // if it is in the RB range, then check the subcarrier index.
      if (k >= rb_begin * NRE && k < rb_end * NRE && (k / NRE - rb_begin) % rb_stride == 0) {
        // Even subcarrier
        gold = (l % 2 == 0);
      }
      TESTASSERT_EQ(mask[k], gold);
    }

    // Set exclude.
    list.get_exclusion_mask(mask, l);

    // All the subcarriers shall be false.
    for (unsigned k = 0; k != MAX_RB * NRE; ++k) {
      TESTASSERT(!mask[k]);
    }
  }
}

int main()
{
  test_merge_1();
  test_merge_2();
  return 0;
}