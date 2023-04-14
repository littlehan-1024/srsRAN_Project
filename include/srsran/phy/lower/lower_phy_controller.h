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

#include "srsran/support/executors/task_executor.h"

namespace srsran {

/// Lower physical layer control interface.
class lower_phy_controller
{
public:
  /// Default destructor.
  virtual ~lower_phy_controller() = default;

  /// Starts the lower physical layer operation.
  virtual void start() = 0;

  /// Requests to lower physical layer to stop the operation.
  virtual void stop() = 0;
};

} // namespace srsran
