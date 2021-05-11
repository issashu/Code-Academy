class EvenOnly(list):
    def append(self, integer):
        if not isinstance(integer, int):
            raise TypeError("Not an integer")
        if integer%2:
            raise ValueError("Reccomended evens")
        super().append(integer)

instance = EvenOnly()
instance.append(5)
print(Instance)