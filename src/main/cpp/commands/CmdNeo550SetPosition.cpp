// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdNeo550SetPosition.h"
#include "Robot.h"

CmdNeo550SetPosition::CmdNeo550SetPosition(float position) {
  
  m_position = position;

  AddRequirements(&robotContainer.m_neo550Test);
}

// Called when the command is initially scheduled.
void CmdNeo550SetPosition::Initialize() 
{
  robotContainer.m_neo550Test.SetPosition(m_position);
}

// Called repeatedly when this Command is scheduled to run
void CmdNeo550SetPosition::Execute() {}

// Called once the command ends or is interrupted.
void CmdNeo550SetPosition::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdNeo550SetPosition::IsFinished() 
{

  const float tolerance = 0.5;
  float curr_pos = robotContainer.m_neo550Test.GetEncoder();
  if(    fabs(m_position-curr_pos) <= tolerance )
  {
    return true;
  }

  return false;
}
