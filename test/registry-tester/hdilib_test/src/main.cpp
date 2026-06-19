#include <hdi/data/embedding.h>
#include <hdi/dimensionality_reduction/hd_joint_probability_generator.h>
#include <hdi/dimensionality_reduction/knn_utils.h>
#include <hdi/dimensionality_reduction/gradient_descent_tsne_texture.h>
#include <hdi/dimensionality_reduction/tsne_parameters.h>
#include <hdi/utils/cout_log.h>

#include <algorithm>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <memory>
#include <random>
#include <stdexcept>
#include <vector>

// Doesn't do anything just demonstrates linking against HDILib and including its headers. 
// If this compiles and links, the test is successful.The test doesn't need to run any 
// code from HDILib, so the main function is empty.
int main(int argc, char** argv)
{
    hdi::dr::knn_library _knn_algorithm;
    hdi::dr::knn_distance_metric _knn_metric;
    hdi::dr::TsneParameters tSNE_param;
    using ProbGenType = hdi::dr::HDJointProbabilityGenerator<float>;
    ProbGenType::Parameters prob_gen_param;
    ProbGenType prob_gen;
    hdi::data::Embedding<float> embedding;
    using MapType = hdi::data::MapMemEff<uint32_t, float>;
    using SparseScalarMatrixType = std::vector<MapType>;
    SparseScalarMatrixType distributions;
    hdi::dr::GradientDescentTSNETexture tSNE;
    tSNE.setType(hdi::dr::GradientDescentTSNETexture::COMPUTE_SHADER_VULKAN);

    return 0;
}