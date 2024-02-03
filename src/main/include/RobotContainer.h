#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc/XboxController.h>
#include <frc/Timer.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc2/command/button/POVButton.h>

#include "subsystems/Neo550Test.h"
#include "subsystems/TalonSRXTest.h"
#include "subsystems/TimeOfFlightTest.h"
#include "subsystems/brushedMotor.h"
#include "subsystems/ShooterAngleTest.h"
#include "subsystems/CandleTest.h"


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
CandleTest       m_candleTest;




  frc2::CommandPtr GetAutonomousCommand();

 private:
  void ConfigureBindings();

/*
  //Button Testing
  frc2::JoystickButton m_topDriver_A{&m_topDriver,frc::XboxController::Button::kA};
  frc2::JoystickButton m_topDriver_B{&m_topDriver,frc::XboxController::Button::kB};

//        POV:
//                  0
//            270 --|--  90
//                 180
// 
  frc2::POVButton      m_topDriver_POV_up{&m_topDriver,     0 };
  frc2::POVButton      m_topDriver_POV_down{&m_topDriver, 180 };         
  frc2::POVButton      m_topDriver_POV_left{&m_topDriver, 270 };         
  frc2::POVButton      m_topDriver_POV_right{&m_topDriver, 90 };         


*/

};
