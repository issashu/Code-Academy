class Square:
    def __init__(self, side):
        self.side = side
    
    def perimeter(self):
        print("The perimeter of the square is: ", self.side*4)
    def area(self):
        print("The area of the square is: ", self.side*self.side)


Kvadrat = Square(2.56)
Kvadrat.perimeter()
Kvadrat.area()