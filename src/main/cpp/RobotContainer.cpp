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
  //Button Testing
  m_topDriver_A.OnTrue(new CmdPrintText("A Button Pressed"));
  m_topDriver_A.OnFalse(new CmdPrintText("A Button Released"));

  m_topDriver_B.OnTrue(new CmdPrintText("B Button Pressed"));
  m_topDriver_B.OnFalse(new CmdPrintText("B Button Released"));


  m_topDriver_POV_up.OnTrue(   new CmdPrintText("POV UP Button Pressed"));
  m_topDriver_POV_down.OnTrue( new CmdPrintText("POV DOWN Button Pressed"));
  m_topDriver_POV_left.OnTrue( new CmdPrintText("POV LEFT Button Pressed"));
  m_topDriver_POV_right.OnTrue(new CmdPrintText("POV_RIGHT Button Pressed"));



  //Composite Buttons
  (m_topDriver_A && m_topDriver_B).OnTrue(new CmdPrintText("A&B Button Pressed") );

  (m_topDriver_A && m_topDriver_POV_up).OnTrue(new CmdPrintText("A&POVup Button Pressed") );
  (m_topDriver_A && m_topDriver_POV_down).OnTrue(new CmdPrintText("A&POVdown Button Pressed") );


  // m_topDriverRightTrigger.WhileTrue(new CmdPrintText("Right Trigger Pressed"));
  // m_topDriverRightTrigger.WhileFalse(new CmdPrintText("Right Trigger Released"));  

  // m_topDriverAButt.OnTrue(new CmdPrintText("A Button Pressed"));
  // m_topDriverAButt.OnFalse(new CmdPrintText("A Button Released"));    

}



frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  return frc2::cmd::Print("No autonomous command configured");
}

