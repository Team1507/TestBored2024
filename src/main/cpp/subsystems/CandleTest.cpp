// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/CandleTest.h"
#include <iostream>

CandleTest::CandleTest()
{
    std::cout<< "CandleTest" << std::endl;

    m_count = 0;

    ctre::phoenix::led::CANdleConfiguration candleConfig {};
    //candleConfig.statusLedOffWhenActive = true;
    candleConfig.disableWhenLOS = false;    //<<<<< IF True = MUST constantly update LEDs or they turn off
   // candleConfig.stripType =ctre::phoenix::led::LEDStripType::GRB;
    candleConfig.brightnessScalar = 0.1;
   // candleConfig.vBatOutputMode = ctre::phoenix::led::VBatOutputMode::Modulated;
    m_candle.ConfigAllSettings(candleConfig, 100);



    m_candle.ConfigBrightnessScalar(0.05);
    

}

// This method will be called once per scheduler run
void CandleTest::Periodic() 
{

    switch(m_count)
    {
        case 0:      m_candle.SetLEDs(255,   0,   0 );   break;
        case 100:    m_candle.SetLEDs(  0, 255,   0 );   break;
        case 200:    m_candle.SetLEDs(  0,   0, 255 );   break;
        case 300:    m_candle.SetLEDs( 255, 255,  0 );   break;
        case 400:    m_candle.SetLEDs(   0, 255, 255 );  break;
        case 500:    m_candle.SetLEDs( 255,   0, 255 );  break;
        case 600:    m_count = 0;                        break;
    }

   m_count++;

}
