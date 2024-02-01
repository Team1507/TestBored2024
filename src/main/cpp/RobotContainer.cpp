// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include "frc/smartdashboard/SmartDashboard.h"

#include <frc2/command/Commands.h>

#include "commands/CmdNeo550SetPosition.h"
#include "commands/GrpNeo550ThereAndBack.h"
#include "commands/CmdPrintText.h"

RobotContainer::RobotContainer() 
{


  //******************SmartDashboard Buttons***************
  frc::SmartDashboard::PutData("Neo550PositionTest",     new CmdNeo550SetPosition(50.0) );
  frc::SmartDashboard::PutData("GrpNeo550ThereAndBack",  new GrpNeo550ThereAndBack()    );



  ConfigureBindings();
}

void RobotContainer::ConfigureBindings() 
{
  // m_topDriverRightTrigger.WhileTrue(new CmdPrintText("Right Trigger Pressed"));
  // m_topDriverRightTrigger.WhileFalse(new CmdPrintText("Right Trigger Released"));  

  // m_topDriverAButt.OnTrue(new CmdPrintText("A Button Pressed"));
  // m_topDriverAButt.OnFalse(new CmdPrintText("A Button Released"));    

}



frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  return frc2::cmd::Print("No autonomous command configured");
}

