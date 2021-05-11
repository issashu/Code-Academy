def any_division(number):
    try:
        if number == 13:
            raise ValueError("Restore the Snyder-verse!")
        return 100/number
    except ZeroDivisionError:
        return "You shall not divide by zero!"
    except TypeError:
        return "One does not just divide non-numbers!"
    except ValueError:
        print("No way!")
        raise

for val in (0, 10, "Golum", 20.3, 13):
    print("Testing with: %s" %val, "and result was:", end=" ")
    print(any_division(val))