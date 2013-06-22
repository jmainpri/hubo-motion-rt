/*
 * Copyright (c) 2013, Georgia Tech Research Corporation
 * All rights reserved.
 *
 * Author: Michael X. Grey <mxgrey@gatech.edu>
 * Date: Feb 03, 2013
 *
 * Humanoid Robotics Lab      Georgia Institute of Technology
 * Director: Mike Stilman     http://www.golems.org
 *
 *
 * This file is provided under the following "BSD-style" License:
 *   Redistribution and use in source and binary forms, with or
 *   without modification, are permitted provided that the following
 *   conditions are met:
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
 *   CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 *   INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 *   MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *   DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 *   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
 *   USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 *   AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *   LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *   ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *   POSSIBILITY OF SUCH DAMAGE.
 */


#ifndef CONTROLDAEMON_H
#define CONTROLDAEMON_H

// For Hubo
#include "hubo.h"
#include "hubo-jointparams.h"

// For control
#include <math.h>
#include "daemonizer.h"

// Trajectory upper bounds
#define TRAJ_FREQ_HZ 200
#define MAX_TRAJ_TIME 10
#define MAX_TRAJ_SIZE MAX_TRAJ_TIME*TRAJ_FREQ_HZ

#define ARM_JOINT_COUNT 10
#define LEG_JOINT_COUNT 10
#define FIN_JOINT_COUNT 5
#define NCK_JOINT_COUNT 5
#define BOD_JOINT_COUNT 5

#define     HUBO_CHAN_RL_CTRL_NAME      "hubo-RL-control" // Right Leg control channel
#define     HUBO_CHAN_LL_CTRL_NAME      "hubo-LL-control" // Left Leg control channel
#define     HUBO_CHAN_RA_CTRL_NAME      "hubo-RA-control" // Right Arm control channel
#define     HUBO_CHAN_LA_CTRL_NAME      "hubo-LA-control" // Left Arm control channel
#define     HUBO_CHAN_RF_CTRL_NAME      "hubo-RF-control" // Right Finger control channel
#define     HUBO_CHAN_LF_CTRL_NAME      "hubo-LF-control" // Left Finger control channel
#define     HUBO_CHAN_BOD_CTRL_NAME     "hubo-BOD-control"// Body (waist) control channel
#define     HUBO_CHAN_NCK_CTRL_NAME     "hubo-NCK-control"// Neck control channel
#define     CTRL_CHAN_STATE             "ctrl-d-state"    // Control daemon state channel



typedef enum {
    CTRL_OFF    = 0,
    CTRL_POS,
    CTRL_TRAJ,
    CTRL_VEL,
    CTRL_HOME,
    CTRL_RESET,
    CTRL_PASS
} hubo_ctrl_mode_t;


typedef struct hubo_joint_control {
    double position;
    double speed;
    double velocity;
    double acceleration;

    double correctness;
// FIXME: Add minimum accel parameter

    double error_limit;

    double pos_min;
    double pos_max;

    double timeOut;

    hubo_ctrl_mode_t mode;
} hubo_joint_control_t;

typedef struct hubo_control {
    struct hubo_joint_control joint[HUBO_JOINT_COUNT];
    int active;
} hubo_control_t;

typedef struct hubo_arm_control {
    struct hubo_joint_control joint[ARM_JOINT_COUNT];
    int jointIndices[ARM_JOINT_COUNT];
    int count;
    int active;
} hubo_arm_control_t;

typedef struct hubo_leg_control {
    struct hubo_joint_control joint[LEG_JOINT_COUNT];
    int jointIndices[LEG_JOINT_COUNT];
    int count;
    int active;
} hubo_leg_control_t;

typedef struct hubo_fin_control {
    struct hubo_joint_control joint[FIN_JOINT_COUNT];
    int jointIndices[FIN_JOINT_COUNT];
    int count;
    int active;
} hubo_fin_control_t;

typedef struct hubo_nck_control {
    struct hubo_joint_control joint[NCK_JOINT_COUNT];
    int jointIndices[NCK_JOINT_COUNT];
    int count;
    int active;
} hubo_nck_control_t;

typedef struct hubo_bod_control {
    struct hubo_joint_control joint[BOD_JOINT_COUNT];
    int jointIndices[BOD_JOINT_COUNT];
    int count;
    int active;
} hubo_bod_control_t;

typedef struct hubo_ctrl_state {
    
    double requested_pos[HUBO_JOINT_COUNT];
    double actual_pos[HUBO_JOINT_COUNT];
    double requested_vel[HUBO_JOINT_COUNT];
    double actual_vel[HUBO_JOINT_COUNT];
    double requested_acc[HUBO_JOINT_COUNT];
    double actual_acc[HUBO_JOINT_COUNT];

    int status[HUBO_JOINT_COUNT];
    int paused;
} hubo_ctrl_state_t;


#endif // CONTROLDAEMON_H
