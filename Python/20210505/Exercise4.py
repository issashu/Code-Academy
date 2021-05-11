class Triangle:
    number_of_sides = 3
    
    def __init__(self,angle1, angle2, angle3):
        self.angle1 = angle1
        self.angle2 = angle2
        self.angle3 = angle3
    
    def check_angles(self):
        angle_sum = self.angle1+self.angle2+self.angle3
        
        if angle_sum == 180:
            return True
        else:
            return False
    
Angle1 = input("First angle:")
Angle2 = input("Second angle:")
Angle3 = input("Third angle:")
my_Triangle = Triangle(Angle1, Angle2, Angle3)
print(my_Triangle.number_of_sides)
print("Is the sum of angles 180?:")
print(my_Triangle.check_angles())