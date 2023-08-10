import serial 
import serial.tools.list_ports
import time
import pyautogui

serialCom = serial.Serial('COM17',9600)

serialCom.setDTR(False)
time.sleep(1)
serialCom.flushInput()
serialCom.setDTR(True)


def presskey(key , htime):
    start = time.time()
    while time.time() - start < htime:
        pyautogui.keyDown(key)
    pyautogui.keyUp(key)


def Calibirate():
    threshold = [0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0]
    avg= [0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0]
    print("Calibirating...")
    for i in range(0,100):
        data = serialCom.readline().decode().strip()
        if data:
            values = [ int(x) for x in data.split(',')]
            for i , value in enumerate(values):
                avg[i] = avg[i] + value
    print("Calibiration Done")
    for i in range(25):
        if i ==12:
            #Having issues with this particualr recivever
            threshold[i] = 0
        else:
            threshold[i] = int(avg[i]/100)
    return threshold
        
vertical = [ 16 , 17 , 18 , 19 ,20 ,21 ,22 ,23 ,24 ]
horizontal = [ 0 , 1 , 2, 3, 4, 5, 6 , 7 ,8 ,9 ,10 ,11 ,12 ,13 ,14 , 15]

def direction(vector):
    increasing = 0
    decreasing = 0
    for i in range(len(vector)-1):
        if vector[i+1]>vector[i]:
            increasing = increasing + 1
        else:
            decreasing = decreasing + 1
    # if vector[0]<vector[len(vector)-1]:
    #     return "+"
    # else:
    #     return "-"
    if increasing>=decreasing:
        return "+"
    else:
        return "-"


def touch(threshold):
    prev_point = -1
    while True:
        points = []
        hor_point = []
        ver_point = []
        for k in range(5):
            up = 0 
            down = 0
            data = serialCom.readline().decode().strip()
            values = [int(x) for x in data.split(",")]
            for i , value in enumerate(values):
                if value < threshold[i]-25:
                    points.append(i)
                    
                    # print(i , " " , value , " " , threshold[i])
        # print(points)
        uniquePoint = []

        for item in points:
            if item != prev_point:
                prev_point = item
                if (item in vertical and item not in ver_point):
                    ver_point.append(item)
                elif (item in horizontal and item not in hor_point):
                    hor_point.append(item)
                else:
                    pass
        if len(ver_point)>1 :
            dir = direction(ver_point)
            if dir =="+":
                presskey("up" , 0.4)
            else:
                presskey("Down" , 0.4)
        if len(hor_point)>1:
            dir = direction(hor_point)
            if dir =="+":
                presskey("left" , 0.4)
            else:
                presskey("right" , 0.4)


        print("Vertical " , ver_point , end="  ")
        print("Horizontal ",hor_point)
        


                
    


threshold = Calibirate()
touch(threshold)