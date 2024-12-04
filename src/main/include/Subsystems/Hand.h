#include <iostream>
#include <frc2/command/SubsystemBase.h>
#include <frc2/command/Commands.h>
#include <frc2/command/RunCommand.h>
#include <frc2/command/ConditionalCommand.h>
#include <ctre/phoenix6/TalonFX.hpp>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandPtr.h>
#include <TimeOfFlight.h>
#include "RobotContainer.h"

class Hand : public frc2::SubsystemBase {

    public:
        Hand(); 

        void Periodic() override;
        bool is_done(units::angle::turn_t goal);

        frc2::CommandPtr Idle();
        frc2::CommandPtr Move_Command(units::angle::turn_t goal, CONSTANTS::Grabber roller_direction);
    
    private:
        ctre::phoenix6::hardware::TalonFX m_roller{CONSTANTS::HAND::CAN_ID_ROLLER_MOTOR, "rio"};
        ctre::phoenix6::hardware::TalonFX m_wrist{CONSTANTS::HAND::CAN_ID_WRIST_MOTOR, "rio"};
        frc::TimeOfFlight m_tof{CONSTANTS::HAND::CAN_ID_SENSOR};

        ctre::phoenix6::controls::PositionTorqueCurrentFOC m_positionTorque =
            ctre::phoenix6::controls::PositionTorqueCurrentFOC{0_tr}.WithSlot(0);

        ctre::phoenix6::controls::DutyCycleOut m_dutyCycle{0};

        void Move(units::angle::turn_t goal);
        void Grabber(CONSTANTS::Grabber roller_direction);
        double Grabber_Direction(CONSTANTS::Grabber roller_direction);
};