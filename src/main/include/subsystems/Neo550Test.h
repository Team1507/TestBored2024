// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "rev/CANSparkMax.h"

#include "Constants.h"

class Neo550Test : public frc2::SubsystemBase {
 public:
  Neo550Test();
  void Periodic() override;


  void  Stop(void);
  void  SetPower(float power);
  float GetPower(void);
  void  SetPosition(float position);
  float GetEncoder(void);

 private:

  //Init SparkMax with Neo 550 brushless motor
  rev::CANSparkMax          m_neo550_motor{CAN_NEO550TEST, rev::CANSparkMax::MotorType::kBrushless};
  rev::SparkPIDController   m_neo550_pid     = m_neo550_motor.GetPIDController();
  rev::SparkRelativeEncoder m_neo550_encoder = m_neo550_motor.GetEncoder(rev::SparkRelativeEncoder::Type::kHallSensor);
          



};
