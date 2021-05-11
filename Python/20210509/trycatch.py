def no_return():
    print("I am about to raise it")
    raise Exception("This is raised")
    print("This won't execute")
    return "nopes"

try:
    no_return()
except:
    print("I caught it")
print("this comes after I caught it")