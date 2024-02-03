// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "ctre/phoenix/led/CANdle.h"
#include "Constants.h"

class CandleTest : public frc2::SubsystemBase {
 public:
  CandleTest();

  void Periodic() override;

 private:

  ctre::phoenix::led::CANdle m_candle {CAN_CANDLE_1, ""};
  int m_count;
};
