#!/usr/bin/env python3
import cv2 as cv
import numpy as np

print(cv.__version__)

# F: {
#    +0.000002       -0.000929       +0.168397
#    +0.000930       -0.000002       -0.612318
#    -0.171481       +0.612492       +1.000000
# }

leftImg = cv.imread('test-images/2011_09_26_drive_0005_sync-83-84/0000000083.png')

F = np.array([
   [+0.000002,       -0.000929,       +0.168397],
   [+0.000930,       -0.000002,       -0.612318],
   [-0.171481,       +0.612492,       +1.000000]
])
img_size = leftImg.shape[1::-1]

rectification = cv.polarrect.PolarRectification_create(F, img_size)

print(rectification)

rectification.compute()
fwm = rectification.forward_map(0)

polar = cv.remap(leftImg, fwm, None, cv.INTER_LINEAR, borderMode=cv.BORDER_TRANSPARENT)
cv.imwrite('out.png', polar)
