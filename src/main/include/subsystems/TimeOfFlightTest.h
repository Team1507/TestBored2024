// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>

#include "TimeOfFlight.h"
#include "Constants.h"

class TimeOfFlightTest : public frc2::SubsystemBase {
 public:
  TimeOfFlightTest();

  void Periodic() override;

  bool Inrange(void);

 private:


  frc::TimeOfFlight m_timeOfFlight{CAN_TIMEOFFLIGHT};

};
