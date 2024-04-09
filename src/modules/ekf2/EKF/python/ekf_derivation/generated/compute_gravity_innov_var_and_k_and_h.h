// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     function/FUNCTION.h.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#pragma once

#include <matrix/math.hpp>

namespace sym {

/**
 * This function was autogenerated from a symbolic function. Do not modify by hand.
 *
 * Symbolic function: compute_gravity_innov_var_and_k_and_h
 *
 * Args:
 *     state: Matrix24_1
 *     P: Matrix24_24
 *     meas: Matrix31
 *     R: Scalar
 *     epsilon: Scalar
 *
 * Outputs:
 *     innov: Matrix31
 *     innov_var: Matrix31
 *     Kx: Matrix24_1
 *     Ky: Matrix24_1
 *     Kz: Matrix24_1
 */
template <typename Scalar>
void ComputeGravityInnovVarAndKAndH(const matrix::Matrix<Scalar, 24, 1>& state,
                                    const matrix::Matrix<Scalar, 24, 24>& P,
                                    const matrix::Matrix<Scalar, 3, 1>& meas, const Scalar R,
                                    const Scalar epsilon,
                                    matrix::Matrix<Scalar, 3, 1>* const innov = nullptr,
                                    matrix::Matrix<Scalar, 3, 1>* const innov_var = nullptr,
                                    matrix::Matrix<Scalar, 24, 1>* const Kx = nullptr,
                                    matrix::Matrix<Scalar, 24, 1>* const Ky = nullptr,
                                    matrix::Matrix<Scalar, 24, 1>* const Kz = nullptr) {
  // Total ops: 736

  // Input arrays

  // Intermediate terms (54)
  const Scalar _tmp0 =
      Scalar(9.8066499999999994) /
      std::sqrt(Scalar(epsilon + std::pow(meas(0, 0), Scalar(2)) + std::pow(meas(1, 0), Scalar(2)) +
                       std::pow(meas(2, 0), Scalar(2))));
  const Scalar _tmp1 = Scalar(19.613299999999999) * state(1, 0);
  const Scalar _tmp2 = -P(3, 0) * _tmp1;
  const Scalar _tmp3 = Scalar(19.613299999999999) * state(2, 0);
  const Scalar _tmp4 = P(0, 0) * _tmp3;
  const Scalar _tmp5 = Scalar(19.613299999999999) * state(0, 0);
  const Scalar _tmp6 = P(2, 0) * _tmp5;
  const Scalar _tmp7 = Scalar(19.613299999999999) * state(3, 0);
  const Scalar _tmp8 = P(3, 1) * _tmp1;
  const Scalar _tmp9 = P(2, 1) * _tmp5;
  const Scalar _tmp10 = -P(1, 1) * _tmp7;
  const Scalar _tmp11 = P(0, 2) * _tmp3;
  const Scalar _tmp12 = P(2, 2) * _tmp5;
  const Scalar _tmp13 = -P(1, 2) * _tmp7;
  const Scalar _tmp14 = -P(3, 3) * _tmp1;
  const Scalar _tmp15 = P(0, 3) * _tmp3;
  const Scalar _tmp16 = -P(1, 3) * _tmp7;
  const Scalar _tmp17 = R - _tmp1 * (P(2, 3) * _tmp5 + _tmp14 + _tmp15 + _tmp16) +
                        _tmp3 * (-P(1, 0) * _tmp7 + _tmp2 + _tmp4 + _tmp6) +
                        _tmp5 * (-P(3, 2) * _tmp1 + _tmp11 + _tmp12 + _tmp13) -
                        _tmp7 * (P(0, 1) * _tmp3 + _tmp10 - _tmp8 + _tmp9);
  const Scalar _tmp18 = P(3, 0) * _tmp3;
  const Scalar _tmp19 = -P(0, 0) * _tmp1;
  const Scalar _tmp20 = -P(1, 0) * _tmp5;
  const Scalar _tmp21 = P(3, 2) * _tmp3;
  const Scalar _tmp22 = -P(2, 2) * _tmp7;
  const Scalar _tmp23 = P(1, 2) * _tmp5;
  const Scalar _tmp24 = P(0, 1) * _tmp1;
  const Scalar _tmp25 = -P(2, 1) * _tmp7;
  const Scalar _tmp26 = -P(1, 1) * _tmp5;
  const Scalar _tmp27 = -P(3, 3) * _tmp3;
  const Scalar _tmp28 = -P(0, 3) * _tmp1;
  const Scalar _tmp29 = -P(2, 3) * _tmp7;
  const Scalar _tmp30 = R - _tmp1 * (-P(2, 0) * _tmp7 - _tmp18 + _tmp19 + _tmp20) -
                        _tmp3 * (-P(1, 3) * _tmp5 + _tmp27 + _tmp28 + _tmp29) -
                        _tmp5 * (-P(3, 1) * _tmp3 - _tmp24 + _tmp25 + _tmp26) -
                        _tmp7 * (-P(0, 2) * _tmp1 - _tmp21 + _tmp22 - _tmp23);
  const Scalar _tmp31 = -P(0, 0) * _tmp5;
  const Scalar _tmp32 = P(2, 0) * _tmp3;
  const Scalar _tmp33 = P(1, 0) * _tmp1;
  const Scalar _tmp34 = -P(3, 2) * _tmp7;
  const Scalar _tmp35 = P(0, 2) * _tmp5;
  const Scalar _tmp36 = P(2, 2) * _tmp3;
  const Scalar _tmp37 = -P(3, 1) * _tmp7;
  const Scalar _tmp38 = -P(0, 1) * _tmp5;
  const Scalar _tmp39 = P(1, 1) * _tmp1;
  const Scalar _tmp40 = -P(3, 3) * _tmp7;
  const Scalar _tmp41 = P(2, 3) * _tmp3;
  const Scalar _tmp42 = P(1, 3) * _tmp1;
  const Scalar _tmp43 = R + _tmp1 * (P(2, 1) * _tmp3 + _tmp37 + _tmp38 + _tmp39) +
                        _tmp3 * (P(1, 2) * _tmp1 + _tmp34 - _tmp35 + _tmp36) -
                        _tmp5 * (-P(3, 0) * _tmp7 + _tmp31 + _tmp32 + _tmp33) -
                        _tmp7 * (-P(0, 3) * _tmp5 + _tmp40 + _tmp41 + _tmp42);
  const Scalar _tmp44 = Scalar(1.0) / (_tmp17);
  const Scalar _tmp45 = Scalar(19.613299999999999) * P(8, 3);
  const Scalar _tmp46 = Scalar(19.613299999999999) * P(8, 0);
  const Scalar _tmp47 = Scalar(19.613299999999999) * P(8, 2);
  const Scalar _tmp48 = Scalar(19.613299999999999) * P(9, 3);
  const Scalar _tmp49 = Scalar(19.613299999999999) * P(9, 2);
  const Scalar _tmp50 = Scalar(19.613299999999999) * P(9, 0);
  const Scalar _tmp51 = Scalar(1.0) / (_tmp30);
  const Scalar _tmp52 = Scalar(19.613299999999999) * P(4, 0);
  const Scalar _tmp53 = Scalar(1.0) / (_tmp43);

  // Output terms (5)
  if (innov != nullptr) {
    matrix::Matrix<Scalar, 3, 1>& _innov = (*innov);

    _innov(0, 0) = -_tmp0 * meas(0, 0) + Scalar(19.613299999999999) * state(0, 0) * state(2, 0) -
                   Scalar(19.613299999999999) * state(1, 0) * state(3, 0);
    _innov(1, 0) = -_tmp0 * meas(1, 0) - Scalar(19.613299999999999) * state(0, 0) * state(1, 0) -
                   Scalar(19.613299999999999) * state(2, 0) * state(3, 0);
    _innov(2, 0) = -_tmp0 * meas(2, 0) -
                   Scalar(9.8066499999999994) * std::pow(state(0, 0), Scalar(2)) +
                   Scalar(9.8066499999999994) * std::pow(state(1, 0), Scalar(2)) +
                   Scalar(9.8066499999999994) * std::pow(state(2, 0), Scalar(2)) -
                   Scalar(9.8066499999999994) * std::pow(state(3, 0), Scalar(2));
  }

  if (innov_var != nullptr) {
    matrix::Matrix<Scalar, 3, 1>& _innov_var = (*innov_var);

    _innov_var(0, 0) = _tmp17;
    _innov_var(1, 0) = _tmp30;
    _innov_var(2, 0) = _tmp43;
  }

  if (Kx != nullptr) {
    matrix::Matrix<Scalar, 24, 1>& _kx = (*Kx);

    _kx(0, 0) = _tmp44 * (-P(0, 1) * _tmp7 + _tmp28 + _tmp35 + _tmp4);
    _kx(1, 0) = _tmp44 * (P(1, 0) * _tmp3 + _tmp10 + _tmp23 - _tmp42);
    _kx(2, 0) = _tmp44 * (-P(2, 3) * _tmp1 + _tmp12 + _tmp25 + _tmp32);
    _kx(3, 0) = _tmp44 * (P(3, 2) * _tmp5 + _tmp14 + _tmp18 + _tmp37);
    _kx(4, 0) = _tmp44 * (P(4, 0) * _tmp3 - P(4, 1) * _tmp7 + P(4, 2) * _tmp5 - P(4, 3) * _tmp1);
    _kx(5, 0) = _tmp44 * (P(5, 0) * _tmp3 - P(5, 1) * _tmp7 + P(5, 2) * _tmp5 - P(5, 3) * _tmp1);
    _kx(6, 0) = _tmp44 * (P(6, 0) * _tmp3 - P(6, 1) * _tmp7 + P(6, 2) * _tmp5 - P(6, 3) * _tmp1);
    _kx(7, 0) = _tmp44 * (P(7, 0) * _tmp3 - P(7, 1) * _tmp7 + P(7, 2) * _tmp5 - P(7, 3) * _tmp1);
    _kx(8, 0) = _tmp44 * (-P(8, 1) * _tmp7 - _tmp45 * state(1, 0) + _tmp46 * state(2, 0) +
                          _tmp47 * state(0, 0));
    _kx(9, 0) = _tmp44 * (-P(9, 1) * _tmp7 - _tmp48 * state(1, 0) + _tmp49 * state(0, 0) +
                          _tmp50 * state(2, 0));
    _kx(10, 0) =
        _tmp44 * (P(10, 0) * _tmp3 - P(10, 1) * _tmp7 + P(10, 2) * _tmp5 - P(10, 3) * _tmp1);
    _kx(11, 0) =
        _tmp44 * (P(11, 0) * _tmp3 - P(11, 1) * _tmp7 + P(11, 2) * _tmp5 - P(11, 3) * _tmp1);
    _kx(12, 0) =
        _tmp44 * (P(12, 0) * _tmp3 - P(12, 1) * _tmp7 + P(12, 2) * _tmp5 - P(12, 3) * _tmp1);
    _kx(13, 0) =
        _tmp44 * (P(13, 0) * _tmp3 - P(13, 1) * _tmp7 + P(13, 2) * _tmp5 - P(13, 3) * _tmp1);
    _kx(14, 0) =
        _tmp44 * (P(14, 0) * _tmp3 - P(14, 1) * _tmp7 + P(14, 2) * _tmp5 - P(14, 3) * _tmp1);
    _kx(15, 0) =
        _tmp44 * (P(15, 0) * _tmp3 - P(15, 1) * _tmp7 + P(15, 2) * _tmp5 - P(15, 3) * _tmp1);
    _kx(16, 0) =
        _tmp44 * (P(16, 0) * _tmp3 - P(16, 1) * _tmp7 + P(16, 2) * _tmp5 - P(16, 3) * _tmp1);
    _kx(17, 0) =
        _tmp44 * (P(17, 0) * _tmp3 - P(17, 1) * _tmp7 + P(17, 2) * _tmp5 - P(17, 3) * _tmp1);
    _kx(18, 0) =
        _tmp44 * (P(18, 0) * _tmp3 - P(18, 1) * _tmp7 + P(18, 2) * _tmp5 - P(18, 3) * _tmp1);
    _kx(19, 0) =
        _tmp44 * (P(19, 0) * _tmp3 - P(19, 1) * _tmp7 + P(19, 2) * _tmp5 - P(19, 3) * _tmp1);
    _kx(20, 0) =
        _tmp44 * (P(20, 0) * _tmp3 - P(20, 1) * _tmp7 + P(20, 2) * _tmp5 - P(20, 3) * _tmp1);
    _kx(21, 0) =
        _tmp44 * (P(21, 0) * _tmp3 - P(21, 1) * _tmp7 + P(21, 2) * _tmp5 - P(21, 3) * _tmp1);
    _kx(22, 0) =
        _tmp44 * (P(22, 0) * _tmp3 - P(22, 1) * _tmp7 + P(22, 2) * _tmp5 - P(22, 3) * _tmp1);
    _kx(23, 0) =
        _tmp44 * (P(23, 0) * _tmp3 - P(23, 1) * _tmp7 + P(23, 2) * _tmp5 - P(23, 3) * _tmp1);
  }

  if (Ky != nullptr) {
    matrix::Matrix<Scalar, 24, 1>& _ky = (*Ky);

    _ky(0, 0) = _tmp51 * (-P(0, 2) * _tmp7 - _tmp15 + _tmp19 + _tmp38);
    _ky(1, 0) = _tmp51 * (-P(1, 3) * _tmp3 + _tmp13 + _tmp26 - _tmp33);
    _ky(2, 0) = _tmp51 * (-P(2, 0) * _tmp1 + _tmp22 - _tmp41 - _tmp9);
    _ky(3, 0) = _tmp51 * (-P(3, 1) * _tmp5 + _tmp2 + _tmp27 + _tmp34);
    _ky(4, 0) =
        _tmp51 * (-P(4, 1) * _tmp5 - P(4, 2) * _tmp7 - P(4, 3) * _tmp3 - _tmp52 * state(1, 0));
    _ky(5, 0) = _tmp51 * (-P(5, 0) * _tmp1 - P(5, 1) * _tmp5 - P(5, 2) * _tmp7 - P(5, 3) * _tmp3);
    _ky(6, 0) = _tmp51 * (-P(6, 0) * _tmp1 - P(6, 1) * _tmp5 - P(6, 2) * _tmp7 - P(6, 3) * _tmp3);
    _ky(7, 0) = _tmp51 * (-P(7, 0) * _tmp1 - P(7, 1) * _tmp5 - P(7, 2) * _tmp7 - P(7, 3) * _tmp3);
    _ky(8, 0) =
        _tmp51 * (-P(8, 1) * _tmp5 - P(8, 2) * _tmp7 - _tmp45 * state(2, 0) - _tmp46 * state(1, 0));
    _ky(9, 0) =
        _tmp51 * (-P(9, 1) * _tmp5 - P(9, 2) * _tmp7 - _tmp48 * state(2, 0) - _tmp50 * state(1, 0));
    _ky(10, 0) =
        _tmp51 * (-P(10, 0) * _tmp1 - P(10, 1) * _tmp5 - P(10, 2) * _tmp7 - P(10, 3) * _tmp3);
    _ky(11, 0) =
        _tmp51 * (-P(11, 0) * _tmp1 - P(11, 1) * _tmp5 - P(11, 2) * _tmp7 - P(11, 3) * _tmp3);
    _ky(12, 0) =
        _tmp51 * (-P(12, 0) * _tmp1 - P(12, 1) * _tmp5 - P(12, 2) * _tmp7 - P(12, 3) * _tmp3);
    _ky(13, 0) =
        _tmp51 * (-P(13, 0) * _tmp1 - P(13, 1) * _tmp5 - P(13, 2) * _tmp7 - P(13, 3) * _tmp3);
    _ky(14, 0) =
        _tmp51 * (-P(14, 0) * _tmp1 - P(14, 1) * _tmp5 - P(14, 2) * _tmp7 - P(14, 3) * _tmp3);
    _ky(15, 0) =
        _tmp51 * (-P(15, 0) * _tmp1 - P(15, 1) * _tmp5 - P(15, 2) * _tmp7 - P(15, 3) * _tmp3);
    _ky(16, 0) =
        _tmp51 * (-P(16, 0) * _tmp1 - P(16, 1) * _tmp5 - P(16, 2) * _tmp7 - P(16, 3) * _tmp3);
    _ky(17, 0) =
        _tmp51 * (-P(17, 0) * _tmp1 - P(17, 1) * _tmp5 - P(17, 2) * _tmp7 - P(17, 3) * _tmp3);
    _ky(18, 0) =
        _tmp51 * (-P(18, 0) * _tmp1 - P(18, 1) * _tmp5 - P(18, 2) * _tmp7 - P(18, 3) * _tmp3);
    _ky(19, 0) =
        _tmp51 * (-P(19, 0) * _tmp1 - P(19, 1) * _tmp5 - P(19, 2) * _tmp7 - P(19, 3) * _tmp3);
    _ky(20, 0) =
        _tmp51 * (-P(20, 0) * _tmp1 - P(20, 1) * _tmp5 - P(20, 2) * _tmp7 - P(20, 3) * _tmp3);
    _ky(21, 0) =
        _tmp51 * (-P(21, 0) * _tmp1 - P(21, 1) * _tmp5 - P(21, 2) * _tmp7 - P(21, 3) * _tmp3);
    _ky(22, 0) =
        _tmp51 * (-P(22, 0) * _tmp1 - P(22, 1) * _tmp5 - P(22, 2) * _tmp7 - P(22, 3) * _tmp3);
    _ky(23, 0) =
        _tmp51 * (-P(23, 0) * _tmp1 - P(23, 1) * _tmp5 - P(23, 2) * _tmp7 - P(23, 3) * _tmp3);
  }

  if (Kz != nullptr) {
    matrix::Matrix<Scalar, 24, 1>& _kz = (*Kz);

    _kz(0, 0) = _tmp53 * (-P(0, 3) * _tmp7 + _tmp11 + _tmp24 + _tmp31);
    _kz(1, 0) = _tmp53 * (P(1, 2) * _tmp3 + _tmp16 + _tmp20 + _tmp39);
    _kz(2, 0) = _tmp53 * (P(2, 1) * _tmp1 + _tmp29 + _tmp36 - _tmp6);
    _kz(3, 0) = _tmp53 * (-P(3, 0) * _tmp5 + _tmp21 + _tmp40 + _tmp8);
    _kz(4, 0) =
        _tmp53 * (P(4, 1) * _tmp1 + P(4, 2) * _tmp3 - P(4, 3) * _tmp7 - _tmp52 * state(0, 0));
    _kz(5, 0) = _tmp53 * (-P(5, 0) * _tmp5 + P(5, 1) * _tmp1 + P(5, 2) * _tmp3 - P(5, 3) * _tmp7);
    _kz(6, 0) = _tmp53 * (-P(6, 0) * _tmp5 + P(6, 1) * _tmp1 + P(6, 2) * _tmp3 - P(6, 3) * _tmp7);
    _kz(7, 0) = _tmp53 * (-P(7, 0) * _tmp5 + P(7, 1) * _tmp1 + P(7, 2) * _tmp3 - P(7, 3) * _tmp7);
    _kz(8, 0) =
        _tmp53 * (P(8, 1) * _tmp1 - P(8, 3) * _tmp7 - _tmp46 * state(0, 0) + _tmp47 * state(2, 0));
    _kz(9, 0) =
        _tmp53 * (P(9, 1) * _tmp1 - P(9, 3) * _tmp7 + _tmp49 * state(2, 0) - _tmp50 * state(0, 0));
    _kz(10, 0) =
        _tmp53 * (-P(10, 0) * _tmp5 + P(10, 1) * _tmp1 + P(10, 2) * _tmp3 - P(10, 3) * _tmp7);
    _kz(11, 0) =
        _tmp53 * (-P(11, 0) * _tmp5 + P(11, 1) * _tmp1 + P(11, 2) * _tmp3 - P(11, 3) * _tmp7);
    _kz(12, 0) =
        _tmp53 * (-P(12, 0) * _tmp5 + P(12, 1) * _tmp1 + P(12, 2) * _tmp3 - P(12, 3) * _tmp7);
    _kz(13, 0) =
        _tmp53 * (-P(13, 0) * _tmp5 + P(13, 1) * _tmp1 + P(13, 2) * _tmp3 - P(13, 3) * _tmp7);
    _kz(14, 0) =
        _tmp53 * (-P(14, 0) * _tmp5 + P(14, 1) * _tmp1 + P(14, 2) * _tmp3 - P(14, 3) * _tmp7);
    _kz(15, 0) =
        _tmp53 * (-P(15, 0) * _tmp5 + P(15, 1) * _tmp1 + P(15, 2) * _tmp3 - P(15, 3) * _tmp7);
    _kz(16, 0) =
        _tmp53 * (-P(16, 0) * _tmp5 + P(16, 1) * _tmp1 + P(16, 2) * _tmp3 - P(16, 3) * _tmp7);
    _kz(17, 0) =
        _tmp53 * (-P(17, 0) * _tmp5 + P(17, 1) * _tmp1 + P(17, 2) * _tmp3 - P(17, 3) * _tmp7);
    _kz(18, 0) =
        _tmp53 * (-P(18, 0) * _tmp5 + P(18, 1) * _tmp1 + P(18, 2) * _tmp3 - P(18, 3) * _tmp7);
    _kz(19, 0) =
        _tmp53 * (-P(19, 0) * _tmp5 + P(19, 1) * _tmp1 + P(19, 2) * _tmp3 - P(19, 3) * _tmp7);
    _kz(20, 0) =
        _tmp53 * (-P(20, 0) * _tmp5 + P(20, 1) * _tmp1 + P(20, 2) * _tmp3 - P(20, 3) * _tmp7);
    _kz(21, 0) =
        _tmp53 * (-P(21, 0) * _tmp5 + P(21, 1) * _tmp1 + P(21, 2) * _tmp3 - P(21, 3) * _tmp7);
    _kz(22, 0) =
        _tmp53 * (-P(22, 0) * _tmp5 + P(22, 1) * _tmp1 + P(22, 2) * _tmp3 - P(22, 3) * _tmp7);
    _kz(23, 0) =
        _tmp53 * (-P(23, 0) * _tmp5 + P(23, 1) * _tmp1 + P(23, 2) * _tmp3 - P(23, 3) * _tmp7);
  }
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
