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

#ifndef FRICTION_MODELS_COULOMB_FRICTION_MODEL_H
#define FRICTION_MODELS_COULOMB_FRICTION_MODEL_H

#include <cassert>
#include <string>
#include <vector>
#include <cmath>

#include <friction_models/friction.h>

namespace friction_models
{

/**
 * \brief Implementation of the Coulomb friction model.
 *
 * This model. The graph of this model is illustrated below.
 * \image html coulomb.png
 *
 * F = F_C sign(v)
 * where F_C = \mu_c F_{normal}
 * the sign function 
 *
 * <CENTER>
 * <table>
 * <tr><th></th><th><CENTER>Effort</CENTER></th><th><CENTER>Velocity</CENTER></th><th><CENTER>Position</CENTER></th></tr>
 * <tr><td>
 * <b> Friction force </b>
 * </td>
 * <td>
 * \f[ \F_f = F_c sign(v) \f]
 * </td>
 * </tr></table>
 * </CENTER>
 *
 * where:
 * - \f$ F_c = \mu F_{normal} \f$ is the Coulomb force (sliding).
 * - The sign function allows a value between \f$ -F_c \f$ and \f$ F_c \f$ for \f$ v=0 \f$.
 *
 * \ingroup friction_models 
 */
 
class CoulombFriction : public Friction
{
public:
  /**
   * \param 
   * \param 
   * \pre 
   */
  CoulombFriction(Parameters& params);

  /**
   * \brief 
   * \param[in] 
   * \param[out] 
   * \pre 
   */
  void computeFrictionForce(const InputData& in_data, 
  							Parameters& params,
                            double& out_force);

  std::size_t numParameters() const {return 1;}

  Parameters getParameters() const {return params_;}
  void setParameters(const Parameters& params) { params_ = params;}

};

inline CoulombFriction::CoulombFriction(Parameters& params)
  : Friction(params)
{
  if (params.mu_c < 0.0)
  {
    std::cout << "Coulomb friction coefficient cannot be negaive." << std::endl;
  }
}

inline void CoulombFriction::computeFrictionForce(const InputData& in_data,
												  Parameters& params,
                           						  double& out_force)
{
  if(std::abs(in_data.dx_dt) < params_.DV)
  {
  	out_force = in_data.f_n * params_.mu_s;
  }
  else
  {
  	out_force = in_data.f_n * params_.mu_c;	
  }
  
}

} // friction_models

#endif // FRICTION_MODELS_COULOMB_FRICTION_MODEL_H