///////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2014, Carlos J. Rosales
// All rights reserved.

// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:

// * Redistributions of source code must retain the above copyright notice, this
//   list of conditions and the following disclaimer.

// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.

// * Neither the name of friction-model-library nor the names of its
//   contributors may be used to endorse or promote products derived from
//   this software without specific prior written permission.

// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//////////////////////////////////////////////////////////////////////////////

#ifndef FRICTION_MODELS_FRICTION_H
#define FRICTION_MODELS_FRICTION_H

#include <cstddef>
#include <string>
#include <vector>
#include <iostream>

namespace friction_models
{

/**
 * @defgroup friction_models Models
 */

/**
 * \brief Contains raw data representing the position, velocity and acceleration of a transmission's
 * actuators.
 */
struct InputData
{
  double w; // fixed contact point
  double x; // moving contact point
  double z; // displacement, z = x-w
  double dx_dt; // time derivative of moving contact point
  double dz_dt; // time derivative of the displacement
  double dz_dx; // displacement respect to the moving point
  double t; // time
  double f_n; // normal contact force
  double f_ext; // external force
};

struct Parameters
{
  double DV; // the karnopp interval for zero velocity detection
  double slope; // the karnopp slope for zero velocity treatment
  double mu_s; // static friction coefficient
  double mu_c; // coulomb friction coefficient, AKA sliding
  double mu_v; // viscous friction coefficient
  double delta_v; // geometry factor
  double v_s; // stribeck velocity
  double t_d; // dwell time in stick slip parameters
  double gamma; // 
  double mode; // stick/slip mode switch variable
};

/**
 * \brief Abstract base class for representing friction models.
 *
 *
 */
class Friction
{
public:

  Friction(Parameters& params);

  virtual ~Friction() {}

  /**
   * \brief 
   * \param[in] 
   * \param[out] 
   * \pre 
   */
  virtual void computeFrictionForce(const InputData& in_data,
                                    Parameters& params,
                                    double& out_force) = 0;

  /**
   * \brief 
   * \param[in] 
   * \param[out] 
   * \pre 
   */
  //virtual void identifyParametersOffline(const std::vector<InputData>& in_data,
  //                                       const std::vector<double>& out_force) = 0;

  /**
   * \brief 
   * \param[in] 
   * \param[out] 
   * \pre 
   */
  //virtual void identifyParametersOnline(InputData& in_data,
  //                                      double& out_force) = 0;

  /**
   * \brief 
   * \param[in] 
   * \param[out] 
   * \pre 
   */
  void printParameters();

  /**
   * \brief 
   * \param[in] 
   * \param[out] 
   * \pre 
   */
  void printInputData(const InputData &in_data);

  /** \return Number of parameters required by the model. Useful for the optimization routines. */
  virtual std::size_t numParameters() const = 0; // seven parameter model + DV + stick/slip mode

  Parameters params_;

};

inline Friction::Friction(Parameters& params)
{
  // TODO, check validity of parameters: positiveness, nonsenses, etc.
  params_ = params;
}


inline void Friction::printParameters()
{
  std::cout << std::endl;
  std::cout << "model parameters" << std::endl << "----------------" << std::endl;
  std::cout << "DV: " << params_.DV << std::endl;
  std::cout << "mu_s: " << params_.mu_s << std::endl;
  std::cout << "mu_c: " << params_.mu_c << std::endl;
  std::cout << "mu_v: " << params_.mu_v << std::endl;
  std::cout << "delta_v: " << params_.delta_v << std::endl;
  std::cout << "v_s: " << params_.v_s << std::endl;
  std::cout << "t_d: " << params_.t_d << std::endl;
  std::cout << "mode: " << params_.mode << std::endl;
  std::cout << std::endl;

  return;
}

inline void Friction::printInputData(const InputData& in_data)
{
  std::cout << std::endl;
  std::cout << "input data" << std::endl << "----------" << std::endl;
  std::cout << "w: " << in_data.w << std::endl;
  std::cout << "x: " << in_data.x << std::endl;
  std::cout << "z: " << in_data.z << std::endl;
  std::cout << "dx_dt: " << in_data.dx_dt << std::endl;
  std::cout << "dz_dt: " << in_data.dz_dt << std::endl;
  std::cout << "dz_dx: " << in_data.dz_dx << std::endl;
  std::cout << "t: " << in_data.t << std::endl;
  std::cout << "f_n: " << in_data.f_n << std::endl;
  std::cout << "f_ext: " << in_data.f_ext << std::endl;
  std::cout << std::endl;

  return;
}

} // friction_models

#endif // FRICTION_MODELS_FRICTION_H