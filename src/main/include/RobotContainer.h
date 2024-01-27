// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc/XboxController.h>
#include <frc/Timer.h>

#include "subsystems/Neo550Test.h"
#include "subsystems/TalonSRXTest.h"
#include "subsystems/TimeOfFlightTest.h"
#include "subsystems/brushedMotor.h"



class RobotContainer {
 public:
  RobotContainer();

  //****************Controllers*******************
  //frc::XboxController m_botDriver{0};

  frc::Timer m_timer;

  //****************Subsystems*******************
  Neo550Test       m_neo550Test;
  TimeOfFlightTest m_timeOfFlightTest;
  // BrushedMotor     m_brushedMotor;
//TalonSRXTest     m_talonSRXTest;  





  frc2::CommandPtr GetAutonomousCommand();

 private:
  void ConfigureBindings();
};
