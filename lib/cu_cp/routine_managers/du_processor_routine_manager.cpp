/*
 *
 * Copyright 2021-2023 Software Radio Systems Limited
 *
 * By using this file, you agree to the terms and conditions set
 * forth in the LICENSE file which can be found at the top level of
 * the distribution.
 *
 */

#include "du_processor_routine_manager.h"
#include "../routines/mobility/inter_du_handover_routine.h"
#include "../routines/pdu_session_resource_modification_routine.h"
#include "../routines/pdu_session_resource_release_routine.h"
#include "../routines/pdu_session_resource_setup_routine.h"
#include "../routines/reestablishment_context_modification_routine.h"
#include "../routines/ue_context_release_routine.h"
#include "srsran/support/async/coroutine.h"

using namespace srsran;
using namespace srs_cu_cp;

du_processor_routine_manager::du_processor_routine_manager(
    du_processor_e1ap_control_notifier&    e1ap_ctrl_notifier_,
    du_processor_f1ap_ue_context_notifier& f1ap_ue_ctxt_notifier_,
    du_processor_rrc_du_ue_notifier&       rrc_du_notifier_,
    du_processor_ue_manager&               ue_manager_,
    srslog::basic_logger&                  logger_) :
  e1ap_ctrl_notifier(e1ap_ctrl_notifier_),
  f1ap_ue_ctxt_notifier(f1ap_ue_ctxt_notifier_),
  rrc_du_notifier(rrc_du_notifier_),
  ue_manager(ue_manager_),
  logger(logger_)
{
}

async_task<cu_cp_pdu_session_resource_setup_response>
du_processor_routine_manager::start_pdu_session_resource_setup_routine(
    const cu_cp_pdu_session_resource_setup_request& setup_msg,
    const srsran::security::sec_as_config&          security_cfg,
    du_processor_rrc_ue_control_message_notifier&   rrc_ue_ctrl_notifier,
    up_resource_manager&                            rrc_ue_up_resource_manager)
{
  return launch_async<pdu_session_resource_setup_routine>(setup_msg,
                                                          ue_manager.get_ue_config(),
                                                          security_cfg,
                                                          e1ap_ctrl_notifier,
                                                          f1ap_ue_ctxt_notifier,
                                                          rrc_ue_ctrl_notifier,
                                                          rrc_ue_up_resource_manager,
                                                          logger);
}

async_task<cu_cp_pdu_session_resource_modify_response>
du_processor_routine_manager::start_pdu_session_resource_modification_routine(
    const cu_cp_pdu_session_resource_modify_request& modify_msg,
    du_processor_rrc_ue_control_message_notifier&    rrc_ue_ctrl_notifier,
    up_resource_manager&                             rrc_ue_up_resource_manager)
{
  return launch_async<pdu_session_resource_modification_routine>(
      modify_msg, e1ap_ctrl_notifier, f1ap_ue_ctxt_notifier, rrc_ue_ctrl_notifier, rrc_ue_up_resource_manager, logger);
}

async_task<cu_cp_pdu_session_resource_release_response>
du_processor_routine_manager::start_pdu_session_resource_release_routine(
    const cu_cp_pdu_session_resource_release_command& release_cmd,
    up_resource_manager&                              rrc_ue_up_resource_manager)
{
  return launch_async<pdu_session_resource_release_routine>(
      release_cmd, e1ap_ctrl_notifier, f1ap_ue_ctxt_notifier, rrc_ue_up_resource_manager, logger);
}

async_task<void>
du_processor_routine_manager::start_ue_context_release_routine(const rrc_ue_context_release_command& command,
                                                               up_resource_manager& ue_up_resource_manager)
{
  return launch_async<ue_context_release_routine>(
      command, e1ap_ctrl_notifier, f1ap_ue_ctxt_notifier, rrc_du_notifier, ue_manager, ue_up_resource_manager, logger);
}

async_task<bool> du_processor_routine_manager::start_reestablishment_context_modification_routine(
    ue_index_t                                    ue_index,
    du_processor_rrc_ue_control_message_notifier& rrc_ue_ctrl_notifier,
    up_resource_manager&                          ue_up_resource_manager)
{
  return launch_async<reestablishment_context_modification_routine>(
      ue_index, e1ap_ctrl_notifier, f1ap_ue_ctxt_notifier, rrc_ue_ctrl_notifier, ue_up_resource_manager, logger);
}

async_task<cu_cp_inter_du_handover_response> du_processor_routine_manager::start_inter_du_handover_routine(
    const cu_cp_inter_du_handover_request&        command,
    du_processor_f1ap_ue_context_notifier&        target_du_f1ap_ue_ctxt_notifier,
    du_processor_rrc_ue_control_message_notifier& rrc_ue_ctrl_notifier,
    up_resource_manager&                          ue_up_resource_manager)
{
  return launch_async<inter_du_handover_routine>(command,
                                                 f1ap_ue_ctxt_notifier,
                                                 target_du_f1ap_ue_ctxt_notifier,
                                                 e1ap_ctrl_notifier,
                                                 ue_manager,
                                                 ue_up_resource_manager,
                                                 logger);
}
