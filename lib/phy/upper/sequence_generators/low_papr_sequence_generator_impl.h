/*
 *
 * Copyright 2013-2022 Software Radio Systems Limited
 *
 * By using this file, you agree to the terms and conditions set
 * forth in the LICENSE file which can be found at the top level of
 * the distribution.
 *
 */

#pragma once

#include "srsgnb/phy/upper/sequence_generators/low_papr_sequence_generator.h"

namespace srsgnb {

/// \brief Describes a generic low PAPR sequence generation implementation.
///
/// \attention This generic class implementation is not optimized for real-time execution.
class low_papr_sequence_generator_impl : public low_papr_sequence_generator
{
private:
  /// Defines the maximum number of short sequences.
  static constexpr unsigned NOF_ZC_SEQ = 30;

  /// Defines Phi values for M_sc=6 Table 5.2.2.2-1 in TS 38.211.
  static const std::array<std::array<float, 6>, NOF_ZC_SEQ> phi_M_sc_6;

  /// Defines Phi values for M_sc=12 Table 5.2.2.2-2 in TS 38.211.
  static const std::array<std::array<float, 12>, NOF_ZC_SEQ> phi_M_sc_12;

  /// Defines Phi values for M_sc=18 Table 5.2.2.2-3 in TS 38.211.
  static const std::array<std::array<float, 18>, NOF_ZC_SEQ> phi_M_sc_18;

  /// Defines Phi values for M_sc=24 Table 5.2.2.2-4 in TS 38.211.
  static const std::array<std::array<float, 24>, NOF_ZC_SEQ> phi_M_sc_24;

  /// \brief Generates argument for the sequence \f$r^{(\alpha, \beta)}_{u,v}(n)\f$ for base sequences of length 6.
  ///
  /// \param[out] tmp_arg Argument generation destination.
  /// \param[in] u Indicates the sequence group index {0,29}.
  static void r_uv_arg_0dot5prb(span<float> tmp_arg, unsigned u);

  /// \brief Generates argument for the sequence \f$r^{(\alpha, \beta)}_{u,v}(n)\f$ for base sequences of length 12.
  ///
  /// \param[out] tmp_arg Argument generation destination.
  /// \param[in] u Indicates the sequence group index {0,29}.
  static void r_uv_arg_1prb(span<float> tmp_arg, unsigned u);

  /// \brief Generates argument for the sequence \f$r^{(\alpha, \beta)}_{u,v}(n)\f$ for base sequences of length 18.
  ///
  /// \param[out] tmp_arg Argument generation destination.
  /// \param[in] u Indicates the sequence group index {0,29}.
  static void r_uv_arg_1dot5prb(span<float> tmp_arg, unsigned u);

  /// \brief Generates argument for the sequence \f$r^{(\alpha, \beta)}_{u,v}(n)\f$ for base sequences of length 24.
  ///
  /// \param[out] tmp_arg Argument generation destination.
  /// \param[in] u Indicates the sequence group index {0,29}.
  static void r_uv_arg_2prb(span<float> tmp_arg, unsigned u);

  /// \brief Generates argument for the sequence \f$r^{(\alpha, \beta)}_{u,v}(n)\f$ for base sequences of length 36 or
  /// larger.
  ///
  /// \param[out] tmp_arg Argument generation destination.
  /// \param[in] u Indicates the sequence group index {0,29}.
  /// \param[in] v Indicates the sequence base index {0,1}.
  static void r_uv_arg_mprb(span<float> tmp_arg, unsigned u, unsigned v);

  /// \brief Generates argument for the sequence \f$r^{(\alpha, \beta)}_{u,v}(n)\f$.
  ///
  /// \param[out] tmp_arg Argument generation destination.
  /// \param[in] u Indicates the sequence group index {0,29}.
  /// \param[in] v Indicates the sequence base index {0,1}.
  static void r_uv_arg(span<float> tmp_arg, unsigned u, unsigned v);

  /// \brief Generates sequence \f$r^{(\alpha, \beta)}_{u,v}(n) = e^{-j (temp_arg[n] + \alpha \times n)  }\f$
  /// \param[out] sequence Sequence generation destination.
  /// \param[in] alpha Provides parameter \f$\alpha\f$.
  /// \param[in] tmp_arg Provides the complex exponential argument.
  static void cexp(span<cf_t> sequence, float alpha, const span<const float> tmp_arg);

public:
  // See interface for documentation.
  void generate(span<cf_t> sequence, unsigned u, unsigned v, float alpha) const override;
};

} // namespace srsgnb
