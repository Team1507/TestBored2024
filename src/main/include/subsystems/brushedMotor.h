// #pragma once

// #include <frc2/command/SubsystemBase.h>
// #include "rev/CANSparkMax.h"

// #include "Constants.h"

// class BrushedMotor : public frc2::SubsystemBase {
//  public:
//   BrushedMotor();
//   void Periodic() override;


//   void  Stop(void);
//   void  SetPower(float power);
//   float GetPower(void);

//   void SetEncoderPosition( float position );

//  private:

//   //Init SparkMax with 775 Pro with encoder test
//   // rev::CANSparkMax          m_brushedMotor{CAN_BRUSHEDMOTOR, rev::CANSparkMax::MotorType::kBrushed};
//   // rev::SparkRelativeEncoder m_brushed_encoder = m_brushedMotor.GetEncoder(rev::SparkRelativeEncoder::Type::kQuadrature, 4096);
//   // rev::SparkAnalogSensor    m_analogSensor    = m_brushedMotor.GetAnalog(rev::SparkAnalogSensor::Mode::kAbsolute);

//   //Limit Switch Test
//   // rev::SparkLimitSwitch m_forwardLimit = m_brushedMotor.GetForwardLimitSwitch(rev::SparkLimitSwitch::Type::kNormallyOpen);
//   // rev::SparkLimitSwitch m_reverseLimit = m_brushedMotor.GetReverseLimitSwitch(rev::SparkLimitSwitch::Type::kNormallyOpen);


//   //Do Not use Alternate Encoder
//   //rev::SparkMaxAlternateEncoder m_brushed_encoder = m_brushedMotor.GetAlternateEncoder(rev::SparkMaxAlternateEncoder::Type::kQuadrature,1024);


// };
