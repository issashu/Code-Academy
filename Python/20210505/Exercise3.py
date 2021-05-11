from math import pi

class Cylinder:
    def __init__(self, height, radius):
        self.height = height
        self.radius = radius
    
    def volume(self):
        return (pi*(self.radius**2)*self.height)
    def area(self):
        return (2*pi*self.radius*self.height)+(2*pi*(self.radius**2))

height = 10
radius = 5
Tzilindar = Cylinder(height, radius)
print(Tzilindar.volume())
print(Tzilindar.area())