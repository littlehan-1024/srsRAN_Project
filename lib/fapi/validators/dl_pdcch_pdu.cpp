/*
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

#include "dl_pdcch_pdu.h"
#include "helpers.h"
#include "srsgnb/fapi/messages.h"
#include "srsgnb/fapi/validator_report.h"

using namespace srsgnb;
using namespace fapi;

/// This validator checks the PDCCH PDU.
static constexpr dl_pdu_type pdu_type = dl_pdu_type::PDCCH;

/// Validates the CORESET BWP size property of the PDCCH PDU, as per SCF-222 v4.0 section 3.4.2.1.
static bool validate_coreset_bwp_size(unsigned value, validator_report& report)
{
  static constexpr unsigned MIN_VALUE = 1;
  static constexpr unsigned MAX_VALUE = 275;

  return validate_field(MIN_VALUE, MAX_VALUE, value, "CORESET BWP size", pdu_type, report);
}

/// Validates the CORESET BWP start property of the PDCCH PDU, as per SCF-222 v4.0 section 3.4.2.1.
static bool validate_coreset_bwp_start(unsigned value, validator_report& report)
{
  static constexpr unsigned MIN_VALUE = 0;
  static constexpr unsigned MAX_VALUE = 274;

  return validate_field(MIN_VALUE, MAX_VALUE, value, "CORESET BWP start", pdu_type, report);
}

/// Validates the subcarrier spacing property of the PDCCH PDU, as per SCF-222 v4.0 section 3.4.2.1.
static bool validate_scs(unsigned value, validator_report& report)
{
  static constexpr unsigned MIN_VALUE = 0;
  static constexpr unsigned MAX_VALUE = 4;

  return validate_field(MIN_VALUE, MAX_VALUE, value, "Subcarrier spacing", pdu_type, report);
}

/// Validates the cyclic prefix property of the PDCCH PDU, as per SCF-222 v4.0 section 3.4.2.1.
static bool validate_cp(unsigned value, validator_report& report)
{
  static constexpr unsigned MIN_VALUE = 0;
  static constexpr unsigned MAX_VALUE = 1;

  return validate_field(MIN_VALUE, MAX_VALUE, value, "Cyclic prefix", pdu_type, report);
}

/// Validates the duration symbols property of the PDCCH PDU, as per SCF-222 v4.0 section 3.4.2.1.
static bool validate_start_symbol_index(unsigned value, validator_report& report)
{
  static constexpr unsigned MIN_VALUE = 0;
  static constexpr unsigned MAX_VALUE = 13;

  return validate_field(MIN_VALUE, MAX_VALUE, value, "Start symbol index", pdu_type, report);
}

/// Validates the duration symbols property of the PDCCH PDU, as per SCF-222 v4.0 section 3.4.2.1.
static bool validate_duration_symbols(unsigned value, validator_report& report)
{
  static constexpr unsigned MIN_VALUE = 1;
  static constexpr unsigned MAX_VALUE = 3;

  return validate_field(MIN_VALUE, MAX_VALUE, value, "Duration symbols", pdu_type, report);
}

/// Validates the CCE to REG mapping type property of the PDCCH PDU, as per SCF-222 v4.0 section 3.4.2.1.
static bool validate_cce_reg_mapping_type(unsigned value, validator_report& report)
{
  static constexpr unsigned MIN_VALUE = 0;
  static constexpr unsigned MAX_VALUE = 1;

  return validate_field(MIN_VALUE, MAX_VALUE, value, "CCE to REG mapping type", pdu_type, report);
}

/// Validates the REG bundle size property of the PDCCH PDU, as per SCF-222 v4.0 section 3.4.2.1.
static bool validate_reg_bundle_size(unsigned value, validator_report& report)
{
  if (value == 2 || value == 3 || value == 6) {
    return true;
  }

  report.append(value, "REG bundle size", pdu_type);
  return false;
}

/// Validates the interleaver size property of the PDCCH PDU, as per SCF-222 v4.0 section 3.4.2.1.
static bool validate_interleaver_size(unsigned value, validator_report& report)
{
  if (value == 2 || value == 3 || value == 6) {
    return true;
  }

  report.append(value, "Interleaver size", pdu_type);
  return false;
}

/// Validates the CORESET type property of the PDCCH PDU, as per SCF-222 v4.0 section 3.4.2.1.
static bool validate_coreset_type(unsigned value, validator_report& report)
{
  static constexpr unsigned MIN_VALUE = 0;
  static constexpr unsigned MAX_VALUE = 1;

  return validate_field(MIN_VALUE, MAX_VALUE, value, "CORESET type", pdu_type, report);
}

/// Validates the shift index property of the PDCCH PDU, as per SCF-222 v4.0 section 3.4.2.1.
static bool validate_shift_index(unsigned value, pdcch_coreset_type coreset_type, validator_report& report)
{
  if (coreset_type == pdcch_coreset_type::pbch_or_sib1) {
    static constexpr unsigned MIN_VALUE = 0;
    static constexpr unsigned MAX_VALUE = 1023;

    return validate_field(MIN_VALUE, MAX_VALUE, value, "Shift index - PBCH or SIB1", pdu_type, report);
  }

  static constexpr unsigned MIN_VALUE = 0;
  static constexpr unsigned MAX_VALUE = 275;

  return validate_field(MIN_VALUE, MAX_VALUE, value, "Shift index - Other", pdu_type, report);
}

/// Validates the precoder granularity property of the PDCCH PDU, as per SCF-222 v4.0 section 3.4.2.1.
static bool validate_precoder_granularity(unsigned value, validator_report& report)
{
  static constexpr unsigned MIN_VALUE = 0;
  static constexpr unsigned MAX_VALUE = 1;

  return validate_field(MIN_VALUE, MAX_VALUE, value, "Precoder granularity", pdu_type, report);
}

/// Validates the RNTI property of the PDCCH PDU, as per SCF-222 v4.0 section 3.4.2.1.
static bool validate_rnti(unsigned value, validator_report& report)
{
  static constexpr unsigned MIN_VALUE = 1;
  static constexpr unsigned MAX_VALUE = 65535;

  return validate_field(MIN_VALUE, MAX_VALUE, value, "RNTI", pdu_type, report);
}

/// Validates the CCE index property of the PDCCH PDU, as per SCF-222 v4.0 section 3.4.2.1.
static bool validate_cce_index(unsigned value, validator_report& report)
{
  static constexpr unsigned MIN_VALUE = 0;
  static constexpr unsigned MAX_VALUE = 135;

  return validate_field(MIN_VALUE, MAX_VALUE, value, "CCE index", pdu_type, report);
}

/// Validates the aggregation level property of the PDCCH PDU, as per SCF-222 v4.0 section 3.4.2.1.
static bool validate_aggregation_level(unsigned value, validator_report& report)
{
  if (value == 1U || value == 2U || value == 4U || value == 8U || value == 16U) {
    return true;
  }

  report.append(value, "Aggregation level", pdu_type);
  return false;
}

/// Validates the power control offset SS profile NR and the PDCCH DMRS power offset profile SSS properties of the PDCCH
/// PDU, as per SCF-222 v4.0 section 3.4.2.1.
static bool validate_power_control_offset_profile_nr(int               power_control_offset_ss_profile_nr,
                                                     int               dmrs_power_profile_sss,
                                                     validator_report& report)
{
  static constexpr int USE_PROFILE_SSS       = -127;
  static constexpr int MIN_VALUE_PROFILE_NR  = -8;
  static constexpr int MAX_VALUE_PROFILE_NR  = 8;
  static constexpr int USE_PROFILE_NR        = -32768;
  static constexpr int MIN_VALUE_PROFILE_SSS = -32767;
  static constexpr int MAX_VALUE_PROFILE_SSS = 32767;

  if (power_control_offset_ss_profile_nr == USE_PROFILE_SSS && MIN_VALUE_PROFILE_SSS <= dmrs_power_profile_sss &&
      dmrs_power_profile_sss <= MAX_VALUE_PROFILE_SSS) {
    return true;
  }

  if (dmrs_power_profile_sss == USE_PROFILE_NR && MIN_VALUE_PROFILE_NR <= power_control_offset_ss_profile_nr &&
      power_control_offset_ss_profile_nr <= MAX_VALUE_PROFILE_NR) {
    return true;
  }

  report.append(dmrs_power_profile_sss, "DMRS Power offset", pdu_type);
  return false;
}

bool srsgnb::fapi::validate_dl_pdcch_pdu(const dl_pdcch_pdu& pdu, validator_report& report)
{
  bool result = true;

  result &= validate_coreset_bwp_size(pdu.coreset_bwp_size, report);
  result &= validate_coreset_bwp_start(pdu.coreset_bwp_start, report);
  result &= validate_scs(static_cast<unsigned>(pdu.scs), report);
  result &= validate_cp(static_cast<unsigned>(pdu.cyclic_prefix), report);
  result &= validate_start_symbol_index(pdu.start_symbol_index, report);
  result &= validate_duration_symbols(pdu.duration_symbols, report);
  result &= validate_cce_reg_mapping_type(static_cast<unsigned>(pdu.cce_reg_mapping_type), report);
  result &= validate_reg_bundle_size(pdu.reg_bundle_size, report);
  result &= validate_interleaver_size(pdu.interleaver_size, report);
  result &= validate_coreset_type(static_cast<unsigned>(pdu.coreset_type), report);
  if (pdu.cce_reg_mapping_type == cce_to_reg_mapping_type::interleaved) {
    result &= validate_shift_index(pdu.shift_index, pdu.coreset_type, report);
  }
  result &= validate_precoder_granularity(static_cast<unsigned>(pdu.precoder_granularity), report);

  // Validate DL DCIs.
  for (unsigned i = 0, e = pdu.dl_dci.size(); i != e; ++i) {
    const auto& dci    = pdu.dl_dci[i];
    const auto& dci_v3 = pdu.maintenance_v3.info[0];

    result &= validate_rnti(static_cast<unsigned>(dci.rnti), report);
    // NOTE: N-Id PDCCH data field uses the whole range of the variable, so it will not be checked.
    // NOTE: N-RNTI PDCCH data field uses the whole range of the variable, so it will not be checked.
    result &= validate_cce_index(dci.cce_index, report);
    result &= validate_aggregation_level(dci.aggregation_level, report);
    result &= validate_power_control_offset_profile_nr(
        dci.power_control_offset_ss_profile_nr, dci_v3.pdcch_dmrs_power_offset_profile_sss, report);
    // NOTE: PDCCH Data power offset profile NR uses the whole range of the variable, so it will not be checked.
    // NOTE: DCI index uses the whole range of the variable, so it will not be checked.
    // NOTE: Collocated AL-16 candidate uses the whole range of the variable, so it will not be checked.
    // NOTE: N-ID uses the whole range of the variable, sso it will not be checked.
  }

  return result;
}
