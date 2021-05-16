#ifndef POLARRECT_H
#define POLARRECT_H

#include <opencv2/core.hpp>

namespace cv {
namespace polarrect {

/** @brief Python gateway API to polar rectification */
class CV_EXPORTS_W PolarRectification {
public:
    virtual ~PolarRectification() = 0;

    CV_WRAP virtual void compute() = 0;
    // CV_WRAP virtual void forward_map(int index, OutputArray mat2f) const = 0;

    /** @brief Computes polar rectification from fundamental matrix F */
    CV_EXPORTS_W Ptr<PolarRectification> create(const cv::Matx33d& F, const cv::Size& image_size);
};


} // polarrect 
} // cv

#endif /* POLARRECT_H */