//     | F_C + (F_S - F_C)*e^(-|v/v_S|^\delta_S) + F_v*v,   if v <> 0
// F = | F_ext,                                             if v=0 and |F_ext|<F_S
//     | F_S*sing(F_ext),                                   otherwise
//
// where F_C = mu*F_normal is the coulomb force, with mu the dynamic friction coefficient
//       F_S = mu_S*F_normal is the stiction force, mu_S is the static/stiction friction coefficient
//       F_v is the viscous friction coefficient
//       delta_S is a geometric parameter, typically 1
//       v_S is the Stribeck velocity
// 
// Karnopp model is available by setting  |v| < DV and the slope for that interval.