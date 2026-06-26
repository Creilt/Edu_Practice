import cv2
import numpy as np

image = cv2.imread(r"C:\Users\Creilt\Downloads\test.jpg")
hsv = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)
hsv_min = np.array((40, 100, 100), np.uint8)
hsv_max = np.array((80, 255, 255), np.uint8)
mask = cv2.inRange(hsv, hsv_min, hsv_max)
contours, _ = cv2.findContours(mask, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

for contour in contours:
    x, y, w, h = cv2.boundingRect(contour)
    cx = x + w // 2
    cy = y + h // 2
    cv2.circle(image, (cx, cy), 10, (0, 0, 255), -1)

cv2.imshow("result", image)
cv2.waitKey(0)
cv2.destroyAllWindows()
