// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>

#include "Constants.h"

//Allow deprecated Phoenix 5 API in this module
#include <wpi/deprecated.h>
WPI_IGNORE_DEPRECATED
#include "ctre/Phoenix.h"


class TalonSRXTest : public frc2::SubsystemBase {
 public:
  TalonSRXTest();

  void Periodic() override;

  void Stop(void);
  void SetPower(float power);

 private:

  WPI_TalonSRX m_talonSRX{CAN_TALONSRXTEST};  //TalonSRX is in PhoenixV5 and is depricated

};
