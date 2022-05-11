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

#ifndef SRSGNB_DU_HIGH_EXECUTOR_STRATEGIES_H
#define SRSGNB_DU_HIGH_EXECUTOR_STRATEGIES_H

#include "srsgnb/adt/circular_array.h"
#include "srsgnb/adt/span.h"
#include "srsgnb/du_high/du_l2_dl_executor_mapper.h"
#include "srsgnb/du_high/du_l2_ul_executor_mapper.h"

namespace srsgnb {

/// L2 UL executor mapper that maps UEs based on their RNTI.
class ue_index_based_ul_executor_mapper final : public du_l2_ul_executor_mapper
{
public:
  ue_index_based_ul_executor_mapper(span<task_executor*> execs_) : execs(execs_.begin(), execs_.end()) {}

  task_executor& rebind_executor(du_ue_index_t ue_index, du_cell_index_t pcell_index) override
  {
    // Static lookup
    srsran_sanity_check(is_du_ue_index_valid(ue_index), "Invalid ueId={}", ue_index);
    return executor(ue_index);
  }

  task_executor& executor(du_ue_index_t ue_index) override
  {
    ue_index = ue_index < MAX_NOF_DU_UES ? ue_index : to_du_ue_index(0);
    return *execs[ue_index % execs.size()];
  }

private:
  std::vector<task_executor*> execs;
};

/// L2 UL executor mapper that maps UEs based on their PCell.
class pcell_ul_executor_mapper final : public du_l2_ul_executor_mapper
{
public:
  explicit pcell_ul_executor_mapper(const std::initializer_list<task_executor*>& execs_) :
    execs(execs_.begin(), execs_.end())
  {
    // Initialize executors in a round-robin fashion.
    unsigned count = 0;
    for (auto& rnti_exec : ue_idx_to_exec) {
      rnti_exec = execs[count % execs.size()];
      count++;
    }
  }

  task_executor& rebind_executor(du_ue_index_t ue_index, du_cell_index_t pcell_index) override
  {
    srsran_sanity_check(is_du_ue_index_valid(ue_index), "Invalid ueId={}", ue_index);
    ue_idx_to_exec[ue_index] = execs[pcell_index % execs.size()];
    return *ue_idx_to_exec[ue_index];
  }

  task_executor& executor(du_ue_index_t ue_index) override
  {
    ue_index = ue_index < MAX_NOF_DU_UES ? ue_index : to_du_ue_index(0);
    return *ue_idx_to_exec[ue_index];
  }

private:
  std::vector<task_executor*>                execs;
  std::array<task_executor*, MAX_NOF_DU_UES> ue_idx_to_exec;
};

/// Dispatch DL tasks based on cell index.
class cell_dl_executor_mapper final : public du_l2_dl_executor_mapper
{
public:
  explicit cell_dl_executor_mapper(const std::initializer_list<task_executor*>& execs_) :
    dl_execs(execs_.begin(), execs_.end())
  {
    srsran_assert(not dl_execs.empty(), "The number of DL executors must be higher than 1");
  }

  task_executor& executor(du_cell_index_t cell_index) override { return *dl_execs[cell_index % dl_execs.size()]; }

private:
  std::vector<task_executor*> dl_execs;
};

} // namespace srsgnb

#endif // SRSGNB_DU_HIGH_EXECUTOR_STRATEGIES_H
