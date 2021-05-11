class EvenOnly(list):
    def append(self, integer):
        if not isinstance(integer, int):
            print("Only integers can be added")
        if integer % 2:
            print("Only even numbers is recommended to be added")
        super().append(integer)

instance = EvenOnly()

instance.append(64)
print(instance)