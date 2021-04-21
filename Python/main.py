from test_module import x,y

print("original x:", x)
print("original y: ", y)
x=42
y[0] = 42
print("x:", x, "and y: ", y)

importlib.reload(test_module)
print("original x:", x)
print("original y: ", y)
