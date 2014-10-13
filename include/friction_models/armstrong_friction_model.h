// or the seven parameter model
//
// detection between stiction and sliding is required to keep track of the time of each state
//
// in stiction state, the behavior is spring-like or strain-stress-like:
//
// F(x) = sigma_0*x 
// 
// in sliding state, things get complicated
//
// F(v,t) = [F_C + F_S(gamma,t_d)*1/(1+(v(t-tau_k)/v_S)^2)]sign(v) + F_v*v
//
// where
//
// F_S(gamma, t_d) = F_S,a + [F_S,inf - F_S,a*t_d/(t_d+gamma)]
//
// F_S the magnitude of the Stribeck friction
// F_S,a the magnitude of the Stribeck friction at the end of the previous sliding preriod
// F_S,inf the magnitude of the Stribeck friction after a long time at rest (with slow application of force)
// t_d the dwell time, that is, the time since becoming stuck.
// v_S the characteristic velocity of the Stribeck friction
// gamma the temporal parameter of the rising static friction