// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdPrintText.h"
#include <iostream>


CmdPrintText::CmdPrintText(std::string text):m_text(text){}

void CmdPrintText::Initialize() 
{
  std::cout<<m_text<<std::endl;
}
