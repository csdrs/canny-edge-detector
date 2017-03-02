
#ifndef _CANNY_EDGE_DETECTOR_HPP_
#define _CANNY_EDGE_DETECTOR_HPP_

#include "edgeDetector.hpp"

///
/// \brief Canny edge dectectior
///
/// Encapsulates the canny edge detection algorithm.
///
class CannyEdgeDetector : public EdgeDetector
{
    public:
        CannyEdgeDetector(std::shared_ptr<ImgMgr> image);
        ~CannyEdgeDetector();

        void detect_edges(bool serial);

    private:
        /* CPU implementation */
        void apply_gaussian_filter(pixel_t *blurred_pixels, pixel_t *input_pixels);
        //void compute_intensity_gradient();
        //void suppress_non_max();
        //void apply_double_threshold();
        void apply_hysteresis(pixel_t *out_pixels, pixel_t *in_pixels, pixel_t hi_thld, pixel_t lo_thld);

        /* CUDA/GPU implementation */
        //void cu_apply_gaussian_filter();
        //void cu_compute_intensity_gradient();
        //void cu_suppress_non_max();
        //void cu_apply_double_threshold();
        //void cu_apply_hysteresis(pixel_t *out_pixels, pixel_t *in_pixels, pixel_t hi_thld, pixel_t lo_thld);

        /* helper functions */
        void trace_immed_neighbors(pixel_t *out_pixels, pixel_t *in_pixels, unsigned idx, pixel_t t_low);

        /* member variables */
        pixel_t m_edge; // defines an edge for image this detector was initialized with
};

#endif // _CANNY_EDGE_DETECTOR_HPP_
