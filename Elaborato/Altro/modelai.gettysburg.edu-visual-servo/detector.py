#!/usr/bin/env python
"""
This program receives an image from a rostopic and 
converts it to a cv2 image. Then it uses the cv2 functions
to detect a blob of a desired color. It draws a bounding
box over the blob and publishes this modified image
to the ~detection_image topic.
"""

import cv2
import numpy as np
import rospy
from sensor_msgs.msg import Image
from std_msgs.msg import Float32
from cv_bridge import CvBridge, CvBridgeError
import sys
import threading

"""
The detector class opereates only on opencv images.  It
will detect Yellow blobs in an image and mark them with 
bounding boxes. It will label MAX_DETECTIONS number of 
blobs, where the blobs are sorted by contour area.
"""

class Detector:
    # hsv ranges for yellow detections
    YELLOW = [np.array(x, np.uint8) for x in \
            [[25,100,100], [35, 255, 255]] ]
    # number of blobs to detect
    MAX_DETECTIONS = 1
    
    """ 
    get_filtered_contours will segment images based on color and then
    return the largest contours. 
    """
    def get_filtered_contours(self,img):
        # convert image to color space hsv
        hsv_img = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
        
        # threshold the image to remove all colors that are not yellpw
        frame_threshed = cv2.inRange(hsv_img, self.YELLOW[0], self.YELLOW[1])
        ret,thresh = cv2.threshold(frame_threshed, self.YELLOW[0][0], 255, 0)
         
        # create the list of filtered contours to return
        filtered_contours = []

        # find all contours in the thresholded image
        contours, hierarchy = cv2.findContours(\
                thresh,cv2.RETR_CCOMP,cv2.CHAIN_APPROX_SIMPLE)
        
        # sort all contours by area, largest to smallest
        contour_area = [ (cv2.contourArea(c), (c) ) for c in contours]
        contour_area = sorted(contour_area,reverse=True, key=lambda x: x[0])

        for j, (area,(cnt)) in enumerate(contour_area):
            # only report MAX_DETECTIONS number of controus
            if j >=self.MAX_DETECTIONS: break

            # create a bounding box around the contour
            x,y,w,h = cv2.boundingRect(cnt)
            box = (x,y,w,h)
            
            # make the color of the box the mean of the contour
            mask = np.zeros(thresh.shape,np.uint8)
            cv2.drawContours(mask,[cnt],0,255,-1)
            mean_val = cv2.mean(img,mask = mask)
            
            # add this contour to the list
            filtered_contours.append( (cnt, box, mean_val) )
        return filtered_contours


    def contour_match(self, img):
        '''
        Returns 1. Image with bounding boxes added
                2. an ObstacleImageDetectionList
        '''
        # get filtered contours
        contours = self.get_filtered_contours(img)
        
        for (cnt, box,  mean_color)  in contours: 
            # plot box and label around contour
            x,y,w,h = box
            font = cv2.FONT_HERSHEY_SIMPLEX
            cv2.putText(img,"yellow", (x,y), font, 1,mean_color,4)
            cv2.rectangle(img,(x,y),(x+w,y+h), mean_color,2)

        # return the image with boxes around detected contours
        return img

"""
This class is built off of Echo to call the contour_match method in 
the Detector class.  It handles the interface between ros messages
and opencv.
"""
class StaticObjectDetectorNode:
    def __init__(self):
        
        self.detector = Detector()
        self.sub_image = rospy.Subscriber("/camera/rgb/image_rect_color", Image, self.processImage, queue_size=1)
        self.pub_image = rospy.Publisher("~detection_image", Image, queue_size=1)
        self.bridge = CvBridge()

        rospy.loginfo("Object Detector Initialized.")

    def processImage(self, image_msg):
         # convert rosmsg to cv2 type
        image_cv = self.bridge.imgmsg_to_cv2(image_msg)            
        
        # call blob detector
        image_detections = self.detector.contour_match(image_cv)

        # convert cv2 image to rosmsg
        image_ros_msg = self.bridge.cv2_to_imgmsg(image_detections, "bgr8")

        # publish rosmsg 
        self.pub_image.publish(image_ros_msg) 

if __name__=="__main__":
    # initalize the ros node
    rospy.init_node('static_object_detector_node')
    
    # create the object detector
    node = StaticObjectDetectorNode()
    
    # continue running node until it is killed from outside process
    rospy.spin()
