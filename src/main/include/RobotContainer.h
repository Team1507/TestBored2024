#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc/XboxController.h>
#include <frc/Timer.h>
#include <frc2/command/button/JoystickButton.h>

#include "subsystems/Neo550Test.h"
#include "subsystems/TalonSRXTest.h"
#include "subsystems/TimeOfFlightTest.h"
#include "subsystems/brushedMotor.h"
#include "subsystems/ShooterAngleTest.h"



class RobotContainer {
 public:
  RobotContainer();

  //****************Controllers*******************
  //frc::XboxController m_topDriver{0};

  frc::Timer m_timer;

  //****************Subsystems*******************
  Neo550Test       m_neo550Test;
  TimeOfFlightTest m_timeOfFlightTest;
  // BrushedMotor     m_brushedMotor;
//TalonSRXTest     m_talonSRXTest;  

ShooterAngleTest m_shooterAngleTest;




  frc2::CommandPtr GetAutonomousCommand();

 private:
  void ConfigureBindings();

    // frc2::JoystickButton m_topDriverRightTrigger{&m_topDriver,frc::XboxController::Axis::kRightTrigger};
    // frc2::JoystickButton m_topDriverAButt{&m_topDriver,frc::XboxController::Button::kA};
    // // frc2::JoystickButton m_topDriverDpadDown{&m_topDriver,frc::XboxController::POV};
};
