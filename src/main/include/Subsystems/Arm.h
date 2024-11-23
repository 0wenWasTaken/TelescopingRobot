#pragma once

#include <iostream>
#include <frc2/command/SubsystemBase.h>
#include <frc2/command/Commands.h>
#include <frc2/command/RunCommand.h>
#include <frc2/command/ConditionalCommand.h>
#include <ctre/phoenix6/TalonFX.hpp>
#include <frc/smartdashboard/SmartDashboard.h>
#include "RobotContainer.h"

class Arm : public frc2::SubsystemBase {

    public:
        Arm();

        void Periodic() override;
        bool Is_Done(units::angle::turn_t goal);
        
        frc2::CommandPtr Move_Command(units::angle::turn_t goal);
        frc2::CommandPtr Idle();

    private:
        ctre::phoenix6::hardware::TalonFX m_motor{CONSTANTS::ARM::CAN_ID_MOTOR, "rio"};

         ctre::phoenix6::controls::PositionTorqueCurrentFOC m_positionTorque =
            ctre::phoenix6::controls::PositionTorqueCurrentFOC{0_tr}.WithSlot(0);
        void Move(units::angle::turn_t goal);
};