import cvzone
from ultralytics import YOLO
import cv2
import math
import numpy as np
import time

#cap = cv2.VideoCapture(2)
cap = cv2.VideoCapture(0)
model = YOLO("best.pt")

classNames = ["all"
              ]

while True:
    success, img = cap.read()
    results = model(img, stream=True , conf=0.5)     # ضفت بس هاي وهاي القيمه كلما زودت راح تزداد الموثوقيه ع قولتك بس الكشف راح يقل
    for r in results:
        boxes = r.boxes
        for box in boxes:
            x1, y1, x2, y2 = box.xyxy[0]
            x1, y1, x2, y2 = int(x1), int(y1), int(x2), int(y2)
            w, h = x2 - x1, y2 - y1
            cvzone.cornerRect(img, (x1, y1, w, h))
            conf = math.ceil((box.conf[0] * 100)) / 100
            cls = int(box.cls[0])
            if 0 <= cls < len(classNames) and conf>0.5:
                cvzone.putTextRect(img, f'{"person"} {conf}', (max(0, x1), max(35, y1)), scale=1, thickness=1)
                print(conf)
            else:
                # Handle invalid class ID
                print(f"Invalid class ID: {cls}")

            print(box)
    cv2.imshow("Webcam", img)
    if cv2.waitKey(1) & 0xff == ord('q'):
        break
cap.release()
cv2.destroyAllWindows()
