#importing Modules

import cv2
import numpy as np

#Capturing Video through input.

cap = cv2.VideoCapture('Fat_OnlyScene.mp4')

while(1):
        _, img = cap.read()

        #converting frame(img) from BGR (Blue-Green-Red) to HSV (hue-saturation-value)
        hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)

        #defining the range of Red color
        red_lower = np.array([161, 155, 84],np.uint8)
        red_upper = np.array([179, 255, 255],np.uint8)

        #finding the range red colour in the image
        red = cv2.inRange(hsv, red_lower, red_upper)

        #Morphological transformation, Dilation
        kernal = np.ones((5 ,5), "uint8")

        blue=cv2.dilate(red, kernal)

        res=cv2.bitwise_and(img, img, mask = red)

        #Tracking Colour (Red)
        (_,contours,hierarchy)=cv2.findContours(red,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)

        for pic, contour in enumerate(contours):
                area = cv2.contourArea(contour)
                if(area>300):

                        x,y,w,h = cv2.boundingRect(contour)
                        img = cv2.rectangle(img,(x,y),(x+w,y+h),(255,0,0),3)

                        print "The area involved is between x: ", x, " and y: ", y, " and also w: ", w, " and h: ", h
                        print "The area is: ", area
                        #print(cv2.countNonZero(img))

        cv2.imshow("Color Tracking",img)
        img = cv2.flip(img,1)
        cv2.imshow("Red",res)

        #ret,thresh=cv2.threshold(img,a,b,cv2.THRESH_BINARY_INV)
        #print cv2.countNonZero(tresh)

        if cv2.waitKey(10) & 0xFF == 27:
                cap.release()
                cv2.destroyAllWindows()
                break
