/*
 *
 * Copyright 2021-2023 Software Radio Systems Limited
 *
 * By using this file, you agree to the terms and conditions set
 * forth in the LICENSE file which can be found at the top level of
 * the distribution.
 *
 */

#pragma once

#include "../ue_manager_impl.h"
#include "srsran/cu_cp/du_processor.h"
#include "srsran/support/async/async_task.h"
#include "srsran/support/async/async_task_loop.h"

namespace srsran {
namespace srs_cu_cp {

/// \brief Service provided by DU Processor to handle routines.
class du_processor_routine_manager
{
public:
  explicit du_processor_routine_manager(du_processor_e1ap_control_notifier&    e1ap_ctrl_notifier_,
                                        du_processor_f1ap_ue_context_notifier& f1ap_ue_ctxt_notifier_,
                                        du_processor_rrc_du_ue_notifier&       rrc_du_notifier_,
                                        du_processor_ue_manager&               ue_manager_,
                                        srslog::basic_logger&                  logger_);
  ~du_processor_routine_manager() = default;

  async_task<cu_cp_pdu_session_resource_setup_response>
  start_pdu_session_resource_setup_routine(const cu_cp_pdu_session_resource_setup_request& setup_msg,
                                           const srsran::security::sec_as_config&          security_cfg,
                                           du_processor_rrc_ue_control_message_notifier&   rrc_ue_ctrl_notifier,
                                           up_resource_manager&                            rrc_ue_up_resource_manager);

  async_task<cu_cp_pdu_session_resource_release_response>
  start_pdu_session_resource_release_routine(const cu_cp_pdu_session_resource_release_command& release_cmd,
                                             up_resource_manager& rrc_ue_up_resource_manager);

  async_task<cu_cp_pdu_session_resource_modify_response>
  start_pdu_session_resource_modification_routine(const cu_cp_pdu_session_resource_modify_request& modify_msg,
                                                  up_resource_manager& rrc_ue_up_resource_manager);

  async_task<void> start_ue_context_release_routine(const cu_cp_ue_context_release_command& command);

private:
  du_processor_e1ap_control_notifier&    e1ap_ctrl_notifier;
  du_processor_f1ap_ue_context_notifier& f1ap_ue_ctxt_notifier;
  du_processor_rrc_du_ue_notifier&       rrc_du_notifier;
  du_processor_ue_manager&               ue_manager;
  srslog::basic_logger&                  logger;
};

} // namespace srs_cu_cp
} // namespace srsran
