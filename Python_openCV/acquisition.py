import cv2
import cv2.cv as cv    #Just a formality!
import time
import numpy
import time



def startAcquisition():
    # Camera 0 is the integrated web cam on my netbook
    
    camera_port1 = 1
    camera_port2 = 2
    camera_port3 = 3
    camera_port4 = 0
    camera_port5 = 5

    cv.NamedWindow("camera1", cv.CV_WINDOW_AUTOSIZE)
    cv.NamedWindow("camera2", cv.CV_WINDOW_AUTOSIZE)
    cv.NamedWindow("camera3", cv.CV_WINDOW_AUTOSIZE)
    cv.NamedWindow("camera4", cv.CV_WINDOW_AUTOSIZE)
    cv.NamedWindow("camera5", cv.CV_WINDOW_AUTOSIZE)

    # Initialize the camera
    capture1 = cv.CaptureFromCAM(camera_port1)# camera_port -> index of camera
    #test = cv.SetCaptureProperty(capture1,cv.CV_CAP_PROP_FRAME_WIDTH,1920)
    #print test
    #cv.SetCaptureProperty(capture1,cv.CV_CAP_PROP_FRAME_HEIGHT,1080) #Does not work. Thanks to openCV and Logitech

    capture2 = cv.CaptureFromCAM(camera_port2)# camera_port -> index of camera
    capture3 = cv.CaptureFromCAM(camera_port3)# camera_port -> index of camera
    capture4 = cv.CaptureFromCAM(camera_port4)# camera_port -> index of camera
    capture5 = cv.CaptureFromCAM(camera_port5)# camera_port -> index of camera

    # termination criteria
    #criteria = (cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_MAX_ITER, 30, 0.001)

    gray=0

    print ("Avant if")

    if (capture1  and capture2 and capture3 and capture4) :
    #It will go in the if even when the cameras are not correctly initialized
        print "In the IF"
     # Camera initialized without any errors
        i = 0

        #tmps1 = time.clock()
        tmps1 = time.time()
        img1 = cv.QueryFrame(capture1)
        cv2.waitKey(30)
        img2 = cv.QueryFrame(capture2)
        cv2.waitKey(30)
        img3 = cv.QueryFrame(capture3)
        cv2.waitKey(30)
        img4 = cv.QueryFrame(capture4)
        cv2.waitKey(30)

        while True:
            #tmpsTMP = time.clock()
            #tmps2 = time.time()
            
            #img5 = cv.QueryFrame(capture5)
            #cv2.waitKey(10)

            tmps2 = time.clock()
            cv.ShowImage("camera1", img1)
            cv.ShowImage("camera2", img2)
            cv.ShowImage("camera3", img3)
            cv.ShowImage("camera4", img4)
            #cv.ShowImage("camera5", img5)

            #print "Time to show Frames = " + str((time.clock()-tmpsTMP2))

            elapsedTime = time.time()-tmps1

            if elapsedTime > 0.75 :
                #When a second passes, saving the images will happen.
                img1 = cv.QueryFrame(capture1)
                cv2.waitKey(30)
                img2 = cv.QueryFrame(capture2)
                cv2.waitKey(30)
                img3 = cv.QueryFrame(capture3)
                cv2.waitKey(30)
                img4 = cv.QueryFrame(capture4)
                cv2.waitKey(30)
                
                print "Images saved after : " + str (elapsedTime)
                cv.SaveImage('./Acquisitions/Camera1/pic{:>05}.jpg'.format(i), img1)
                cv.SaveImage('./Acquisitions/Camera2/pic{:>05}.jpg'.format(i), img2)
                cv.SaveImage('./Acquisitions/Camera3/pic{:>05}.jpg'.format(i), img3)
                cv.SaveImage('./Acquisitions/Camera4/pic{:>05}.jpg'.format(i), img4)
                #cv.SaveImage('./Acquisitions/Camera5/pic{:>05}.jpg'.format(i), img5)
                i+=1
                tmps1 = time.time()

            k = cv2.waitKey(15) & 0xFF
               
            if  k == ord('q'):
                break

            if  k== ord('s'):
                cv.SaveImage('./imagesCalibration/pic{:>05}.jpg'.format(i), img4)
                print("Image saved.")
                i += 1

    else:
        print "Probleme d'initialisation des cameras"

        
    cv2.cv.DestroyWindow("camera1")
    cv2.cv.DestroyWindow("camera2")
    cv2.cv.DestroyWindow("camera3")
    cv2.cv.DestroyWindow("camera4")
    cv2.cv.DestroyWindow("camera5")
    print ("Fin")

########################################################################## 
def main():
    print "Begin acquisition"

    startAcquisition()

    
    print "End acquisition"
    return

##########################################################################
if __name__ == '__main__':
    main()
