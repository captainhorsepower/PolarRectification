#include "opencv2/polarrect.hpp"
#include "c_polar_stereo_rectification.h"

using namespace cv;
using namespace cv::polarrect;

class PolarRectification_Impl : public PolarRectification {
private:
    cv::Matx33d F;
    cv::Size image_size;
    c_polar_stereo_rectification delegate;
public:
    PolarRectification_Impl(const cv::Matx33d& F, const cv::Size& image_size): F(F), image_size(image_size), delegate(c_polar_stereo_rectification()) {};
    // ~PolarRectification_Impl() {};

    void compute() { delegate.compute(F, image_size); }

    void forward_map(int index, OutputArray mat2f) const {
        Mat2f map =  delegate.forward_map(index); 
        mat2f.create(map.size(), map.type());   
        Mat outMat = mat2f.getMat();
        // TODO: replace this copy to!
        map.copyTo(outMat);
    };

    // void reverse_map(int index, cv::OutputArray mat2f); const { return delegate.reverse_map(index); };
};

Ptr<PolarRectification> PolarRectification::create(const cv::Matx33d& F, const cv::Size& image_size) {
    return makePtr<PolarRectification_Impl>(F, image_size);
}
