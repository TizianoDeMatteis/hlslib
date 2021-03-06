/// @author    Jannis Widmer (widmerja@ethz.ch)
/// @copyright This software is copyrighted under the BSD 3-Clause License.

constexpr int kDataSize = 1024;

extern "C" {
void HBMandBlockCopy(int *hbm0, int *ddr1, int *hbm13, int *hbm20, int *hbm31,
                     int *ddr0) {
  for (int i = 0; i < kDataSize; i++) {
    #pragma HLS PIPELINE II=1
    ddr0[i] = hbm0[i] + ddr1[i] + hbm13[i] + hbm20[i] + hbm31[i];
  }
}
}
