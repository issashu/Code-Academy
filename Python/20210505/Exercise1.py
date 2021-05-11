def calc_77(min,max):
    list =[i for i in range(min, max+1) if i%111 == 0 and i%2 == 0]
    print(list)

calc_77(7000, 8658)
calc_77(9000, 9547)