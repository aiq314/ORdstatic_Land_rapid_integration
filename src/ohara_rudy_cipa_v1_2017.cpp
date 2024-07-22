/*
   There are a total of 200 entries in the algebraic variable array.
   There are a total of 49 entries in each of the rate and state variable arrays.
   There are a total of 206 entries in the constant variable array.
 */

#include "ohara_rudy_cipa_v1_2017.hpp"
#include <cmath>
#include <cstdlib>
#include <iostream>

// #include <Eigen/Dense>
// #include <Eigen/Eigenvalues>

// using Eigen::MatrixXd;
// using Eigen::MatrixXcd;
// using Eigen::VectorXcd;
// using Eigen::EigenSolver;

/*
 * TIME is time in component environment (millisecond).
 * CONSTANTS[celltype] is celltype in component environment (dimensionless).
 * CONSTANTS[nao] is nao in component extracellular (millimolar).
 * CONSTANTS[cao] is cao in component extracellular (millimolar).
 * CONSTANTS[ko] is ko in component extracellular (millimolar).
 * CONSTANTS[R] is R in component physical_constants (joule_per_kilomole_kelvin).
 * CONSTANTS[T] is T in component physical_constants (kelvin).
 * CONSTANTS[F] is F in component physical_constants (coulomb_per_mole).
 * CONSTANTS[zna] is zna in component physical_constants (dimensionless).
 * CONSTANTS[zca] is zca in component physical_constants (dimensionless).
 * CONSTANTS[zk] is zk in component physical_constants (dimensionless).
 * CONSTANTS[L] is L in component cell_geometry (centimeter).
 * CONSTANTS[rad] is rad in component cell_geometry (centimeter).
 * CONSTANTS[vcell] is vcell in component cell_geometry (microliter).
 * CONSTANTS[Ageo] is Ageo in component cell_geometry (centimeter_squared).
 * CONSTANTS[Acap] is Acap in component cell_geometry (centimeter_squared).
 * CONSTANTS[vmyo] is vmyo in component cell_geometry (microliter).
 * CONSTANTS[vnsr] is vnsr in component cell_geometry (microliter).
 * CONSTANTS[vjsr] is vjsr in component cell_geometry (microliter).
 * CONSTANTS[vss] is vss in component cell_geometry (microliter).
 * STATES[V] is v in component membrane (millivolt).
 * ALGEBRAIC[vfrt] is vfrt in component membrane (dimensionless).
 * CONSTANTS[ffrt] is ffrt in component membrane (coulomb_per_mole_millivolt).
 * CONSTANTS[frt] is frt in component membrane (per_millivolt).
 * ALGEBRAIC[INa] is INa in component INa (microA_per_microF).
 * ALGEBRAIC[INaL] is INaL in component INaL (microA_per_microF).
 * ALGEBRAIC[Ito] is Ito in component Ito (microA_per_microF).
 * ALGEBRAIC[ICaL] is ICaL in component ICaL (microA_per_microF).
 * ALGEBRAIC[ICaNa] is ICaNa in component ICaL (microA_per_microF).
 * ALGEBRAIC[ICaK] is ICaK in component ICaL (microA_per_microF).
 * ALGEBRAIC[IKr] is IKr in component IKr (microA_per_microF).
 * ALGEBRAIC[IKs] is IKs in component IKs (microA_per_microF).
 * ALGEBRAIC[IK1] is IK1 in component IK1 (microA_per_microF).
 * ALGEBRAIC[INaCa_i] is INaCa_i in component INaCa_i (microA_per_microF).
 * ALGEBRAIC[INaCa_ss] is INaCa_ss in component INaCa_i (microA_per_microF).
 * ALGEBRAIC[INaK] is INaK in component INaK (microA_per_microF).
 * ALGEBRAIC[INab] is INab in component INab (microA_per_microF).
 * ALGEBRAIC[IKb] is IKb in component IKb (microA_per_microF).
 * ALGEBRAIC[IpCa] is IpCa in component IpCa (microA_per_microF).
 * ALGEBRAIC[ICab] is ICab in component ICab (microA_per_microF).
 * ALGEBRAIC[Istim] is Istim in component membrane (microA_per_microF).
 * CONSTANTS[stim_start] is stim_start in component membrane (millisecond).
 * CONSTANTS[stim_end] is stim_end in component membrane (millisecond).
 * CONSTANTS[amp] is amp in component membrane (microA_per_microF).
 * CONSTANTS[BCL] is BCL in component membrane (millisecond).
 * CONSTANTS[duration] is duration in component membrane (millisecond).
 * CONSTANTS[KmCaMK] is KmCaMK in component CaMK (millimolar).
 * CONSTANTS[aCaMK] is aCaMK in component CaMK (per_millimolar_per_millisecond).
 * CONSTANTS[bCaMK] is bCaMK in component CaMK (per_millisecond).
 * CONSTANTS[CaMKo] is CaMKo in component CaMK (dimensionless).
 * CONSTANTS[KmCaM] is KmCaM in component CaMK (millimolar).
 * ALGEBRAIC[CaMKb] is CaMKb in component CaMK (millimolar).
 * ALGEBRAIC[CaMKa] is CaMKa in component CaMK (millimolar).
 * STATES[CaMKt] is CaMKt in component CaMK (millimolar).
 * STATES[cass] is cass in component intracellular_ions (millimolar).
 * CONSTANTS[cmdnmax_b] is cmdnmax_b in component intracellular_ions (millimolar).
 * CONSTANTS[cmdnmax] is cmdnmax in component intracellular_ions (millimolar).
 * CONSTANTS[kmcmdn] is kmcmdn in component intracellular_ions (millimolar).
 * CONSTANTS[trpnmax] is trpnmax in component intracellular_ions (millimolar).
 * CONSTANTS[kmtrpn] is kmtrpn in component intracellular_ions (millimolar).
 * CONSTANTS[BSRmax] is BSRmax in component intracellular_ions (millimolar).
 * CONSTANTS[KmBSR] is KmBSR in component intracellular_ions (millimolar).
 * CONSTANTS[BSLmax] is BSLmax in component intracellular_ions (millimolar).
 * CONSTANTS[KmBSL] is KmBSL in component intracellular_ions (millimolar).
 * CONSTANTS[csqnmax] is csqnmax in component intracellular_ions (millimolar).
 * CONSTANTS[kmcsqn] is kmcsqn in component intracellular_ions (millimolar).
 * STATES[nai] is nai in component intracellular_ions (millimolar).
 * STATES[nass] is nass in component intracellular_ions (millimolar).
 * STATES[ki] is ki in component intracellular_ions (millimolar).
 * STATES[kss] is kss in component intracellular_ions (millimolar).
 * STATES[cansr] is cansr in component intracellular_ions (millimolar).
 * STATES[cajsr] is cajsr in component intracellular_ions (millimolar).
 * STATES[cai] is cai in component intracellular_ions (millimolar).
 * ALGEBRAIC[JdiffNa] is JdiffNa in component diff (millimolar_per_millisecond).
 * ALGEBRAIC[Jdiff] is Jdiff in component diff (millimolar_per_millisecond).
 * ALGEBRAIC[Jup] is Jup in component SERCA (millimolar_per_millisecond).
 * ALGEBRAIC[JdiffK] is JdiffK in component diff (millimolar_per_millisecond).
 * ALGEBRAIC[Jrel] is Jrel in component ryr (millimolar_per_millisecond).
 * ALGEBRAIC[Jtr] is Jtr in component trans_flux (millimolar_per_millisecond).
 * ALGEBRAIC[Bcai] is Bcai in component intracellular_ions (dimensionless).
 * ALGEBRAIC[Bcajsr] is Bcajsr in component intracellular_ions (dimensionless).
 * ALGEBRAIC[Bcass] is Bcass in component intracellular_ions (dimensionless).
 * CONSTANTS[cm] is cm in component intracellular_ions (microF_per_centimeter_squared).
 * CONSTANTS[PKNa] is PKNa in component reversal_potentials (dimensionless).
 * ALGEBRAIC[ENa] is ENa in component reversal_potentials (millivolt).
 * ALGEBRAIC[EK] is EK in component reversal_potentials (millivolt).
 * ALGEBRAIC[EKs] is EKs in component reversal_potentials (millivolt).
 * ALGEBRAIC[mss] is mss in component INa (dimensionless).
 * ALGEBRAIC[tm] is tm in component INa (millisecond).
 * CONSTANTS[mssV1] is mssV1 in component INa (millivolt).
 * CONSTANTS[mssV2] is mssV2 in component INa (millivolt).
 * CONSTANTS[mtV1] is mtV1 in component INa (millivolt).
 * CONSTANTS[mtV2] is mtV2 in component INa (millivolt).
 * CONSTANTS[mtD1] is mtD1 in component INa (dimensionless).
 * CONSTANTS[mtD2] is mtD2 in component INa (dimensionless).
 * CONSTANTS[mtV3] is mtV3 in component INa (millivolt).
 * CONSTANTS[mtV4] is mtV4 in component INa (millivolt).
 * STATES[m] is m in component INa (dimensionless).
 * ALGEBRAIC[hss] is hss in component INa (dimensionless).
 * ALGEBRAIC[thf] is thf in component INa (millisecond).
 * ALGEBRAIC[ths] is ths in component INa (millisecond).
 * CONSTANTS[hssV1] is hssV1 in component INa (millivolt).
 * CONSTANTS[hssV2] is hssV2 in component INa (millivolt).
 * CONSTANTS[Ahs] is Ahs in component INa (dimensionless).
 * CONSTANTS[Ahf] is Ahf in component INa (dimensionless).
 * STATES[hf] is hf in component INa (dimensionless).
 * STATES[hs] is hs in component INa (dimensionless).
 * ALGEBRAIC[h] is h in component INa (dimensionless).
 * CONSTANTS[GNa] is GNa in component INa (milliS_per_microF).
 * CONSTANTS[shift_INa_inact] is shift_INa_inact in component INa (millivolt).
 * ALGEBRAIC[jss] is jss in component INa (dimensionless).
 * ALGEBRAIC[tj] is tj in component INa (millisecond).
 * STATES[j] is j in component INa (dimensionless).
 * ALGEBRAIC[hssp] is hssp in component INa (dimensionless).
 * ALGEBRAIC[thsp] is thsp in component INa (millisecond).
 * STATES[hsp] is hsp in component INa (dimensionless).
 * ALGEBRAIC[hp] is hp in component INa (dimensionless).
 * ALGEBRAIC[tjp] is tjp in component INa (millisecond).
 * STATES[jp] is jp in component INa (dimensionless).
 * ALGEBRAIC[fINap] is fINap in component INa (dimensionless).
 * ALGEBRAIC[mLss] is mLss in component INaL (dimensionless).
 * ALGEBRAIC[tmL] is tmL in component INaL (millisecond).
 * STATES[mL] is mL in component INaL (dimensionless).
 * CONSTANTS[thL] is thL in component INaL (millisecond).
 * ALGEBRAIC[hLss] is hLss in component INaL (dimensionless).
 * STATES[hL] is hL in component INaL (dimensionless).
 * ALGEBRAIC[hLssp] is hLssp in component INaL (dimensionless).
 * CONSTANTS[thLp] is thLp in component INaL (millisecond).
 * STATES[hLp] is hLp in component INaL (dimensionless).
 * CONSTANTS[GNaL_b] is GNaL_b in component INaL (milliS_per_microF).
 * CONSTANTS[GNaL] is GNaL in component INaL (milliS_per_microF).
 * ALGEBRAIC[fINaLp] is fINaLp in component INaL (dimensionless).
 * CONSTANTS[Gto_b] is Gto_b in component Ito (milliS_per_microF).
 * ALGEBRAIC[ass] is ass in component Ito (dimensionless).
 * ALGEBRAIC[ta] is ta in component Ito (millisecond).
 * STATES[a] is a in component Ito (dimensionless).
 * ALGEBRAIC[iss] is iss in component Ito (dimensionless).
 * ALGEBRAIC[delta_epi] is delta_epi in component Ito (dimensionless).
 * ALGEBRAIC[tiF_b] is tiF_b in component Ito (millisecond).
 * ALGEBRAIC[tiS_b] is tiS_b in component Ito (millisecond).
 * ALGEBRAIC[tiF] is tiF in component Ito (millisecond).
 * ALGEBRAIC[tiS] is tiS in component Ito (millisecond).
 * ALGEBRAIC[AiF] is AiF in component Ito (dimensionless).
 * ALGEBRAIC[AiS] is AiS in component Ito (dimensionless).
 * STATES[iF] is iF in component Ito (dimensionless).
 * STATES[iS] is iS in component Ito (dimensionless).
 * ALGEBRAIC[i] is i in component Ito (dimensionless).
 * ALGEBRAIC[assp] is assp in component Ito (dimensionless).
 * STATES[ap] is ap in component Ito (dimensionless).
 * ALGEBRAIC[dti_develop] is dti_develop in component Ito (dimensionless).
 * ALGEBRAIC[dti_recover] is dti_recover in component Ito (dimensionless).
 * ALGEBRAIC[tiFp] is tiFp in component Ito (millisecond).
 * ALGEBRAIC[tiSp] is tiSp in component Ito (millisecond).
 * STATES[iFp] is iFp in component Ito (dimensionless).
 * STATES[iSp] is iSp in component Ito (dimensionless).
 * ALGEBRAIC[ip] is ip in component Ito (dimensionless).
 * CONSTANTS[Gto] is Gto in component Ito (milliS_per_microF).
 * ALGEBRAIC[fItop] is fItop in component Ito (dimensionless).
 * CONSTANTS[Kmn] is Kmn in component ICaL (millimolar).
 * CONSTANTS[k2n] is k2n in component ICaL (per_millisecond).
 * CONSTANTS[PCa_b] is PCa_b in component ICaL (dimensionless).
 * ALGEBRAIC[dss] is dss in component ICaL (dimensionless).
 * STATES[d] is d in component ICaL (dimensionless).
 * ALGEBRAIC[fss] is fss in component ICaL (dimensionless).
 * CONSTANTS[Aff] is Aff in component ICaL (dimensionless).
 * CONSTANTS[Afs] is Afs in component ICaL (dimensionless).
 * STATES[ff] is ff in component ICaL (dimensionless).
 * STATES[fs] is fs in component ICaL (dimensionless).
 * ALGEBRAIC[f] is f in component ICaL (dimensionless).
 * ALGEBRAIC[fcass] is fcass in component ICaL (dimensionless).
 * ALGEBRAIC[Afcaf] is Afcaf in component ICaL (dimensionless).
 * ALGEBRAIC[Afcas] is Afcas in component ICaL (dimensionless).
 * STATES[fcaf] is fcaf in component ICaL (dimensionless).
 * STATES[fcas] is fcas in component ICaL (dimensionless).
 * ALGEBRAIC[fca] is fca in component ICaL (dimensionless).
 * STATES[jca] is jca in component ICaL (dimensionless).
 * STATES[ffp] is ffp in component ICaL (dimensionless).
 * ALGEBRAIC[fp] is fp in component ICaL (dimensionless).
 * STATES[fcafp] is fcafp in component ICaL (dimensionless).
 * ALGEBRAIC[fcap] is fcap in component ICaL (dimensionless).
 * ALGEBRAIC[km2n] is km2n in component ICaL (per_millisecond).
 * ALGEBRAIC[anca] is anca in component ICaL (dimensionless).
 * STATES[nca] is nca in component ICaL (dimensionless).
 * ALGEBRAIC[PhiCaL] is PhiCaL in component ICaL (dimensionless).
 * ALGEBRAIC[PhiCaNa] is PhiCaNa in component ICaL (dimensionless).
 * ALGEBRAIC[PhiCaK] is PhiCaK in component ICaL (dimensionless).
 * CONSTANTS[PCa] is PCa in component ICaL (dimensionless).
 * CONSTANTS[PCap] is PCap in component ICaL (dimensionless).
 * CONSTANTS[PCaNa] is PCaNa in component ICaL (dimensionless).
 * CONSTANTS[PCaK] is PCaK in component ICaL (dimensionless).
 * CONSTANTS[PCaNap] is PCaNap in component ICaL (dimensionless).
 * CONSTANTS[PCaKp] is PCaKp in component ICaL (dimensionless).
 * ALGEBRAIC[fICaLp] is fICaLp in component ICaL (dimensionless).
 * ALGEBRAIC[td] is td in component ICaL (millisecond).
 * ALGEBRAIC[tff] is tff in component ICaL (millisecond).
 * ALGEBRAIC[tfs] is tfs in component ICaL (millisecond).
 * ALGEBRAIC[tfcaf] is tfcaf in component ICaL (millisecond).
 * ALGEBRAIC[tfcas] is tfcas in component ICaL (millisecond).
 * CONSTANTS[tjca] is tjca in component ICaL (millisecond).
 * ALGEBRAIC[tffp] is tffp in component ICaL (millisecond).
 * ALGEBRAIC[tfcafp] is tfcafp in component ICaL (millisecond).
 * CONSTANTS[v0_CaL] is v0 in component ICaL (millivolt).
 * ALGEBRAIC[A_1] is A_1 in component ICaL (dimensionless).
 * CONSTANTS[B_1] is B_1 in component ICaL (per_millivolt).
 * ALGEBRAIC[U_1] is U_1 in component ICaL (dimensionless).
 * ALGEBRAIC[A_2] is A_2 in component ICaL (dimensionless).
 * CONSTANTS[B_2] is B_2 in component ICaL (per_millivolt).
 * ALGEBRAIC[U_2] is U_2 in component ICaL (dimensionless).
 * ALGEBRAIC[A_3] is A_3 in component ICaL (dimensionless).
 * CONSTANTS[B_3] is B_3 in component ICaL (per_millivolt).
 * ALGEBRAIC[U_3] is U_3 in component ICaL (dimensionless).
 * CONSTANTS[GKr_b] is GKr_b in component IKr (milliS_per_microF).
 * STATES[IC1] is IC1 in component IKr (dimensionless).
 * STATES[IC2] is IC2 in component IKr (dimensionless).
 * STATES[C1] is C1 in component IKr (dimensionless).
 * STATES[C2] is C2 in component IKr (dimensionless).
 * STATES[O] is O in component IKr (dimensionless).
 * STATES[IO] is IO in component IKr (dimensionless).
 * STATES[IObound] is IObound in component IKr (dimensionless).
 * STATES[Obound] is Obound in component IKr (dimensionless).
 * STATES[Cbound] is Cbound in component IKr (dimensionless).
 * STATES[D] is D in component IKr (dimensionless).
 * CONSTANTS[GKr] is GKr in component IKr (milliS_per_microF).
 * CONSTANTS[A1] is A1 in component IKr (per_millisecond).
 * CONSTANTS[B1] is B1 in component IKr (per_millivolt).
 * CONSTANTS[q1] is q1 in component IKr (dimensionless).
 * CONSTANTS[A2] is A2 in component IKr (per_millisecond).
 * CONSTANTS[B2] is B2 in component IKr (per_millivolt).
 * CONSTANTS[q2] is q2 in component IKr (dimensionless).
 * CONSTANTS[A3] is A3 in component IKr (per_millisecond).
 * CONSTANTS[B3] is B3 in component IKr (per_millivolt).
 * CONSTANTS[q3] is q3 in component IKr (dimensionless).
 * CONSTANTS[A4] is A4 in component IKr (per_millisecond).
 * CONSTANTS[B4] is B4 in component IKr (per_millivolt).
 * CONSTANTS[q4] is q4 in component IKr (dimensionless).
 * CONSTANTS[A11] is A11 in component IKr (per_millisecond).
 * CONSTANTS[B11] is B11 in component IKr (per_millivolt).
 * CONSTANTS[q11] is q11 in component IKr (dimensionless).
 * CONSTANTS[A21] is A21 in component IKr (per_millisecond).
 * CONSTANTS[B21] is B21 in component IKr (per_millivolt).
 * CONSTANTS[q21] is q21 in component IKr (dimensionless).
 * CONSTANTS[A31] is A31 in component IKr (per_millisecond).
 * CONSTANTS[B31] is B31 in component IKr (per_millivolt).
 * CONSTANTS[q31] is q31 in component IKr (dimensionless).
 * CONSTANTS[A41] is A41 in component IKr (per_millisecond).
 * CONSTANTS[B41] is B41 in component IKr (per_millivolt).
 * CONSTANTS[q41] is q41 in component IKr (dimensionless).
 * CONSTANTS[A51] is A51 in component IKr (per_millisecond).
 * CONSTANTS[B51] is B51 in component IKr (per_millivolt).
 * CONSTANTS[q51] is q51 in component IKr (dimensionless).
 * CONSTANTS[A52] is A52 in component IKr (per_millisecond).
 * CONSTANTS[B52] is B52 in component IKr (per_millivolt).
 * CONSTANTS[q52] is q52 in component IKr (dimensionless).
 * CONSTANTS[A53] is A53 in component IKr (per_millisecond).
 * CONSTANTS[B53] is B53 in component IKr (per_millivolt).
 * CONSTANTS[q53] is q53 in component IKr (dimensionless).
 * CONSTANTS[A61] is A61 in component IKr (per_millisecond).
 * CONSTANTS[B61] is B61 in component IKr (per_millivolt).
 * CONSTANTS[q61] is q61 in component IKr (dimensionless).
 * CONSTANTS[A62] is A62 in component IKr (per_millisecond).
 * CONSTANTS[B62] is B62 in component IKr (per_millivolt).
 * CONSTANTS[q62] is q62 in component IKr (dimensionless).
 * CONSTANTS[A63] is A63 in component IKr (per_millisecond).
 * CONSTANTS[B63] is B63 in component IKr (per_millivolt).
 * CONSTANTS[q63] is q63 in component IKr (dimensionless).
 * CONSTANTS[Kmax] is Kmax in component IKr (dimensionless).
 * CONSTANTS[Ku] is Ku in component IKr (per_millisecond).
 * CONSTANTS[n] is n in component IKr (dimensionless).
 * CONSTANTS[halfmax] is halfmax in component IKr (dimensionless).
 * CONSTANTS[Kt] is Kt in component IKr (per_millisecond).
 * CONSTANTS[Vhalf] is Vhalf in component IKr (millivolt).
 * CONSTANTS[Temp] is Temp in component IKr (dimensionless).
 * CONSTANTS[GKs_b] is GKs_b in component IKs (milliS_per_microF).
 * CONSTANTS[GKs] is GKs in component IKs (milliS_per_microF).
 * ALGEBRAIC[xs1ss] is xs1ss in component IKs (dimensionless).
 * ALGEBRAIC[xs2ss] is xs2ss in component IKs (dimensionless).
 * ALGEBRAIC[txs1] is txs1 in component IKs (millisecond).
 * CONSTANTS[txs1_max] is txs1_max in component IKs (millisecond).
 * STATES[xs1] is xs1 in component IKs (dimensionless).
 * STATES[xs2] is xs2 in component IKs (dimensionless).
 * ALGEBRAIC[KsCa] is KsCa in component IKs (dimensionless).
 * ALGEBRAIC[txs2] is txs2 in component IKs (millisecond).
 * CONSTANTS[GK1] is GK1 in component IK1 (milliS_per_microF).
 * CONSTANTS[GK1_b] is GK1_b in component IK1 (milliS_per_microF).
 * ALGEBRAIC[xk1ss] is xk1ss in component IK1 (dimensionless).
 * ALGEBRAIC[txk1] is txk1 in component IK1 (millisecond).
 * STATES[xk1] is xk1 in component IK1 (dimensionless).
 * ALGEBRAIC[rk1] is rk1 in component IK1 (millisecond).
 * CONSTANTS[kna1] is kna1 in component INaCa_i (per_millisecond).
 * CONSTANTS[kna2] is kna2 in component INaCa_i (per_millisecond).
 * CONSTANTS[kna3] is kna3 in component INaCa_i (per_millisecond).
 * CONSTANTS[kasymm] is kasymm in component INaCa_i (dimensionless).
 * CONSTANTS[wna] is wna in component INaCa_i (dimensionless).
 * CONSTANTS[wca] is wca in component INaCa_i (dimensionless).
 * CONSTANTS[wnaca] is wnaca in component INaCa_i (dimensionless).
 * CONSTANTS[kcaon] is kcaon in component INaCa_i (per_millisecond).
 * CONSTANTS[kcaoff] is kcaoff in component INaCa_i (per_millisecond).
 * CONSTANTS[qna] is qna in component INaCa_i (dimensionless).
 * CONSTANTS[qca] is qca in component INaCa_i (dimensionless).
 * ALGEBRAIC[hna] is hna in component INaCa_i (dimensionless).
 * ALGEBRAIC[hca] is hca in component INaCa_i (dimensionless).
 * CONSTANTS[KmCaAct] is KmCaAct in component INaCa_i (millimolar).
 * CONSTANTS[Gncx_b] is Gncx_b in component INaCa_i (milliS_per_microF).
 * CONSTANTS[Gncx] is Gncx in component INaCa_i (milliS_per_microF).
 * ALGEBRAIC[h1_i] is h1_i in component INaCa_i (dimensionless).
 * ALGEBRAIC[h2_i] is h2_i in component INaCa_i (dimensionless).
 * ALGEBRAIC[h3_i] is h3_i in component INaCa_i (dimensionless).
 * ALGEBRAIC[h4_i] is h4_i in component INaCa_i (dimensionless).
 * ALGEBRAIC[h5_i] is h5_i in component INaCa_i (dimensionless).
 * ALGEBRAIC[h6_i] is h6_i in component INaCa_i (dimensionless).
 * ALGEBRAIC[h7_i] is h7_i in component INaCa_i (dimensionless).
 * ALGEBRAIC[h8_i] is h8_i in component INaCa_i (dimensionless).
 * ALGEBRAIC[h9_i] is h9_i in component INaCa_i (dimensionless).
 * CONSTANTS[h10_i] is h10_i in component INaCa_i (dimensionless).
 * CONSTANTS[h11_i] is h11_i in component INaCa_i (dimensionless).
 * CONSTANTS[h12_i] is h12_i in component INaCa_i (dimensionless).
 * CONSTANTS[k1_i] is k1_i in component INaCa_i (dimensionless).
 * CONSTANTS[k2_i] is k2_i in component INaCa_i (dimensionless).
 * ALGEBRAIC[k3p_i] is k3p_i in component INaCa_i (dimensionless).
 * ALGEBRAIC[k3pp_i] is k3pp_i in component INaCa_i (dimensionless).
 * ALGEBRAIC[k3_i] is k3_i in component INaCa_i (dimensionless).
 * ALGEBRAIC[k4_i] is k4_i in component INaCa_i (dimensionless).
 * ALGEBRAIC[k4p_i] is k4p_i in component INaCa_i (dimensionless).
 * ALGEBRAIC[k4pp_i] is k4pp_i in component INaCa_i (dimensionless).
 * CONSTANTS[k5_i] is k5_i in component INaCa_i (dimensionless).
 * ALGEBRAIC[k6_i] is k6_i in component INaCa_i (dimensionless).
 * ALGEBRAIC[k7_i] is k7_i in component INaCa_i (dimensionless).
 * ALGEBRAIC[k8_i] is k8_i in component INaCa_i (dimensionless).
 * ALGEBRAIC[x1_i] is x1_i in component INaCa_i (dimensionless).
 * ALGEBRAIC[x2_i] is x2_i in component INaCa_i (dimensionless).
 * ALGEBRAIC[x3_i] is x3_i in component INaCa_i (dimensionless).
 * ALGEBRAIC[x4_i] is x4_i in component INaCa_i (dimensionless).
 * ALGEBRAIC[E1_i] is E1_i in component INaCa_i (dimensionless).
 * ALGEBRAIC[E2_i] is E2_i in component INaCa_i (dimensionless).
 * ALGEBRAIC[E3_i] is E3_i in component INaCa_i (dimensionless).
 * ALGEBRAIC[E4_i] is E4_i in component INaCa_i (dimensionless).
 * ALGEBRAIC[allo_i] is allo_i in component INaCa_i (dimensionless).
 * ALGEBRAIC[JncxNa_i] is JncxNa_i in component INaCa_i (millimolar_per_millisecond).
 * ALGEBRAIC[JncxCa_i] is JncxCa_i in component INaCa_i (millimolar_per_millisecond).
 * ALGEBRAIC[h1_ss] is h1_ss in component INaCa_i (dimensionless).
 * ALGEBRAIC[h2_ss] is h2_ss in component INaCa_i (dimensionless).
 * ALGEBRAIC[h3_ss] is h3_ss in component INaCa_i (dimensionless).
 * ALGEBRAIC[h4_ss] is h4_ss in component INaCa_i (dimensionless).
 * ALGEBRAIC[h5_ss] is h5_ss in component INaCa_i (dimensionless).
 * ALGEBRAIC[h6_ss] is h6_ss in component INaCa_i (dimensionless).
 * ALGEBRAIC[h7_ss] is h7_ss in component INaCa_i (dimensionless).
 * ALGEBRAIC[h8_ss] is h8_ss in component INaCa_i (dimensionless).
 * ALGEBRAIC[h9_ss] is h9_ss in component INaCa_i (dimensionless).
 * CONSTANTS[h10_ss] is h10_ss in component INaCa_i (dimensionless).
 * CONSTANTS[h11_ss] is h11_ss in component INaCa_i (dimensionless).
 * CONSTANTS[h12_ss] is h12_ss in component INaCa_i (dimensionless).
 * CONSTANTS[k1_ss] is k1_ss in component INaCa_i (dimensionless).
 * CONSTANTS[k2_ss] is k2_ss in component INaCa_i (dimensionless).
 * ALGEBRAIC[k3p_ss] is k3p_ss in component INaCa_i (dimensionless).
 * ALGEBRAIC[k3pp_ss] is k3pp_ss in component INaCa_i (dimensionless).
 * ALGEBRAIC[k3_ss] is k3_ss in component INaCa_i (dimensionless).
 * ALGEBRAIC[k4_ss] is k4_ss in component INaCa_i (dimensionless).
 * ALGEBRAIC[k4p_ss] is k4p_ss in component INaCa_i (dimensionless).
 * ALGEBRAIC[k4pp_ss] is k4pp_ss in component INaCa_i (dimensionless).
 * CONSTANTS[k5_ss] is k5_ss in component INaCa_i (dimensionless).
 * ALGEBRAIC[k6_ss] is k6_ss in component INaCa_i (dimensionless).
 * ALGEBRAIC[k7_ss] is k7_ss in component INaCa_i (dimensionless).
 * ALGEBRAIC[k8_ss] is k8_ss in component INaCa_i (dimensionless).
 * ALGEBRAIC[x1_ss] is x1_ss in component INaCa_i (dimensionless).
 * ALGEBRAIC[x2_ss] is x2_ss in component INaCa_i (dimensionless).
 * ALGEBRAIC[x3_ss] is x3_ss in component INaCa_i (dimensionless).
 * ALGEBRAIC[x4_ss] is x4_ss in component INaCa_i (dimensionless).
 * ALGEBRAIC[E1_ss] is E1_ss in component INaCa_i (dimensionless).
 * ALGEBRAIC[E2_ss] is E2_ss in component INaCa_i (dimensionless).
 * ALGEBRAIC[E3_ss] is E3_ss in component INaCa_i (dimensionless).
 * ALGEBRAIC[E4_ss] is E4_ss in component INaCa_i (dimensionless).
 * ALGEBRAIC[allo_ss] is allo_ss in component INaCa_i (dimensionless).
 * ALGEBRAIC[JncxNa_ss] is JncxNa_ss in component INaCa_i (millimolar_per_millisecond).
 * ALGEBRAIC[JncxCa_ss] is JncxCa_ss in component INaCa_i (millimolar_per_millisecond).
 * CONSTANTS[k1p] is k1p in component INaK (per_millisecond).
 * CONSTANTS[k1m] is k1m in component INaK (per_millisecond).
 * CONSTANTS[k2p] is k2p in component INaK (per_millisecond).
 * CONSTANTS[k2m] is k2m in component INaK (per_millisecond).
 * CONSTANTS[k3p] is k3p in component INaK (per_millisecond).
 * CONSTANTS[k3m] is k3m in component INaK (per_millisecond).
 * CONSTANTS[k4p] is k4p in component INaK (per_millisecond).
 * CONSTANTS[k4m] is k4m in component INaK (per_millisecond).
 * CONSTANTS[Knai0] is Knai0 in component INaK (millimolar).
 * CONSTANTS[Knao0] is Knao0 in component INaK (millimolar).
 * CONSTANTS[delta] is delta in component INaK (millivolt).
 * CONSTANTS[Kki] is Kki in component INaK (per_millisecond).
 * CONSTANTS[Kko] is Kko in component INaK (per_millisecond).
 * CONSTANTS[MgADP] is MgADP in component INaK (millimolar).
 * CONSTANTS[MgATP] is MgATP in component INaK (millimolar).
 * CONSTANTS[Kmgatp] is Kmgatp in component INaK (millimolar).
 * CONSTANTS[H] is H in component INaK (millimolar).
 * CONSTANTS[eP] is eP in component INaK (dimensionless).
 * CONSTANTS[Khp] is Khp in component INaK (millimolar).
 * CONSTANTS[Knap] is Knap in component INaK (millimolar).
 * CONSTANTS[Kxkur] is Kxkur in component INaK (millimolar).
 * CONSTANTS[Pnak_b] is Pnak_b in component INaK (milliS_per_microF).
 * CONSTANTS[Pnak] is Pnak in component INaK (milliS_per_microF).
 * ALGEBRAIC[Knai] is Knai in component INaK (millimolar).
 * ALGEBRAIC[Knao] is Knao in component INaK (millimolar).
 * ALGEBRAIC[P] is P in component INaK (dimensionless).
 * ALGEBRAIC[a1] is a1 in component INaK (dimensionless).
 * CONSTANTS[b1] is b1 in component INaK (dimensionless).
 * CONSTANTS[a2] is a2 in component INaK (dimensionless).
 * ALGEBRAIC[b2] is b2 in component INaK (dimensionless).
 * ALGEBRAIC[a3] is a3 in component INaK (dimensionless).
 * ALGEBRAIC[b3] is b3 in component INaK (dimensionless).
 * CONSTANTS[a4] is a4 in component INaK (dimensionless).
 * ALGEBRAIC[b4] is b4 in component INaK (dimensionless).
 * ALGEBRAIC[x1] is x1 in component INaK (dimensionless).
 * ALGEBRAIC[x2] is x2 in component INaK (dimensionless).
 * ALGEBRAIC[x3] is x3 in component INaK (dimensionless).
 * ALGEBRAIC[x4] is x4 in component INaK (dimensionless).
 * ALGEBRAIC[E1] is E1 in component INaK (dimensionless).
 * ALGEBRAIC[E2] is E2 in component INaK (dimensionless).
 * ALGEBRAIC[E3] is E3 in component INaK (dimensionless).
 * ALGEBRAIC[E4] is E4 in component INaK (dimensionless).
 * ALGEBRAIC[JnakNa] is JnakNa in component INaK (millimolar_per_millisecond).
 * ALGEBRAIC[JnakK] is JnakK in component INaK (millimolar_per_millisecond).
 * ALGEBRAIC[xkb] is xkb in component IKb (dimensionless).
 * CONSTANTS[GKb_b] is GKb_b in component IKb (milliS_per_microF).
 * CONSTANTS[GKb] is GKb in component IKb (milliS_per_microF).
 * CONSTANTS[PNab] is PNab in component INab (milliS_per_microF).
 * ALGEBRAIC[A_Nab] is A in component INab (microA_per_microF).
 * CONSTANTS[B_Nab] is B in component INab (per_millivolt).
 * CONSTANTS[v0_Nab] is v0 in component INab (millivolt).
 * ALGEBRAIC[U] is U in component INab (dimensionless).
 * CONSTANTS[PCab] is PCab in component ICab (milliS_per_microF).
 * ALGEBRAIC[A_Cab] is A in component ICab (microA_per_microF).
 * CONSTANTS[B_Cab] is B in component ICab (per_millivolt).
 * CONSTANTS[v0_Cab] is v0 in component ICab (millivolt).
 * ALGEBRAIC[U] is U in component ICab (dimensionless).
 * CONSTANTS[GpCa] is GpCa in component IpCa (milliS_per_microF).
 * CONSTANTS[KmCap] is KmCap in component IpCa (millimolar).
 * CONSTANTS[bt] is bt in component ryr (millisecond).
 * CONSTANTS[a_rel] is a_rel in component ryr (millisecond).
 * ALGEBRAIC[Jrel_inf] is Jrel_inf in component ryr (dimensionless).
 * ALGEBRAIC[tau_rel] is tau_rel in component ryr (millisecond).
 * ALGEBRAIC[Jrel_infp] is Jrel_infp in component ryr (dimensionless).
 * ALGEBRAIC[Jrel_temp] is Jrel_temp in component ryr (dimensionless).
 * ALGEBRAIC[tau_relp] is tau_relp in component ryr (millisecond).
 * STATES[Jrelnp] is Jrelnp in component ryr (dimensionless).
 * STATES[Jrelp] is Jrelp in component ryr (dimensionless).
 * CONSTANTS[btp] is btp in component ryr (millisecond).
 * CONSTANTS[a_relp] is a_relp in component ryr (millisecond).
 * ALGEBRAIC[Jrel_inf_temp] is Jrel_inf_temp in component ryr (dimensionless).
 * ALGEBRAIC[fJrelp] is fJrelp in component ryr (dimensionless).
 * CONSTANTS[Jrel_scaling_factor] is Jrel_scaling_factor in component ryr (dimensionless).
 * ALGEBRAIC[tau_rel_temp] is tau_rel_temp in component ryr (millisecond).
 * ALGEBRAIC[tau_relp_temp] is tau_relp_temp in component ryr (millisecond).
 * CONSTANTS[upScale] is upScale in component SERCA (dimensionless).
 * ALGEBRAIC[Jupnp] is Jupnp in component SERCA (millimolar_per_millisecond).
 * ALGEBRAIC[Jupp] is Jupp in component SERCA (millimolar_per_millisecond).
 * ALGEBRAIC[fJupp] is fJupp in component SERCA (dimensionless).
 * ALGEBRAIC[Jleak] is Jleak in component SERCA (millimolar_per_millisecond).
 * CONSTANTS[Jup_b] is Jup_b in component SERCA (dimensionless).
 * RATES[V] is d/dt v in component membrane (millivolt).
 * RATES[CaMKt] is d/dt CaMKt in component CaMK (millimolar).
 * RATES[nai] is d/dt nai in component intracellular_ions (millimolar).
 * RATES[nass] is d/dt nass in component intracellular_ions (millimolar).
 * RATES[ki] is d/dt ki in component intracellular_ions (millimolar).
 * RATES[kss] is d/dt kss in component intracellular_ions (millimolar).
 * RATES[cai] is d/dt cai in component intracellular_ions (millimolar).
 * RATES[cass] is d/dt cass in component intracellular_ions (millimolar).
 * RATES[cansr] is d/dt cansr in component intracellular_ions (millimolar).
 * RATES[cajsr] is d/dt cajsr in component intracellular_ions (millimolar).
 * RATES[m] is d/dt m in component INa (dimensionless).
 * RATES[hf] is d/dt hf in component INa (dimensionless).
 * RATES[hs] is d/dt hs in component INa (dimensionless).
 * RATES[j] is d/dt j in component INa (dimensionless).
 * RATES[hsp] is d/dt hsp in component INa (dimensionless).
 * RATES[jp] is d/dt jp in component INa (dimensionless).
 * RATES[mL] is d/dt mL in component INaL (dimensionless).
 * RATES[hL] is d/dt hL in component INaL (dimensionless).
 * RATES[hLp] is d/dt hLp in component INaL (dimensionless).
 * RATES[a] is d/dt a in component Ito (dimensionless).
 * RATES[iF] is d/dt iF in component Ito (dimensionless).
 * RATES[iS] is d/dt iS in component Ito (dimensionless).
 * RATES[ap] is d/dt ap in component Ito (dimensionless).
 * RATES[iFp] is d/dt iFp in component Ito (dimensionless).
 * RATES[iSp] is d/dt iSp in component Ito (dimensionless).
 * RATES[d] is d/dt d in component ICaL (dimensionless).
 * RATES[ff] is d/dt ff in component ICaL (dimensionless).
 * RATES[fs] is d/dt fs in component ICaL (dimensionless).
 * RATES[fcaf] is d/dt fcaf in component ICaL (dimensionless).
 * RATES[fcas] is d/dt fcas in component ICaL (dimensionless).
 * RATES[jca] is d/dt jca in component ICaL (dimensionless).
 * RATES[ffp] is d/dt ffp in component ICaL (dimensionless).
 * RATES[fcafp] is d/dt fcafp in component ICaL (dimensionless).
 * RATES[nca] is d/dt nca in component ICaL (dimensionless).
 * RATES[IC1] is d/dt IC1 in component IKr (dimensionless).
 * RATES[IC2] is d/dt IC2 in component IKr (dimensionless).
 * RATES[C1] is d/dt C1 in component IKr (dimensionless).
 * RATES[C2] is d/dt C2 in component IKr (dimensionless).
 * RATES[O] is d/dt O in component IKr (dimensionless).
 * RATES[IO] is d/dt IO in component IKr (dimensionless).
 * RATES[IObound] is d/dt IObound in component IKr (dimensionless).
 * RATES[Obound] is d/dt Obound in component IKr (dimensionless).
 * RATES[Cbound] is d/dt Cbound in component IKr (dimensionless).
 * RATES[D] is d/dt D in component IKr (dimensionless).
 * RATES[xs1] is d/dt xs1 in component IKs (dimensionless).
 * RATES[xs2] is d/dt xs2 in component IKs (dimensionless).
 * RATES[xk1] is d/dt xk1 in component IK1 (dimensionless).
 * RATES[Jrelnp] is d/dt Jrelnp in component ryr (dimensionless).
 * RATES[Jrelp] is d/dt Jrelp in component ryr (dimensionless).
 */


ohara_rudy_cipa_v1_2017::ohara_rudy_cipa_v1_2017()
{
algebraic_size = 200;
constants_size = 206;
states_size = 50;
ALGEBRAIC = new double[algebraic_size];
CONSTANTS = new double[constants_size];
RATES = new double[states_size];
STATES = new double[states_size];
}

ohara_rudy_cipa_v1_2017::~ohara_rudy_cipa_v1_2017()
{
delete []ALGEBRAIC;
delete []CONSTANTS;
delete []RATES;
delete []STATES;
}

void ohara_rudy_cipa_v1_2017::initConsts()
{
  ___initConsts(0.);
}

void ohara_rudy_cipa_v1_2017::initConsts(double type)
{
  ___initConsts(type);
}

void ohara_rudy_cipa_v1_2017::initConsts(double type, double conc, const double *hill, const double *herg)
{
  ___initConsts(type);
  std::cout << "Celltype: " << CONSTANTS[celltype] << std::endl;
  std::cout << "Control Hill inhibition " << CONSTANTS[PCa] << " " << CONSTANTS[GK1] << " " << CONSTANTS[GKs] << " " << CONSTANTS[GNaL] << " " << CONSTANTS[GNa] << " " << CONSTANTS[Gto] <<std::endl;
  ___applyDrugEffect(conc, hill);
  std::cout << "After drug " << CONSTANTS[PCa] << " " << CONSTANTS[GK1] << " " << CONSTANTS[GKs] << " " << CONSTANTS[GNaL] << " " << CONSTANTS[GNa] << " " << CONSTANTS[Gto] << std::endl;
  std::cout << "Control hERG binding " << CONSTANTS[Kmax] << " " << CONSTANTS[Ku] << " " << CONSTANTS[n] << " " << CONSTANTS[halfmax] << " " << CONSTANTS[Vhalf] << " " << CONSTANTS[Kt] << " " << CONSTANTS[cnc] << " " << std::endl;
  ___applyHERGBinding(conc, herg);
  std::cout << "After drug " << CONSTANTS[Kmax] << " " << CONSTANTS[Ku] << " " << CONSTANTS[n] << " " << CONSTANTS[halfmax] << " " << CONSTANTS[Vhalf] << " " << CONSTANTS[Kt] << " " << CONSTANTS[cnc] << " " << std::endl;
}

void ohara_rudy_cipa_v1_2017::___initConsts(double type)
{
CONSTANTS[celltype] = type;
CONSTANTS[nao] = 140;
CONSTANTS[cao] = 1.8;
CONSTANTS[ko] = 5.4;
CONSTANTS[R] = 8314;
CONSTANTS[T] = 310;
CONSTANTS[F] = 96485;
CONSTANTS[zna] = 1;
CONSTANTS[zca] = 2;
CONSTANTS[zk] = 1;
CONSTANTS[L] = 0.01;
CONSTANTS[rad] = 0.0011;
STATES[V] = -88.00190465;
CONSTANTS[stim_start] = 10;
CONSTANTS[stim_end] = 100000000000000000;
CONSTANTS[amp] = -80;
CONSTANTS[BCL] = 1000;
CONSTANTS[duration] = 0.5;
CONSTANTS[KmCaMK] = 0.15;
CONSTANTS[aCaMK] = 0.05;
CONSTANTS[bCaMK] = 0.00068;
CONSTANTS[CaMKo] = 0.05;
CONSTANTS[KmCaM] = 0.0015;
STATES[CaMKt] = 0.0125840447;
STATES[cass] = 8.49e-05;
CONSTANTS[cmdnmax_b] = 0.05;
CONSTANTS[kmcmdn] = 0.00238;
CONSTANTS[trpnmax] = 0.07;
CONSTANTS[kmtrpn] = 0.0005;
CONSTANTS[BSRmax] = 0.047;
CONSTANTS[KmBSR] = 0.00087;
CONSTANTS[BSLmax] = 1.124;
CONSTANTS[KmBSL] = 0.0087;
CONSTANTS[csqnmax] = 10;
CONSTANTS[kmcsqn] = 0.8;
STATES[nai] = 7.268004498;
STATES[nass] = 7.268089977;
STATES[ki] = 144.6555918;
STATES[kss] = 144.6555651;
STATES[cansr] = 1.619574538;
STATES[cajsr] = 1.571234014;
STATES[cai] = 8.6e-05;
CONSTANTS[cm] = 1;
CONSTANTS[PKNa] = 0.01833;
CONSTANTS[mssV1] = 39.57;
CONSTANTS[mssV2] = 9.871;
CONSTANTS[mtV1] = 11.64;
CONSTANTS[mtV2] = 34.77;
CONSTANTS[mtD1] = 6.765;
CONSTANTS[mtD2] = 8.552;
CONSTANTS[mtV3] = 77.42;
CONSTANTS[mtV4] = 5.955;
STATES[m] = 0.007344121102;
CONSTANTS[hssV1] = 82.9;
CONSTANTS[hssV2] = 6.086;
CONSTANTS[Ahf] = 0.99;
STATES[hf] = 0.6981071913;
STATES[hs] = 0.6980895801;
CONSTANTS[GNa] = 75;
CONSTANTS[shift_INa_inact] = 0;
STATES[j] = 0.6979908432;
STATES[hsp] = 0.4549485525;
STATES[jp] = 0.6979245865;
STATES[mL] = 0.0001882617273;
CONSTANTS[thL] = 200;
STATES[hL] = 0.5008548855;
STATES[hLp] = 0.2693065357;
CONSTANTS[GNaL_b] = 0.019957499999999975;
CONSTANTS[Gto_b] = 0.02;
STATES[a] = 0.001001097687;
STATES[iF] = 0.9995541745;
STATES[iS] = 0.5865061736;
STATES[ap] = 0.0005100862934;
STATES[iFp] = 0.9995541823;
STATES[iSp] = 0.6393399482;
CONSTANTS[Kmn] = 0.002;
CONSTANTS[k2n] = 1000;
CONSTANTS[PCa_b] = 0.0001007;
STATES[d] = 2.34e-9;
STATES[ff] = 0.9999999909;
STATES[fs] = 0.9102412777;
STATES[fcaf] = 0.9999999909;
STATES[fcas] = 0.9998046777;
STATES[jca] = 0.9999738312;
STATES[ffp] = 0.9999999909;
STATES[fcafp] = 0.9999999909;
STATES[nca] = 0.002749414044;
CONSTANTS[GKr_b] = 0.04658545454545456;
STATES[IC1] = 0.999637;
STATES[IC2] = 6.83208e-05;
STATES[C1] = 1.80145e-08;
STATES[C2] = 8.26619e-05;
STATES[O] = 0.00015551;
STATES[IO] = 5.67623e-05;
STATES[IObound] = 0;
STATES[Obound] = 0;
STATES[Cbound] = 0;
STATES[D] = 0;
CONSTANTS[A1] = 0.0264;
CONSTANTS[B1] = 4.631E-05;
CONSTANTS[q1] = 4.843;
CONSTANTS[A2] = 4.986E-06;
CONSTANTS[B2] = -0.004226;
CONSTANTS[q2] = 4.23;
CONSTANTS[A3] = 0.001214;
CONSTANTS[B3] = 0.008516;
CONSTANTS[q3] = 4.962;
CONSTANTS[A4] = 1.854E-05;
CONSTANTS[B4] = -0.04641;
CONSTANTS[q4] = 3.769;
CONSTANTS[A11] = 0.0007868;
CONSTANTS[B11] = 1.535E-08;
CONSTANTS[q11] = 4.942;
CONSTANTS[A21] = 5.455E-06;
CONSTANTS[B21] = -0.1688;
CONSTANTS[q21] = 4.156;
CONSTANTS[A31] = 0.005509;
CONSTANTS[B31] = 7.771E-09;
CONSTANTS[q31] = 4.22;
CONSTANTS[A41] = 0.001416;
CONSTANTS[B41] = -0.02877;
CONSTANTS[q41] = 1.459;
CONSTANTS[A51] = 0.4492;
CONSTANTS[B51] = 0.008595;
CONSTANTS[q51] = 5;
CONSTANTS[A52] = 0.3181;
CONSTANTS[B52] = 3.613E-08;
CONSTANTS[q52] = 4.663;
CONSTANTS[A53] = 0.149;
CONSTANTS[B53] = 0.004668;
CONSTANTS[q53] = 2.412;
CONSTANTS[A61] = 0.01241;
CONSTANTS[B61] = 0.1725;
CONSTANTS[q61] = 5.568;
CONSTANTS[A62] = 0.3226;
CONSTANTS[B62] = -0.0006575;
CONSTANTS[q62] = 5;
CONSTANTS[A63] = 0.008978;
CONSTANTS[B63] = -0.02215;
CONSTANTS[q63] = 5.682;
CONSTANTS[Kmax] = 0;
CONSTANTS[Ku] = 0;
CONSTANTS[n] = 1;
CONSTANTS[halfmax] = 1;
CONSTANTS[Kt] = 0;
CONSTANTS[Vhalf] = 1;
CONSTANTS[Temp] = 37;
CONSTANTS[GKs_b] = 0.006358000000000001;
CONSTANTS[txs1_max] = 817.3;
STATES[xs1] = 0.2707758025;
STATES[xs2] = 0.0001928503426;
CONSTANTS[GK1_b] = 0.3239783999999998;
STATES[xk1] = 0.9967597594;
CONSTANTS[kna1] = 15;
CONSTANTS[kna2] = 5;
CONSTANTS[kna3] = 88.12;
CONSTANTS[kasymm] = 12.5;
CONSTANTS[wna] = 6e4;
CONSTANTS[wca] = 6e4;
CONSTANTS[wnaca] = 5e3;
CONSTANTS[kcaon] = 1.5e6;
CONSTANTS[kcaoff] = 5e3;
CONSTANTS[qna] = 0.5224;
CONSTANTS[qca] = 0.167;
CONSTANTS[KmCaAct] = 150e-6;
CONSTANTS[Gncx_b] = 0.0008;
CONSTANTS[k1p] = 949.5;
CONSTANTS[k1m] = 182.4;
CONSTANTS[k2p] = 687.2;
CONSTANTS[k2m] = 39.4;
CONSTANTS[k3p] = 1899;
CONSTANTS[k3m] = 79300;
CONSTANTS[k4p] = 639;
CONSTANTS[k4m] = 40;
CONSTANTS[Knai0] = 9.073;
CONSTANTS[Knao0] = 27.78;
CONSTANTS[delta] = -0.155;
CONSTANTS[Kki] = 0.5;
CONSTANTS[Kko] = 0.3582;
CONSTANTS[MgADP] = 0.05;
CONSTANTS[MgATP] = 9.8;
CONSTANTS[Kmgatp] = 1.698e-7;
CONSTANTS[H] = 1e-7;
CONSTANTS[eP] = 4.2;
CONSTANTS[Khp] = 1.698e-7;
CONSTANTS[Knap] = 224;
CONSTANTS[Kxkur] = 292;
CONSTANTS[Pnak_b] = 30;
CONSTANTS[GKb_b] = 0.003;
CONSTANTS[PNab] = 3.75e-10;
CONSTANTS[PCab] = 2.5e-8;
CONSTANTS[GpCa] = 0.0005;
CONSTANTS[KmCap] = 0.0005;
CONSTANTS[bt] = 4.75;
STATES[Jrelnp] = 2.5e-7;
STATES[Jrelp] = 3.12e-7;
CONSTANTS[Jrel_scaling_factor] = 1.0;
CONSTANTS[Jup_b] = 1.0;
CONSTANTS[frt] = CONSTANTS[F]/( CONSTANTS[R]*CONSTANTS[T]);
CONSTANTS[cmdnmax] = (CONSTANTS[celltype]==1.00000 ?  CONSTANTS[cmdnmax_b]*1.30000 : CONSTANTS[cmdnmax_b]);
CONSTANTS[Ahs] = 1.00000 - CONSTANTS[Ahf];
CONSTANTS[thLp] =  3.00000*CONSTANTS[thL];
CONSTANTS[GNaL] = (CONSTANTS[celltype]==1.00000 ?  CONSTANTS[GNaL_b]*0.600000 : CONSTANTS[GNaL_b]);
CONSTANTS[Gto] = (CONSTANTS[celltype]==1.00000 ?  CONSTANTS[Gto_b]*4.00000 : CONSTANTS[celltype]==2.00000 ?  CONSTANTS[Gto_b]*4.00000 : CONSTANTS[Gto_b]);
CONSTANTS[Aff] = 0.600000;
CONSTANTS[PCa] = (CONSTANTS[celltype]==1.00000 ?  CONSTANTS[PCa_b]*1.20000 : CONSTANTS[celltype]==2.00000 ?  CONSTANTS[PCa_b]*2.50000 : CONSTANTS[PCa_b]);
CONSTANTS[tjca] = 75.0000;
CONSTANTS[v0_CaL] = 0.000000;
CONSTANTS[GKr] = (CONSTANTS[celltype]==1.00000 ?  CONSTANTS[GKr_b]*1.30000 : CONSTANTS[celltype]==2.00000 ?  CONSTANTS[GKr_b]*0.800000 : CONSTANTS[GKr_b]);
CONSTANTS[GKs] = (CONSTANTS[celltype]==1.00000 ?  CONSTANTS[GKs_b]*1.40000 : CONSTANTS[GKs_b]);
CONSTANTS[GK1] = (CONSTANTS[celltype]==1.00000 ?  CONSTANTS[GK1_b]*1.20000 : CONSTANTS[celltype]==2.00000 ?  CONSTANTS[GK1_b]*1.30000 : CONSTANTS[GK1_b]);
CONSTANTS[vcell] =  1000.00*3.14000*CONSTANTS[rad]*CONSTANTS[rad]*CONSTANTS[L];
CONSTANTS[GKb] = (CONSTANTS[celltype]==1.00000 ?  CONSTANTS[GKb_b]*0.600000 : CONSTANTS[GKb_b]);
CONSTANTS[v0_Nab] = 0.000000;
CONSTANTS[v0_Cab] = 0.000000;
CONSTANTS[a_rel] =  0.500000*CONSTANTS[bt];
CONSTANTS[btp] =  1.25000*CONSTANTS[bt];
CONSTANTS[upScale] = (CONSTANTS[celltype]==1.00000 ? 1.30000 : 1.00000);
CONSTANTS[cnc] = 0.000000;
CONSTANTS[ffrt] =  CONSTANTS[F]*CONSTANTS[frt];
CONSTANTS[Afs] = 1.00000 - CONSTANTS[Aff];
CONSTANTS[PCap] =  1.10000*CONSTANTS[PCa];
CONSTANTS[PCaNa] =  0.00125000*CONSTANTS[PCa];
CONSTANTS[PCaK] =  0.000357400*CONSTANTS[PCa];
CONSTANTS[B_1] =  2.00000*CONSTANTS[frt];
CONSTANTS[B_2] = CONSTANTS[frt];
CONSTANTS[B_3] = CONSTANTS[frt];
CONSTANTS[Ageo] =  2.00000*3.14000*CONSTANTS[rad]*CONSTANTS[rad]+ 2.00000*3.14000*CONSTANTS[rad]*CONSTANTS[L];
CONSTANTS[B_Nab] = CONSTANTS[frt];
CONSTANTS[B_Cab] =  2.00000*CONSTANTS[frt];
CONSTANTS[a_relp] =  0.500000*CONSTANTS[btp];
CONSTANTS[PCaNap] =  0.00125000*CONSTANTS[PCap];
CONSTANTS[PCaKp] =  0.000357400*CONSTANTS[PCap];
CONSTANTS[Acap] =  2.00000*CONSTANTS[Ageo];
CONSTANTS[vmyo] =  0.680000*CONSTANTS[vcell];
CONSTANTS[vnsr] =  0.0552000*CONSTANTS[vcell];
CONSTANTS[vjsr] =  0.00480000*CONSTANTS[vcell];
CONSTANTS[vss] =  0.0200000*CONSTANTS[vcell];
CONSTANTS[h10_i] = CONSTANTS[kasymm]+1.00000+ (CONSTANTS[nao]/CONSTANTS[kna1])*(1.00000+CONSTANTS[nao]/CONSTANTS[kna2]);
CONSTANTS[h11_i] = ( CONSTANTS[nao]*CONSTANTS[nao])/( CONSTANTS[h10_i]*CONSTANTS[kna1]*CONSTANTS[kna2]);
CONSTANTS[h12_i] = 1.00000/CONSTANTS[h10_i];
CONSTANTS[k1_i] =  CONSTANTS[h12_i]*CONSTANTS[cao]*CONSTANTS[kcaon];
CONSTANTS[k2_i] = CONSTANTS[kcaoff];
CONSTANTS[k5_i] = CONSTANTS[kcaoff];
CONSTANTS[Gncx] = (CONSTANTS[celltype]==1.00000 ?  CONSTANTS[Gncx_b]*1.10000 : CONSTANTS[celltype]==2.00000 ?  CONSTANTS[Gncx_b]*1.40000 : CONSTANTS[Gncx_b]);
CONSTANTS[h10_ss] = CONSTANTS[kasymm]+1.00000+ (CONSTANTS[nao]/CONSTANTS[kna1])*(1.00000+CONSTANTS[nao]/CONSTANTS[kna2]);
CONSTANTS[h11_ss] = ( CONSTANTS[nao]*CONSTANTS[nao])/( CONSTANTS[h10_ss]*CONSTANTS[kna1]*CONSTANTS[kna2]);
CONSTANTS[h12_ss] = 1.00000/CONSTANTS[h10_ss];
CONSTANTS[k1_ss] =  CONSTANTS[h12_ss]*CONSTANTS[cao]*CONSTANTS[kcaon];
CONSTANTS[k2_ss] = CONSTANTS[kcaoff];
CONSTANTS[k5_ss] = CONSTANTS[kcaoff];
CONSTANTS[b1] =  CONSTANTS[k1m]*CONSTANTS[MgADP];
CONSTANTS[a2] = CONSTANTS[k2p];
CONSTANTS[a4] = (( CONSTANTS[k4p]*CONSTANTS[MgATP])/CONSTANTS[Kmgatp])/(1.00000+CONSTANTS[MgATP]/CONSTANTS[Kmgatp]);
CONSTANTS[Pnak] = (CONSTANTS[celltype]==1.00000 ?  CONSTANTS[Pnak_b]*0.900000 : CONSTANTS[celltype]==2.00000 ?  CONSTANTS[Pnak_b]*0.700000 : CONSTANTS[Pnak_b]);
}

void ohara_rudy_cipa_v1_2017::computeRates( double TIME, double *CONSTANTS, double *RATES, double *STATES, double *ALGEBRAIC ){
ALGEBRAIC[hLss] = 1.00000/(1.00000+exp((STATES[V]+87.6100)/7.48800));
ALGEBRAIC[hLssp] = 1.00000/(1.00000+exp((STATES[V]+93.8100)/7.48800));
ALGEBRAIC[mss] = 1.00000/(1.00000+exp(- (STATES[V]+CONSTANTS[mssV1])/CONSTANTS[mssV2]));
ALGEBRAIC[tm] = 1.00000/( CONSTANTS[mtD1]*exp((STATES[V]+CONSTANTS[mtV1])/CONSTANTS[mtV2])+ CONSTANTS[mtD2]*exp(- (STATES[V]+CONSTANTS[mtV3])/CONSTANTS[mtV4]));
ALGEBRAIC[hss] = 1.00000/(1.00000+exp(((STATES[V]+CONSTANTS[hssV1]) - CONSTANTS[shift_INa_inact])/CONSTANTS[hssV2]));
ALGEBRAIC[thf] = 1.00000/( 1.43200e-05*exp(- ((STATES[V]+1.19600) - CONSTANTS[shift_INa_inact])/6.28500)+ 6.14900*exp(((STATES[V]+0.509600) - CONSTANTS[shift_INa_inact])/20.2700));
ALGEBRAIC[ths] = 1.00000/( 0.00979400*exp(- ((STATES[V]+17.9500) - CONSTANTS[shift_INa_inact])/28.0500)+ 0.334300*exp(((STATES[V]+5.73000) - CONSTANTS[shift_INa_inact])/56.6600));
ALGEBRAIC[ass] = 1.00000/(1.00000+exp(- (STATES[V] - 14.3400)/14.8200));
ALGEBRAIC[ta] = 1.05150/(1.00000/( 1.20890*(1.00000+exp(- (STATES[V] - 18.4099)/29.3814)))+3.50000/(1.00000+exp((STATES[V]+100.000)/29.3814)));
ALGEBRAIC[dss] = 1.00000/(1.00000+exp(- (STATES[V]+3.94000)/4.23000));
ALGEBRAIC[td] = 0.600000+1.00000/(exp( - 0.0500000*(STATES[V]+6.00000))+exp( 0.0900000*(STATES[V]+14.0000)));
ALGEBRAIC[fss] = 1.00000/(1.00000+exp((STATES[V]+19.5800)/3.69600));
ALGEBRAIC[tff] = 7.00000+1.00000/( 0.00450000*exp(- (STATES[V]+20.0000)/10.0000)+ 0.00450000*exp((STATES[V]+20.0000)/10.0000));
ALGEBRAIC[tfs] = 1000.00+1.00000/( 3.50000e-05*exp(- (STATES[V]+5.00000)/4.00000)+ 3.50000e-05*exp((STATES[V]+5.00000)/6.00000));
ALGEBRAIC[fcass] = ALGEBRAIC[fss];
ALGEBRAIC[km2n] =  STATES[jca]*1.00000;
ALGEBRAIC[anca] = 1.00000/(CONSTANTS[k2n]/ALGEBRAIC[km2n]+pow(1.00000+CONSTANTS[Kmn]/STATES[cass], 4.00000));
ALGEBRAIC[xs1ss] = 1.00000/(1.00000+exp(- (STATES[V]+11.6000)/8.93200));
ALGEBRAIC[txs1] = CONSTANTS[txs1_max]+1.00000/( 0.000232600*exp((STATES[V]+48.2800)/17.8000)+ 0.00129200*exp(- (STATES[V]+210.000)/230.000));
ALGEBRAIC[xk1ss] = 1.00000/(1.00000+exp(- (STATES[V]+ 2.55380*CONSTANTS[ko]+144.590)/( 1.56920*CONSTANTS[ko]+3.81150)));
ALGEBRAIC[txk1] = 122.200/(exp(- (STATES[V]+127.200)/20.3600)+exp((STATES[V]+236.800)/69.3300));
ALGEBRAIC[CaMKb] = ( CONSTANTS[CaMKo]*(1.00000 - STATES[CaMKt]))/(1.00000+CONSTANTS[KmCaM]/STATES[cass]);
ALGEBRAIC[jss] = ALGEBRAIC[hss];
ALGEBRAIC[tj] = 2.03800+1.00000/( 0.0213600*exp(- ((STATES[V]+100.600) - CONSTANTS[shift_INa_inact])/8.28100)+ 0.305200*exp(((STATES[V]+0.994100) - CONSTANTS[shift_INa_inact])/38.4500));
ALGEBRAIC[assp] = 1.00000/(1.00000+exp(- (STATES[V] - 24.3400)/14.8200));
ALGEBRAIC[tfcaf] = 7.00000+1.00000/( 0.0400000*exp(- (STATES[V] - 4.00000)/7.00000)+ 0.0400000*exp((STATES[V] - 4.00000)/7.00000));
ALGEBRAIC[tfcas] = 100.000+1.00000/( 0.000120000*exp(- STATES[V]/3.00000)+ 0.000120000*exp(STATES[V]/7.00000));
ALGEBRAIC[tffp] =  2.50000*ALGEBRAIC[tff];
ALGEBRAIC[xs2ss] = ALGEBRAIC[xs1ss];
ALGEBRAIC[txs2] = 1.00000/( 0.0100000*exp((STATES[V] - 50.0000)/20.0000)+ 0.0193000*exp(- (STATES[V]+66.5400)/31.0000));
ALGEBRAIC[hssp] = 1.00000/(1.00000+exp(((STATES[V]+89.1000) - CONSTANTS[shift_INa_inact])/6.08600));
ALGEBRAIC[thsp] =  3.00000*ALGEBRAIC[ths];
ALGEBRAIC[tjp] =  1.46000*ALGEBRAIC[tj];
ALGEBRAIC[mLss] = 1.00000/(1.00000+exp(- (STATES[V]+42.8500)/5.26400));
ALGEBRAIC[tmL] = ALGEBRAIC[tm];
ALGEBRAIC[tfcafp] =  2.50000*ALGEBRAIC[tfcaf];
ALGEBRAIC[iss] = 1.00000/(1.00000+exp((STATES[V]+43.9400)/5.71100));
ALGEBRAIC[delta_epi] = (CONSTANTS[celltype]==1.00000 ? 1.00000 - 0.950000/(1.00000+exp((STATES[V]+70.0000)/5.00000)) : 1.00000);
ALGEBRAIC[tiF_b] = 4.56200+1.00000/( 0.393300*exp(- (STATES[V]+100.000)/100.000)+ 0.0800400*exp((STATES[V]+50.0000)/16.5900));
ALGEBRAIC[tiF] =  ALGEBRAIC[tiF_b]*ALGEBRAIC[delta_epi];
ALGEBRAIC[tiS_b] = 23.6200+1.00000/( 0.00141600*exp(- (STATES[V]+96.5200)/59.0500)+ 1.78000e-08*exp((STATES[V]+114.100)/8.07900));
ALGEBRAIC[tiS] =  ALGEBRAIC[tiS_b]*ALGEBRAIC[delta_epi];
ALGEBRAIC[dti_develop] = 1.35400+0.000100000/(exp((STATES[V] - 167.400)/15.8900)+exp(- (STATES[V] - 12.2300)/0.215400));
ALGEBRAIC[dti_recover] = 1.00000 - 0.500000/(1.00000+exp((STATES[V]+70.0000)/20.0000));
ALGEBRAIC[tiFp] =  ALGEBRAIC[dti_develop]*ALGEBRAIC[dti_recover]*ALGEBRAIC[tiF];
ALGEBRAIC[tiSp] =  ALGEBRAIC[dti_develop]*ALGEBRAIC[dti_recover]*ALGEBRAIC[tiS];
ALGEBRAIC[f] =  CONSTANTS[Aff]*STATES[ff]+ CONSTANTS[Afs]*STATES[fs];
ALGEBRAIC[Afcaf] = 0.300000+0.600000/(1.00000+exp((STATES[V] - 10.0000)/10.0000));
ALGEBRAIC[Afcas] = 1.00000 - ALGEBRAIC[Afcaf];
ALGEBRAIC[fca] =  ALGEBRAIC[Afcaf]*STATES[fcaf]+ ALGEBRAIC[Afcas]*STATES[fcas];
ALGEBRAIC[fp] =  CONSTANTS[Aff]*STATES[ffp]+ CONSTANTS[Afs]*STATES[fs];
ALGEBRAIC[fcap] =  ALGEBRAIC[Afcaf]*STATES[fcafp]+ ALGEBRAIC[Afcas]*STATES[fcas];
ALGEBRAIC[vfrt] =  STATES[V]*CONSTANTS[frt];
ALGEBRAIC[A_1] = ( 4.00000*CONSTANTS[ffrt]*( STATES[cass]*exp( 2.00000*ALGEBRAIC[vfrt]) -  0.341000*CONSTANTS[cao]))/CONSTANTS[B_1];
ALGEBRAIC[U_1] =  CONSTANTS[B_1]*(STATES[V] - CONSTANTS[v0_CaL]);
ALGEBRAIC[PhiCaL] = (- 1.00000e-07<=ALGEBRAIC[U_1]&&ALGEBRAIC[U_1]<=1.00000e-07 ?  ALGEBRAIC[A_1]*(1.00000 -  0.500000*ALGEBRAIC[U_1]) : ( ALGEBRAIC[A_1]*ALGEBRAIC[U_1])/(exp(ALGEBRAIC[U_1]) - 1.00000));
ALGEBRAIC[CaMKa] = ALGEBRAIC[CaMKb]+STATES[CaMKt];
ALGEBRAIC[fICaLp] = 1.00000/(1.00000+CONSTANTS[KmCaMK]/ALGEBRAIC[CaMKa]);
ALGEBRAIC[ICaL] =  (1.00000 - ALGEBRAIC[fICaLp])*CONSTANTS[PCa]*ALGEBRAIC[PhiCaL]*STATES[d]*( ALGEBRAIC[f]*(1.00000 - STATES[nca])+ STATES[jca]*ALGEBRAIC[fca]*STATES[nca])+ ALGEBRAIC[fICaLp]*CONSTANTS[PCap]*ALGEBRAIC[PhiCaL]*STATES[d]*( ALGEBRAIC[fp]*(1.00000 - STATES[nca])+ STATES[jca]*ALGEBRAIC[fcap]*STATES[nca]);
ALGEBRAIC[Jrel_inf_temp] = ( CONSTANTS[a_rel]*- ALGEBRAIC[ICaL])/(1.00000+ 1.00000*pow(1.50000/STATES[cajsr], 8.00000));
ALGEBRAIC[Jrel_inf] = (CONSTANTS[celltype]==2.00000 ?  ALGEBRAIC[Jrel_inf_temp]*1.70000 : ALGEBRAIC[Jrel_inf_temp]);
ALGEBRAIC[tau_rel_temp] = CONSTANTS[bt]/(1.00000+0.0123000/STATES[cajsr]);
ALGEBRAIC[tau_rel] = (ALGEBRAIC[tau_rel_temp]<0.00100000 ? 0.00100000 : ALGEBRAIC[tau_rel_temp]);
ALGEBRAIC[Jrel_temp] = ( CONSTANTS[a_relp]*- ALGEBRAIC[ICaL])/(1.00000+pow(1.50000/STATES[cajsr], 8.00000));
ALGEBRAIC[Jrel_infp] = (CONSTANTS[celltype]==2.00000 ?  ALGEBRAIC[Jrel_temp]*1.70000 : ALGEBRAIC[Jrel_temp]);
ALGEBRAIC[tau_relp_temp] = CONSTANTS[btp]/(1.00000+0.0123000/STATES[cajsr]);
ALGEBRAIC[tau_relp] = (ALGEBRAIC[tau_relp_temp]<0.00100000 ? 0.00100000 : ALGEBRAIC[tau_relp_temp]);
ALGEBRAIC[EK] =  (( CONSTANTS[R]*CONSTANTS[T])/CONSTANTS[F])*log(CONSTANTS[ko]/STATES[ki]);
ALGEBRAIC[AiF] = 1.00000/(1.00000+exp((STATES[V] - 213.600)/151.200));
ALGEBRAIC[AiS] = 1.00000 - ALGEBRAIC[AiF];
ALGEBRAIC[i] =  ALGEBRAIC[AiF]*STATES[iF]+ ALGEBRAIC[AiS]*STATES[iS];
ALGEBRAIC[ip] =  ALGEBRAIC[AiF]*STATES[iFp]+ ALGEBRAIC[AiS]*STATES[iSp];
ALGEBRAIC[fItop] = 1.00000/(1.00000+CONSTANTS[KmCaMK]/ALGEBRAIC[CaMKa]);
ALGEBRAIC[Ito] =  CONSTANTS[Gto]*(STATES[V] - ALGEBRAIC[EK])*( (1.00000 - ALGEBRAIC[fItop])*STATES[a]*ALGEBRAIC[i]+ ALGEBRAIC[fItop]*STATES[ap]*ALGEBRAIC[ip]);
ALGEBRAIC[IKr] =  CONSTANTS[GKr]* pow((CONSTANTS[ko]/5.40000), 1.0 / 2)*STATES[O]*(STATES[V] - ALGEBRAIC[EK]);
ALGEBRAIC[EKs] =  (( CONSTANTS[R]*CONSTANTS[T])/CONSTANTS[F])*log((CONSTANTS[ko]+ CONSTANTS[PKNa]*CONSTANTS[nao])/(STATES[ki]+ CONSTANTS[PKNa]*STATES[nai]));
ALGEBRAIC[KsCa] = 1.00000+0.600000/(1.00000+pow(3.80000e-05/STATES[cai], 1.40000));
ALGEBRAIC[IKs] =  CONSTANTS[GKs]*ALGEBRAIC[KsCa]*STATES[xs1]*STATES[xs2]*(STATES[V] - ALGEBRAIC[EKs]);
ALGEBRAIC[rk1] = 1.00000/(1.00000+exp(((STATES[V]+105.800) -  2.60000*CONSTANTS[ko])/9.49300));
ALGEBRAIC[IK1] =  CONSTANTS[GK1]* pow(CONSTANTS[ko], 1.0 / 2)*ALGEBRAIC[rk1]*STATES[xk1]*(STATES[V] - ALGEBRAIC[EK]);
ALGEBRAIC[Knao] =  CONSTANTS[Knao0]*exp(( (1.00000 - CONSTANTS[delta])*STATES[V]*CONSTANTS[F])/( 3.00000*CONSTANTS[R]*CONSTANTS[T]));
ALGEBRAIC[a3] = ( CONSTANTS[k3p]*pow(CONSTANTS[ko]/CONSTANTS[Kko], 2.00000))/((pow(1.00000+CONSTANTS[nao]/ALGEBRAIC[Knao], 3.00000)+pow(1.00000+CONSTANTS[ko]/CONSTANTS[Kko], 2.00000)) - 1.00000);
ALGEBRAIC[P] = CONSTANTS[eP]/(1.00000+CONSTANTS[H]/CONSTANTS[Khp]+STATES[nai]/CONSTANTS[Knap]+STATES[ki]/CONSTANTS[Kxkur]);
ALGEBRAIC[b3] = ( CONSTANTS[k3m]*ALGEBRAIC[P]*CONSTANTS[H])/(1.00000+CONSTANTS[MgATP]/CONSTANTS[Kmgatp]);
ALGEBRAIC[Knai] =  CONSTANTS[Knai0]*exp(( CONSTANTS[delta]*STATES[V]*CONSTANTS[F])/( 3.00000*CONSTANTS[R]*CONSTANTS[T]));
ALGEBRAIC[a1] = ( CONSTANTS[k1p]*pow(STATES[nai]/ALGEBRAIC[Knai], 3.00000))/((pow(1.00000+STATES[nai]/ALGEBRAIC[Knai], 3.00000)+pow(1.00000+STATES[ki]/CONSTANTS[Kki], 2.00000)) - 1.00000);
ALGEBRAIC[b2] = ( CONSTANTS[k2m]*pow(CONSTANTS[nao]/ALGEBRAIC[Knao], 3.00000))/((pow(1.00000+CONSTANTS[nao]/ALGEBRAIC[Knao], 3.00000)+pow(1.00000+CONSTANTS[ko]/CONSTANTS[Kko], 2.00000)) - 1.00000);
ALGEBRAIC[b4] = ( CONSTANTS[k4m]*pow(STATES[ki]/CONSTANTS[Kki], 2.00000))/((pow(1.00000+STATES[nai]/ALGEBRAIC[Knai], 3.00000)+pow(1.00000+STATES[ki]/CONSTANTS[Kki], 2.00000)) - 1.00000);
ALGEBRAIC[x1] =  CONSTANTS[a4]*ALGEBRAIC[a1]*CONSTANTS[a2]+ ALGEBRAIC[b2]*ALGEBRAIC[b4]*ALGEBRAIC[b3]+ CONSTANTS[a2]*ALGEBRAIC[b4]*ALGEBRAIC[b3]+ ALGEBRAIC[b3]*ALGEBRAIC[a1]*CONSTANTS[a2];
ALGEBRAIC[x2] =  ALGEBRAIC[b2]*CONSTANTS[b1]*ALGEBRAIC[b4]+ ALGEBRAIC[a1]*CONSTANTS[a2]*ALGEBRAIC[a3]+ ALGEBRAIC[a3]*CONSTANTS[b1]*ALGEBRAIC[b4]+ CONSTANTS[a2]*ALGEBRAIC[a3]*ALGEBRAIC[b4];
ALGEBRAIC[x3] =  CONSTANTS[a2]*ALGEBRAIC[a3]*CONSTANTS[a4]+ ALGEBRAIC[b3]*ALGEBRAIC[b2]*CONSTANTS[b1]+ ALGEBRAIC[b2]*CONSTANTS[b1]*CONSTANTS[a4]+ ALGEBRAIC[a3]*CONSTANTS[a4]*CONSTANTS[b1];
ALGEBRAIC[x4] =  ALGEBRAIC[b4]*ALGEBRAIC[b3]*ALGEBRAIC[b2]+ ALGEBRAIC[a3]*CONSTANTS[a4]*ALGEBRAIC[a1]+ ALGEBRAIC[b2]*CONSTANTS[a4]*ALGEBRAIC[a1]+ ALGEBRAIC[b3]*ALGEBRAIC[b2]*ALGEBRAIC[a1];
ALGEBRAIC[E1] = ALGEBRAIC[x1]/(ALGEBRAIC[x1]+ALGEBRAIC[x2]+ALGEBRAIC[x3]+ALGEBRAIC[x4]);
ALGEBRAIC[E2] = ALGEBRAIC[x2]/(ALGEBRAIC[x1]+ALGEBRAIC[x2]+ALGEBRAIC[x3]+ALGEBRAIC[x4]);
ALGEBRAIC[JnakNa] =  3.00000*( ALGEBRAIC[E1]*ALGEBRAIC[a3] -  ALGEBRAIC[E2]*ALGEBRAIC[b3]);
ALGEBRAIC[E3] = ALGEBRAIC[x3]/(ALGEBRAIC[x1]+ALGEBRAIC[x2]+ALGEBRAIC[x3]+ALGEBRAIC[x4]);
ALGEBRAIC[E4] = ALGEBRAIC[x4]/(ALGEBRAIC[x1]+ALGEBRAIC[x2]+ALGEBRAIC[x3]+ALGEBRAIC[x4]);
ALGEBRAIC[JnakK] =  2.00000*( ALGEBRAIC[E4]*CONSTANTS[b1] -  ALGEBRAIC[E3]*ALGEBRAIC[a1]);
ALGEBRAIC[INaK] =  CONSTANTS[Pnak]*( CONSTANTS[zna]*ALGEBRAIC[JnakNa]+ CONSTANTS[zk]*ALGEBRAIC[JnakK]);
ALGEBRAIC[xkb] = 1.00000/(1.00000+exp(- (STATES[V] - 14.4800)/18.3400));
ALGEBRAIC[IKb] =  CONSTANTS[GKb]*ALGEBRAIC[xkb]*(STATES[V] - ALGEBRAIC[EK]);
ALGEBRAIC[Istim] = (TIME>=CONSTANTS[stim_start]&&TIME<=CONSTANTS[stim_end]&&(TIME - CONSTANTS[stim_start]) -  floor((TIME - CONSTANTS[stim_start])/CONSTANTS[BCL])*CONSTANTS[BCL]<=CONSTANTS[duration] ? CONSTANTS[amp] : 0.000000);
ALGEBRAIC[JdiffK] = (STATES[kss] - STATES[ki])/2.00000;
ALGEBRAIC[A_3] = ( 0.750000*CONSTANTS[ffrt]*( STATES[kss]*exp(ALGEBRAIC[vfrt]) - CONSTANTS[ko]))/CONSTANTS[B_3];
ALGEBRAIC[U_3] =  CONSTANTS[B_3]*(STATES[V] - CONSTANTS[v0_CaL]);
ALGEBRAIC[PhiCaK] = (- 1.00000e-07<=ALGEBRAIC[U_3]&&ALGEBRAIC[U_3]<=1.00000e-07 ?  ALGEBRAIC[A_3]*(1.00000 -  0.500000*ALGEBRAIC[U_3]) : ( ALGEBRAIC[A_3]*ALGEBRAIC[U_3])/(exp(ALGEBRAIC[U_3]) - 1.00000));
ALGEBRAIC[ICaK] =  (1.00000 - ALGEBRAIC[fICaLp])*CONSTANTS[PCaK]*ALGEBRAIC[PhiCaK]*STATES[d]*( ALGEBRAIC[f]*(1.00000 - STATES[nca])+ STATES[jca]*ALGEBRAIC[fca]*STATES[nca])+ ALGEBRAIC[fICaLp]*CONSTANTS[PCaKp]*ALGEBRAIC[PhiCaK]*STATES[d]*( ALGEBRAIC[fp]*(1.00000 - STATES[nca])+ STATES[jca]*ALGEBRAIC[fcap]*STATES[nca]);
ALGEBRAIC[ENa] =  (( CONSTANTS[R]*CONSTANTS[T])/CONSTANTS[F])*log(CONSTANTS[nao]/STATES[nai]);
ALGEBRAIC[h] =  CONSTANTS[Ahf]*STATES[hf]+ CONSTANTS[Ahs]*STATES[hs];
ALGEBRAIC[hp] =  CONSTANTS[Ahf]*STATES[hf]+ CONSTANTS[Ahs]*STATES[hsp];
ALGEBRAIC[fINap] = 1.00000/(1.00000+CONSTANTS[KmCaMK]/ALGEBRAIC[CaMKa]);
ALGEBRAIC[INa] =  CONSTANTS[GNa]*(STATES[V] - ALGEBRAIC[ENa])*pow(STATES[m], 3.00000)*( (1.00000 - ALGEBRAIC[fINap])*ALGEBRAIC[h]*STATES[j]+ ALGEBRAIC[fINap]*ALGEBRAIC[hp]*STATES[jp]);
ALGEBRAIC[fINaLp] = 1.00000/(1.00000+CONSTANTS[KmCaMK]/ALGEBRAIC[CaMKa]);
ALGEBRAIC[INaL] =  CONSTANTS[GNaL]*(STATES[V] - ALGEBRAIC[ENa])*STATES[mL]*( (1.00000 - ALGEBRAIC[fINaLp])*STATES[hL]+ ALGEBRAIC[fINaLp]*STATES[hLp]);
ALGEBRAIC[allo_i] = 1.00000/(1.00000+pow(CONSTANTS[KmCaAct]/STATES[cai], 2.00000));
ALGEBRAIC[hna] = exp(( CONSTANTS[qna]*STATES[V]*CONSTANTS[F])/( CONSTANTS[R]*CONSTANTS[T]));
ALGEBRAIC[h7_i] = 1.00000+ (CONSTANTS[nao]/CONSTANTS[kna3])*(1.00000+1.00000/ALGEBRAIC[hna]);
ALGEBRAIC[h8_i] = CONSTANTS[nao]/( CONSTANTS[kna3]*ALGEBRAIC[hna]*ALGEBRAIC[h7_i]);
ALGEBRAIC[k3pp_i] =  ALGEBRAIC[h8_i]*CONSTANTS[wnaca];
ALGEBRAIC[h1_i] = 1.00000+ (STATES[nai]/CONSTANTS[kna3])*(1.00000+ALGEBRAIC[hna]);
ALGEBRAIC[h2_i] = ( STATES[nai]*ALGEBRAIC[hna])/( CONSTANTS[kna3]*ALGEBRAIC[h1_i]);
ALGEBRAIC[k4pp_i] =  ALGEBRAIC[h2_i]*CONSTANTS[wnaca];
ALGEBRAIC[h4_i] = 1.00000+ (STATES[nai]/CONSTANTS[kna1])*(1.00000+STATES[nai]/CONSTANTS[kna2]);
ALGEBRAIC[h5_i] = ( STATES[nai]*STATES[nai])/( ALGEBRAIC[h4_i]*CONSTANTS[kna1]*CONSTANTS[kna2]);
ALGEBRAIC[k7_i] =  ALGEBRAIC[h5_i]*ALGEBRAIC[h2_i]*CONSTANTS[wna];
ALGEBRAIC[k8_i] =  ALGEBRAIC[h8_i]*CONSTANTS[h11_i]*CONSTANTS[wna];
ALGEBRAIC[h9_i] = 1.00000/ALGEBRAIC[h7_i];
ALGEBRAIC[k3p_i] =  ALGEBRAIC[h9_i]*CONSTANTS[wca];
ALGEBRAIC[k3_i] = ALGEBRAIC[k3p_i]+ALGEBRAIC[k3pp_i];
ALGEBRAIC[hca] = exp(( CONSTANTS[qca]*STATES[V]*CONSTANTS[F])/( CONSTANTS[R]*CONSTANTS[T]));
ALGEBRAIC[h3_i] = 1.00000/ALGEBRAIC[h1_i];
ALGEBRAIC[k4p_i] = ( ALGEBRAIC[h3_i]*CONSTANTS[wca])/ALGEBRAIC[hca];
ALGEBRAIC[k4_i] = ALGEBRAIC[k4p_i]+ALGEBRAIC[k4pp_i];
ALGEBRAIC[h6_i] = 1.00000/ALGEBRAIC[h4_i];
ALGEBRAIC[k6_i] =  ALGEBRAIC[h6_i]*STATES[cai]*CONSTANTS[kcaon];
ALGEBRAIC[x1_i] =  CONSTANTS[k2_i]*ALGEBRAIC[k4_i]*(ALGEBRAIC[k7_i]+ALGEBRAIC[k6_i])+ CONSTANTS[k5_i]*ALGEBRAIC[k7_i]*(CONSTANTS[k2_i]+ALGEBRAIC[k3_i]);
ALGEBRAIC[x2_i] =  CONSTANTS[k1_i]*ALGEBRAIC[k7_i]*(ALGEBRAIC[k4_i]+CONSTANTS[k5_i])+ ALGEBRAIC[k4_i]*ALGEBRAIC[k6_i]*(CONSTANTS[k1_i]+ALGEBRAIC[k8_i]);
ALGEBRAIC[x3_i] =  CONSTANTS[k1_i]*ALGEBRAIC[k3_i]*(ALGEBRAIC[k7_i]+ALGEBRAIC[k6_i])+ ALGEBRAIC[k8_i]*ALGEBRAIC[k6_i]*(CONSTANTS[k2_i]+ALGEBRAIC[k3_i]);
ALGEBRAIC[x4_i] =  CONSTANTS[k2_i]*ALGEBRAIC[k8_i]*(ALGEBRAIC[k4_i]+CONSTANTS[k5_i])+ ALGEBRAIC[k3_i]*CONSTANTS[k5_i]*(CONSTANTS[k1_i]+ALGEBRAIC[k8_i]);
ALGEBRAIC[E1_i] = ALGEBRAIC[x1_i]/(ALGEBRAIC[x1_i]+ALGEBRAIC[x2_i]+ALGEBRAIC[x3_i]+ALGEBRAIC[x4_i]);
ALGEBRAIC[E2_i] = ALGEBRAIC[x2_i]/(ALGEBRAIC[x1_i]+ALGEBRAIC[x2_i]+ALGEBRAIC[x3_i]+ALGEBRAIC[x4_i]);
ALGEBRAIC[E3_i] = ALGEBRAIC[x3_i]/(ALGEBRAIC[x1_i]+ALGEBRAIC[x2_i]+ALGEBRAIC[x3_i]+ALGEBRAIC[x4_i]);
ALGEBRAIC[E4_i] = ALGEBRAIC[x4_i]/(ALGEBRAIC[x1_i]+ALGEBRAIC[x2_i]+ALGEBRAIC[x3_i]+ALGEBRAIC[x4_i]);
ALGEBRAIC[JncxNa_i] = ( 3.00000*( ALGEBRAIC[E4_i]*ALGEBRAIC[k7_i] -  ALGEBRAIC[E1_i]*ALGEBRAIC[k8_i])+ ALGEBRAIC[E3_i]*ALGEBRAIC[k4pp_i]) -  ALGEBRAIC[E2_i]*ALGEBRAIC[k3pp_i];
ALGEBRAIC[JncxCa_i] =  ALGEBRAIC[E2_i]*CONSTANTS[k2_i] -  ALGEBRAIC[E1_i]*CONSTANTS[k1_i];
ALGEBRAIC[INaCa_i] =  0.800000*CONSTANTS[Gncx]*ALGEBRAIC[allo_i]*( CONSTANTS[zna]*ALGEBRAIC[JncxNa_i]+ CONSTANTS[zca]*ALGEBRAIC[JncxCa_i]);
ALGEBRAIC[A_Nab] = ( CONSTANTS[PNab]*CONSTANTS[ffrt]*( STATES[nai]*exp(ALGEBRAIC[vfrt]) - CONSTANTS[nao]))/CONSTANTS[B_Nab];
ALGEBRAIC[U_Nab] =  CONSTANTS[B_Nab]*(STATES[V] - CONSTANTS[v0_Nab]);
ALGEBRAIC[INab] = (- 1.00000e-07<=ALGEBRAIC[U_Nab]&&ALGEBRAIC[U_Nab]<=1.00000e-07 ?  ALGEBRAIC[A_Nab]*(1.00000 -  0.500000*ALGEBRAIC[U_Nab]) : ( ALGEBRAIC[A_Nab]*ALGEBRAIC[U_Nab])/(exp(ALGEBRAIC[U_Nab]) - 1.00000));
ALGEBRAIC[JdiffNa] = (STATES[nass] - STATES[nai])/2.00000;
ALGEBRAIC[A_2] = ( 0.750000*CONSTANTS[ffrt]*( STATES[nass]*exp(ALGEBRAIC[vfrt]) - CONSTANTS[nao]))/CONSTANTS[B_2];
ALGEBRAIC[U_2] =  CONSTANTS[B_2]*(STATES[V] - CONSTANTS[v0_CaL]);
ALGEBRAIC[PhiCaNa] = (- 1.00000e-07<=ALGEBRAIC[U_2]&&ALGEBRAIC[U_2]<=1.00000e-07 ?  ALGEBRAIC[A_2]*(1.00000 -  0.500000*ALGEBRAIC[U_2]) : ( ALGEBRAIC[A_2]*ALGEBRAIC[U_2])/(exp(ALGEBRAIC[U_2]) - 1.00000));
ALGEBRAIC[ICaNa] =  (1.00000 - ALGEBRAIC[fICaLp])*CONSTANTS[PCaNa]*ALGEBRAIC[PhiCaNa]*STATES[d]*( ALGEBRAIC[f]*(1.00000 - STATES[nca])+ STATES[jca]*ALGEBRAIC[fca]*STATES[nca])+ ALGEBRAIC[fICaLp]*CONSTANTS[PCaNap]*ALGEBRAIC[PhiCaNa]*STATES[d]*( ALGEBRAIC[fp]*(1.00000 - STATES[nca])+ STATES[jca]*ALGEBRAIC[fcap]*STATES[nca]);
ALGEBRAIC[allo_ss] = 1.00000/(1.00000+pow(CONSTANTS[KmCaAct]/STATES[cass], 2.00000));
ALGEBRAIC[h7_ss] = 1.00000+ (CONSTANTS[nao]/CONSTANTS[kna3])*(1.00000+1.00000/ALGEBRAIC[hna]);
ALGEBRAIC[h8_ss] = CONSTANTS[nao]/( CONSTANTS[kna3]*ALGEBRAIC[hna]*ALGEBRAIC[h7_ss]);
ALGEBRAIC[k3pp_ss] =  ALGEBRAIC[h8_ss]*CONSTANTS[wnaca];
ALGEBRAIC[h1_ss] = 1.00000+ (STATES[nass]/CONSTANTS[kna3])*(1.00000+ALGEBRAIC[hna]);
ALGEBRAIC[h2_ss] = ( STATES[nass]*ALGEBRAIC[hna])/( CONSTANTS[kna3]*ALGEBRAIC[h1_ss]);
ALGEBRAIC[k4pp_ss] =  ALGEBRAIC[h2_ss]*CONSTANTS[wnaca];
ALGEBRAIC[h4_ss] = 1.00000+ (STATES[nass]/CONSTANTS[kna1])*(1.00000+STATES[nass]/CONSTANTS[kna2]);
ALGEBRAIC[h5_ss] = ( STATES[nass]*STATES[nass])/( ALGEBRAIC[h4_ss]*CONSTANTS[kna1]*CONSTANTS[kna2]);
ALGEBRAIC[k7_ss] =  ALGEBRAIC[h5_ss]*ALGEBRAIC[h2_ss]*CONSTANTS[wna];
ALGEBRAIC[k8_ss] =  ALGEBRAIC[h8_ss]*CONSTANTS[h11_ss]*CONSTANTS[wna];
ALGEBRAIC[h9_ss] = 1.00000/ALGEBRAIC[h7_ss];
ALGEBRAIC[k3p_ss] =  ALGEBRAIC[h9_ss]*CONSTANTS[wca];
ALGEBRAIC[k3_ss] = ALGEBRAIC[k3p_ss]+ALGEBRAIC[k3pp_ss];
ALGEBRAIC[h3_ss] = 1.00000/ALGEBRAIC[h1_ss];
ALGEBRAIC[k4p_ss] = ( ALGEBRAIC[h3_ss]*CONSTANTS[wca])/ALGEBRAIC[hca];
ALGEBRAIC[k4_ss] = ALGEBRAIC[k4p_ss]+ALGEBRAIC[k4pp_ss];
ALGEBRAIC[h6_ss] = 1.00000/ALGEBRAIC[h4_ss];
ALGEBRAIC[k6_ss] =  ALGEBRAIC[h6_ss]*STATES[cass]*CONSTANTS[kcaon];
ALGEBRAIC[x1_ss] =  CONSTANTS[k2_ss]*ALGEBRAIC[k4_ss]*(ALGEBRAIC[k7_ss]+ALGEBRAIC[k6_ss])+ CONSTANTS[k5_ss]*ALGEBRAIC[k7_ss]*(CONSTANTS[k2_ss]+ALGEBRAIC[k3_ss]);
ALGEBRAIC[x2_ss] =  CONSTANTS[k1_ss]*ALGEBRAIC[k7_ss]*(ALGEBRAIC[k4_ss]+CONSTANTS[k5_ss])+ ALGEBRAIC[k4_ss]*ALGEBRAIC[k6_ss]*(CONSTANTS[k1_ss]+ALGEBRAIC[k8_ss]);
ALGEBRAIC[x3_ss] =  CONSTANTS[k1_ss]*ALGEBRAIC[k3_ss]*(ALGEBRAIC[k7_ss]+ALGEBRAIC[k6_ss])+ ALGEBRAIC[k8_ss]*ALGEBRAIC[k6_ss]*(CONSTANTS[k2_ss]+ALGEBRAIC[k3_ss]);
ALGEBRAIC[x4_ss] =  CONSTANTS[k2_ss]*ALGEBRAIC[k8_ss]*(ALGEBRAIC[k4_ss]+CONSTANTS[k5_ss])+ ALGEBRAIC[k3_ss]*CONSTANTS[k5_ss]*(CONSTANTS[k1_ss]+ALGEBRAIC[k8_ss]);
ALGEBRAIC[E1_ss] = ALGEBRAIC[x1_ss]/(ALGEBRAIC[x1_ss]+ALGEBRAIC[x2_ss]+ALGEBRAIC[x3_ss]+ALGEBRAIC[x4_ss]);
ALGEBRAIC[E2_ss] = ALGEBRAIC[x2_ss]/(ALGEBRAIC[x1_ss]+ALGEBRAIC[x2_ss]+ALGEBRAIC[x3_ss]+ALGEBRAIC[x4_ss]);
ALGEBRAIC[E3_ss] = ALGEBRAIC[x3_ss]/(ALGEBRAIC[x1_ss]+ALGEBRAIC[x2_ss]+ALGEBRAIC[x3_ss]+ALGEBRAIC[x4_ss]);
ALGEBRAIC[E4_ss] = ALGEBRAIC[x4_ss]/(ALGEBRAIC[x1_ss]+ALGEBRAIC[x2_ss]+ALGEBRAIC[x3_ss]+ALGEBRAIC[x4_ss]);
ALGEBRAIC[JncxNa_ss] = ( 3.00000*( ALGEBRAIC[E4_ss]*ALGEBRAIC[k7_ss] -  ALGEBRAIC[E1_ss]*ALGEBRAIC[k8_ss])+ ALGEBRAIC[E3_ss]*ALGEBRAIC[k4pp_ss]) -  ALGEBRAIC[E2_ss]*ALGEBRAIC[k3pp_ss];
ALGEBRAIC[JncxCa_ss] =  ALGEBRAIC[E2_ss]*CONSTANTS[k2_ss] -  ALGEBRAIC[E1_ss]*CONSTANTS[k1_ss];
ALGEBRAIC[INaCa_ss] =  0.200000*CONSTANTS[Gncx]*ALGEBRAIC[allo_ss]*( CONSTANTS[zna]*ALGEBRAIC[JncxNa_ss]+ CONSTANTS[zca]*ALGEBRAIC[JncxCa_ss]);
ALGEBRAIC[IpCa] = ( CONSTANTS[GpCa]*STATES[cai])/(CONSTANTS[KmCap]+STATES[cai]);
ALGEBRAIC[A_Cab] = ( CONSTANTS[PCab]*4.00000*CONSTANTS[ffrt]*( STATES[cai]*exp( 2.00000*ALGEBRAIC[vfrt]) -  0.341000*CONSTANTS[cao]))/CONSTANTS[B_Cab];
ALGEBRAIC[U_Cab] =  CONSTANTS[B_Cab]*(STATES[V] - CONSTANTS[v0_Cab]);
ALGEBRAIC[ICab] = (- 1.00000e-07<=ALGEBRAIC[U_Cab]&&ALGEBRAIC[U_Cab]<=1.00000e-07 ?  ALGEBRAIC[A_Cab]*(1.00000 -  0.500000*ALGEBRAIC[U_Cab]) : ( ALGEBRAIC[A_Cab]*ALGEBRAIC[U_Cab])/(exp(ALGEBRAIC[U_Cab]) - 1.00000));
ALGEBRAIC[Jdiff] = (STATES[cass] - STATES[cai])/0.200000;
ALGEBRAIC[fJrelp] = 1.00000/(1.00000+CONSTANTS[KmCaMK]/ALGEBRAIC[CaMKa]);
ALGEBRAIC[Jrel] =  CONSTANTS[Jrel_scaling_factor]*( (1.00000 - ALGEBRAIC[fJrelp])*STATES[Jrelnp]+ ALGEBRAIC[fJrelp]*STATES[Jrelp]);
ALGEBRAIC[Bcass] = 1.00000/(1.00000+( CONSTANTS[BSRmax]*CONSTANTS[KmBSR])/pow(CONSTANTS[KmBSR]+STATES[cass], 2.00000)+( CONSTANTS[BSLmax]*CONSTANTS[KmBSL])/pow(CONSTANTS[KmBSL]+STATES[cass], 2.00000));
ALGEBRAIC[Jupnp] = ( CONSTANTS[upScale]*0.00437500*STATES[cai])/(STATES[cai]+0.000920000);
ALGEBRAIC[Jupp] = ( CONSTANTS[upScale]*2.75000*0.00437500*STATES[cai])/((STATES[cai]+0.000920000) - 0.000170000);
ALGEBRAIC[fJupp] = 1.00000/(1.00000+CONSTANTS[KmCaMK]/ALGEBRAIC[CaMKa]);
ALGEBRAIC[Jleak] = ( 0.00393750*STATES[cansr])/15.0000;
ALGEBRAIC[Jup] =  CONSTANTS[Jup_b]*(( (1.00000 - ALGEBRAIC[fJupp])*ALGEBRAIC[Jupnp]+ ALGEBRAIC[fJupp]*ALGEBRAIC[Jupp]) - ALGEBRAIC[Jleak]);
// ALGEBRAIC[Bcai] = 1.00000/(1.00000+( CONSTANTS[cmdnmax]*CONSTANTS[kmcmdn])/pow(CONSTANTS[kmcmdn]+STATES[cai], 2.00000)+( CONSTANTS[trpnmax]*CONSTANTS[kmtrpn])/pow(CONSTANTS[kmtrpn]+STATES[cai], 2.00000));
ALGEBRAIC[Bcai] = 1.00000/(1.00000+( CONSTANTS[cmdnmax]*CONSTANTS[kmcmdn])/pow(CONSTANTS[kmcmdn]+STATES[cai], 2.00000)); //modified
// using 2011's Bcai
ALGEBRAIC[Jtr] = (STATES[cansr] - STATES[cajsr])/100.000;
ALGEBRAIC[Bcajsr] = 1.00000/(1.00000+( CONSTANTS[csqnmax]*CONSTANTS[kmcsqn])/pow(CONSTANTS[kmcsqn]+STATES[cajsr], 2.00000));

//RATES[D] = CONSTANTS[cnc];
RATES[D] = 0.;
RATES[IC1] = (- ( CONSTANTS[A11]*exp( CONSTANTS[B11]*STATES[V])*STATES[IC1]*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q11]))/10.0000) -  CONSTANTS[A21]*exp( CONSTANTS[B21]*STATES[V])*STATES[IC2]*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q21]))/10.0000))+ CONSTANTS[A51]*exp( CONSTANTS[B51]*STATES[V])*STATES[C1]*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q51]))/10.0000)) -  CONSTANTS[A61]*exp( CONSTANTS[B61]*STATES[V])*STATES[IC1]*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q61]))/10.0000);
RATES[IC2] = ((( CONSTANTS[A11]*exp( CONSTANTS[B11]*STATES[V])*STATES[IC1]*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q11]))/10.0000) -  CONSTANTS[A21]*exp( CONSTANTS[B21]*STATES[V])*STATES[IC2]*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q21]))/10.0000)) - ( CONSTANTS[A3]*exp( CONSTANTS[B3]*STATES[V])*STATES[IC2]*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q3]))/10.0000) -  CONSTANTS[A4]*exp( CONSTANTS[B4]*STATES[V])*STATES[IO]*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q4]))/10.0000)))+ CONSTANTS[A52]*exp( CONSTANTS[B52]*STATES[V])*STATES[C2]*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q52]))/10.0000)) -  CONSTANTS[A62]*exp( CONSTANTS[B62]*STATES[V])*STATES[IC2]*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q62]))/10.0000);
RATES[C1] = - ( CONSTANTS[A1]*exp( CONSTANTS[B1]*STATES[V])*STATES[C1]*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q1]))/10.0000) -  CONSTANTS[A2]*exp( CONSTANTS[B2]*STATES[V])*STATES[C2]*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q2]))/10.0000)) - ( CONSTANTS[A51]*exp( CONSTANTS[B51]*STATES[V])*STATES[C1]*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q51]))/10.0000) -  CONSTANTS[A61]*exp( CONSTANTS[B61]*STATES[V])*STATES[IC1]*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q61]))/10.0000));
RATES[C2] = (( CONSTANTS[A1]*exp( CONSTANTS[B1]*STATES[V])*STATES[C1]*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q1]))/10.0000) -  CONSTANTS[A2]*exp( CONSTANTS[B2]*STATES[V])*STATES[C2]*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q2]))/10.0000)) - ( CONSTANTS[A31]*exp( CONSTANTS[B31]*STATES[V])*STATES[C2]*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q31]))/10.0000) -  CONSTANTS[A41]*exp( CONSTANTS[B41]*STATES[V])*STATES[O]*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q41]))/10.0000))) - ( CONSTANTS[A52]*exp( CONSTANTS[B52]*STATES[V])*STATES[C2]*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q52]))/10.0000) -  CONSTANTS[A62]*exp( CONSTANTS[B62]*STATES[V])*STATES[IC2]*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q62]))/10.0000));
RATES[O] = (( CONSTANTS[A31]*exp( CONSTANTS[B31]*STATES[V])*STATES[C2]*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q31]))/10.0000) -  CONSTANTS[A41]*exp( CONSTANTS[B41]*STATES[V])*STATES[O]*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q41]))/10.0000)) - ( CONSTANTS[A53]*exp( CONSTANTS[B53]*STATES[V])*STATES[O]*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q53]))/10.0000) -  CONSTANTS[A63]*exp( CONSTANTS[B63]*STATES[V])*STATES[IO]*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q63]))/10.0000))) - ( (( CONSTANTS[Kmax]*CONSTANTS[Ku]*pow( STATES[D],CONSTANTS[n]))/(pow( STATES[D],CONSTANTS[n])+CONSTANTS[halfmax]))*STATES[O] -  CONSTANTS[Ku]*STATES[Obound]);
RATES[IO] = ((( CONSTANTS[A3]*exp( CONSTANTS[B3]*STATES[V])*STATES[IC2]*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q3]))/10.0000) -  CONSTANTS[A4]*exp( CONSTANTS[B4]*STATES[V])*STATES[IO]*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q4]))/10.0000))+ CONSTANTS[A53]*exp( CONSTANTS[B53]*STATES[V])*STATES[O]*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q53]))/10.0000)) -  CONSTANTS[A63]*exp( CONSTANTS[B63]*STATES[V])*STATES[IO]*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q63]))/10.0000)) - ( (( CONSTANTS[Kmax]*CONSTANTS[Ku]*pow( STATES[D],CONSTANTS[n]))/(pow( STATES[D],CONSTANTS[n])+CONSTANTS[halfmax]))*STATES[IO] -  (( CONSTANTS[Ku]*CONSTANTS[A53]*exp( CONSTANTS[B53]*STATES[V])*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q53]))/10.0000))/( CONSTANTS[A63]*exp( CONSTANTS[B63]*STATES[V])*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q63]))/10.0000)))*STATES[IObound]);
RATES[IObound] = (( (( CONSTANTS[Kmax]*CONSTANTS[Ku]*pow( STATES[D],CONSTANTS[n]))/(pow( STATES[D],CONSTANTS[n])+CONSTANTS[halfmax]))*STATES[IO] -  (( CONSTANTS[Ku]*CONSTANTS[A53]*exp( CONSTANTS[B53]*STATES[V])*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q53]))/10.0000))/( CONSTANTS[A63]*exp( CONSTANTS[B63]*STATES[V])*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q63]))/10.0000)))*STATES[IObound])+ (CONSTANTS[Kt]/(1.00000+exp(- (STATES[V] - CONSTANTS[Vhalf])/6.78900)))*STATES[Cbound]) -  CONSTANTS[Kt]*STATES[IObound];
RATES[Obound] = (( (( CONSTANTS[Kmax]*CONSTANTS[Ku]*pow( STATES[D],CONSTANTS[n]))/(pow( STATES[D],CONSTANTS[n])+CONSTANTS[halfmax]))*STATES[O] -  CONSTANTS[Ku]*STATES[Obound])+ (CONSTANTS[Kt]/(1.00000+exp(- (STATES[V] - CONSTANTS[Vhalf])/6.78900)))*STATES[Cbound]) -  CONSTANTS[Kt]*STATES[Obound];
RATES[Cbound] = - ( (CONSTANTS[Kt]/(1.00000+exp(- (STATES[V] - CONSTANTS[Vhalf])/6.78900)))*STATES[Cbound] -  CONSTANTS[Kt]*STATES[Obound]) - ( (CONSTANTS[Kt]/(1.00000+exp(- (STATES[V] - CONSTANTS[Vhalf])/6.78900)))*STATES[Cbound] -  CONSTANTS[Kt]*STATES[IObound]);
RATES[hL] = (ALGEBRAIC[hLss] - STATES[hL])/CONSTANTS[thL];
RATES[hLp] = (ALGEBRAIC[hLssp] - STATES[hLp])/CONSTANTS[thLp];
RATES[m] = (ALGEBRAIC[mss] - STATES[m])/ALGEBRAIC[tm];
RATES[hf] = (ALGEBRAIC[hss] - STATES[hf])/ALGEBRAIC[thf];
RATES[hs] = (ALGEBRAIC[hss] - STATES[hs])/ALGEBRAIC[ths];
RATES[a] = (ALGEBRAIC[ass] - STATES[a])/ALGEBRAIC[ta];
RATES[d] = (ALGEBRAIC[dss] - STATES[d])/ALGEBRAIC[td];
RATES[ff] = (ALGEBRAIC[fss] - STATES[ff])/ALGEBRAIC[tff];
RATES[fs] = (ALGEBRAIC[fss] - STATES[fs])/ALGEBRAIC[tfs];
RATES[jca] = (ALGEBRAIC[fcass] - STATES[jca])/CONSTANTS[tjca];
RATES[nca] =  ALGEBRAIC[anca]*CONSTANTS[k2n] -  STATES[nca]*ALGEBRAIC[km2n];
RATES[xs1] = (ALGEBRAIC[xs1ss] - STATES[xs1])/ALGEBRAIC[txs1];
RATES[xk1] = (ALGEBRAIC[xk1ss] - STATES[xk1])/ALGEBRAIC[txk1];
RATES[CaMKt] =  CONSTANTS[aCaMK]*ALGEBRAIC[CaMKb]*(ALGEBRAIC[CaMKb]+STATES[CaMKt]) -  CONSTANTS[bCaMK]*STATES[CaMKt];
RATES[j] = (ALGEBRAIC[jss] - STATES[j])/ALGEBRAIC[tj];
RATES[ap] = (ALGEBRAIC[assp] - STATES[ap])/ALGEBRAIC[ta];
RATES[fcaf] = (ALGEBRAIC[fcass] - STATES[fcaf])/ALGEBRAIC[tfcaf];
RATES[fcas] = (ALGEBRAIC[fcass] - STATES[fcas])/ALGEBRAIC[tfcas];
RATES[ffp] = (ALGEBRAIC[fss] - STATES[ffp])/ALGEBRAIC[tffp];
RATES[xs2] = (ALGEBRAIC[xs2ss] - STATES[xs2])/ALGEBRAIC[txs2];
RATES[hsp] = (ALGEBRAIC[hssp] - STATES[hsp])/ALGEBRAIC[thsp];
RATES[jp] = (ALGEBRAIC[jss] - STATES[jp])/ALGEBRAIC[tjp];
RATES[mL] = (ALGEBRAIC[mLss] - STATES[mL])/ALGEBRAIC[tmL];
RATES[fcafp] = (ALGEBRAIC[fcass] - STATES[fcafp])/ALGEBRAIC[tfcafp];
RATES[iF] = (ALGEBRAIC[iss] - STATES[iF])/ALGEBRAIC[tiF];
RATES[iS] = (ALGEBRAIC[iss] - STATES[iS])/ALGEBRAIC[tiS];
RATES[iFp] = (ALGEBRAIC[iss] - STATES[iFp])/ALGEBRAIC[tiFp];
RATES[iSp] = (ALGEBRAIC[iss] - STATES[iSp])/ALGEBRAIC[tiSp];
RATES[Jrelnp] = (ALGEBRAIC[Jrel_inf] - STATES[Jrelnp])/ALGEBRAIC[tau_rel];
RATES[Jrelp] = (ALGEBRAIC[Jrel_infp] - STATES[Jrelp])/ALGEBRAIC[tau_relp];
RATES[ki] = ( - ((ALGEBRAIC[Ito]+ALGEBRAIC[IKr]+ALGEBRAIC[IKs]+ALGEBRAIC[IK1]+ALGEBRAIC[IKb]+ALGEBRAIC[Istim]) -  2.00000*ALGEBRAIC[INaK])*CONSTANTS[cm]*CONSTANTS[Acap])/( CONSTANTS[F]*CONSTANTS[vmyo])+( ALGEBRAIC[JdiffK]*CONSTANTS[vss])/CONSTANTS[vmyo];
RATES[kss] = ( - ALGEBRAIC[ICaK]*CONSTANTS[cm]*CONSTANTS[Acap])/( CONSTANTS[F]*CONSTANTS[vss]) - ALGEBRAIC[JdiffK];
RATES[nai] = ( - (ALGEBRAIC[INa]+ALGEBRAIC[INaL]+ 3.00000*ALGEBRAIC[INaCa_i]+ 3.00000*ALGEBRAIC[INaK]+ALGEBRAIC[INab])*CONSTANTS[Acap]*CONSTANTS[cm])/( CONSTANTS[F]*CONSTANTS[vmyo])+( ALGEBRAIC[JdiffNa]*CONSTANTS[vss])/CONSTANTS[vmyo];
RATES[nass] = ( - (ALGEBRAIC[ICaNa]+ 3.00000*ALGEBRAIC[INaCa_ss])*CONSTANTS[cm]*CONSTANTS[Acap])/( CONSTANTS[F]*CONSTANTS[vss]) - ALGEBRAIC[JdiffNa];
RATES[V] = - (ALGEBRAIC[INa]+ALGEBRAIC[INaL]+ALGEBRAIC[Ito]+ALGEBRAIC[ICaL]+ALGEBRAIC[ICaNa]+ALGEBRAIC[ICaK]+ALGEBRAIC[IKr]+ALGEBRAIC[IKs]+ALGEBRAIC[IK1]+ALGEBRAIC[INaCa_i]+ALGEBRAIC[INaCa_ss]+ALGEBRAIC[INaK]+ALGEBRAIC[INab]+ALGEBRAIC[IKb]+ALGEBRAIC[IpCa]+ALGEBRAIC[ICab]+ALGEBRAIC[Istim]);
RATES[cass] =  ALGEBRAIC[Bcass]*((( - (ALGEBRAIC[ICaL] -  2.00000*ALGEBRAIC[INaCa_ss])*CONSTANTS[cm]*CONSTANTS[Acap])/( 2.00000*CONSTANTS[F]*CONSTANTS[vss])+( ALGEBRAIC[Jrel]*CONSTANTS[vjsr])/CONSTANTS[vss]) - ALGEBRAIC[Jdiff]);
// new for coupling
// RATES[ca_trpn] = CONSTANTS[trpnmax] * land_trpn;
RATES[cai] =  ALGEBRAIC[Bcai]*((( - ((ALGEBRAIC[IpCa]+ALGEBRAIC[ICab]) -  2.00000*ALGEBRAIC[INaCa_i])*CONSTANTS[cm]*CONSTANTS[Acap])/( 2.00000*CONSTANTS[F]*CONSTANTS[vmyo]) - ( ALGEBRAIC[Jup]*CONSTANTS[vnsr])/CONSTANTS[vmyo])+( ALGEBRAIC[Jdiff]*CONSTANTS[vss])/CONSTANTS[vmyo] - RATES[ca_trpn]); //modified
RATES[cansr] = ALGEBRAIC[Jup] - ( ALGEBRAIC[Jtr]*CONSTANTS[vjsr])/CONSTANTS[vnsr];
RATES[cajsr] =  ALGEBRAIC[Bcajsr]*(ALGEBRAIC[Jtr] - ALGEBRAIC[Jrel]);
}

void ohara_rudy_cipa_v1_2017::solveEuler(double dt){
  for(int i=0;i<states_size;i++){
    STATES[i] = STATES[i] + RATES[i] * dt;
  }
}

// void ohara_rudy_cipa_v1_2017::solveAnalytical(int forward_euler_only, double dt, double *CONSTANTS, double *RATES, double* STATES, double* ALGEBRAIC )
// {
  // if (forward_euler_only == 1 || dt <= 0.005){
  //   for(int i=0;i<states_size;i++){
  //     STATES[i] = STATES[i] + RATES[i] * dt;
  //   }
  // }
  // else {
    ////==============
    ////Exact solution
    ////==============
    ////INa
      // STATES[m] = ALGEBRAIC[mss] - (ALGEBRAIC[mss] - STATES[m]) * exp(-dt / ALGEBRAIC[tm]);
      // STATES[hf] = ALGEBRAIC[hss] - (ALGEBRAIC[hss] - STATES[hf]) * exp(-dt / ALGEBRAIC[thf]);
      // STATES[hs] = ALGEBRAIC[hss] - (ALGEBRAIC[hss] - STATES[hs]) * exp(-dt / ALGEBRAIC[ths]);
      // STATES[j] = ALGEBRAIC[jss] - (ALGEBRAIC[jss] - STATES[j]) * exp(-dt / ALGEBRAIC[tj]);
      // STATES[hsp] = ALGEBRAIC[hssp] - (ALGEBRAIC[hssp] - STATES[hsp]) * exp(-dt / ALGEBRAIC[thsp]);
      // STATES[jp] = ALGEBRAIC[jss] - (ALGEBRAIC[jss] - STATES[jp]) * exp(-dt / ALGEBRAIC[tjp]);
      // STATES[mL] = ALGEBRAIC[mLss] - (ALGEBRAIC[mLss] - STATES[mL]) * exp(-dt / ALGEBRAIC[tmL]);
      // STATES[hL] = ALGEBRAIC[hLss] - (ALGEBRAIC[hLss] - STATES[hL]) * exp(-dt / CONSTANTS[thL]);
      // STATES[hLp] = ALGEBRAIC[hLssp] - (ALGEBRAIC[hLssp] - STATES[hLp]) * exp(-dt / CONSTANTS[thLp]);
    ////Ito
      // STATES[a] = ALGEBRAIC[ass] - (ALGEBRAIC[ass] - STATES[a]) * exp(-dt / ALGEBRAIC[ta]);
      // STATES[iF] = ALGEBRAIC[iss] - (ALGEBRAIC[iss] - STATES[iF]) * exp(-dt / ALGEBRAIC[tiF]);
      // STATES[iS] = ALGEBRAIC[iss] - (ALGEBRAIC[iss] - STATES[iS]) * exp(-dt / ALGEBRAIC[tiS]);
      // STATES[ap] = ALGEBRAIC[assp] - (ALGEBRAIC[assp] - STATES[ap]) * exp(-dt / ALGEBRAIC[ta]);
      // STATES[iFp] = ALGEBRAIC[iss] - (ALGEBRAIC[iss] - STATES[iFp]) * exp(-dt / ALGEBRAIC[tiFp]);
      // STATES[iSp] = ALGEBRAIC[iss] - (ALGEBRAIC[iss] - STATES[iSp]) * exp(-dt / ALGEBRAIC[tiSp]);
    ////ICaL
      // STATES[d] = ALGEBRAIC[dss] - (ALGEBRAIC[dss] - STATES[d]) * exp(-dt / ALGEBRAIC[td]);
      // STATES[ff] = ALGEBRAIC[fss] - (ALGEBRAIC[fss] - STATES[ff]) * exp(-dt / ALGEBRAIC[tff]);
      // STATES[fs] = ALGEBRAIC[fss] - (ALGEBRAIC[fss] - STATES[fs]) * exp(-dt / ALGEBRAIC[tfs]);
      // STATES[fcaf] = ALGEBRAIC[fcass] - (ALGEBRAIC[fcass] - STATES[fcaf]) * exp(-dt / ALGEBRAIC[tfcaf]);
      // STATES[fcas] = ALGEBRAIC[fcass] - (ALGEBRAIC[fcass] - STATES[fcas]) * exp(-dt / ALGEBRAIC[tfcas]);
      // STATES[jca] = ALGEBRAIC[fcass] - (ALGEBRAIC[fcass] - STATES[jca]) * exp(- dt / CONSTANTS[tjca]);
      // STATES[ffp] = ALGEBRAIC[fss] - (ALGEBRAIC[fss] - STATES[ffp]) * exp(-dt / ALGEBRAIC[tffp]);
      // STATES[fcafp] = ALGEBRAIC[fcass] - (ALGEBRAIC[fcass] - STATES[fcafp]) * exp(-d / ALGEBRAIC[tfcafp]);
      // STATES[nca] = ALGEBRAIC[anca] * CONSTANTS[k2n] / ALGEBRAIC[km2n] -
      //     (ALGEBRAIC[anca] * CONSTANTS[k2n] / ALGEBRAIC[km2n] - STATES[nca]) * exp(-ALGEBRAIC[km2n] * dt);
    ////IKs
      // STATES[xs1] = ALGEBRAIC[xs1ss] - (ALGEBRAIC[xs1ss] - STATES[xs1]) * exp(-dt / ALGEBRAIC[txs1]);
      // STATES[xs2] = ALGEBRAIC[xs2ss] - (ALGEBRAIC[xs2ss] - STATES[xs2]) * exp(-dt / ALGEBRAIC[txs2]);
    ////IK1
      // STATES[xk1] = ALGEBRAIC[xk1ss] - (ALGEBRAIC[xk1ss] - STATES[xk1]) * exp(-dt / ALGEBRAIC[txk1]);
    ////RyR receptors
      // STATES[Jrelnp] = ALGEBRAIC[Jrel_inf] - (ALGEBRAIC[Jrel_inf] - STATES[Jrelnp]) * exp(-dt / ALGEBRAIC[tau_rel]);
      // STATES[Jrelp] = ALGEBRAIC[Jrel_infp] - (ALGEBRAIC[Jrel_infp] - STATES[Jrelp]) * exp(-dt / ALGEBRAIC[tau_relp]);
    ////=============================
    ////Approximated solution (Implicit methods)
    ////=============================
    ////IKr
      // double* coeffs = new double[31];
      // coeffs[0] = - CONSTANTS[A11]*exp( CONSTANTS[B11]*STATES[V])*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q11]))/10.0000) - CONSTANTS[A61]*exp( CONSTANTS[B61]*STATES[V])*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q61]))/10.0000);
      // coeffs[1] = CONSTANTS[A21]*exp( CONSTANTS[B21]*STATES[V])*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q21]))/10.0000);
      // coeffs[2] = CONSTANTS[A51]*exp( CONSTANTS[B51]*STATES[V])*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q51]))/10.0000);

      // coeffs[3] = CONSTANTS[A11]*exp( CONSTANTS[B11]*STATES[V])*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q11]))/10.0000);
      // coeffs[4] = - CONSTANTS[A21]*exp( CONSTANTS[B21]*STATES[V])*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q21]))/10.0000) - CONSTANTS[A3]*exp( CONSTANTS[B3]*STATES[V])*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q3]))/10.0000) - CONSTANTS[A62]*exp( CONSTANTS[B62]*STATES[V])*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q62]))/10.0000);
      // coeffs[5] = CONSTANTS[A52]*exp( CONSTANTS[B52]*STATES[V])*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q52]))/10.0000);
      // coeffs[6] = CONSTANTS[A4]*exp( CONSTANTS[B4]*STATES[V])*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q4]))/10.0000);

      // coeffs[7] = CONSTANTS[A61]*exp( CONSTANTS[B61]*STATES[V])*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q61]))/10.0000);
      // coeffs[8] = - CONSTANTS[A1]*exp( CONSTANTS[B1]*STATES[V])*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q1]))/10.0000) - CONSTANTS[A51]*exp( CONSTANTS[B51]*STATES[V])*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q51]))/10.0000);
      // coeffs[9] = CONSTANTS[A2]*exp( CONSTANTS[B2]*STATES[V])*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q2]))/10.0000);

      // coeffs[10] = CONSTANTS[A62]*exp( CONSTANTS[B62]*STATES[V])*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q62]))/10.0000);
      // coeffs[11] = CONSTANTS[A1]*exp( CONSTANTS[B1]*STATES[V])*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q1]))/10.0000);
      // coeffs[12] = - CONSTANTS[A2]*exp( CONSTANTS[B2]*STATES[V])*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q2]))/10.0000) - CONSTANTS[A31]*exp( CONSTANTS[B31]*STATES[V])*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q31]))/10.0000) - CONSTANTS[A52]*exp( CONSTANTS[B52]*STATES[V])*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q52]))/10.0000);
      // coeffs[13] = CONSTANTS[A41]*exp( CONSTANTS[B41]*STATES[V])*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q41]))/10.0000);

      // coeffs[14] = CONSTANTS[A31]*exp( CONSTANTS[B31]*STATES[V])*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q31]))/10.0000);
      // coeffs[15] = - CONSTANTS[A41]*exp( CONSTANTS[B41]*STATES[V])*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q41]))/10.0000) - CONSTANTS[A53]*exp( CONSTANTS[B53]*STATES[V])*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q53]))/10.0000) - (( CONSTANTS[Kmax]*CONSTANTS[Ku]*pow( STATES[D],CONSTANTS[n]))/(pow( STATES[D],CONSTANTS[n])+CONSTANTS[halfmax]));
      // coeffs[16] = CONSTANTS[A63]*exp( CONSTANTS[B63]*STATES[V])*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q63]))/10.0000);
      // coeffs[17] = CONSTANTS[Kt];

      // coeffs[18] = CONSTANTS[A3]*exp( CONSTANTS[B3]*STATES[V])*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q3]))/10.0000);
      // coeffs[19] = CONSTANTS[A53]*exp( CONSTANTS[B53]*STATES[V])*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q53]))/10.0000);
      // coeffs[20] = - CONSTANTS[A4]*exp( CONSTANTS[B4]*STATES[V])*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q4]))/10.0000) - CONSTANTS[A63]*exp( CONSTANTS[B63]*STATES[V])*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q63]))/10.0000) - (( CONSTANTS[Kmax]*CONSTANTS[Ku]*pow( STATES[D],CONSTANTS[n]))/(pow( STATES[D],CONSTANTS[n])+CONSTANTS[halfmax]));
      // coeffs[21] = (( CONSTANTS[Ku]*CONSTANTS[A53]*exp( CONSTANTS[B53]*STATES[V])*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q53]))/10.0000))/( CONSTANTS[A63]*exp( CONSTANTS[B63]*STATES[V])*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q63]))/10.0000)));

      // coeffs[22] = (( CONSTANTS[Kmax]*CONSTANTS[Ku]*pow( STATES[D],CONSTANTS[n]))/(pow( STATES[D],CONSTANTS[n])+CONSTANTS[halfmax]));
      // coeffs[23] = -  CONSTANTS[Ku] - CONSTANTS[Kt];
      // coeffs[24] = (CONSTANTS[Kt]/(1.00000+exp(- (STATES[V] - CONSTANTS[Vhalf])/6.78900)));

      // coeffs[25] = (( CONSTANTS[Kmax]*CONSTANTS[Ku]*pow( STATES[D],CONSTANTS[n]))/(pow( STATES[D],CONSTANTS[n])+CONSTANTS[halfmax]));
      // coeffs[26] = - (( CONSTANTS[Ku]*CONSTANTS[A53]*exp( CONSTANTS[B53]*STATES[V])*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q53]))/10.0000))/( CONSTANTS[A63]*exp( CONSTANTS[B63]*STATES[V])*exp(( (CONSTANTS[Temp] - 20.0000)*log(CONSTANTS[q63]))/10.0000))) - CONSTANTS[Kt];
      // coeffs[27] = (CONSTANTS[Kt]/(1.00000+exp(- (STATES[V] - CONSTANTS[Vhalf])/6.78900)));

      // coeffs[28] = CONSTANTS[Kt];
      // coeffs[29] = CONSTANTS[Kt];
      // coeffs[30] = - (CONSTANTS[Kt]/(1.00000+exp(- (STATES[V] - CONSTANTS[Vhalf])/6.78900))) - (CONSTANTS[Kt]/(1.00000+exp(- (STATES[V] - CONSTANTS[Vhalf])/6.78900)));
      // int m = 9;
      // double* a = new double[m*m]; // Flattened a
      // double* b = new double[m];
      // double* x = new double[m];
      // for(int i = 0; i < m; i++){
      //   x[i] = 0.0;
      // }
      //====================
      // Backward euler
      //====================
      // a[0 * m + 0] = 1.0 - dt * coeffs[0];   a[0 * m + 1] = - dt * coeffs[1];     a[0 * m + 2] = - dt * coeffs[2];     a[0 * m + 3] = 0.0;                      a[0 * m + 4] = 0.0;                      a[0 * m + 5] = 0.0;                      a[0 * m + 6] = 0.0;                      a[0 * m + 7] = 0.0;                      a[0 * m + 8] = 0.0;
      // a[1 * m + 0] = - dt * coeffs[3];       a[1 * m + 1] = 1.0 - dt * coeffs[4]; a[1 * m + 2] = 0.0;                  a[1 * m + 3] = - dt * coeffs[5];         a[1 * m + 4] = 0.0;                      a[1 * m + 5] = - dt * coeffs[6];         a[1 * m + 6] = 0.0;                      a[1 * m + 7] = 0.0;                      a[1 * m + 8] = 0.0;
      // a[2 * m + 0] = - dt * coeffs[7];       a[2 * m + 1] = 0.0;                  a[2 * m + 2] = 1.0 - dt * coeffs[8]; a[2 * m + 3] = - dt * coeffs[9];         a[2 * m + 4] = 0.0;                      a[2 * m + 5] = 0.0;                      a[2 * m + 6] = 0.0;                      a[2 * m + 7] = 0.0;                      a[2 * m + 8] = 0.0;
      // a[3 * m + 0] = 0.0;                    a[3 * m + 1] = - dt * coeffs[10];    a[3 * m + 2] = - dt * coeffs[11];    a[3 * m + 3] = 1.0 - dt * coeffs[12];    a[3 * m + 4] = - dt * coeffs[13];        a[3 * m + 5] = 0.0;                      a[3 * m + 6] = 0.0;                      a[3 * m + 7] = 0.0;                      a[3 * m + 8] = 0.0;
      // a[4 * m + 0] = 0.0;                    a[4 * m + 1] = 0.0;                  a[4 * m + 2] = 0.0;                  a[4 * m + 3] = - dt * coeffs[14];        a[4 * m + 4] = 1.0 - dt * coeffs[15];    a[4 * m + 5] = - dt * coeffs[16];        a[4 * m + 6] = - dt * coeffs[17];        a[4 * m + 7] = 0.0;                      a[4 * m + 8] = 0.0;
      // a[5 * m + 0] = 0.0;                    a[5 * m + 1] = - dt * coeffs[18];    a[5 * m + 2] = 0.0;                  a[5 * m + 3] = 0.0;                      a[5 * m + 4] = - dt * coeffs[19];        a[5 * m + 5] = 1.0 - dt * coeffs[20];    a[5 * m + 6] = - dt * coeffs[21];        a[5 * m + 7] = 0.0;                      a[5 * m + 8] = 0.0;
      // a[6 * m + 0] = 0.0;                    a[6 * m + 1] = 0.0;                  a[6 * m + 2] = 0.0;                  a[6 * m + 3] = 0.0;                      a[6 * m + 4] = - dt * coeffs[22];        a[6 * m + 5] = 0.0;                      a[6 * m + 6] = 1.0 - dt * coeffs[23];    a[6 * m + 7] = 0.0;                      a[6 * m + 8] = - dt * coeffs[24];
      // a[7 * m + 0] = 0.0;                    a[7 * m + 1] = 0.0;                  a[7 * m + 2] = 0.0;                  a[7 * m + 3] = 0.0;                      a[7 * m + 4] = 0.0;                      a[7 * m + 5] = - dt * coeffs[25];        a[7 * m + 6] = 0.0;                      a[7 * m + 7] = 1.0 - dt * coeffs[26];    a[7 * m + 8] = - dt * coeffs[27];
      // a[8 * m + 0] = 0.0;                    a[8 * m + 1] = 0.0;                  a[8 * m + 2] = 0.0;                  a[8 * m + 3] = 0.0;                      a[8 * m + 4] = 0.0;                      a[8 * m + 5] = 0.0;                      a[8 * m + 6] = - dt * coeffs[28];        a[8 * m + 7] = - dt * coeffs[29];        a[8 * m + 8] = 1.0 - dt * coeffs[30];
      // b[0] = STATES[IC1];
      // b[1] = STATES[IC2];
      // b[2] = STATES[C1];
      // b[3] = STATES[C2];
      // b[4] = STATES[O];
      // b[5] = STATES[IO];
      // b[6] = STATES[Obound];
      // b[7] = STATES[IObound];
      // b[8] = STATES[Cbound];
      //====================
      // Implicit trapezoid
      //====================
      // for(int i = 0; i < 31; i++){
      //   coeffs[i] = 0.5 * coeffs[i];
      // }
      // a[0 * m + 0] = 1.0 - dt * coeffs[0];   a[0 * m + 1] = - dt * coeffs[1];     a[0 * m + 2] = - dt * coeffs[2];     a[0 * m + 3] = 0.0;                      a[0 * m + 4] = 0.0;                      a[0 * m + 5] = 0.0;                      a[0 * m + 6] = 0.0;                      a[0 * m + 7] = 0.0;                      a[0 * m + 8] = 0.0;
      // a[1 * m + 0] = - dt * coeffs[3];       a[1 * m + 1] = 1.0 - dt * coeffs[4]; a[1 * m + 2] = 0.0;                  a[1 * m + 3] = - dt * coeffs[5];         a[1 * m + 4] = 0.0;                      a[1 * m + 5] = - dt * coeffs[6];         a[1 * m + 6] = 0.0;                      a[1 * m + 7] = 0.0;                      a[1 * m + 8] = 0.0;
      // a[2 * m + 0] = - dt * coeffs[7];       a[2 * m + 1] = 0.0;                  a[2 * m + 2] = 1.0 - dt * coeffs[8]; a[2 * m + 3] = - dt * coeffs[9];         a[2 * m + 4] = 0.0;                      a[2 * m + 5] = 0.0;                      a[2 * m + 6] = 0.0;                      a[2 * m + 7] = 0.0;                      a[2 * m + 8] = 0.0;
      // a[3 * m + 0] = 0.0;                    a[3 * m + 1] = - dt * coeffs[10];    a[3 * m + 2] = - dt * coeffs[11];    a[3 * m + 3] = 1.0 - dt * coeffs[12];    a[3 * m + 4] = - dt * coeffs[13];        a[3 * m + 5] = 0.0;                      a[3 * m + 6] = 0.0;                      a[3 * m + 7] = 0.0;                      a[3 * m + 8] = 0.0;
      // a[4 * m + 0] = 0.0;                    a[4 * m + 1] = 0.0;                  a[4 * m + 2] = 0.0;                  a[4 * m + 3] = - dt * coeffs[14];        a[4 * m + 4] = 1.0 - dt * coeffs[15];    a[4 * m + 5] = - dt * coeffs[16];        a[4 * m + 6] = - dt * coeffs[17];        a[4 * m + 7] = 0.0;                      a[4 * m + 8] = 0.0;
      // a[5 * m + 0] = 0.0;                    a[5 * m + 1] = - dt * coeffs[18];    a[5 * m + 2] = 0.0;                  a[5 * m + 3] = 0.0;                      a[5 * m + 4] = - dt * coeffs[19];        a[5 * m + 5] = 1.0 - dt * coeffs[20];    a[5 * m + 6] = - dt * coeffs[21];        a[5 * m + 7] = 0.0;                      a[5 * m + 8] = 0.0;
      // a[6 * m + 0] = 0.0;                    a[6 * m + 1] = 0.0;                  a[6 * m + 2] = 0.0;                  a[6 * m + 3] = 0.0;                      a[6 * m + 4] = - dt * coeffs[22];        a[6 * m + 5] = 0.0;                      a[6 * m + 6] = 1.0 - dt * coeffs[23];    a[6 * m + 7] = 0.0;                      a[6 * m + 8] = - dt * coeffs[24];
      // a[7 * m + 0] = 0.0;                    a[7 * m + 1] = 0.0;                  a[7 * m + 2] = 0.0;                  a[7 * m + 3] = 0.0;                      a[7 * m + 4] = 0.0;                      a[7 * m + 5] = - dt * coeffs[25];        a[7 * m + 6] = 0.0;                      a[7 * m + 7] = 1.0 - dt * coeffs[26];    a[7 * m + 8] = - dt * coeffs[27];
      // a[8 * m + 0] = 0.0;                    a[8 * m + 1] = 0.0;                  a[8 * m + 2] = 0.0;                  a[8 * m + 3] = 0.0;                      a[8 * m + 4] = 0.0;                      a[8 * m + 5] = 0.0;                      a[8 * m + 6] = - dt * coeffs[28];        a[8 * m + 7] = - dt * coeffs[29];        a[8 * m + 8] = 1.0 - dt * coeffs[30];
      // b[0] = (1.0 + dt * coeffs[0]) * STATES[IC1] + (dt * coeffs[1]) * STATES[IC2]            + (dt * coeffs[2]) * STATES[C1];
      // b[1] = (dt * coeffs[3]) * STATES[IC1]       + (1.0 + dt * coeffs[4]) * STATES[IC2]      + (dt * coeffs[5]) * STATES[C2]         + (dt * coeffs[6]) * STATES[IO];
      // b[2] = (dt * coeffs[7]) * STATES[IC1]       + (1.0 + dt * coeffs[8]) * STATES[C1]       + (dt * coeffs[9]) * STATES[C2];
      // b[3] = (dt * coeffs[10]) * STATES[IC2]      + (dt * coeffs[11]) * STATES[C1]            + (1.0 + dt * coeffs[12]) * STATES[C2]  + (dt * coeffs[13]) * STATES[O];
      // b[4] = (dt * coeffs[14]) * STATES[C2]       + (1.0 + dt * coeffs[15]) * STATES[O]       + (dt * coeffs[16]) * STATES[IO]        + (dt * coeffs[17]) * STATES[Obound];
      // b[5] = (dt * coeffs[18]) * STATES[IC2]      + (dt * coeffs[19]) * STATES[O]             + (1.0 + dt * coeffs[20]) * STATES[IO]  + (dt * coeffs[21]) * STATES[IObound];
      // b[6] = (dt * coeffs[22]) * STATES[O]        + (1.0 + dt * coeffs[23]) * STATES[Obound]  + (dt * coeffs[24]) * STATES[Cbound];
      // b[7] = (dt * coeffs[25]) * STATES[IO]       + (1.0 + dt * coeffs[26]) * STATES[IObound] + (dt * coeffs[27]) * STATES[Cbound];
      // b[8] = (dt * coeffs[28]) * STATES[Obound]   + (dt * coeffs[29]) * STATES[IObound]       + (1.0 + dt * coeffs[30]) * STATES[Cbound];
      // gaussElimination(a,b,x,m);
      // STATES[IC1] = x[0];
      // STATES[IC2] = x[1];
      // STATES[C1] = x[2];
      // STATES[C2] = x[3];
      // STATES[O] = x[4];
      // STATES[IO] = x[5];
      // STATES[Obound] = x[6];
      // STATES[IObound] = x[7];
      // STATES[Cbound] = x[8];
      // delete[] coeffs;
      // delete[] a;
      // delete[] b;
      // delete[] x;
      //====================
      // Explicit RK4 
      //====================
      // int m =  9;
      // double** a = new double*[m];
      // double* y =  new double[m];
      // for (int i = 0; i < m; ++i) {
      //   a[i] = new double[m];
      // }
      // a[0][0] = coeffs[0];    a[0][1] = coeffs[1];    a[0][2] = coeffs[2];    a[0][3] = 0.0;          a[0][4] = 0.0;          a[0][5] = 0.0;          a[0][6] = 0.0;          a[0][7] = 0.0;          a[0][8] = 0.0;
      // a[1][0] = coeffs[3];    a[1][1] = coeffs[4];    a[1][2] = 0.0;          a[1][3] = coeffs[5];    a[1][4] = 0.0;          a[1][5] = coeffs[6];    a[1][6] = 0.0;          a[1][7] = 0.0;          a[1][8] = 0.0;
      // a[2][0] = coeffs[7];    a[2][1] = 0.0;          a[2][2] = coeffs[8];    a[2][3] = coeffs[9];    a[2][4] = 0.0;          a[2][5] = 0.0;          a[2][6] = 0.0;          a[2][7] = 0.0;          a[2][8] = 0.0;
      // a[3][0] = 0.0;          a[3][1] = coeffs[10];   a[3][2] = coeffs[11];   a[3][3] = coeffs[12];   a[3][4] = coeffs[13];   a[3][5] = 0.0;          a[3][6] = 0.0;          a[3][7] = 0.0;          a[3][8] = 0.0;
      // a[4][0] = 0.0;          a[4][1] = 0.0;          a[4][2] = 0.0;          a[4][3] = coeffs[14];   a[4][4] = coeffs[15];   a[4][5] = coeffs[16];   a[4][6] = coeffs[17];   a[4][7] = 0.0;          a[4][8] = 0.0;
      // a[5][0] = 0.0;          a[5][1] = coeffs[18];   a[5][2] = 0.0;          a[5][3] = 0.0;          a[5][4] = coeffs[19];   a[5][5] = coeffs[20];   a[5][6] = coeffs[21];   a[5][7] = 0.0;          a[5][8] = 0.0;
      // a[6][0] = 0.0;          a[6][1] = 0.0;          a[6][2] = 0.0;          a[6][3] = 0.0;          a[6][4] = coeffs[22];   a[6][5] = 0.0;          a[6][6] = coeffs[23];   a[6][7] = 0.0;          a[6][8] = coeffs[24];
      // a[7][0] = 0.0;          a[7][1] = 0.0;          a[7][2] = 0.0;          a[7][3] = 0.0;          a[7][4] = 0.0;          a[7][5] = coeffs[25];   a[7][6] = 0.0;          a[7][7] = coeffs[26];   a[7][8] = coeffs[27];
      // a[8][0] = 0.0;          a[8][1] = 0.0;          a[8][2] = 0.0;          a[8][3] = 0.0;          a[8][4] = 0.0;          a[8][5] = 0.0;          a[8][6] = coeffs[28];   a[8][7] = coeffs[29];   a[8][8] = coeffs[30];
      // y[0] = STATES[IC1];
      // y[1] = STATES[IC2];
      // y[2] = STATES[C1];
      // y[3] = STATES[C2];
      // y[4] = STATES[O];
      // y[5] = STATES[IO];
      // y[6] = STATES[Obound];
      // y[7] = STATES[IObound];
      // y[8] = STATES[Cbound];
      // solve_rk_hERG(a,y,dt,m);
      // STATES[IC1] = y[0];
      // STATES[IC2] = y[1];
      // STATES[C1] = y[2];
      // STATES[C2] = y[3];
      // STATES[O] = y[4];
      // STATES[IO] = y[5];
      // STATES[Obound] = y[6];
      // STATES[IObound] = y[7];
      // STATES[Cbound] = y[8];
      // delete[] coeffs;
      // for (int i = 0; i < m; ++i) {
      //   delete[] a[i];  // Delete each sub-array
      // }
      // delete[] a;  // Delete the outer array
      // delete[] y;
      //====================
      // Analytical approach 
      //====================
      // int m = 9;
      // Eigen::MatrixXd as(m,m);
      // as(0,0) = coeffs[0];    as(0,1) = coeffs[1];    as(0,2) = coeffs[2];    as(0,3) = 0.0;          as(0,4) = 0.0;          as(0,5) = 0.0;          as(0,6) = 0.0;          as(0,7) = 0.0;          as(0,8) = 0.0;
      // as(1,0) = coeffs[3];    as(1,1) = coeffs[4];    as(1,2) = 0.0;          as(1,3) = coeffs[5];    as(1,4) = 0.0;          as(1,5) = coeffs[6];    as(1,6) = 0.0;          as(1,7) = 0.0;          as(1,8) = 0.0;
      // as(2,0) = coeffs[7];    as(2,1) = 0.0;          as(2,2) = coeffs[8];    as(2,3) = coeffs[9];    as(2,4) = 0.0;          as(2,5) = 0.0;          as(2,6) = 0.0;          as(2,7) = 0.0;          as(2,8) = 0.0;
      // as(3,0) = 0.0;          as(3,1) = coeffs[10];   as(3,2) = coeffs[11];   as(3,3) = coeffs[12];   as(3,4) = coeffs[13];   as(3,5) = 0.0;          as(3,6) = 0.0;          as(3,7) = 0.0;          as(3,8) = 0.0;
      // as(4,0) = 0.0;          as(4,1) = 0.0;          as(4,2) = 0.0;          as(4,3) = coeffs[14];   as(4,4) = coeffs[15];   as(4,5) = coeffs[16];   as(4,6) = coeffs[17];   as(4,7) = 0.0;          as(4,8) = 0.0;
      // as(5,0) = 0.0;          as(5,1) = coeffs[18];   as(5,2) = 0.0;          as(5,3) = 0.0;          as(5,4) = coeffs[19];   as(5,5) = coeffs[20];   as(5,6) = coeffs[21];   as(5,7) = 0.0;          as(5,8) = 0.0;
      // as(6,0) = 0.0;          as(6,1) = 0.0;          as(6,2) = 0.0;          as(6,3) = 0.0;          as(6,4) = coeffs[22];   as(6,5) = 0.0;          as(6,6) = coeffs[23];   as(6,7) = 0.0;          as(6,8) = coeffs[24];
      // as(7,0) = 0.0;          as(7,1) = 0.0;          as(7,2) = 0.0;          as(7,3) = 0.0;          as(7,4) = 0.0;          as(7,5) = coeffs[25];   as(7,6) = 0.0;          as(7,7) = coeffs[26];   as(7,8) = coeffs[27];
      // as(8,0) = 0.0;          as(8,1) = 0.0;          as(8,2) = 0.0;          as(8,3) = 0.0;          as(8,4) = 0.0;          as(8,5) = 0.0;          as(8,6) = coeffs[28];   as(8,7) = coeffs[29];   as(8,8) = coeffs[30];
      // // std::cout << "Here is a matrix, as:" << std::endl << as << std::endl << std::endl;
      // Eigen::EigenSolver<Eigen::MatrixXd> es(as);
      // Eigen::VectorXcd eigenvalues = es.eigenvalues();
      // Eigen::MatrixXcd eigenvectors = es.eigenvectors();
      // Eigen::VectorXcd y0_complex(m);
      // y0_complex[0] = STATES[IC1];
      // y0_complex[1] = STATES[IC2];
      // y0_complex[2] = STATES[C1];
      // y0_complex[3] = STATES[C2];
      // y0_complex[4] = STATES[O];
      // y0_complex[5] = STATES[IO];
      // y0_complex[6] = STATES[Obound];
      // y0_complex[7] = STATES[IObound];
      // y0_complex[8] = STATES[Cbound];
      // Eigen::VectorXcd c = eigenvectors.colPivHouseholderQr().solve(y0_complex);
      // double solution[m];
      // std::complex<double> y_complex[m] = {0};
      // for (int i = 0; i < m; ++i) {
      //   std::complex<double> lambda = eigenvalues[i];
      //   std::complex<double> e_lambda_t = std::exp(lambda * dt);
      //   std::complex<double> v[m];
      //   for (int j = 0; j < m; ++j) {
      //       v[j] = eigenvectors(j, i);
      //   }
      //   for (int j = 0; j < m; ++j) {
      //     y_complex[j] += c[i] * e_lambda_t * v[j];
      //   }
      // }
      // for (int i = 0; i < m; i++){
      //   solution[i] = y_complex[i].real();
      // }
      // STATES[IC1] = solution[0];
      // STATES[IC2] = solution[1];
      // STATES[C1] = solution[2];
      // STATES[C2] = solution[3];
      // STATES[O] = solution[4];
      // STATES[IO] = solution[5];
      // STATES[Obound] = solution[6];
      // STATES[IObound] = solution[7];
      // STATES[Cbound] = solution[8];
      // std::cout << "The eigenvalues of as are:" << std::endl << es.eigenvalues() << std::endl;
      // std::cout << "The matrix of eigenvectors, V, is:" << std::endl << es.eigenvectors() << std::endl << std::endl;
      // double lambda = es.eigenvalues()[0].real();
      // std::cout << "Consider the first eigenvalue, lambda = " << lambda << std::endl;
      // delete[] coeffs;
    ////=============================
    ////Approximated solution (Forward Euler)
    ////=============================
    ////CaMK
      // STATES[CaMKt] = STATES[CaMKt] + RATES[CaMKt] * dt;
    ////Membrane potential
      // STATES[V] = STATES[V] + RATES[V] * dt;
    ////Ion Concentrations and Buffers
      // STATES[nai] = STATES[nai] + RATES[nai] * dt;
      // STATES[nass] = STATES[nass] + RATES[nass] * dt;
      // STATES[ki] = STATES[ki] + RATES[ki] * dt;
      // STATES[kss] = STATES[kss] + RATES[kss] * dt;
      // STATES[cai] = STATES[cai] + RATES[cai] * dt;
      // STATES[cass] = STATES[cass] + RATES[cass] * dt;
      // STATES[cansr] = STATES[cansr] + RATES[cansr] * dt;
      // STATES[cajsr] = STATES[cajsr] + RATES[cajsr] * dt;
  // }
// }

void ohara_rudy_cipa_v1_2017::gaussElimination(double *A, double *b, double *x, int N) {
        // Using A as a flat array to represent an N x N matrix
    for (int i = 0; i < N; i++) {
        // Search for maximum in this column
        double maxEl = fabs(A[i*N + i]);
        int maxRow = i;
        for (int k = i + 1; k < N; k++) {
            if (fabs(A[k*N + i]) > maxEl) {
                maxEl = fabs(A[k*N + i]);
                maxRow = k;
            }
        }

        // Swap maximum row with current row (column by column)
        for (int k = i; k < N; k++) {
            double tmp = A[maxRow*N + k];
            A[maxRow*N + k] = A[i*N + k];
            A[i*N + k] = tmp;
        }
        double tmp = b[maxRow];
        b[maxRow] = b[i];
        b[i] = tmp;

        // Make all rows below this one 0 in current column
        for (int k = i + 1; k < N; k++) {
            double c = -A[k*N + i] / A[i*N + i];
            for (int j = i; j < N; j++) {
                if (i == j) {
                    A[k*N + j] = 0;
                } else {
                    A[k*N + j] += c * A[i*N + j];
                }
            }
            b[k] += c * b[i];
        }
    }

    // Solve equation Ax=b for an upper triangular matrix A
    for (int i = N - 1; i >= 0; i--) {
        x[i] = b[i] / A[i*N + i];
        for (int k = i - 1; k >= 0; k--) {
            b[k] -= A[k*N + i] * x[i];
        }
    }
}

void ohara_rudy_cipa_v1_2017::solveRK4(double TIME, double dt){
	unsigned short idx;
	double k1[49],k2[49],k3[49],k4[49];
	double states_temp[49];

	computeRates(TIME, CONSTANTS, RATES, STATES, ALGEBRAIC );
	for(idx = 0; idx < states_size; idx++){
		k1[idx] = dt * RATES[idx];
		states_temp[idx] = STATES[idx] + k1[idx]*0.5;
	}
	computeRates(TIME+(dt*0.5), CONSTANTS, RATES, states_temp, ALGEBRAIC );
	for(idx = 0; idx < states_size; idx++){
		k2[idx] = dt * RATES[idx];
		states_temp[idx] = STATES[idx] + k2[idx]*0.5;
	}
	computeRates(TIME+(dt*0.5), CONSTANTS, RATES, states_temp, ALGEBRAIC );
	for(idx = 0; idx < states_size; idx++){
		k3[idx] = dt * RATES[idx];
		states_temp[idx] = STATES[idx] + k3[idx];
	}
	computeRates(TIME+dt, CONSTANTS, RATES, states_temp, ALGEBRAIC );
	for(idx = 0; idx < states_size; idx++){
		k4[idx] = dt * RATES[idx];
		STATES[idx] += (k1[idx]/6) + (k2[idx]/3) + (k3[idx]/3) + (k4[idx]/6) ;
	}
}

double ohara_rudy_cipa_v1_2017::set_time_step(double TIME,
                                              double time_point,
                                              double min_time_step,
                                              double max_time_step,
                                              double min_dV,
                                              double max_dV,
                                              double* CONSTANTS,
                                              double* RATES,
                                              double* STATES,
                                              double* ALGEBRAIC) {
// double time_step = 0.005;
 double time_step = min_time_step;
 if (TIME <= time_point || (TIME - floor(TIME / CONSTANTS[BCL]) * CONSTANTS[BCL]) <= time_point) {
    //printf("TIME <= time_point ms\n");
    return time_step;
    //printf("TIME = %E, dV = %E, time_step = %E\n",TIME, RATES[V] * time_step, time_step);
  }
  else {
    //printf("TIME > time_point ms\n");
    if (std::abs(RATES[V] * time_step) <= min_dV) {//Slow changes in V
        //printf("dV/dt <= 0.2\n");
        time_step = std::abs(max_dV / RATES[V]);
        //Make sure time_step is between min time step and max_time_step
        if (time_step < min_time_step) {
            time_step = min_time_step;
        }
        else if (time_step > max_time_step) {
            time_step = max_time_step;
        }
        //printf("TIME = %E, dV = %E, time_step = %E\n",TIME, RATES[V] * time_step, time_step);
    }
    else if (std::abs(RATES[V] * time_step) >= max_dV) {//Fast changes in V
        //printf("dV/dt >= 0.8\n");
        time_step = std::abs(min_dV / RATES[V]);
        //Make sure time_step is not less than 0.005
        if (time_step < min_time_step) {
            time_step = min_time_step;
        }
        //printf("TIME = %E, dV = %E, time_step = %E\n",TIME, RATES[V] * time_step, time_step);
    } else {
        time_step = min_time_step;
    }
    return time_step;
  }
}

void ohara_rudy_cipa_v1_2017::___applyDrugEffect(double conc, const double *hill)
{
CONSTANTS[GK1] = CONSTANTS[GK1] * ((hill[2] > 10E-14 && hill[3] > 10E-14) ? 1./(1.+pow(conc/hill[2],hill[3])) : 1.);
CONSTANTS[GKs] = CONSTANTS[GKs] * ((hill[4] > 10E-14 && hill[5] > 10E-14) ? 1./(1.+pow(conc/hill[4],hill[5])) : 1.);
CONSTANTS[GNaL] = CONSTANTS[GNaL] * ((hill[8] > 10E-14 && hill[9] > 10E-14) ? 1./(1.+pow(conc/hill[8],hill[9])) : 1.);
CONSTANTS[GNa] = CONSTANTS[GNa] * ((hill[6] > 10E-14 && hill[7] > 10E-14) ? 1./(1.+pow(conc/hill[6],hill[7])) : 1.);
CONSTANTS[Gto] = CONSTANTS[Gto] * ((hill[10] > 10E-14 && hill[11] > 10E-14) ? 1./(1.+pow(conc/hill[10],hill[11])) : 1.);
CONSTANTS[PCa] = CONSTANTS[PCa] * ( (hill[0] > 10E-14 && hill[1] > 10E-14) ? 1./(1.+pow(conc/hill[0],hill[1])) : 1.);
}

void ohara_rudy_cipa_v1_2017::___applyHERGBinding(double conc, const double *herg)
{
if(conc > 10E-14){
CONSTANTS[Kmax] = herg[0];
CONSTANTS[Ku] = herg[1];
CONSTANTS[n] = herg[2];
CONSTANTS[halfmax] = herg[3];
CONSTANTS[Vhalf] = herg[4];
CONSTANTS[cnc] = conc;
CONSTANTS[Kt] = 0.000035;
STATES[D] = conc;
}
}

void ohara_rudy_cipa_v1_2017::mat_vec_multiply(double** a, double* x, double *result, int n) {
    for (int i = 0; i < n; i++) {
        result[i] = 0.0;
        for (int j = 0; j < n; j++) {
            result[i] += a[i][j] * x[j];
        }
    }
}

void ohara_rudy_cipa_v1_2017::solve_rk_hERG(double** a, double* y, double dt, int n ){
  double* k1 = new double[n];
  double* k2 = new double[n];
  double* k3 = new double[n];
  double* k4 = new double[n];
  double* temp_y = new double[n];
  mat_vec_multiply(a,y,k1,n);
  for(int i = 0; i < n ; i++){
    k1[i] = dt * k1[i];
    temp_y[i] =  y[i] + 0.5 * k1[i];
  }
  mat_vec_multiply(a,temp_y,k2,n);
  for(int i = 0; i < n ; i++){
    k2[i] = dt * k2[i];
    temp_y[i] =  y[i] + 0.5 * k2[i];
  }
  mat_vec_multiply(a,temp_y,k3,n);
  for(int i = 0; i < n ; i++){
    k3[i] = dt * k3[i];
    temp_y[i] =  y[i] + k3[i];
  }
  mat_vec_multiply(a,temp_y,k4,n);
  for(int i = 0; i < n ; i++){
    k4[i] = dt * k4[i];
    y[i] = y[i] + 1.0 / 6.0 * (k1[i] + 2.0 * k2[i] + 2.0 * k3[i] + k4[i]);
  }
  delete[] temp_y;
  delete[] k4;
  delete[] k3;
  delete[] k2;
  delete[] k1;
}

