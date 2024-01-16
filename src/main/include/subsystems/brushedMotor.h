// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "rev/CANSparkMax.h"

#include "Constants.h"

class brushedMotor : public frc2::SubsystemBase {
 public:
  brushedMotor();
  void Periodic() override;


  void  Stop(void);
  void  SetPower(float power);
  float GetPower(void);

 private:

  //Init SparkMax with Neo 550 brushless motor
  rev::CANSparkMax          m_brushed_motor{CAN_NEO550TEST, rev::CANSparkMax::MotorType::kBrushed};


};
