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

#include "srsran/gateways/baseband/baseband_gateway.h"
#include "srsran/radio/radio_configuration.h"
#include "srsran/radio/radio_management_plane.h"
#include "srsran/radio/radio_notification_handler.h"

namespace srsran {

/// Describes a radio baseband unit session interface.
class radio_session : radio_base
{
public:
  /// \brief Gets the management plane.
  /// \return The reference to the management plane for this radio session.
  virtual radio_management_plane& get_management_plane() = 0;

  /// \brief Gets the data plane.
  /// \return The reference to the data plane for this radio session.
  virtual baseband_gateway& get_baseband_gateway() = 0;

  /// \brief Starts the radio operation.
  ///
  /// It requests all radio streams to start simultaneously. The radio streams must be stopped .
  ///
  /// \remark Calling start() more than once has undefined behaviour even after calling stop().
  virtual void start() = 0;

  /// \brief Stops the radio session operation.
  ///
  /// Any call to transmit or receive after calling stop() will return instantly without interacting with the physical
  /// radio.
  ///
  /// \remark Calling stop() without having called start() earlier behaviour is undefined.
  /// \remark Calling start() after stop() behaviour is undefined.
  virtual void stop() = 0;
};

} // namespace srsran
