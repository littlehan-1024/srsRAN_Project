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

#include "srsgnb/fapi/slot_data_message_notifier.h"
#include "srsgnb/srslog/srslog.h"

namespace srsgnb {
namespace fapi {

class logging_slot_data_notifier_decorator : public slot_data_message_notifier
{
public:
  logging_slot_data_notifier_decorator(srslog::basic_logger& logger, slot_data_message_notifier& notifier) :
    logger(logger), notifier(notifier)
  {
  }

  // See interface for documentation.
  void on_dl_tti_response(const dl_tti_response_message& msg) override;

  // See interface for documentation.
  void on_rx_data_indication(const rx_data_indication_message& msg) override;

  // See interface for documentation.
  void on_crc_indication(const crc_indication_message& msg) override;

  // See interface for documentation.
  void on_uci_indication(const uci_indication_message& msg) override;

  // See interface for documentation.
  void on_srs_indication(const srs_indication_message& msg) override;

  // See interface for documentation.
  void on_rach_indication(const rach_indication_message& msg) override;

private:
  /// FAPI logger.
  srslog::basic_logger&       logger;
  slot_data_message_notifier& notifier;
};

} // namespace fapi
} // namespace srsgnb