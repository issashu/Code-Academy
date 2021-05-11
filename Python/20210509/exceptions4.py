import random

some_exceptions = [ValueError, TypeError, IndexError, None]

try:
    choice = random.choice(some_exceptions)
    print("Raising {}".format(choice))
    if choice:
        raise choice("An error")
except ValueError:
    print("Caught ValueError")
except TypeError:
    print("Caught a Value`Error")
except Exception as b:
    print("Caught some other error: %s" %b.__class__.__name__)
else:
    print("No exception raised or caught")
finally:
    print("Cleanup crew reporting for duty")
    